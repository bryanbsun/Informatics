#include <bits/stdc++.h>
using namespace std;
int n,c=0,x,a[1010];
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        if(x==1)
            ++c;
        ++a[c];
    }
    cout<<c<<endl;
    for(int i=1;i<=c;++i)
        cout<<a[i]<<" ";
    return 0;
}
