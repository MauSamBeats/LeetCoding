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

ListNode* mid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* slower = nullptr;
    while(fast && fast->next){
        slower=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return slower;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head && head->next){
            ListNode* middle = mid(head);
            ListNode* r = middle->next;
            middle->next=nullptr;
            ListNode* l = head;
            ListNode* left = sortList(l);
            ListNode* right = sortList(r);
            
            ListNode dummy(0);
            ListNode* temp = &dummy;

            while(left && right){
                if(left->val<right->val){
                    temp->next=left;
                    left=left->next;
                }
                else{
                    temp->next=right;
                    right=right->next;
                }
                temp=temp->next;
            }
            if(left){
                temp->next=left;
            }
            if(right){
                temp->next=right;
            }
            return dummy.next;
        }
        return head;
    }
};