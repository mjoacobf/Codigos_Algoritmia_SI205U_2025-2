#include<iostream>

using namespace std;

int main() {
	int C = 0;
	char o[100];
	char palabra[100];
	
	cout<<"Oracion: ";
	cin.getline(o,100);
	
	cout<<"Palabra: ";
	cin>>palabra;
	
	int j = 0;
	while (palabra[j] != '\0') {
		j++;
	}
	
	
	int i = 0;
	int l = 0;
	bool es = true;
	
	char w[100];
	while (o[i] != '\0') {
		
		if (o[i] != ' ') {
			
			w[l] = o[i];
			l++;
			if (o[i+1] ==' ' or o[i+1] == '\0') {
				
				if (j == l) {
					for (int k = 0; k<j; k++) {
						if (w[k] != palabra[k]) es = false;
					}
					if (es) C++;
				}
				
				es = true;
				l = 0;
				
			}
			
			
		}
		
		i++;
	}
	
	cout<<C;
	
	return 0;
}
