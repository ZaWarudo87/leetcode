/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int i, j, temp[100] = {};
        bool known[100][100] = {};
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i == j) continue;
                if(knows(i, j)){
                    known[j][i] = 1;
                    temp[i]++;
                }
                if(temp[i] > 0)
                    break;
            }
            if(temp[i] == 0){
                for(j = 0; j < n; j++){
                    if(i == j || known[i][j]) continue;
                    if(knows(j, i)){
                        temp[j]++;
                    }else{
                        goto CONTI;
                    }
                }
                return i;
            }
            CONTI:
        }
        return -1;
    }
};
