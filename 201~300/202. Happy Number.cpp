class Solution {
public:
    bool isHappy(int n) {
        int temp, n2 = n, wait;
        do{
            temp = n;
            n = 0;
            while(temp > 0){
                n += (temp % 10) * (temp % 10);
                temp /= 10;
            }

            wait = 2;
            while(wait--){
                temp = n2;
                n2 = 0;
                while(temp > 0){
                    n2 += (temp % 10) * (temp % 10);
                    temp /= 10;
                }
            }
            if(n == 1 || n2 == 1) return true;
        }while(n != n2);
        return false;
    }
};
