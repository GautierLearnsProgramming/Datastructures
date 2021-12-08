//
// Created by gautier on 07/12/2021.
//

#ifndef DATASTRUCTURES_DOUBLY_LINKED_LIST_H
#define DATASTRUCTURES_DOUBLY_LINKED_LIST_H

namespace linked_list {

    template<typename T>
    class Node {

    public:
        Node(T v, Node* n, Node* p);
        // Node's value
        T v;
        // Node's next node
        Node* n;
        // Node's previous node
        Node* p;
        template <typename> friend class DoublyLinkedList;
    };

    template<typename T>
    Node<T>::Node(T v, Node* n, Node* p) {
        this->v = v;
        this->n = n;
        this->p = p;
    }

    template<typename T>
    class DoublyLinkedList {
    public:
        /**
         * Get the size of the list
         * @return 
         */
        int size();
        
        /**
         * Check if the list is empty
         * @return 
         */
        bool empty();

        /**
         * Add a new element at the front of the list
         * @param item - The item of the new head node
         */
        void push_front(T item);

        /**
         *
         */
        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, DoublyLinkedList<U> l);

        /**
         * Return the value at the given index
         * @param index 
         * @return 
         * @throw out_of_range exception if index is greater than the size of the list
         */
        T value_at(int index);

        /**
         * Remove the head from the list and return its value
         * @return 
         */
        T pop_front();

        /**
         * Create a node with the value and set it as the tail of the list
         * @param value 
         */
        void push_back(T value);

        /**
         * Remove the tail from the list and return its value
         * @return 
         */
        T pop_back();

        /**
         * Return the value contained by the head
         * @return 
         */
        T front();

        /**
         * Return the value contained by the tail
         * @return 
         */
        T back();

        /**
         * Insert a node containing the value at the specified index.
         * @param index 
         * @param value 
         * @throw out_of_range exception if the index is greater than the size of the list
         */
        void insert(int index, T value);

        /**
         * Removes the node at the specified index
         * @param index 
         * @throw out_of_range exception if the index is greater than the size of the list
         */
        void erase(int index);

        /**
         * Reverse the list
         */
        void reverse();

        /**
         * Remove the first node whose value matches the passed value
         * @param value
         * @return whether a value was removed or not
         */
        bool remove_value(T value);
    private:
        /**
         * Throw an out of range exception if the list is empty
         * @throw out_of_range
         */
        void crash_empty();
        /**
         * Insert a node with the specified value before the specified node.
         * In case the specified node is null, the new node is made as the tail.
         * @param node
         * @param value
         */
        void insert_before(Node<T>* node, T value);
        /**
         * Delete the specified node
         * @param node
         */
        void remove_node(Node<T> *node);
        Node<T>* head;
        Node<T>* tail;
    };


}
#endif //DATASTRUCTURES_DOUBLY_LINKED_LIST_H
