#include<iostream>

using namespace std;

int main() {
	char o[100];
	
	int sum = 0;
	
	cout<<"Oracion: ";
	cin.getline(o,100);
	
	int i = 0;
	int t = 0;
	while (o[i] != '\0') {
		
		if (o[i] != ' ') {
			
			if (o[i] - '0' >= 0 and o[i] - '0' <= 9) {
				t*=10;
				t+=o[i] - '0';
			}
			
			if (o[i+1] ==' ' or o[i+1] == '\0') {
				sum+=t;
				t = 0;
			}
			
			
		}
		
		i++;
	}
	
	cout<<sum;
	
	return 0;
}
