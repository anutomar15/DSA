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
private:  
 ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }  

ListNode* merge(ListNode* left, ListNode* right){
    if(left==NULL){ 
        return right;
    }
    if(right==NULL){ 
        return left;
    }
    ListNode* ans = new ListNode(-1);  // dummy node
    ListNode* temp = ans;
    // merge 2 sorted
    while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next = left;
                temp = left;
                left=left->next;
            
            }
            else{
                temp->next = right;
                temp = right;
                right=right->next;
            
            }
        }
        // append the remaining nodes
    while(left!=NULL){
        temp->next = left;
        temp = left;
        left=left->next;
    }
    while(right!=NULL){
        temp->next = right;
        temp = right;
        right=right->next;
            
    }
    ans=ans->next; //as only temp moves and ans stays at the dummy node so ans = ans->next skips the dummy node
    return ans;
    }


public:
    ListNode* sortList(ListNode* head) {
        // base case
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid=middleNode(head);
        //two halves are created
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next=NULL; 

        // recursive calls to sort both halves
        left = sortList(left);
        right = sortList(right);

        // merge both halves
        ListNode* result = merge(left, right);
        return result;
    }
};