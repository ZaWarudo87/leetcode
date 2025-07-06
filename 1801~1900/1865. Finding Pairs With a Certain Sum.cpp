class FindSumPairs {
private:
    vector<int> n1, n2;
    unordered_map<int, int> m2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for(int &i : nums2)
            ++m2[i];
    }
    
    void add(int index, int val) {
        --m2[n2[index]];
        n2[index] += val;
        ++m2[n2[index]];
    }
    
    int count(int tot) {
        int ans = 0;
        for(int &i : n1)
            if(m2.count(tot - i))
                ans += m2[tot - i];
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
