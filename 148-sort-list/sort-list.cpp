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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* temp=head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=nullptr;
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        return mergesort(left,right);
    }
    ListNode* mergesort(ListNode* l, ListNode* r){
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(l!=nullptr && r!=nullptr){
            if(l->val>r->val){
                tail->next=r;
                r=r->next;
            }else{
                tail->next=l;
                l=l->next;
            }
            tail=tail->next;
        }while(l!=nullptr){
            tail->next=l;
            l=l->next;
            tail=tail->next;
        }while(r!=nullptr){
            tail->next=r;
            r=r->next;
            tail=tail->next;
        }
        return dummy->next;
    }
};