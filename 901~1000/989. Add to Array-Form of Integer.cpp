class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int add = 0, temp;
        for(auto i = num.rbegin(); i != num.rend(); i++){
            *i += k % 10 + add;
            k /= 10;
            add = *i / 10;
            *i %= 10;
        }
        while(k > 0){
            temp = k % 10 + add;
            num.insert(num.begin(), temp % 10);
            k /= 10;
            add = temp / 10;
        }
        if(add > 0)
            num.insert(num.begin(), add);
        return num;
    }
};
