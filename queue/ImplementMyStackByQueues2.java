package mytest;

/**
 * Created by zhengjie on 17/3/1.
 */

import java.util.Queue;
import java.util.LinkedList;

public class MyStack2 {

    private Queue<Integer> q1 = new LinkedList<Integer>();
    private Queue<Integer> q2 = new LinkedList<Integer>();

        // Push element x onto stack.
    public void push(int x) {
            q1.offer(x);
        }

        // Removes the element on top of the stack.
        public int pop() {
            while (q1.size() > 1) {
                q2.offer(q1.poll());
            }
            int top = q1.peek();
            q1.poll();

            Queue tmp = q1;
            q1 = q2;
            q2 = tmp;
            return top;
        }

        // Get the top element.
        public int top() {
            while (q1.size() > 1) {
                q2.offer(q1.poll());
            }
            int top = q1.peek();
            q2.offer(q1.poll());

            Queue tmp = q1;
            q1 = q2;
            q2 = tmp;

            return top;
        }

        // Return whether the stack is empty.
        public boolean empty() {
            return q1.isEmpty();
        }
    }



