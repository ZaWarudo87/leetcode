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
    ListNode* sortList(ListNode* head) {
        ListNode *now = head;
        vector<int> arr;
        arr.reserve(50000);
        while(now){
            arr.emplace_back(now->val);
            now = now->next;
        }
        sort(arr.begin(), arr.end());
        now = head;
        for(auto &i : arr){
            now->val = i;
            now = now->next;
        }
        return head;
    }
};
