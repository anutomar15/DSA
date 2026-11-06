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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // find length of ll
        ListNode* curr = head;
        int len = 0;
        while(curr){
            len++;
            curr = curr ->next;
        }

        int eachBucketNodes = len/k;
        int remainderNodes = len%k;

        vector<ListNode*> result(k, NULL);
            if(head == NULL) {
                return result;
            }
            curr = head;
            ListNode* prev = NULL;
            for(int i=0; i<k; i++){
                result[i] = curr;
                for(int count=1; count<=eachBucketNodes + (remainderNodes>0?1:0); count++){
                    prev = curr;
                    curr = curr->next;
                }
                prev -> next = NULL;
                remainderNodes--;
            }
            return result;
    }
};