#include <bits/stdc++.h>
using namespace std;

int	main(){
	int n, m = 0, p;
	int stairs[1010];

	cin >> n;
	for (int i = 0; i < n; i ++){
		cin >> p;
		if (p == 1){
			stairs[++m] = 1;
		}else
			stairs[m] ++;
	}

	cout << m << endl;
	for (int i = 1; i <= m; i ++)
		cout << stairs[i] << " ";

	return 0;
}

