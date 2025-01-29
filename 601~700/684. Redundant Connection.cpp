class Solution {
public:
    vector<int> disjoint;

    int check(int a){
        if(a == disjoint[a])
            return a;
        return disjoint[a] = check(disjoint[a]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        disjoint.resize(1001);
        for(int i = 1; i <= 1000; ++i)
            disjoint[i] = i;
        vector<int> ans(2);
        for(vector<int> &i : edges){
            if(check(i[0]) == check(i[1]))
                ans = i;
            else{
                if(check(i[0]) < check(i[1]))
                    disjoint[disjoint[i[1]]] = disjoint[i[0]];
                else
                    disjoint[disjoint[i[0]]] = disjoint[i[1]];
            }
        }
        return ans;
    }
};
