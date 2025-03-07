class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        bool isprime[1001] = {}, check;
        int prime[168] = {}, len = 0, i, j, l = -1, r = -1, al = -1, ar = -1, temp = 1000001;
        for(i = 2; i * i <= right; ++i){
            if(!isprime[i]){
                prime[len++] = i;
                for(j = i * i; j < 1001 && j * j <= right; j += i)
                    isprime[j] = 1;
            }
        }
        for(i = left; i <= right && temp > 2; ++i){
            check = 0;
            for(j = 0; j < len && prime[j] < i; ++j){
                if(i % prime[j] == 0){
                    check = 1;
                    break;
                }
            }
            if(j < len){
                if(i == prime[j])
                    check = 0;
                else if(i < prime[j])
                    check = 1;
            }
            if(!check){
                l = r;
                r = i;
                if(l != -1 && r - l < temp){
                    temp = r - l;
                    ar = r;
                    al = l;
                }
            }
        }
        if(al == -1 || ar == -1)
            return {-1, -1};
        else
            return {al, ar};
    }
};
