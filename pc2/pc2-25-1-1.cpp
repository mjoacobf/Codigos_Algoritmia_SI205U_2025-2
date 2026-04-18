#include<iostream>

using namespace std;

int main() {
	int n = 0;
	do {
		cout<<"Ingrese el orden de la matriz: ";cin>>n;
	} while (n<=0);
	
	int x[n][n];
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			int e = 0;
			do {
				cout<<"Ingrese el valor en ("<<i+1<<";"<<j+1<<"): ";cin>>e;
			} while (e<0);
			
			x[i][j] = e;
		}
	}
	
	int a = 0;
	do {
		cout<<"Ingrese la coordenada 1: ";cin>>a;
	} while (a <= 0 or a > n);
	a--;
	int b = 0;
	do {
		cout<<"Ingrese la coordenada 2: ";cin>>b;
	} while (b <= 0 or b > n);
	b--;
	
	int L = -1;
	do {
		cout<<"Ingrese L: ";cin>>L;
	} while (L<=0 or a+L>n or b+L>n);
	
	int prod = 1;
	for (int i = a; i<a+L;i++) {
		for (int j = b; j<b+L; j++) {
			if (i-a + j-b == L-1) {
				prod*=x[i][j];
			}
		}
	}
	
	cout<<prod;
	return 0;
}
/*
7
27
60
10
56
21
70
74
63
93
71
78
57
91
11
40
19
26
76
32
87
41
85
93
16
91
47
71
11
18
16
59
55
47
16
35
24
48
56
48
77
48
37
19
90
33
34
57
14
28
3
2
4
*/