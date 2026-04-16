#include<iostream>

using namespace std;

int main() {
	char o[100];
	int palabras = 0;
	
	cin.getline(o,100);
	int i = 0;
	while (o[i]!='\0') {
		if (o[i] != ' ' and (o[i+1] == ' ' or o[i+1] == '\0')) {
			palabras++;
		}
		i++;
	}
	
	cout<<palabras;
	
	
	return 0;
}
