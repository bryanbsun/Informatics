#include <bits/stdc++.h>
using namespace std;

int	main(){
	int n, a[110], min = 1010, mini;

	cin >> n;
	for (int i = 0; i < n; i ++){
		cin >> a[i];
		if (a[i] < min){
			min = a[i];
			mini = i;
		}
	}

	cout << min << " ";
	for (int i = 0; i < n; i ++){
		if (i != mini)
			cout << a[i] << " ";
	}


	return 0;
}

