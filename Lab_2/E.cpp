#include <iostream>
using namespace std;

class Node {
    public:
    string data;
    Node *next, *prev;

    Node(string data) { 
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
}; 

class Linked_list {
    public:
    Node *tail, *head;
    int sz;

    Linked_list() {
        tail = NULL;
        head = NULL;
        sz = 0;
    }

    void push_back(string data) {
        Node *node = new Node(data);
        if(tail != NULL) {
            tail->next = node;
            node->prev = tail;
            tail = node;
        } else {
            tail = node;
            head = node;
        }
        sz ++;
    }

    void pop_back() {
        if(tail != NULL) {
            Node *toDelete = tail;
            tail = tail->prev;
            if(tail != NULL) {
                tail->next = NULL;
            } else {
                head = NULL;
            }
            delete toDelete;
            sz--;
        }
    }

    void pop_front() {
        if(head != NULL) {
            Node *toDelete = head;
            head = head->next;
            if(head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
            delete toDelete;
            sz--;
        }
    }

    int size() {
        return sz;
    }
    
    void print() {
        Node *node = tail;
        while(node != NULL) {
            cout << node->data << endl;
            node = node->prev;
        }
    }

    void del_node(Node *node) {
        if(node == tail) {
            pop_back();
            return;
        }
        else if(node == head) {
            pop_front();
            return;
        } else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
            delete node;
            sz--;
            return;
        }
    }
};


int main() {
    int num;
    cin >> num;
    Linked_list *ll = new Linked_list();

    for(int i = 0; i < num; i++) {
        string student;
        cin >> student;
        ll->push_back(student);
    }

    Node *a = ll->head;
    while(a != NULL && a->next != NULL) {
        if(a->data == a->next->data) {
            ll->del_node(a->next);
        } else{
            a = a->next;
        }
    }
    
    cout << "All in all: " << ll->size() << endl;
    cout << "Students:" << endl;
    ll->print();
    return 0;
}