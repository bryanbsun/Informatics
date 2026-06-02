#include <bits/stdc++.h>
using namespace std;

int	main(){
	int n,m,g;
	int cap, buses = 0;

	cin >> n >> m;
	
	cap = m;
	buses = 1;
	for (int i = 0; i < n; i ++){
		cin >> g;
		if(g > cap){
			buses ++;
			cap = m;
		}
		cap -= g;
	}

	cout << buses << endl;

	return 0;
}
