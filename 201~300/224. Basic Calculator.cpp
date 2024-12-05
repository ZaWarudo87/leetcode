class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> sym;
        int temp, temp2, temp3 = 0;
        char last = ' ';

        for(int i = 0, length = s.size(); i < length; i++){
            if(s[i] == ' ')
                continue;

            if(isdigit(s[i])){
                temp3 = temp3 * 10 + int(s[i] - '0');
                goto CONTI;
            }else if(isdigit(last)){
                num.push(temp3);
                //cout << "push " << temp3 << '\n';
                temp3 = 0;
                if(!sym.empty() && !num.empty() && (sym.top() == '+' || sym.top() == '-')){
                    temp2 = num.top();
                    num.pop();
                    temp = num.top();
                    num.pop();
                    if(sym.top() == '+'){
                        num.push(temp + temp2);
                    }else{
                        num.push(temp - temp2);
                    }
                    sym.pop();
                }
            }

            if(s[i] == '+' || s[i] == '-' || s[i] == '('){
                sym.push(s[i]);
                if(s[i] == '-' && (num.empty() || last == '(')){
                    num.push(0);
                }
            }else if (s[i] == ')'){
                sym.pop();
                if(!sym.empty() && !num.empty() && (sym.top() == '+' || sym.top() == '-')){
                    temp2 = num.top();
                    num.pop();
                    temp = num.top();
                    num.pop();
                    if(sym.top() == '+'){
                        num.push(temp + temp2);
                    }else{
                        num.push(temp - temp2);
                    }
                    sym.pop();
                }
            }

            CONTI:
            last = s[i];
        }

        if(isdigit(last)){
            num.push(temp3);
        }

        if(!sym.empty() && !num.empty() && (sym.top() == '+' || sym.top() == '-')){
            temp2 = num.top();
            num.pop();
            temp = num.top();
            num.pop();
            if(sym.top() == '+'){
                num.push(temp + temp2);
            }else{
                num.push(temp - temp2);
            }
            sym.pop();
        }

        return num.top();
    }
};
