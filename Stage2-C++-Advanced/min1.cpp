#include <bits/stdc++.h>

using namespace std;

int n,a[110],minn,mini;

int main(){
    cin >> n >> a[0];
    minn = a[0];
    
    for(int i = 1;i < n;++ i){
        cin >> a[i];
        if(a[i] < minn){
            minn = a[i];
            mini = i;
        }
    }

    for(int i = mini;i > 0;-- i)
        a[i] = a[i-1];
    a[0] = minn;
    for(int i = 0;i < n;++ i)
        cout << a[i] << " ";

    return 0;
}
