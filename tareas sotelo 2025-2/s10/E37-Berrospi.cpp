#include<iostream>

using namespace std;

int fibonacci(int n) {
	int x;
	if (n>2) {
		x = fibonacci(n-2) + fibonacci(n-1);
	} else {
		x = 1;
	}
	
	return x;
}

int main() {
	int n = 0;
	do {
		cin>>n;
	} while (n<=0);
	
	cout<<fibonacci(n);
	
	return 0;

}
