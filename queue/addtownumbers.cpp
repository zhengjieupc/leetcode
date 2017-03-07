#include <cstddef>
using namespace std;

/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        typedef struct ListNode{
            int val;
            ListNode *next;

            ListNode(int x){
                val = x;
                next = NULL;
            }
        }ListNode;

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* result = new ListNode(0);
            ListNode* p1=l1,*p2=l2,*p3=result;
            int N = 0;
        
            while (p1!=NULL|p2!=NULL ){
                if (p1!=NULL){
                    N +=p1->val;
                    p1 = p1->next;
                }
                if (p2!=NULL){
                    N +=p2->val;
                    p2 = p2->next;
                }
                p3->next = new ListNode((N)%10);
                N = (N)/10;
                p3 = p3->next;
            }
            if(N==1){p3->next = new ListNode(1);}
            return result->next;
        }

};

int main (){
    int a = 1;
}

