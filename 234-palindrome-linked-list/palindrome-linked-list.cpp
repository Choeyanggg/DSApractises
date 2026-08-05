/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){ //middle path
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr; //reverse from middle
        while(slow){
            ListNode* temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        ListNode* curr=head; //compare from head
        while(prev!=nullptr){
            if(curr->val!=prev->val) return false;
            curr=curr->next;
            prev=prev->next;
        }return true;
    }
};