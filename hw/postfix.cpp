#include <bits/stdc++.h>

using namespace std;


int order(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}

string infixToPrefix(string a){
    stack<char> s;
    string res = "";
    for(auto i:a){
        if(isalnum(i)) res += i;
        else if(i == '('){
            s.push(i);
        } else if(i == '^'){
            s.push(i);
        } else if(i == ')'){
            while(!s.empty() && s.top() != '('){
                res += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        } else {
            if(s.empty()) s.push(i);
            else if(order(i) > order(s.top())) s.push(i);
            else {
                while(!s.empty() && order(i) <= order(s.top())){
                    res += s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
    }

    while(!s.empty()){
        res += s.top();
        s.pop();
    }

    return res;
}

int cal(string a){
    stack<int> s;
    string tmp = "";
    int a1, a2;
    for(auto i:a){
        if(isalnum(i)){
            tmp += i;
        } else {
            cout << tmp << endl;
            s.push(stoi(tmp));
            tmp = "";
            if(i == '+'){
                a1 = s.top();s.pop();
                a2 = s.top();s.pop();
                s.push(a1+a2);
            } else if(i == '-'){
                a1 = s.top();s.pop();
                a2 = s.top();s.pop();
                s.push(a1-a2);
            } else if(i == '*'){
                a1 = s.top();s.pop();
                a2 = s.top();s.pop();
                s.push(a1*a2);
            } else if(i == '/'){
                a1 = s.top();s.pop();
                a2 = s.top();s.pop();
                s.push(a1/a2);
            } else if(i == '^'){
                a1 = s.top();s.pop();
                a2 = s.top();s.pop();
                s.push(a1^a2);
            }
        }
    }

    return s.top();
}

int main(){
    string s;
    cin >> s;
    cout << infixToPrefix(s) << endl;
    // cout << cal(infixToPrefix(s)) << endl;
}