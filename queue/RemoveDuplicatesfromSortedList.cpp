/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 *Given a sorted linked list, delete all duplicates such that each element appear only once.

 *For example,
 *Given 1->1->2, return 1->2.
 *Given 1->1->2->3->3, return 1->2->3.
 * */
#include <cstddef>
#include <string>
using namespace std;

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
            if (head==NULL)return head;
            ListNode* p = head->next,*pl = head;
            while (p!=NULL){
                if (p->val==pl->val){
                    pl->next = p->next;
                }
                else{
                    pl = p;
                }
                p = p->next;
            }
            return head;    
        }

};

int main(){
    
}

