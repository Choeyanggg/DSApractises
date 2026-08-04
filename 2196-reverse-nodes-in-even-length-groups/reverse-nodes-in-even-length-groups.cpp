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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        ListNode* curr=head;
        int group=1;
        while(curr!=nullptr){
            ListNode* temp=curr;
            int size=group;
            int count=0;
            while(temp && count<size){
                temp=temp->next;
                count++;
            }
            if(count%2==0){
                ListNode* afterreverse=curr;
                ListNode* prev=nullptr;
                while(count--){
                    ListNode* temp=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=temp;
                }
                tail->next=prev;
                afterreverse->next=curr;
                tail=afterreverse;
            }else{
                while(count--){
                    tail->next=curr;
                    tail=curr;
                    curr=curr->next;
                }
            }
            group++;
        }
        return dummy->next;
    }
};
