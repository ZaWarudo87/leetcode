class Solution {
public:
    int dfs(int now, vector<vector<int> > &graph, vector<bool> &bef, vector<int> &node){
        if(node[now])
            return node[now];
        else if(graph[now].empty())
            return 1;
        else if(bef[now])
            return 2;

        bef[now] = 1;
        int rtn = 0;
        for(int &i : graph[now]){
            node[i] = dfs(i, graph, bef, node);
            if(node[i] == 2)
                return 2;
            else if(node[i] == 1 && rtn == 0)
                rtn = 1;
        }
        return rtn;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(), i, j, len;
        vector<int> node(n), ans;
        vector<bool> visited(n);
        ans.reserve(n);
        for(i = 0; i < n; ++i)
            if(node[i] == 0)
                node[i] = dfs(i, graph, visited, node);
        for(i = 0; i < n; ++i)
            if(node[i] == 1)
                ans.emplace_back(i);
        return ans;
    }
};
