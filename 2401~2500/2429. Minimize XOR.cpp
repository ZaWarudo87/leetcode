class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<30> a(num1), b(num2);
        int flip = b.count() - a.count();
        if(flip >= 0){
            for(int i = 0, j = 0; i < 30 && j < flip; ++i){
                if(!a[i]){
                    a[i] = 1;
                    ++j;
                }
            }
        }else{
            flip = -flip;
            for(int i = 0, j = 0; i < 30 && j < flip; ++i){
                if(a[i]){
                    a[i] = 0;
                    ++j;
                }
            }
        }
        return a.to_ulong();
    }
};
