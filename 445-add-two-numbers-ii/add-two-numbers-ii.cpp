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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        l1=reverse(l1);
        l2=reverse(l2);
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry!=0 ){
            int x,y;
            if(l1!=nullptr){
                x=l1->val;
            }
            else{
                x=0;
            }
            if(l2!=nullptr){
                y=l2->val;
            }
            else{
                y=0;
            }
            int sum=x+y+carry;
            carry=sum/10;
            ListNode* newNode=new ListNode(sum%10);
            if(head==nullptr){
                head=tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
            if(l1!=nullptr){
                l1=l1->next;
            }
            if(l2!=nullptr){
                l2=l2->next;
            }
        }
        return reverse(head);
    }
};