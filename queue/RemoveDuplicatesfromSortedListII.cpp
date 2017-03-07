/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 *
 * */
#include <cstddef>

class Solution {
    public:
        typedef struct ListNode{
            int val;
            ListNode* next;

            ListNode(int x){
                val = x;
                next = NULL;
            }
        }ListNode;


        ListNode* deleteDuplicates(ListNode* head) {
            if (head ==NULL)return head;
            else if (head->next == NULL) return head;
            ListNode* newhead = new ListNode(0);
            newhead->next = head;
            ListNode* p0=newhead,*p1 = head,*p2 = head->next;
            int last = head->val ;
            while (p1!=NULL && p2 !=NULL){
                if (p1->val==p2->val){
                    last = p1->val;
                    while (p1!=NULL &&  p1->val==last){
                        p1 = p1->next;
                    }
                    // p1 !=val
                    p0->next = p1;
                    if (p1==NULL) return newhead->next;  
                    else p2 = p1->next;
                }
                else{
                    p0 = p1;
                    p1 = p2;
                    p2 = p2->next;
                }
            }
            return newhead->next;            
        }

};
int main(){}
