#include <bits/stdc++.h>
using namespace std;
int n,c=0,x[1010],a[1010];
int main(){
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>x[i];
    x[n]=1; // 在最后一层之后再模拟一层
    for(int i=1;i<=n;++i){
        if(x[i]<=x[i-1]){
            a[c]=x[i-1];
//            cout<<i<<" "<<x[i]<<" "<<x[i-1]<<" "<<c<<" "<<a[c]<<endl;
            ++c;
        }
    }
    cout<<c<<endl;
    for(int i=0;i<c;++i)
        cout<<a[i]<<" ";
    return 0;
}
