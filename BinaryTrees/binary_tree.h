//
// Created by gautier on 20/12/2021.
//

#ifndef DATASTRUCTURES_BINARY_TREE_H
#define DATASTRUCTURES_BINARY_TREE_H
#include <iostream>
#include "../Queues/DynamicQueue.h"

namespace gb_datastructures {

    template<typename T>
    class Node;

    template<typename T>
    class BinaryTree;

    template<typename T>
    class BinaryTree {
    public:
        void insert(T value);
        void remove(T value);
        Node<T>* search(T value);
        bool empty();

        BinaryTree();
        ~BinaryTree();
        BinaryTree(const BinaryTree<T> &copy);
        template<typename U>
        friend std::ostream &operator<<(std::ostream& os,const  BinaryTree<U>& binaryTree);
        BinaryTree<T> &operator=(const BinaryTree<T> &other);

        Node<T>* getRoot(){
            return *root;
        }

    private:
        Node<T> **root;
        int *root_count;

        void delete_tree();
        void delete_subtree(Node<T> *node);
        void delete_node_with_one_child(Node<T>* node, Node<T>* parent, bool parent_greater_than_child);
        void delete_leaf(Node<T>* node, Node<T>* parent, bool parent_greater_than_child);
        void initialize(T v);
    };


/**
 * @class Node for a binary tree. The following property is always true :
 * The value held by a node is greater than any value in the left subtree, and lower than any value in the right subtree.
 * @tparam T - The kind of value to hold in a node. T must implement the greater than operator to define an order relationship
 */
    template<typename T>
    class Node {
        friend BinaryTree<T>;
    public:
        Node(T v) {
            left = nullptr;
            right = nullptr;
            value = v;
        }

        Node(T v, Node *l, Node *r) {
            left = l;
            right = r;
            value = v;
        }

        T getValue(){
            return value;
        }
        Node<T>* getLeft(){
            return left;
        };
        Node<T>* getRight(){
            return right;
        }

    private:
        Node *left;
        Node *right;
        T value;
    };

}

#endif //DATASTRUCTURES_BINARY_TREE_H
