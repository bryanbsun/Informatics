#include <bits/stdc++.h>
using namespace std;

string s;
int ct = 0;

void    perm(int n, int d){
    if (d == n){ 
        cout << ++ct << ":" << s << endl;
        return;
    }
    for (int i = d; i < n; i ++){
        char c = s[i];
        for (int j = i; j > d; j --)
            s[j] = s[j-1];
        s[d] = c;
        perm(n, d+1);
        for (int j = d; j < i; j ++)
            s[j] = s[j+1];
        s[i] = c;
    }
}

int main(){
    cin >> s;
    cout << s.size() << endl;

    perm(s.size(), 0);

    return 0;
}
