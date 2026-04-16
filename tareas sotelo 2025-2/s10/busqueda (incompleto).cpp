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

int busqueda(int x[], int n, int num) {
	if (num < x[n/2]) {
		
	}
	
}
