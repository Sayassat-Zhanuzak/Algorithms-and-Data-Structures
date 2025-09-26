#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    int count;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        count = 1;
        next = NULL;
        prev = NULL;
    }
};

class Linked_list {
    public:
    Node* head;
    Node* tail;

    Linked_list() {
        head = NULL;
        tail = NULL;
    }

    void insert_or_update(int x) {
        Node* cur = head;
        Node* prev = NULL;
        while(cur != NULL) {
            if (cur->data == x) {
                cur->count++;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        Node* node = new Node(x);
        if(head == NULL) {
            head = node;
            tail = node;
        } else {
            prev->next = node;
            node->prev = prev;
            tail = node;
        }
    }
};

int main() {
    int n;
    cin >> n;

    Linked_list *ll = new Linked_list();
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ll->insert_or_update(x);
    }

    int max_freq = 0;
    for(Node* cur = ll->head; cur != NULL; cur = cur->next) {
        if (cur->count > max_freq) {
            max_freq = cur->count;
        }
    }

    vector<int> modes;
    for (Node* cur = ll->head; cur != NULL; cur = cur->next) {
        if (cur->count == max_freq) {
            modes.push_back(cur->data);
        }
    }

    sort(modes.begin(), modes.end(), greater<int>());

    for (int i = 0; i < modes.size(); i++) {
        cout << modes[i] << " ";
    }
    return 0;
}
