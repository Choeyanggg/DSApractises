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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        int carry=0;
        while(l1!=nullptr && l2!=nullptr){
            int res=carry+l1->val+l2->val;
            int curr=res%10;
            carry=res/10;
            tail->next=new ListNode(curr);
            tail=tail->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr){
            int res=carry+l1->val;
            int curr=res%10;
            carry=res/10;
            tail->next=new ListNode(curr);
            tail=tail->next;
            l1=l1->next;
        }while(l2!=nullptr){
            int res=carry+l2->val;
            int curr=res%10;
            carry=res/10;
            tail->next=new ListNode(curr);
            tail=tail->next;
            l2=l2->next;
        }
        if(carry) tail->next=new ListNode(carry);
        return dummy->next;
    }
};