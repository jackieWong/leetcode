#include <sstream>
#include <vector>

class Solution {
public:
    void reverseWords(string &s) {
        istringstream ss(s);
        string tmp;
        vector<string> sv;
        while(ss >> tmp) {
            sv.push_back(tmp);
        }
        s.clear();
        while(! sv.empty()) {
            s += sv.back();
            sv.pop_back();
            if (sv.size() != 0) {
                s += " ";
            }
        }
     
    }
};
