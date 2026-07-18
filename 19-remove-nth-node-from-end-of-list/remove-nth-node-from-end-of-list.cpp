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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return nullptr;
        ListNode* curr=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==nullptr){
            ListNode* temp=head;
            head=head->next;
            delete(temp);
        }else{
            while(fast->next!=nullptr){
                curr=curr->next;
                fast=fast->next;
            }
            ListNode* temp=curr->next;
            curr->next=curr->next->next;
            delete(temp);
        }
        return head;
    }
};