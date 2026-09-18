class RandomizedSet {
public:

    vector<int> arr;
    unordered_map<int,int> mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(mp.find(val) != mp.end())
            return false;

        arr.push_back(val);
        mp[val] = arr.size()-1;
        return true;
    }
    
    bool remove(int val) {

        if(mp.find(val) == mp.end())
            return false;

        int index = mp[val];
        int last = arr.back(); 
        arr[index] = last;
        mp[last] = index;

        mp.erase(val);
        arr.pop_back();

        return true;
        
    }
    
    int getRandom() {
        
        int i = rand()%arr.size();
        return arr[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */