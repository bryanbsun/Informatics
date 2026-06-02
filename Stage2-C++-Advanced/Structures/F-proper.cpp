#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n), freq(n+1, 0);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (1 <= a[i] && a[i] <= n)
            freq[a[i]]++;
    }
 
    int missing = 0;
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) missing++;
    }
 
    cout << missing;
    return 0;
}
 

