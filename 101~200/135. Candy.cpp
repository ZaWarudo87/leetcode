// slice, calc and merge
class Solution {
private:
    static vector<int> part(vector<int> ratings){
        int len = ratings.size(), mi = 0, mii = 0;
        if(len <= 1) return {1};
        vector<int> candy(len);
        
        for(int i = 1; i < len; i++){
            if(ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
            else if(ratings[i] < ratings[i - 1]){
                /*if(i + 1 >= len || candy[i + 1] > candy[i])
                    candy[i] = mi - (mii == i - 1);
                else*/
                    candy[i] = candy[i - 1] - 1;
            }
            if(candy[i] < mi){
                mi = candy[i];
                mii = i;
            }
        }

        //cout << "> ";
        for(auto &i : candy){
            i += abs(1 - mi);
            //cout << i << ' ';
        }
        //cout << '\n';
        return candy;
    }

public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        int ans = 0;
        if(len <= 1) return 1;
        vector<int> result, temp;
        vector<int>::iterator st = ratings.begin();
        bool la = false, lala = false;
        for(vector<int>::iterator i = ratings.begin() + 1; i != ratings.end(); i++){
            if(*i == *(i - 1) || i + 1 != ratings.end() && *(i + 1) < *i && *(i - 1) < *i){
                la = i + 1 != ratings.end() && *(i + 1) < *i && *(i - 1) < *i;
                temp = part(vector<int>(st, i));
                if(lala && !result.empty() && temp[0] <= result.back()){
                    for(auto &j : temp)
                        j += result.back() + 1 - temp[0];
                }
                result.insert(result.end(), temp.begin(), temp.end());
                st = i;
                lala = la;
            }
        }
        temp = part(vector<int>(st, ratings.end()));
        if(lala && !result.empty() && temp[0] <= result.back()){
            for(auto &j : temp)
                j += result.back() + 1 - temp[0];
        }
        result.insert(result.end(), temp.begin(), temp.end());
        
        for(auto &i : result){
            //cout << i << ' ';
            ans += i;
        }
        return ans;
    }
};
