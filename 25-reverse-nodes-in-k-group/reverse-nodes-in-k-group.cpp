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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        ListNode* curr=head;
        while(curr){
            int count=0;
            ListNode* temp=curr;
            while(temp && count<k){
                temp=temp->next;
                count++;
            }
            if(count==k){
                ListNode* prev=0;
                ListNode* afterreverse=curr;
                while(curr!=nullptr && count>0){
                    ListNode* t=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=t;
                    count--;
                }
                tail->next=prev;
                afterreverse->next=curr;
                tail=afterreverse;
            }else{
                while(curr){
                    tail->next=curr;
                    tail=tail->next;
                    curr=curr->next;
                }
            }
        }
        return dummy->next;
    }
};