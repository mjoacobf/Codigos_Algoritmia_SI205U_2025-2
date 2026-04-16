#include<iostream>

using namespace std;

void bubblesort(int x[], int n) {
	for (int i = 0; i<n; i++) {
		for (int j = n-1; j>i; j--) {
			if (x[i] > x[j]) {
				int t = x[j];
				x[j] = x[i];
				x[i] = t;
			}
		}
	}
}


int main() {
	int n = 0;
	do {
		cout<<"n: ";cin>>n;
	} while (n<=0);
	
	int x[n];
	
	for (int i = 0; i<n; i++) {
		cout<<"x["<<i<<"]: ";cin>>x[i];
	}
	
	bubblesort(x, n);
	
	for (int i = 0; i<n; i++) {
		cout<<x[i]<<" ";
	}
	
	return 0; // D:
}
