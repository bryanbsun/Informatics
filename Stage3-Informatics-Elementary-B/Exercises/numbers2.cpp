#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    long long n;
    cin >> n;
    long long t = 0;
    if(n > 1000){
        int s[100]{0};
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            if(s[a - 1] == 0){
                s[a - 1]++;
            }
        }
        for(int j = 0; j < 100; j++){
            if(s[j] != 0){
                t++;
            }
        }
    }else{
        long long s[n];
        t = 1;
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        sort(s, s + n);
        for(int i = 1; i < n; i++){
            if(s[i] != s[i - 1]){
                t++;
            }
        }
    }
    cout << t;
}
