#include<bits/stdc++.h>
using namespace std;
struct win {
    int l,r,t,b; //l:left r:right t:top b:bottom
};
win w1,w2,w3;
void read(win& w)
{
    cin>>w.l>>w.r>>w.t>>w.b;
}
int main()
{
    int ans=0;
    read(w1);
    read(w2);
    w3.l=max(w1.l,w2.l);
    w3.r=min(w1.r,w2.r);
    w3.t=max(w1.t,w2.t);
    w3.b=min(w1.b,w2.b);
    if (w3.l<w3.r&&w3.t<w3.b)
        ans=(w3.r-w3.l)*(w3.b-w3.t);
    cout<<ans<<endl;
    return 0;
}