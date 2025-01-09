class NumArray {
private:
    vector<int> fenwick, vec;
public:
    NumArray(vector<int>& nums) {
        int len = nums.size();
        vec.resize(len);
        fenwick.resize(len + 1);
        for(int i = 0; i < len; ++i)
            update(i, nums[i]);
    }
    
    void update(int index, int val) {
        int len = fenwick.size(), delta = val - vec[index];
        vec[index] = val;
        ++index;
        while(index < len){
            fenwick[index] += delta;
            index += (index & -index);
        }
    }
    
    int sumRange(int left, int right) {
        int ansr = 0, ansl = 0;
        ++right;
        while(right > 0){
            ansr += fenwick[right];
            right -= (right & -right);
        }
        while(left > 0){
            ansl += fenwick[left];
            left -= (left & -left);
        }
        return ansr - ansl;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
