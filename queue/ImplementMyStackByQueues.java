
/**
 * Created by zhengjie on 17/2/27.
 * 114ms
 * Implement Stack using Queues
 * 两个队列 组成一个栈
 */

import java.util.Queue;

import java.util.LinkedList;

public class ImplementMyStackByQueues<T> {

        Queue<T> queue;
        // tmpQueue is always empty
        Queue<T> tmpQueue;

        /** Initialize your data structure here. */
        public ImplementMyStackByQueues() {
            queue = new LinkedList();
            tmpQueue = new LinkedList();;
        }

        /** Push element x onto stack. */
        public void push(T x) {
            tmpQueue.add(x);
            while (queue.isEmpty()){
                tmpQueue.add(queue.remove());
            }
            queue = tmpQueue;
            tmpQueue = new LinkedList();
        }

        /** Removes the element on top of the stack and returns that element. */
        public T pop() {
            return queue.remove();
        }

        /** Get the top element. */
        public T top() {
            return queue.peek();
        }

        /** Returns whether the stack is empty. */
        public boolean empty() {
            return queue.isEmpty();
        }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */


