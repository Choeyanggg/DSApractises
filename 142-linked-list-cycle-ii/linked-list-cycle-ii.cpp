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
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode* curr=head;
                ListNode* meet=slow;
                while(curr!=meet){
                    curr=curr->next;
                    meet=meet->next;
                }return curr;
            }
        }
        return nullptr;
    }
};