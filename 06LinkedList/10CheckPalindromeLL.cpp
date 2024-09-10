#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //recurse reverse funcn
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) return true;
        ListNode* slow = head;                  //tortoiseHare method
        ListNode* fast = head;
        while (fast->next && fast->next->next) {    //finding middle element
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next); //reversing second half
        ListNode* it1 = head;
        ListNode* it2 = newHead;
        while (it2 != nullptr) {              //running iterators on both halves to compare
            if (it1->val != it2->val) {
                return false;
            }
            it1 = it1->next;
            it2 = it2->next;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Manually creating a linked list: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    // Print the result of the palindrome check
    if (sol.isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    return 0;
}
