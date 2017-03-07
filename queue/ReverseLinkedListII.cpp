#include <iostream>
#include <cstddef>
#include <stack>
using namespace std;

/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 **/
class Solution {
    public:
        typedef struct ListNode{
            int val;
            ListNode *next;
            
            ListNode(int x)
            {
                val = x;
                next = NULL;
            }

        }ListNode;


        // [3,5] 1, 2
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            if(m==n)return head;
            int min = std::min(m,n);
            int max = std::max(m,n);
            int i = 0;
            ListNode* newhead = new ListNode(0);
            newhead->next = head; 
            ListNode* p = newhead,*p1 = newhead,*pmin,*pmax;

            while (i<min){    
                i++;
                p1 = p;
                p = p->next;
            }
            pmin = p;
            // i =1 p1 =newhead pmin =head
            // if min=1 ,p1 = newhead,pmin = head i=min
            // if min > 1 ,p1 =before min,pmin =min  i=min


            while (i<max){
                i++;
                p = p->next; // after min
                pmin->next = p->next;
                p->next = p1->next;
                p1->next = p;
            }
            // i=2 p -> 5  
            //  3 -> null 
            //  5 -> 3
            //  newhead -> 5
            //  head ->3 

            return newhead->next;
        }

};

int main(){
    int a = 1;

}
