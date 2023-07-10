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
    ListNode* rotateRight(ListNode* head, int k) {
        //edge cases
        if(head==NULL || head->next==NULL || k==0) return head;
        int len=1;
        ListNode* temp=head;
        while(temp->next){
            len++;
            temp=temp->next;     //standing at last node;
        }
        temp->next=head;    // forms a cycle
        k=k%len;
        k=len-k;
        while(k--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};