#include<iostream>
using namespace std;

int prod(int a, int b) {
	int p = a;
	if (b != 1) {
		p+=prod(a,b-1);
	}
	return p;
}

int main() {
	int a, b;
	cin>>a>>b;
	cout<<prod(a,b);
	return 0;
}
