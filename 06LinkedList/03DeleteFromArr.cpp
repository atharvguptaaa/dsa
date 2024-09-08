#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute- O(m*n)
/* ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    for (auto i : nums) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        if (head == nullptr) return head;
        while (temp) {
            if (head->val == i) {
                head = head->next;
            } else if (temp->val == i) {
                prev->next = temp->next;
            } else {
                prev = temp;
            }
            temp = temp->next;
        }
    }
    return head;
} */

// Optimized- using set, O(m+n)
/* ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> st(nums.begin(), nums.end());

    ListNode* dummy=new ListNode();
    dummy->next=head;

        ListNode* temp = head;
        ListNode* prev = dummy;
        if (head == nullptr) return head;
        while (temp) {
            if (st.find(temp->val) !=st.end()) {
                prev->next = temp->next;
            }
             else {
                prev = temp;
            }
            temp = temp->next;

    }
    return dummy->next;
} */

// Same Optimized approach with memory deallocation
ListNode *modifiedList(vector<int> &nums, ListNode *head)
{
    unordered_set<int> st(nums.begin(), nums.end());

    ListNode *dummy = new ListNode();
    dummy->next = head;

    ListNode *current = head;
    ListNode *prev = dummy;
    if (head == nullptr)
        return head;
    while (current)
    {
        if (st.find(current->val) != st.end())
        {
            ListNode *temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    ListNode *newHead = dummy->next;
    delete dummy;
    return newHead;
}

// Function to convert an array (vector) to a linked list
ListNode *arrayToLinkedList(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    ListNode *head = new ListNode(arr[0]); // Create the head node
    ListNode *current = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        current->next = new ListNode(arr[i]); // Create the next node
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a vector of values: 1, 2, 3, 4, 5
    vector<int> arr = {1, 2, 3, 4, 5};

    // Convert the array to a linked list
    ListNode *head = arrayToLinkedList(arr);

    // Print the original list
    cout << "Original List: ";
    printList(head);

    // List of values to remove
    vector<int> nums = {2, 4};

    // Modify the list by removing nodes with values from nums
    head = modifiedList(nums, head);

    // Print the modified list
    cout << "Modified List: ";
    printList(head);

    return 0;
}
