#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//Iterative Soln :
/* ListNode* reverseList(ListNode* head) {
        
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    } */

//Recursive Soln :
ListNode* reverseList(ListNode* head) {
    // Base case
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursive call 
    ListNode* newHead = reverseList(head->next);

    // Reverse the current node's next pointer.
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;  

    return newHead;  // Return the new head of the reversed list.
}


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Reverse the list.
    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    // Free memory.
    freeList(head);

    return 0;
}
