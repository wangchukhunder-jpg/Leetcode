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
ListNode* reverseList(ListNode* head){
        ListNode*prev=NULL;
        ListNode*curr=head;

        while(curr){
            ListNode*next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }
ListNode*getknode(ListNode*temp,int k){
    k--;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
            ListNode*kthNode=getknode(temp,k);
            if(kthNode==NULL){
                if(prev)prev->next=temp;
                break;
            }
            ListNode*nextNode=kthNode->next;
            kthNode->next=NULL;
            reverseList(temp);
            if(temp==head){
                head=kthNode;
            }else{
                prev->next=kthNode;
                
            }prev=temp;
            temp=nextNode;
        }return head;

    }
};