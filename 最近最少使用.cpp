#include <map>
#include <iostream>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
       size = capacity;
        
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) {
            return m[key];
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if(m.size() < size) {
            m[key] = value;
        } else {
			cout << "size less than need" << endl;
            if(m.find(key) == m.end() ){
                auto minIter = m.begin();
                auto iter = minIter;
                while(iter != m.end()){
                    if(minIter->second > iter->second){
                        minIter = iter;
                    }
                    iter ++;
                }
				//cout << "before erase" << endl;
				cout << minIter->first << " " << minIter->second << endl;
                m.erase(minIter);
				//cout << "before set" << endl;
                m[key] = value;
            } else {
                m[key] = value;
            }
        }
    }
private:
     map<int, int> m;
     size_t size;
};
int main()
{
	LRUCache lru(2);
	lru.set(2,1);
	lru.set(2,2);
	cout << lru.get(2) << endl;
	lru.set(1,1);
	lru.set(4,1);
	cout << lru.get(2) << endl;
}

