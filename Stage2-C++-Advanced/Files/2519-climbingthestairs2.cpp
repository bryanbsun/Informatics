#include <bits/stdc++.h>
using namespace std;
int n,c=0,x,x1=0,a[1010];
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        if(x==1){
            if(x1)
                a[c]=x1;
            ++c;
        }
        x1=x;
    }
    a[c]=x1;
    cout<<c<<endl;
    for(int i=1;i<=c;++i)
        cout<<a[i]<<" ";
    return 0;
}
