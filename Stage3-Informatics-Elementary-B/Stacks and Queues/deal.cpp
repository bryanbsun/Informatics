#include <bits/stdc++.h>
using namespace std;

int n, k, p;
int que[1000010];
int f,r;
int ans[100010]; 

void    push(int x){
    que[r++] = x;
}

int     pop(){
    int x = que[f];
    f ++;
    return x;
//    return que[f++];
}

void    print(){
    for(int i = f; i < r; i ++)
        cout << que[i] << " ";
    cout << endl;
}

bool    empty(){
    return f == r;
}

int     main(){
    cin >> n >> k >> p;
    for (int i = 1; i <= k; i ++)
        push(i);
//    print();

    int pp = 0, qq = 0;
    while (!empty()){
        int x = pop();
//        print();
        pp = (pp + 1)%n;
        if (!pp)
            ans[qq++] = x;
        for (int i = 0; i < p; i ++){
            x = pop();
            push(x);
//            print();
        }
    }

    sort(ans, ans + k/n);
    for (int i = 0; i < k/n; i ++)
        cout << ans[i] << endl;
    return 0;
}
