//
// Created by gautier on 07/12/2021.
//

#ifndef DATASTRUCTURES_DOUBLY_LINKED_LIST_H
#define DATASTRUCTURES_DOUBLY_LINKED_LIST_H


    // Helper Node class forward declaration
    template<typename T>
    class Node;

    /**
     * The DoublyLinkedList class, with generic type T representing the type of values that the nodes of the list can store.
     * @class DoublyLinkedList
     * @method int getSize()
     * @method bool empty()
     * @method void push_front(T item)
     * @method T pop_front()
     * @method T front()
     * @method void push_back()
     * @method T pop_back()
     * @method T back()
     * @method T value_at(int index)
     * @method void insert(int index, T value)
     * @method void erase(int index)
     * @method void reverse()
     * @tparam T
     */
    template<typename T>
    class DoublyLinkedList {
    public:
        DoublyLinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
        };
        /**
         * Get the getSize of the list
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
        void push_front(T value);

        /**
         *
         */
        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, DoublyLinkedList<U> l);

        /**
         * Return the value at the given index
         * @param index 
         * @return 
         * @throw out_of_range exception if index is greater than the getSize of the list
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
         * @throw out_of_range exception if the index is greater than the getSize of the list
         */
        void insert(int index, T value);

        /**
         * Removes the node at the specified index
         * @param index 
         * @throw out_of_range exception if the index is greater than the getSize of the list
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

    /**
     * The Node class represents a member of a linked list, cointening a key and a next and previous pointers.
     * @class Node
     * @tparam T
     */
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

#include "doubly_linked_list.tpp"
#endif //DATASTRUCTURES_DOUBLY_LINKED_LIST_H
