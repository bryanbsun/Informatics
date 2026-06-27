#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int sta[55];
int top;

int main(){
    cin >> s;
    n = s.size();

    for(int i = 0; i < n; i ++){
        if (s[i] == '('){
            sta[top] = i;
            top ++;
        }else{
            top --;
            cout << sta[top] << " " << i << endl;
        }
    }
    return 0;
}
