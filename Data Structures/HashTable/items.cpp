#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class ItemsInCommon {
public:
    bool static itemInCommonA(vector<int> vector1, vector<int> vector2) {
        for (auto i : vector1) {
            for (auto j : vector2) {
                if (i==j) return true;
            }
        }
        return false;
    };

    bool static itemInCommonB(vector<int> vector1, vector<int> vector2) {
        unordered_map<int, bool> map1;
        for (auto i : vector1){
            map1.insert({i, true});
        }
        for (auto j : vector2) {
            if (map1[j]) return true;
        }
        return false;
    }
};


int main() {
    // define vector 
    vector<int> vec;

    // vector<int> v1{1,3,5};
    // vector<int> v2 {2,4,6};
    // cout << "iic(A): " << ItemsInCommon::itemInCommonA(v1,v2) << endl;
    // cout << "iic(B): " << ItemsInCommon::itemInCommonB(v1,v2) << endl;
    return 0;
}
