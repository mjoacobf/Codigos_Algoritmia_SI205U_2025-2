#include<iostream>
using namespace std;

int main() {
	char n[100];
	int s = 0;
	cin.getline(n,100);
	for (int i = 0; n[i]!='\0'; i++) if (n[i]-'0'>=0 and n[i]-'0'<=9) s+=n[i]-'0';
	cout<<s;
	
	
	
	return 0;
}
