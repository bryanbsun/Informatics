#include <bits/stdc++.h>
using namespace std;

struct person{
    int id;
    int t;
}p[1010];
int n, m;
long long total;

bool cmp(person &p1, person &p2){
    if (p1.t == p2.t)
        return (p1.id < p2.id);
    else
        return p1.t < p2.t;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        p[i].id = i;
        cin >> p[i].t;
    }
    
    sort(p+1, p + n+1, cmp);

    long long t[11]{0};
    for (int i = 1; i <= n; i ++){
        int q = (i -1)%m + 1; 
        if (i > m)
            total += t[q];
        t[q] += p[i].t;
        cout << p[i].id << " ";
    }
    cout << endl << fixed << setprecision(2) << (double)total/n <<endl;

    return 0;
}
