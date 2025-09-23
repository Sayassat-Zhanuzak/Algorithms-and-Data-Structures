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
    int size;

    Linked_list() {
        tail = NULL;
        head = NULL;
        size = 0;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if(tail == NULL) {
            tail = head = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }

    void pop_front() {
        if(head != NULL) {
            head = head->next;
            if(head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
            size--;
        }
    }

    int front() {
        return head->data;
    }

    bool empty() {
        return (size == 0);
    }

    void insert(int pos_insert, int data) {
        Node *curr = head;
        int pos = 0;

        while( curr != nullptr && pos < pos_insert) {
            curr = curr->next;
            pos++;
        }

        Node *newNode = new Node(data);

        if(curr == nullptr) {
            if(tail == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        } else {
            newNode->next = curr;
            newNode->prev = curr->prev;

            if(curr->prev != nullptr)
                curr->prev->next = newNode;
            else 
                head = newNode;
            curr->prev = newNode;
        }
        size++;
    }
};

int main() {
    int number;
    int pos = 0;
    int pos_insert;
    cin >> number;
    Linked_list *ll = new Linked_list();

    for(int i = 0; i < number; i++) {
        int data; 
        cin >> data;
        ll->push_back(data);
    }

    int data;
    cin >> data >> pos_insert;

    Node *curr = ll->head;
    while(curr != nullptr) {
        if(pos == pos_insert) {
            ll->insert(pos_insert, data);
            break;
        }
        curr = curr->next;
        pos++;
    }

    while(!ll->empty()) {
        cout << ll->front() << " ";
        ll->pop_front();
    }
}