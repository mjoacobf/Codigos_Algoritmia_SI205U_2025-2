#include<iostream>

using namespace std;

bool verificar(int num) {
	int s = 0;
	while (num>0) {
		s+=num%10;
		num/=10;
	}
	
	if (s%2==1) return true;
	else return false;
}


int main() {
	int sum = 0;
	int n = 0;
	do {
		cout<<"Ingrese el orden de la matriz (impar y mayor que 5): ";cin>>n;
	} while (n%2 == 0 or n <= 5);
	
	int m = 0;
	do {
		cout<<"Ingrese m (0<m<n-1): ";cin>>m;
	} while (m<=0 or m>=n-1);
	
	int x[n][n];
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cout<<"Ingrese el elemento ("<<i+1<<";"<<j+1<<"): ";cin>>x[i][j];
			
			for (int k = 1; k<=m; k++) {
				if (i + j == n-1+k and verificar(x[i][j])) {
					sum+=x[i][j];
				}
				
				if (i + j == n-1-k and verificar(x[i][j])) {
					sum+=x[i][j];
				}
			}
		}
	}
	
	
	cout<<sum;
	
	
	return 0;
}
/*
7
3
123
1457
6576
2452
2343
128
24
265
397
2546
256
739
1056
5385
945
234
1077
789
1090
2256
9106
401
18401
360
1678
4259
115
1300
752
1120
546
234
136
8296
1202
385
2487
4115
783
945
1001
18
1500
2452
703
4567
746
668
123
*/