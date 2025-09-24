#include <iostream>
#include <map>
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
    int size;
    Node *tail, *head;

    Linked_list() {
        tail = NULL;
        head = NULL;
        size = 0;
    }

    void push_front(int data) {
        Node *node = new Node(data);
        if(tail != NULL) {
            tail->next = node;
            node->prev = tail;
            tail = node;
        } else {
            tail = node;
            head = node;
        }
        size++;
    }


    void pop_front() {
        if(tail != NULL) {
            tail = tail->prev;
            if(tail != NULL) {
                tail->next = NULL;
            } else {
                tail = NULL;
            }
        }
        size--;
    }

    bool empty() {
        return (size == 0);
    }

    int front() {
        return tail->data;
    }
};

int main() {
    int num;
    cin >> num;
    map<int, int> mp;
    Linked_list *ll = new Linked_list();

    for(int i = 0; i < num; i++) {
        int value;
        cin >> value;
        mp[value]++;
    }

    map<int, int>::iterator it = mp.begin();
    int max = it->second; 
    for(it = mp.begin(); it != mp.end(); it++) {
        if(max < it->second) {
            max = it->second;
        }
    }

    for(map<int, int>::iterator jt = mp.begin(); jt != mp.end(); jt++) {
        if(jt->second == max) {
            ll->push_front(jt->first);
        }
    }

    while(!ll->empty()) {
        cout << ll->front() << " ";
        ll->pop_front(); 
    }
}