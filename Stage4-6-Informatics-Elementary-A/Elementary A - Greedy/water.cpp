#include <bits/stdc++.h>
using namespace std;

struct person{
    int id;
    int t;
}p[1010];
int n;
long long total;

bool cmp(person &p1, person &p2){
    if (p1.t == p2.t)
        return (p1.id < p2.id);
    else
        return p1.t < p2.t;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        p[i].id = i;
        cin >> p[i].t;
    }
    
    sort(p+1, p + n+1, cmp);

    long long t = 0;
    for (int i = 1; i <= n; i ++){
        if (i > 1)
            total += t;
        t += p[i].t;
        cout << p[i].id << " ";
    }
    cout << endl << fixed << setprecision(2) << (double)total/n <<endl;

    return 0;
}
