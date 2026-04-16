#include<iostream>

using namespace std;

int modo(int x[][100], int m, int n) {
	int max = 0;
	for (int i = 0; i<m; i++) {
		int s = 0;
		for (int j = 0; j<n; j++) {
			s+=x[i][j];
		}
		
		if (s<0) s*=-1;
		if (s>max) max = s;
	}
	
	return max;
}

int main() {
	int m = 0, n = 0;
	
	do {
		cout<<"m: ";cin>>m;
	} while (m<=0);
	
	do {
		cout<<"n: ";cin>>n;
	} while (n<=0);
	
	int x[m][100];
	
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			cout<<"x["<<i<<"]["<<j<<"]: ";cin>>x[i][j];
		}
	}
	
	cout<<modo(x, m, n);
	
	return 0;
}
/*
4
4
12
15
9
7
-3
4
-5
-18
-12
-18
3
4
3
17
12
15

Modo: 47
*/
