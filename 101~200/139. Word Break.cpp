class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> visited;
        queue<string> qq;
        qq.push(s);
        visited.insert(s);
        while(!qq.empty()){
            for(string &i : wordDict){
                if(qq.front().find(i) == 0){
                    string temp = qq.front().substr(i.size(), qq.front().size());
                    if(temp.empty())
                        return true;
                    else if(!visited.count(temp)){
                        qq.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            qq.pop();
        }
        return false;
    }
};
