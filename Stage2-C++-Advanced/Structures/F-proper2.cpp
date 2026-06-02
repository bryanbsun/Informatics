#include <bits/stdc++.h>
using namespace std;

int	n, a[5050];

int	main(){
	int p, c = 0;

	cin >> n;
	
	for (int i = 0; i < n; i ++){
		cin >> p;
		if (p <= n) a[p-1] = 1;
	}

	for (int i = 0; i < n; i ++)
		c += (a[i] == 0);

	cout << c;

	return 0;
}

