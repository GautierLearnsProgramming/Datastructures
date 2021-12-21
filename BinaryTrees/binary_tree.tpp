
#ifndef BINARY_TREE_IMPL
#define BINARY_TREE_IMPL
#include "binary_tree.h"

namespace gb_datastructures {

    template<typename T>
    BinaryTree<T>::BinaryTree() {
        root_count = nullptr;
        root = nullptr;
    }

    template<typename T>
    BinaryTree<T>::BinaryTree(const BinaryTree<T> &copy):
    root(copy.root), root_count(copy.root_count){
        std::cout << "Copy constructor called" <<std::endl;
        *root_count += 1;
    }

    template<typename T>
    BinaryTree<T>::~BinaryTree() {
        *root_count -= 1;
        if(*root_count <= 0){
            delete_tree();
            delete root_count;
            delete root;
        }
        std::cout << "Destructor called" << std::endl;
    }

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &other) {
        if(other != this){
            *root_count -= 1;
            if(*root_count == 0){
                delete_tree();
                delete root_count;
            }
            root = other.root;
            root_count = other.root_count;
            *root_count += 1;
        }
        std::cout << "Assignment operator called" << std::endl;
        return *this;
    }

    template<typename T>
    void BinaryTree<T>::delete_tree() {
        if(root != nullptr) {
            delete_subtree(*root);
        }
    }

    template<typename T>
    void BinaryTree<T>::delete_subtree(Node<T> *node) {
        // Post-order traversal with deletion at each point
        if(node == nullptr) return;
        delete_subtree(node->left);
        delete_subtree(node->right);
        delete node;
    }

    template<typename T>
    void BinaryTree<T>::initialize(T v) {
        if(root == nullptr){
           Node<T>* root_node = new Node<T>(v);
           root = new Node<T>*();
           *root = root_node;
           root_count = new int;
           *root_count = 1;
        }
    }


    template<typename T>
    void BinaryTree<T>::insert(T value) {
        // If the tree is empty, create a root node the value
        if(root == nullptr){
            initialize(value);
            return;
        }

        // Otherwise, go down the tree until we find the correct place of insertion
        Node<T>* n = *root;
        bool found_parent = false;
        while(!found_parent){
            if(value >= n->value){
                if(n->right != nullptr){
                    n = n->right;
                }
                else {
                    n->right = new Node<T>(value);
                    found_parent = true;
                }
            } else {
                if(n->left != nullptr) {
                    n = n->left;
                }
                else {
                    n->left = new Node<T>(value);
                    found_parent = true;
                }
            }
        }
    }

    template<typename T>
    void BinaryTree<T>::remove(T value) {
        // If the tree is empty, return
        if(root == nullptr) return;

        Node<T>* parent = nullptr;
        bool parent_greater_than_child = false;
        Node<T>* node = *root;

        bool found = false;
        while(!found){
            // Search for the node to delete while maintaining a parent pointer
            if(node->value == value){
                found = true;
            }
            else {
                // Go down the tree left or right depending on the current node's value and the value we try to insert.
                // If the value to insert is bigger than the current node's value, go right, else go left.
                if(value >= node->value){
                    parent = node;
                    node = node->right;
                    parent_greater_than_child = false;
                } else {
                    parent = node;
                    node = node->left;
                    parent_greater_than_child = true;
                }
                if(node == nullptr){
                    std::cout << "Could not delete, value not found" << std::endl;
                    return;
                }
            }
        }
        // Depending on the status of the node (leaf, 1 child, 2 children), delete with the correct method
        /*
         * Case leaf : Delete the node and remove parent's pointer to node
         * Case 1 child : Delete the node and set the parent's pointer to node to child
         * Case 2 children : See case two children below
         * What changes when the parent is root instead of a middle node ?
         * Case leaf : Delete the root and don't set a new root
         * Case one child : Delete the root and set the child as the new root
         * Case two children : Swap the root with the successor, delete the root and set the successor as the new root
         */
        // Leaf node
        if(node->left == nullptr && node->right == nullptr){
            delete_leaf(node, parent, parent_greater_than_child);
        }
        // Case one child
        else if ((node->left != nullptr && node->right == nullptr) || (node->right != nullptr && node->left == nullptr)) {
            delete_node_with_one_child(node, parent, parent_greater_than_child);
        }
        // Case two children
        // Explore again to find the successor, defined as the deleted node's lowest bigger node.
        // We need to maintain a pointer to the successor parent's in order to properly make the swap.
        else {
            Node<T>* successor = node->right;
            Node<T>* successor_parent = node;
            bool found_successor = false;
            while(!found_successor){
                // We have found a successor if the current potential successor does not have a lower child
                if(successor->left == nullptr){
                    found_successor = true;
                } else {
                    successor_parent = successor;
                    successor = successor->left;
                }
            }
            // At this point, we have node, parent, successor, successor_parent.
            // We want to swap successor and node, and then to properly delete node.
            // To do the swap : the parent's pointer to node now points to successor (or the successor becomes the root
            // if the node to delete is the root)
            // The successor's left and right children become the node's left and right children
            // The node's left child is now null, and the node's right child becomes the successor's right child
            // The successor's parent's left child becomes the node.
            if(parent == nullptr){
                *root = successor;
            } else {
                if(parent_greater_than_child){
                    parent->left = successor;
                } else {
                    parent->right = successor;
                }
            }
            Node<T>* successor_right_child = successor->right;
            successor->right = node->right;
            successor->left = node->left;
            node->left = nullptr;
            node->right = successor_right_child;
            successor_parent->left = node;
            // We can now safely delete the node who has at most one child.
            if(node->right == nullptr){
                delete_leaf(node, successor_parent, true);
            } else {
                delete_node_with_one_child(node, successor_parent, true);
            }
        }
    }

    template<typename T>
    bool BinaryTree<T>::empty() {
        return **root == nullptr;
    }

    template<typename T>
    void BinaryTree<T>::delete_node_with_one_child(Node<T> *node, Node<T> *parent, bool parent_greater_than_child) {
        if(parent == nullptr){ // i.e we want to delete the root node
            if(node->right != nullptr){
                *root = node->right;
            } else {
                *root = node->left;
            }
        }
        else {
            // Replace the parent's node left or right child with the deleted node's child
            if (parent_greater_than_child) {
                if(node->right != nullptr){
                    parent->left = node->right;
                } else {
                    parent->left = node->left;
                }
            } else {
                if(node->right != nullptr){
                    parent->right = node->right;
                } else {
                    parent->right = node->left;
                }
            }
        }
        delete node;
    }

    template<typename T>
    void BinaryTree<T>::delete_leaf(Node<T> *node, Node<T> *parent, bool parent_greater_than_child) {
        // Case the node is the root
        if(parent == nullptr){
            // Set the root count as 0 and remove the root pointer
            *root_count = 0;
            delete root;
            root = nullptr;
        }
        else {
            // Set the parent's pointer to the node to null
            if (parent_greater_than_child) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        }
        delete node;
    }

    template<typename T>
    struct NodeAndDepth {
        Node<T>* node;
        int depth;
    };

    template<typename T>
    std::ostream &operator<<(std::ostream& os, const BinaryTree<T>& binaryTree) {
        // Make a breadth first traversal and print each layer of the binary tree
        int current_depth = 0;
        gb_datastructures::DynamicQueue<NodeAndDepth<T>>* queue = new gb_datastructures::DynamicQueue<NodeAndDepth<T>>();
        queue->queue({*binaryTree.root, 0});
        while(!queue->empty()){
            NodeAndDepth<T> s = queue->dequeue();
            if(s.depth > current_depth){
                current_depth = s.depth;
                os << std::endl;
            }
            os << s.node->getValue() << " ";

            if(s.node->getLeft() != nullptr){
                queue->queue({s.node->getLeft(), s.depth+1});
            }
            if(s.node->getRight() != nullptr){
                queue->queue({s.node->getRight(), s.depth + 1});
            }
        }
        delete queue;
        os << std::endl;
        return os;
    }

    template<typename T>
    Node<T> *BinaryTree<T>::search(T value) {
        if(root == nullptr) return;
        Node<T>* node = *root;
        while(node != nullptr){
            if (node->getValue == value) return node;
            if(value > node->getValue()){
                node = node->getRight();
            } else {
                node = node->getLeft();
            }
        }
        return nullptr;
    }
}

#endif
