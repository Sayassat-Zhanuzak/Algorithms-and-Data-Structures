#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    char data;
    Node* next;
    Node* prev;
    Node(char data) {
        this->data = data; 
        next = NULL;
        prev = NULL;
    }
};

class Linked_list {
    public:
    Node *tail, *head;

    Linked_list() {
        tail = NULL;
        head = NULL;
    }

    void push_back(Node* node) {
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void remove(Node* node) {
        if(node == NULL) {
            return;
        }
        if(node->prev != NULL) {
            node->prev->next = node->next;
        }
        else {
            head = node->next;
        }

        if(node->next != NULL) {
            node->next->prev = node->prev;
        }
        else {
            tail = node->prev;
        }
    }

    char front() {
        return head->data;
    }

    bool empty() {
        return head == NULL;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> freq(26, 0);
        vector<Node*> ref(26, NULL);
        Linked_list *ll = new Linked_list();

        for(int i = 0; i < N; i++) {
            char ch;
            cin >> ch;
            freq[ch - 'a']++;

            if (freq[ch - 'a'] == 1) {
                Node* node = new Node(ch);
                ref[ch - 'a'] = node;
                ll->push_back(node);
            } else if(freq[ch - 'a'] == 2) {
                ll->remove(ref[ch - 'a']);
                ref[ch - 'a'] = NULL;
            }

            if (!ll->empty()) {
                cout << ll->front() << " ";
            }
            else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
