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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next!=nullptr){
            ListNode* slow=head;
            ListNode* fast=head;
            ListNode* curr=head;
            while(fast!=nullptr && fast->next!=nullptr){
                curr=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            curr->next=curr->next->next;
            delete(slow);
            return head;
        }else return nullptr;
    }
};