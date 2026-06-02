#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a;

    cin >> n;
    int max = -1;
    int len = 0;
    int maxlen = 0;
    int inseq = 0;
    for (int i = 0; i < n; i ++){
        cin >> a;
        if (a > max){
            max = a;
            maxlen = len = 1;
            inseq = 1;
        }else if (a == max){
            if (inseq){
                len ++;
                if (len > maxlen)
                    maxlen = len;
            }else{
                inseq = 1;
                len = 1;
            }
        }else if (a < max)
            inseq = 0;
    }

    cout << maxlen << endl;
    return 0;
}
