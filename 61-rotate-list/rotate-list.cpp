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

    ListNode* findLength(ListNode* temp, int k){
        int cnt = 1;
        while(temp != NULL){
            if(cnt == k) return temp;
            temp = temp->next;
            cnt++;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail -> next != NULL){
            tail = tail->next;
            len++;
        }
        if(k % len == 0) return head;
        k = k % len;
        tail->next = head;
        ListNode* newLastNode = findLength(head, len-k);
        head = newLastNode->next;
        newLastNode->next = NULL;
        return head;
    }
};