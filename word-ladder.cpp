class Solution {
public:
    bool canTransfer(string src, string dst){
            string::iterator it1 = src.begin();
            string::iterator it2 = src.begin();
            int diff = 0;
            while (it1 != src.end()) {
                if(*it1 != *it2){
                    diff++
                }
                it1++;
                it2++;
            }
            
            if(diff == 1) return true;
            return false;
    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
    }
};
