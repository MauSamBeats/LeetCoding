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
    ListNode* findTail(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* temp = head;
        while(temp->next){
            temp=temp->next;
        }
        return temp;
    }
    int sz(ListNode* head){
        int ans=0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            ans++;
        }
        return ans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len = sz(head); k%=len;
        ListNode* temp = head;
        ListNode* bar = head;
        for(int i=0; i<k; i++) bar=bar->next;
        while(bar->next){
            temp=temp->next;
            bar=bar->next;
        }
        bar->next=head;
        head=temp->next;
        temp->next=nullptr; 
        return head;
    }
};