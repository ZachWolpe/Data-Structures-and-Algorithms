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