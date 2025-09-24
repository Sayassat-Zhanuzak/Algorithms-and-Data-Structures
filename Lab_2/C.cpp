#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Linked_list {
    public:
    Node *tail, *head;
    Linked_list() {
        tail = NULL;
        head = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if(tail != NULL) {
            tail->next = node;
            node->prev = tail;
            tail = node;
        } else {
            tail = node;
            head = node;
        }
    }

    void pop_front() {
        if(head != NULL) {
            head = head->next;
            if(head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
        }
    }

    void pop_back() {
        if(tail != NULL) {
            tail = tail->prev;
            if(tail != NULL) {
                tail->next = NULL;
            } else {
                head = NULL;
            }
        }
    }

    void del_node(Node *node) {
        if(node == tail) {
            pop_back();
        }
        else if(node == head) {
            pop_front();
        } else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }

    void print() {
        Node *node = head;
        while(node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }   
};


int main() {
    Linked_list *ll = new Linked_list();
    int num;
    cin >> num;

    for(int i = 0; i < num; i++) {
        int a;
        cin >> a;
        ll->push_back(a);
    }

    Node *curr = ll->head;

    int pos = 1;
    while(curr != NULL) {
        Node *nextnode = curr->next;
        if(pos % 2 == 0) {
            ll->del_node(curr);
        }
        curr = nextnode;
        pos++;
    }

    ll->print();
    return 0;
}