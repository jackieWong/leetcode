#include <stack>

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
         stack<string> ss;
        vector<string>::iterator iter = tokens.begin();
        
        while(iter != tokens.end()) {
                if(*iter == "+" || *iter == "-" || *iter == "*" || *iter == "/") {
                    if(ss.size() < 2){
                        throw runtime_error("invalid notation");
                    }
                    
                    int i1 = stoi(ss.top());
                    ss.pop();
                    int i2 = stoi(ss.top());
                    ss.pop();
                    
                    if(*iter == "+"){
                        ss.push(to_string(i1 + i2));
                    }
                    if(*iter == "-"){
                        ss.push(to_string(i2 - i1));
                    }
                    if(*iter == "*"){
                        ss.push(to_string(i1 * i2));
                    }
                    if(*iter == "/"){
                        ss.push(to_string(i2 / i1));
                    }
                } else {
                    ss.push(*iter);
                }
			iter++;
                
        }
        return stoi(ss.top());

    }
};
