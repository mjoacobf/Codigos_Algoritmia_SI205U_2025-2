#include<iostream>
using namespace std;

float convertir(char nc[], int &creales, int &centeros) {
	float count = 1;
	bool decim = false;
	float numero = 0;
	int i = 0;
	while (nc[i]!='\0') {
		if (not decim) {
			if(nc[i] == '.' or nc[i] == ','){
				decim = true;
			} else {
				numero*=10;
				numero+=nc[i]-'0';
			}
		} else {
			count*=0.1;
			float c = nc[i]-'0';
			numero+=c*count;
		}
		i++;
	}
	
	int t = numero;
	if (t*1.0 == numero) centeros++; else creales++;
	
	return numero;
}

int main() {
	char t[200];

	
	cin.getline(t, 200);
	
	float sum = 0;
	int creales = 0;
	int centeros = 0;
	
	int i = 0;
	
	while (t[i]!='\0') {
		while (t[i]!= '\0' and (t[i]-'0'>9 or t[i]-'0'<0)) i++;

		char p[200];
		int j = 0;
		bool existe = false;
		while (t[i]!='\0' and ((t[i]-'0'>=0 and t[i]-'0'<=9) or t[i] ==',' or t[i]=='.')) {
			existe = true;

			if (not(((t[i]==',' or t[i]=='.') and (t[i+1] - '0' < 0 or t[i+1]-'0'>9)))) {
				p[j]=t[i];
				cout<<t[i]<<" "<<i;
				j++;
			}
			p[j] = '\0';
			i++;
			cout<<endl;
		}
		
		if (existe) {
			float w = convertir(p, creales, centeros);
			cout<<w<<endl;
			sum+=w;
		}
		
		existe = false;
		
		i++;
	}
	
	cout<<sum<<endl<<creales<<endl<<centeros;

}