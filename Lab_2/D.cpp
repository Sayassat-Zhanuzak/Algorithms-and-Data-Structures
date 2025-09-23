#include <iostream>

using namespace std;

class Node {
    int data;
    Node *prev, *next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class Linked_list {
    Linked_list() {
        Node *tail, *head;
        tail = NULL;
        head = NULL;
    }

    void push_front(int data) {
        
    }
};