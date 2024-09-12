#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to delete the middle node of a singly linked list.
ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prevS = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prevS = slow;
        slow = slow->next;
    }

    prevS->next = slow->next;
    delete slow;

    return head;
}

// Helper function to print the linked list.
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Manually create the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Delete the middle node
    head = deleteMiddle(head);

    cout << "List after deleting the middle node: ";
    printList(head);

    return 0;
}
