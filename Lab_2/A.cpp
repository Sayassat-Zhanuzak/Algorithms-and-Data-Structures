#include <iostream>
#include <vector>

using namespace std;

int abs(int a) {
    if(a < 0) {
        return (0 - a);
    }
    return a;
}

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
    Node *tail, *front;
    int sz;

    Linked_list() {
        tail = NULL;
        front = NULL;
        sz = 0;
    }
    void push_back(int data) {
        Node *node = new Node(data);
        if(tail == NULL) {
            tail = node;
            front = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        sz ++;
    }

    bool empty() {
        return (sz == 0);
    }

    int show_front() {
        return front->data;
    }
    
    void pop_front() {
        if(front != NULL) {
            front = front->next;
            if(front != NULL) {
                front->prev = NULL;
            } else {
                tail = NULL;
            }
            sz--;
        }
    }
};


int main() {
    int num;
    cin >> num;

    vector<int> len;

    Linked_list *ll = new Linked_list();

    for(int i = 0; i < num; i++) {
        int data;
        cin >> data;

        ll->push_back(data);
    }

    int a; cin >> a;

    for(int i = 0; i < num; i++) {
        int diff;
        diff = abs(ll->show_front() - a);

        ll->pop_front();
        len.push_back(diff);
    }

    int min_index;

    int min = len[0];
    for(int i = 0; i < len.size(); i++) {
        if(min > len[i]) {
            min = len[i];
        }
    }

    for(int i = 0; i < len.size(); i++) {
        if(min == len[i]) {
            cout << i << endl;
            return 0;
        }
    }
}