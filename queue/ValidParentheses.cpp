#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
    public:
        static bool isValid(string s) {
            std::stack<char> stacks ;
            //cout << "stacks" << endl;
            for (int i=0;i<s.length();i++){
                stacks.push(s[i]); 
            }
            if (stacks.size()<2){return false;}
            std::stack<char> stacksTmp;
            while (!stacks.empty()){
                char tmp = stacks.top();
                stacks.pop();

                if (tmp == '}' or tmp == ']' or tmp ==')'){
                    stacksTmp.push(tmp);
                }
                else{
                    if (stacksTmp.size()==0) return false;                    
                    if (!identify(tmp,stacksTmp.top())){
                        cout << "!identify(tmp,stacksTmp.top() or stacksTmp.size()==0)" <<endl;
                        cout << tmp << stacksTmp.top() << endl;
                        cout << stacksTmp.size()<< endl;
                        return false;
                    }
                    stacksTmp.pop();
                }
            }
            if (!stacksTmp.empty()) return false;
            return true; 
        }

        static bool identify(char a ,char b ){
            if ( (a=='{' && b=='}') or (a=='(' && b == ')') or ( a=='[' && b==']' ) ){
                return true;
            }
            return false;
        }    
           
};
 
int main(){
    bool a =Solution::isValid("((");
    cout << "begins" << endl;
    cout << a << endl;

};
