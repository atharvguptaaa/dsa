#include <iostream>
using namespace std; //Leetcode 2.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* it = dummy;

        while (a || b) {
            int sum = carry;
            if (a) sum += a->val;
            if (b) sum += b->val;

            carry = sum / 10;
            sum = sum % 10;
            it->next = new ListNode(sum);
            if (a) a = a->next;
            if (b) b = b->next;
            it = it->next;
        }

        if (carry > 0) {
            it->next = new ListNode(carry);
        }

        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        head = head->next;
        if (head) cout << " -> ";
    }
    cout << endl;
}

int main() {
    // Manually creating linked list l1: 2 -> 4 -> 3 (represents the number 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Manually creating linked list l2: 5 -> 6 -> 4 (represents the number 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Print the input linked lists
    cout << "Input List 1: ";
    printList(l1);
    cout << "Input List 2: ";
    printList(l2);

    // Perform the addition
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    cout << "Result: ";
    printList(result);

    return 0;
}
