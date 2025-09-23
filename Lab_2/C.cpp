#include <iostream>
using namespace std;

class Node {
    public:
    int data; 
    Node *next, *prev;

    Node(int data) {
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
    }

    void push_front(int data) {
        Node *node = new Node(data);
        if(tail == NULL) {
            tail = node;
            head = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        sz++;
    }

    void pop_back() {
        if(tail != NULL) {
            tail = tail->prev;
            if(tail != NULL) {
                tail->next = NULL;
            } else {
                tail = NULL;
            }
        }
        sz--;
    }

    void pop_front() {
        if(head != NULL) {
            head = head->next;
            if(head != NULL) {
                head->prev = NULL;
            } else {
                head = NULL;
            }
        }
    }

    void del_node(Node *node) {
        if(node == tail) {
            pop_back();
        } else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
        sz--;
    }

    Node* addr_head() {
        return head;
    }

    bool empty() {
        return (sz == 0);
    }

    int front() {
        return head->data;
    }
};

int main() {
    int num;
    cin >> num;

    Linked_list *ll = new Linked_list();

    for(int i = 0; i < num; i++) {
        int a;
        cin >> a;
        ll->push_front(a);
    }

    int i = 1;
    Node *current = ll->addr_head();
    while(current != nullptr) {
        Node *nextNode = current->next;

        if(i % 2 == 0) {
            ll->del_node(current);
        }
        current = nextNode;
        i++;
    } 

    while(!ll->empty()) {
        cout << ll->front() << " ";
        ll->pop_front();

    }
}