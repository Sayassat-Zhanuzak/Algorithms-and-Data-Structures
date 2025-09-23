#include <iostream>
using namespace std;

class Node {
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

    void add_front(string data) {
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

    void add_back(string data) {
        Node *node = new Node(data);
        if(head == NULL) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        sz++;
    }

    void erase_front() {
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

    void erase_back() {
        if(tail != NULL) {
            tail = tail->prev;
            if(tail != NULL) {
                tail->next = NULL; 
            } else {
                head = NULL;
            }
            sz--;
        }
    }

    string front() {
            return head->data;
    }

    string back() {
            return tail->data;
    }

    bool empty() {
        return (sz == 0);
    }

    void clear() {
        Node *curr = head;
        while(curr != nullptr) {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
        tail = head = NULL;
        sz = 0;
    }

    int exit() {
        cout << "goodbye" << endl;
        return 0;
    }
};

int main() {
    Linked_list *ll = new Linked_list();
    string command, book;
    while(command != "exit") {
        cin >> command;
        if(command == "add_front") {
            cin >> book;
            ll->add_front(book);
            cout << "ok" << endl;
        }
        if(command == "add_back") {
            cin >> book;
            ll->add_back(book);
            cout << "ok" << endl;
        }
        if(command == "erase_front") {
            if(!ll->empty()) {
                cout << ll->back() << endl;
                ll->erase_back();
            } else {
                cout << "error" << endl;
            }
        }
        if(command == "erase_back") {
            if(!ll->empty()) {
                cout << ll->back() << endl;
                ll->erase_back();
            } else {
                cout << "error" << endl;
            }
        }
        if(command == "back") {
            if(!ll->empty()) {
                cout << ll->front() << endl;
            } else {
                cout << "error" << endl;
            }
        }
        if(command == "clear") {
            ll->clear();
            cout << "ok" << endl;
        }
        if(command == "exit") {
            ll->exit();
        }
        if(command == "front") {
            if(!ll->empty()) {
                cout << ll->back() << endl;
            } else {
                cout << "error" << endl;
            }
        }
    }
}