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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)
            return 0;

        ListNode *ansHead = new ListNode;
        ListNode *now = ansHead;
        while(true){
            if(list1 && (!list2 || list1->val < list2->val)){
                now->val = list1->val;
                list1 = list1->next;
            }else if(list2){
                now->val = list2->val;
                list2 = list2->next;
            }else
                break;
            if(!list1 && !list2) break;
            now->next = new ListNode;
            now = now->next;
        }
        return ansHead;
    }
};
