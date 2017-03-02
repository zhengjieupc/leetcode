#include <stack> 

using namespace std;

class ImplementMyQueueByStacks {

    private:
            std::stack<int> stackTmp ;
            std::stack<int> s ;

    public:
            /** Initialize your data structure here. */
            
            /** Push element x to the back of queue. */
        void push(int x) {
            s.push(x);
        }
            
            /** Removes the element from in front of queue and returns that element. */
        int pop() {
            while (!s.empty()){
                stackTmp.push(s.top());
                s.pop();
            }
            int tmp = stackTmp.top();
            stackTmp.pop();
            while (!stackTmp.empty()){
                s.push(stackTmp.top());
                stackTmp.pop();
            }
            return tmp;
        }
            
            /** Get the front element. */
        int peek() {
            
            while (!s.empty()){
                stackTmp.push(s.top());
                s.pop();
            }
            int tmp = stackTmp.top();
            while (!stackTmp.empty()){
                s.push(stackTmp.top());
                stackTmp.pop();
            }

            return tmp;
                
        }
            
           /** Returns whether the queue is empty. */
        bool empty() {
            return s.empty();
        }

};


    int main(){
        int tmp = 1;
        
        return tmp;
    }

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/
