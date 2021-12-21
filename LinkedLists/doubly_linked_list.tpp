//
// Created by gautier on 07/12/2021.
//


#ifndef DATASTRUCTURES_DOUBLY_LINKED_LIST_IMPL_H
#define DATASTRUCTURES_DOUBLY_LINKED_LIST_IMPL_H

    template<typename T>
    int DoublyLinkedList<T>::size() {
        //Initialize size
        int s = 0;
        //Loop over all elements in the list and increment size for each element
        auto *cn = head;
        while (cn != nullptr) {
            cn = cn->n;
            s++;
        }
        return s;
    }

    template<typename T>
    void DoublyLinkedList<T>::push_front(T value) {
        //Create a new node
        auto *newNode = new Node<T>(value, nullptr, nullptr);
        // If the list is empty, set the new node as head and tail
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
            //Otherwise, point the new node to the head and the head the new node
        else {
            newNode->n = head;
            head->p = newNode;
            head = newNode;
        }
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, DoublyLinkedList <T> l) {
        //If list is empty, print empty list
        if (l.empty()) {
            os << "List is empty" << std::endl;
        }
            // Otherwise, print every value
        else {
            os << "head : " << l.head << " head.p : " << l.head->p << " head.n : " << l.head->n << " head.v "
               << l.head->v << std::endl;
            os << "tail : " << l.tail << " tail.p : " << l.tail->p << " tail.n : " << l.tail->n << " tail.v "
               << l.tail->v << std::endl;
            auto *n = l.head;
            while (true) {
                os << n->v << " ";
                if (n->n == nullptr) break;
                n = n->n;
            }
            os << std::endl;
        }
        return os;
    }

    template<typename T>
    bool DoublyLinkedList<T>::empty() {
        return this->head == nullptr;
    }

    template<typename T>
    T DoublyLinkedList<T>::value_at(int index) {
        // Check the list is not empty and throw out of bound otherwise
        this->crash_empty();
        // Go through the linked list.
        auto *n = head;
        while (true) {
            // When we reach the demanded index, return the value
            if (index == 0) {
                return n->v;
            }
            // If we have reached the end of the list, throw an out of range exception
            if (n->n == nullptr) {
                throw std::out_of_range("");
            }
            n = n->n;
            index--;
        }
    }

    template<typename T>
    T DoublyLinkedList<T>::pop_front() {
        T ret = head->v;
        // Throw out of range if empty
        this->crash_empty();
        // If the list was only one element, set both head and tail to nullptr
        if (this->head->n == nullptr) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
        }
            // Else, set the next node as the new head and delete the current head
        else {
            head = head->n;
            delete head->p;
            head->p = nullptr;
        }
        //Return the value
        return ret;
    }

    template<typename T>
    void DoublyLinkedList<T>::crash_empty() {
        if (this->empty()) {
            throw std::out_of_range("Trying to read from an empty list");
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::push_back(T value) {
        // If empty, set both head and tail to a new node with no neighbours.
        if (this->empty()) {
            this->head = new Node<T>(value, nullptr, nullptr);
            this->tail = head;
        }
            // Otherwise, set the new tail and link it to the current tail
        else {
            auto *new_tail = new Node<T>(value, nullptr, this->tail);
            this->tail->n = new_tail;
            this->tail = new_tail;
        }
    }

    template<typename T>
    T DoublyLinkedList<T>::pop_back() {
        // Throw out_of_range if empty
        this->crash_empty();
        // Prepare the returned value
        T ret = this->tail->v;
        // Case only one element
        if (this->head->n == nullptr) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
        }
        // Otherwise, set the new tail and delete the old tail
        this->tail = this->tail->p;
        delete this->tail->n;
        this->tail->n = nullptr;
        return ret;
    }

    template<typename T>
    T DoublyLinkedList<T>::front() {
        // Throw out of range if empty
        this->crash_empty();
        // Return the front value
        return this->head->v;
    }

    template<typename T>
    T DoublyLinkedList<T>::back() {
        // Throw out of range if empty
        this->crash_empty();
        return this->tail->v;
    }

    template<typename T>
    void DoublyLinkedList<T>::insert_before(Node <T> *node, T value) {
        // If node is the nullptr, then the behavior is to define the new_node as the tail
        if (node == nullptr) {
            auto *new_node = new Node<T>(value, nullptr, tail);
            if (tail != nullptr) {
                tail->n = new_node;
            } else {
                head = new_node;
            }
            tail = new_node;
        } else {
            auto *new_node = new Node<T>(value, node, node->p);
            node->p = new_node;
            // Set the new node as the head if we insert before the head
            if (new_node->p == nullptr) head = new_node;
            else new_node->p->n = new_node;
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::insert(int index, T value) {
        /*
         * Iterate through the list. Throw out of range if we get to the end before reaching the desired index.
         * When we get to the desired index, insert a new node with value value
         */
        auto *cn = head;
        while (true) {
            /* When we reach 0 index, insert the node before the current node (current node can be null in which case
             * the new node is set as the tail
             */
            if (index == 0) {
                this->insert_before(cn, value);
                return;
            }
            cn = cn->n;
            index--;
            if (cn == nullptr && index > 0) {
                throw std::out_of_range("");
            }
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::remove_node(Node <T> *node) {
        // If cn is the current head, set the new head
        if (node->p == nullptr) {
            this->head = node->n;
        }
            // Otherwise, set the previous node's successor as the node's successor
        else {
            node->p->n = node->n;
        }
        // If the node is the current tail, set the new tail
        if (node->n == nullptr) {
            this->tail = node->p;
        }
            // Otherwise, set the next node's predecessor as cn's predecessor
        else {
            node->n->p = node->p;
        }
        delete node;
    }

    template<typename T>
    void DoublyLinkedList<T>::erase(int index) {
        // Current node in iteration
        auto *cn = this->head;
        while (cn != nullptr) {
            if (index == 0) {
                remove_node(cn);
                return;
            }
            // Decrease index and go to the next node
            cn = cn->n;
            index--;
        }
        throw std::out_of_range("");
    }

    template<typename T>
    void DoublyLinkedList<T>::reverse() {
        // Head becomes tail, tail becomes head
        // Every node gets its previous and next pointers swapped
        auto *cn = head;
        this->head = this->tail;
        this->tail = cn;
        //Iterate through the list, swapping node pointers each time
        while (cn != nullptr) {
            auto *next = cn->n;
            cn->n = cn->p;
            cn->p = next;
            // Go to next node
            cn = next;
        }
    }

    template<typename T>
    bool DoublyLinkedList<T>::remove_value(T value) {
        auto *cn = head;
        while (cn != nullptr) {
            if (cn->v == value) {
                remove_node(cn);
                return true;
            }
            cn = cn->n;
        }
        return false;
    }

#endif //DATASTRUCTURES_DOUBLY_LINKED_LIST_IMPL_H
