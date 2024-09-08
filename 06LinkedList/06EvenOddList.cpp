#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

    //Brute force - O(n/2)+O(n/2)+O(n)
     /*   Node* oddEvenList(Node* head) {
        vector<int> arr;

     Node* temp=head;
        //stores odd indexes in array
        while(temp&& temp->next){
            arr.push_back(temp->val);
            temp=temp->next->next; 
        }
        //since loop wont run for last temp as temp->next is null
        if(temp) arr.push_back(temp->val);
       
        temp=head->next;
        //stores even indexes in array
        while(temp&& temp->next){
            arr.push_back(temp->val);
            temp=temp->next->next; 
        }
        //since loop wont run for last temp as temp->next is null
        if(temp) arr.push_back(temp->val); 

        temp=head;
        int i=0;
        while(temp){
            temp->val=arr[i];
            temp=temp->next;
            i++;
        }
        return head;
    } */
    
    //optimized - O(n/2)*2 = O(n)
    Node* oddEvenList(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;

        Node* odd = head;
        Node* evenHead = head->next;
        Node* even = evenHead;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }


// Helper function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    // Manually creating the linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* n5 = new Node(5);
    Node* n4 = new Node(4, n5);
    Node* n3 = new Node(3, n4);
    Node* n2 = new Node(2, n3);
    Node* head = new Node(1, n2);

    std::cout << "Original list: ";
    printList(head);

    // Apply the oddEvenList function

    Node* result = oddEvenList1(head);

    std::cout << "Modified list (Odd-Even): ";
    printList(result);

    return 0;
}
