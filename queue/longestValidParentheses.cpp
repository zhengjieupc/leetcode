#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
    public:
        /* 
         * 题目：输出只包含（）的自字符串的最大可靠子串
         * 解法：建立左括号的索引栈
         * 一开始遇见的坑：单纯的建立左括号的存储栈，没有利用有用的信息；利用计数和归零的方式记录长度，会在某些情况失效，例如存储栈!empty,(()()(()
         * */
        static int longestValidParentheses(string s) {                   
            int last = -1 ;
            std::stack<int> stacksTmp;
            int max =0;          
            for (int i=0;i<s.size();i++){
                char tmp = s[i];
                // cout << "s" <<i << tmp << endl;
                if (tmp== '('){
                    stacksTmp.push(i);
                    // cout << "stacksTmp.push(tmp) " << tmp << endl;
                    continue;
                }
                else {
                    // 记录上一次匹配结束的值
                    if (stacksTmp.empty()){last = i;}
                    else {
                        // 能匹配上，则弹出对应的字符索引
                        stacksTmp.pop();
                        if (stacksTmp.empty()){
                            max = std::max(max,i-last);
                        }
                        else{
                            max = std::max(max,i-stacksTmp.top());
                        }
                    }
                }
            }
                // cout << "RESULT max:" << max << endl;
            return max;
        }
};

int main(){
    Solution::longestValidParentheses("(()(((()");
    cout << "begins" << endl;
}
