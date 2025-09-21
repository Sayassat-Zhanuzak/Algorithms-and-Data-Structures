#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
    string data;
    Node *next, *prev;

    Node(string data) {
        this->data = data;
        this->next = next;
        this->prev = prev;
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

    void push_to_tail(string data) {
        Node *node = new Node(data);
        if(tail == NULL) {
            tail = node;
            head = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        sz++;
    }

    void pop_head() {
        if(head != NULL) {
            head = head->next;
            if(head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
            sz--;
        }
    }

    string show_back() {
            return head->data;
    }

    void circle(int a) {
        for(int i = 0; i < a; i++) {
            Node *a = head;
            head = head->next;
            head->prev = NULL;
            a->prev = tail;
            tail->next = a;
            tail = a;
            tail->next = NULL;
        }
    }

    int empty() {
        return (sz == 0);
    }
};

int main() {
    int a;
    cin >> a;
    Linked_list *ll = new Linked_list();

    int cycle;
    cin >> cycle;

    for(int i = 0; i < a; i++) {
        string word;
        cin >> word;
        ll->push_to_tail(word);
    }

    ll->circle(cycle);

    while(!ll->empty()) {
        cout << ll->show_back() << " ";
        ll->pop_head();
    }
    return 0;
}