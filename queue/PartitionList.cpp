#include <string>
#include <cstddef>

using namespace std;


/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 * 把小于3的元素按顺序放前面
 *
 * */
class Solution {
    public:
        typedef struct ListNode {
            int val;
            ListNode * next;

            ListNode(int x){
                val = x;
                next = NULL;
            }
        }ListNode;

        ListNode* partition(ListNode* head, int x) {
            ListNode* new1 = new ListNode(0);
            ListNode * new2 = new ListNode(0);
            new1->next = head;
            new2->next = head;
            ListNode* p1 = new1,*p2 = new2;

            while (p1->next!=NULL){
                if (p1->next->val<x){
                    p2->next = p1->next;
                    p2 = p2->next;
                    p1->next = p1->next->next;
                }
                else {p1 = p1->next;} 
            }            
            p2->next =new1->next;
            return new2->next;
        }

};

int main(){
    int a= 1;
}

