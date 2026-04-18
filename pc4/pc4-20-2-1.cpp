#include<iostream>

using namespace std;

int mcd(int a, int b) {
	if (a==b) return a;
	if (a>b) return mcd(a-b,b);
	else return mcd(a, b-a);
}

int main() {
	int a,b;
	cin>>a>>b;
	cout<<mcd(a,b);
	return 0;
}