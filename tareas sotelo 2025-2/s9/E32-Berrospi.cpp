#include<iostream>
using namespace std;

bool esPerfecto(int num) {
	int sum = 0;
	for (int i = 1; i<num; i++) {
		if (num%i == 0) sum+=i;
	}
	
	if (sum == num) return true; else return false;
}

int mayorperfecto(int x[], int n) {
	int max = 0;
	for (int i = 0; i<n; i++) {
		if (esPerfecto(x[i]) and x[i] > max) max = x[i];
	}
	
	return max;
}

int main() {
	int m = 0;
	do {
		cout<<"m: ";cin>>m;
	} while (m<=0);
	
	int n = 0;
	do {
		cout<<"n: ";cin>>n;
	} while (n<=0);
	
	int a[m], b[n];
	
	for (int i = 0; i<m; i++) {
		cout<<"a["<<i<<"]: ";cin>>a[i];
	}
	
	for (int i = 0; i<n; i++) {
		cout<<"b["<<i<<"]: ";cin>>b[i];
	}
	
	cout<<mayorperfecto(a, m) + mayorperfecto(b, n);
	
	
	return 0;
}
