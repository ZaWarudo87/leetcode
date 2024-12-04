class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool invalid[9][9][10];
        int i, j, k, h, x, y;
        
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(board[i][j] != '.' && invalid[i][j][board[i][j] - '0']){
                    /*cout << i << ' ' << j << '\n';
                    for(auto &l : invalid){
                        for(auto &m : l){
                            string cot;
                            for(auto &n : m)
                                cot += n;
                            cout << setw(9) << cot << ' ';
                        }
                        cout << '\n';
                    }*/
                    return false;
                }
                if(board[i][j] != '.'){
                    for(k = 0; k < 9; k++){
                        invalid[i][k][board[i][j] - '0'] = 1;
                        invalid[k][j][board[i][j] - '0'] = 1;
                    }
                    x = i - i % 3;
                    y = j - j % 3;
                    for(k = 0; k < 3; k++)
                        for(h = 0; h < 3; h++)
                            invalid[x + k][y + h][board[i][j] - '0'] = 1;
                }
            }
        }
        return true;
    }
};
