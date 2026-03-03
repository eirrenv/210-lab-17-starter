#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);

void insertAtHead(Node *headNode); // insert Node at head prototype

void insertAtTail(Node *headNode); // insert Node at tail prototype

void deleteNode(Node *headNode); // delete node prototype

void insertNode(Node *headNode); // insert node prototype

void deleteList(Node *headNode); // delete list prototype


int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    deleteNode(head);

    // insert a node
    insertNode(head);

    // deleting the linked list
    deleteList(head);
    /*
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
    */

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// insert node at head of linked list
void insertAtHead(Node *headNode) {
    Node *newNode = new Node;
    newNode->next = headNode;
    headNode = newNode;
}

// insert node at tail of linked list
void insertAtTail(Node *headNode) {
    Node *newNode = new Node;
    Node *current = headNode;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// delete node function
void deleteNode(Node *headNode) {
    Node * current = headNode;
    cout << "Which node to delete? " << endl;
    output(headNode);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = headNode;
    Node *prev = headNode;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(headNode);
}

// insert node function
void insertNode(Node *headNode) {
    Node * current = headNode;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    int entry;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = headNode;
    Node * prev = headNode;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(headNode);
}

// delete the linked list
void deleteList(Node *headNode) {
    Node * current = headNode;
        while (current) {
            headNode = current->next;
            delete current;
            current = headNode;
        }
        headNode = nullptr;
        output(headNode);
}