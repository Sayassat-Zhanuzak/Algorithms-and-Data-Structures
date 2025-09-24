#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(p == 0) {
        node->next = head;
        return node;
    }
    Node *curr = head;
    for(int i = 0; i < p - 1; i++) {
        curr = curr->next;
    }
    curr->next = curr->next;
    curr->next = node;
    return head;
}
 
Node* remove(Node* head, int p){
    if(head == nullptr) return nullptr;
    if(p == 0){
        Node* tmp = head->next;
        delete head;
        return tmp;
    }
    Node* cur = head;
    for(int i = 0; i < p-1; i++){
        cur = cur->next;
    }
    Node* toDelete = cur->next;
    cur->next = toDelete->next;
    delete toDelete;
    return head;

}
 
Node* replace(Node* head, int p1, int p2){
    if(p1 == p2) return head;

    Node* cur = head;
    Node* toMove;
    if(p1 == 0){
        toMove = head;
        head = head->next;
    } else {
        for(int i = 0; i < p1-1; i++) cur = cur->next;
        toMove = cur->next;
        cur->next = toMove->next;
    }

    if(p2 == 0){
        toMove->next = head;
        head = toMove;
    } else {
        cur = head;
        for(int i = 0; i < p2-1; i++) cur = cur->next;
        toMove->next = cur->next;
        cur->next = toMove;
    }
    return head;

}
 
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur = head;
    while(cur != nullptr){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;

}
 
void print(Node* head){
    if(head == nullptr){
        cout << -1 << endl;
        return;
    }
    Node* cur = head;
    while(cur != nullptr){
        cout << cur->val;
        if(cur->next != nullptr) cout << " ";
        cur = cur->next;
    }
    cout << endl;

}
 
Node* cyclic_left(Node* head, int x){
    if(head == nullptr) return nullptr;

    int len = 0;
    Node* cur = head;
    while(cur){ len++; cur = cur->next; }
    x %= len;
    if(x == 0) return head;

    cur = head;
    for(int i = 0; i < x-1; i++) cur = cur->next;
    Node* newHead = cur->next;
    cur->next = nullptr;

    Node* tail = newHead;
    while(tail->next) tail = tail->next;
    tail->next = head;

    return newHead;

}
 
Node* cyclic_right(Node* head, int x){
    if(head == nullptr) return nullptr;

    int len = 0;
    Node* cur = head;
    while(cur){ len++; cur = cur->next; }
    x %= len;
    if(x == 0) return head;

    return cyclic_left(head, len - x);
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}