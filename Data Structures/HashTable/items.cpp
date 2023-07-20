/**
========================================================================
@file items.cpp

An illustrutation of how to use a hashmap to reduce time complexity from O(n^2) to O(n).

: zach wolpe
: zach.wolpe@medibio.com.au
: 07 July 2023
========================================================================
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Big O: O(n^2)

class ItemsInCommon {
public:
    bool static itemInCommonA(vector<int> vector1, vector<int> vector2) {
        // suboptimal solution: O(n^2)
        for (auto i : vector1) {
            for (auto j : vector2) {
                if (i==j) return true;
            }
        }
        return false;
    };

    bool static itemInCommonB(vector<int> vector1, vector<int> vector2) {
        // optimal solution: O(n)
        unordered_map<int, bool> map1;
        // copy into hashtable
        for (auto i : vector1){
            map1.insert({i, true});
        }
        // loopup in a hashtable is O(1), thus O(n)
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
