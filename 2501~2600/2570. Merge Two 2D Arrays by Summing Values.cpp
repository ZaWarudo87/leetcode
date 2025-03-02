class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int> > ans;
        ans.reserve(nums1.size() + nums2.size());
        vector<vector<int> >::iterator it1 = nums1.begin(), it2 = nums2.begin();
        while(it1 != nums1.end() || it2 != nums2.end()){
            if(it2 == nums2.end() || it1 != nums1.end() && (*it1)[0] <= (*it2)[0]){
                if(!ans.empty() && ans.back()[0] == (*it1)[0])
                    ans.back()[1] += (*it1)[1];
                else
                    ans.push_back(*it1);
                it1++;
            }else{
                if(!ans.empty() && ans.back()[0] == (*it2)[0])
                    ans.back()[1] += (*it2)[1];
                else
                    ans.push_back(*it2);
                it2++;
            }
        }
        return ans;
    }
};
