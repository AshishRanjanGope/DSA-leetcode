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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total_node=0;
        ListNode* temp= head;
        while (temp!= NULL){
            temp= temp->next;
            total_node++;
        }


        if (total_node==1) return NULL;
        
        int nFront = total_node-n+1;

        if (nFront ==1) return head->next;
        ListNode* temp2= head;




        for (int i =0;i<nFront-2; i++){
           
            temp2= temp2->next;

            

        }
        if (temp2->next!= NULL){

        temp2->next= temp2 ->next ->next;
        }
        else{
            temp2->next = NULL;
        }

        return head;
        
    }
};