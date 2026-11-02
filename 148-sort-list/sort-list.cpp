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
        vector <int> values;
        ListNode* temp= head;

        while (temp!= NULL){
            values.push_back(temp->val);
            temp= temp->next;
        }
        sort(begin(values), end(values));
        ListNode* temp2= head;
        for (int i =0;i<values.size();i++){
            temp2->val= values[i];
            temp2= temp2->next;
        }

        return head;

        
    }
};