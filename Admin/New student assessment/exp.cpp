#include <bits/stdc++.h>
using namespace std;

int     main(){
    string s;
    cin >> s;
    int l = s.length();
    int n = 1 << (l-1);
    int p = 0;
    long long ans = 0;

    for (int i = 0; i < n; i ++){
        long long num = s[0] - '0';
        for (int j = 0; j < l-1; j ++){
//            num = num * 10 + s[j]
            p = (i >> j)  & 1;
            if(p){
                ans += num;
                num = s[j + 1] - '0';
            }else {
                num = num * 10 + s[j + 1] -'0';
            }
        }
        ans += num;
    }

    cout << ans << endl;

    return 0;
}
