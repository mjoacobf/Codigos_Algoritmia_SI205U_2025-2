#include<iostream>

using namespace std;

int main() {
	int n = 0;
	
	do {
		cout<<"n: ";cin>>n;
	} while (n<=0);
	
	int x[n][n+1];
	
	for (int i = 0; i<n*(n+1); i++) {
		x[i%n][i%(n+1)] = i+1;
	}
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n+1; j++) {
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for (int i = 0; i<n; i++) {
		for(int j = i; j<n; j++) {
			x[i][j] = x[i][j+1];
		}
	}
	cout<<endl<<endl;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}