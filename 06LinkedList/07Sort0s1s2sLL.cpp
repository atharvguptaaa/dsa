#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// Function to free the memory allocated for the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to sort a linked list of 0s, 1s, and 2s.

//brute - taking three counters in one iteration and saving them in LL in another.O(2)

//Optimized - single iteration O(n)
Node* segregate(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* dummyZero = new Node(-1);
    Node* dummyOne = new Node(-1);
    Node* dummyTwo = new Node(-1);

    Node* zero = dummyZero;
    Node* one = dummyOne;
    Node* two = dummyTwo;

    Node* temp = head;

    // Traverse the list and distribute nodes into three separate lists
    while (temp) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        }
        else {  // data == 2
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    // Connect the lists
    zero->next = (dummyOne->next) ? dummyOne->next : dummyTwo->next;
    one->next = dummyTwo->next;
    two->next = nullptr;

    // Free dummy nodes
    delete dummyOne;
    delete dummyTwo;

    return dummyZero->next;
}


// Main function to test the above code
int main() {
    // Creating the linked list manually
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    Node *head = nullptr, *tail = nullptr;
    cout << "Enter the elements (0, 1, or 2): ";
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (head == nullptr) {
            head = new Node(x);
            tail = head;
        } else {
            tail->next = new Node(x);
            tail = tail->next;
        }
    }

    // Print the original list
    cout << "Original list: ";
    printList(head);


    Node* newHead = segregate(head);

    // Print the sorted list
    cout << "Sorted list: ";
    printList(newHead);

    // Free memory
    freeList(newHead);

    return 0;
}
