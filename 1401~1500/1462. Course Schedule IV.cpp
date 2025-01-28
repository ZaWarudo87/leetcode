class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool> > mapu(numCourses, vector<bool>(numCourses));
        for(vector<int> &i : prerequisites)
            mapu[i[0]][i[1]] = true;

        int i, j, k;
        for(i = 0; i < numCourses; ++i)
            for(j = 0; j < numCourses; ++j)
                for(k = 0; k < numCourses; ++k)
                    if(mapu[j][i] && mapu[i][k])
                        mapu[j][k] = true;

        vector<bool> ans(queries.size());
        for(i = 0; i < queries.size(); ++i)
            ans[i] = mapu[queries[i][0]][queries[i][1]];
        return ans;
    }
};
