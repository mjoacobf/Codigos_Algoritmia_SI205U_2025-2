#include<iostream>

using namespace std;

int main() {
	char o1[200];
	char o2[200];
	
	cin.getline(o1, 200);

	
	cin.getline(o2, 200);
	
	string f1 = "";
	string f2 = "";
	
	int i = 0;
	while (o1[i]!='\0') {
		while(o1[i]!='\0' and (o1[i] == ' ' or o1[i] == ',' or o1[i] == '.' or o1[i] == ':')) i++;
		
		
		string a = "";
		
		int l = 0;
		bool encontrado = false;
		
		while (o1[i]!='\0' and o1[i] != ' ' and o1[i] != ',' and o1[i] != '.' and o1[i] != ':') {
			a+=o1[i];
			l++;
			i++;
		}
		
		
		int j = 0;

		while (o2[j]!='\0') {
			while(o2[j]!='\0' and (o2[j] == ' ' or o2[j] == ',' or o2[j] == '.' or o2[j] == ':')) j++;
			string b = "";
			while (o2[j]!='\0' and o2[j] != ' ' and o2[j] != ',' and o2[j] != '.' and o2[j] != ':') {
				b+=o2[j];
				j++;
			}

			if (a == b) {
				encontrado = true;
				break;
			}
		}
		
		if (not encontrado) {
			f1+=a+" ";
		}
		
	}
	
	i = 0;
	while (o2[i]!='\0') {
		while(o2[i]!='\0' and (o2[i] == ' ' or o2[i] == ',' or o2[i] == '.' or o2[i] == ':')) i++;
		
		
		string a = "";
		
		int l = 0;
		bool encontrado = false;
		
		while (o2[i]!='\0' and o2[i] != ' ' and o2[i] != ',' and o2[i] != '.' and o2[i] != ':') {
			a+=o2[i];
			l++;
			i++;
		}
		
		
		int j = 0;

		while (o1[j]!='\0') {
			while(o1[j]!='\0' and (o1[j] == ' ' or o1[j] == ',' or o1[j] == '.' or o1[j] == ':')) j++;
			string b = "";
			while (o1[j]!='\0' and o1[j] != ' ' and o1[j] != ',' and o1[j] != '.' and o1[j] != ':') {
				b+=o1[j];
				j++;
			}

			if (a == b) {
				encontrado = true;
				break;
			}
		}
		
		if (not encontrado) {
			f2+=a+" ";
		}
		
	}
	
	cout<<f1<<endl<<f2;
	
}
/*
NO TODOS LOS ALUMNOS EN LA PC3 APROBARON
NO APROBARON. ESTAN JALADOS EN LA PC3
*/