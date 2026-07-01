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
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        bool carry=false;
        while(l1 && l2){
            temp->next = new ListNode(0);
            temp=temp->next;
            int sum=l1->val+l2->val+(carry?1:0); carry=false;
            if(sum>9){
                carry=true;
                temp->val=sum%10;
            }
            else temp->val=sum;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            temp->next = new ListNode(0);
            temp=temp->next;
            int sum=l1->val+(carry?1:0); carry=false;
            if(sum>9){
                carry=true;
                temp->val=sum%10;
            }
            else temp->val=sum;
            l1=l1->next;
        }
        while(l2){
            temp->next = new ListNode(0);
            temp=temp->next;
            int sum=l2->val+(carry?1:0); carry=false;
            if(sum>9){
                carry=true;
                temp->val=sum%10;
            }
            else temp->val=sum;
            l2=l2->next;
        }
        if(carry) temp->next=new ListNode(1);
        return head->next;
    }
};