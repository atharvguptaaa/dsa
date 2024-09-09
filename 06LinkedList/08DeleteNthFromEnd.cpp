#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        while (n > 0) {
            fast = fast->next;
            n--;
        }

        // If fast is null, we need to remove the head node
        if (fast == NULL) {
            ListNode* tbd = head;
            head = head->next;
            delete tbd;
            return head;
        }

        // Move both fast and slow pointers until fast reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        ListNode* tbd = slow->next;
        slow->next = slow->next->next;
        delete tbd;

        return head;
    }


void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Manually create the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Assume n (for example, 2)
    int n = 2;

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Remove the nth node from the end

    head = removeNthFromEnd(head, n);

    // Print the updated list
    cout << "Updated list: ";
    printList(head);

    return 0;
}
