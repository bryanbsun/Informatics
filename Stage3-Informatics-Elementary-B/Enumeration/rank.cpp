#include <bits/stdc++.h>
using namespace std;

int     main(){
    const int A=0, B=1, C=2, D=3, E=4;
    int rank[5]{1,2,3,4,5};
    int top[5]{0};

    do {
        for (int i = 0; i < 5; i ++)
            top[i] = (rank[i] == 1 or rank[i] == 2);

/*        cout << "*rank[" << rank[A] << "," << rank[B] << "," << rank[C] << "," << rank[D] << "," << rank[E] << "]" << endl;
        cout << "*top [" << top[A] << "," << top[B] << "," << top[C] << "," << top[D] << "," << top[E] << "]" << endl;
*/
        if (rank[E] == 2 or rank[E] == 3) continue;
        if (top[A] ^ (rank[E] == 1)) continue;
        if (top[B] ^ (rank[B] == 2)) continue;
        if (top[C] ^ (rank[A] == 5)) continue;
        if (top[D] ^ (rank[C] != 1)) continue;
        if (top[E] ^ (rank[D] == 1)) continue;

        cout << rank[A] << endl << rank[B] << endl << rank[C] << endl << rank[D] << endl << rank[E] << endl;
    }while(next_permutation(rank,rank+5));

    return 0;
}
