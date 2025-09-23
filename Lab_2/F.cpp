#include <iostream>

using namespace std;

class Node {
    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Linked_list {
    Linked_list *head, *tail;

    Linked_list() {
        tail = NULL;
        head = NULL;
    }

    void insert(int data, int pos) {
        Node *node = new Node(data);
        
    } 
}