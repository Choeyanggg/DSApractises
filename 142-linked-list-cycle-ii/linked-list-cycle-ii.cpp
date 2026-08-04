/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* curr=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            curr=curr->next;
            fast=fast->next->next;
            if(curr==fast){
                ListNode* temp=head;
                ListNode* slow=curr;
                while(temp!=slow){
                    temp=temp->next;
                    slow=slow->next;
                }
                return temp;
            }
        }
        return nullptr;
    }
};