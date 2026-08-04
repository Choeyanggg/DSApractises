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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* tail=dummy;
        ListNode* curr=head;
        int index=1;
        while(curr!=nullptr){
            if(index==left){
                break;
            }
            tail=curr;
            curr=curr->next;
            index++;
        }
        int count=right-left+1;
        ListNode* prev=nullptr;
        ListNode* afterreverse=curr;
        while(count-- && curr!=nullptr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        tail->next=prev;
        afterreverse->next=curr;
        return dummy->next;
    }
};