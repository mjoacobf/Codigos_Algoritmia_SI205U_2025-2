//PC4 24-2 preg 1

#include<iostream>
#include<fstream>

using namespace std;

struct reg_nodo {
	char cadena[50];
	reg_nodo *psigue;
} *pinicio, *pactual, *paux;

void ordenarcadena() {
	pactual = pinicio;
	while (pactual!=NULL) {
		//Mayusculas y minusculas
		int i = 0;
		while (pactual->cadena[i]!='\0') {
			int j = i+1;
			while (pactual->cadena[j]!='\0') {
				if (pactual->cadena[i]-'A'>=0 and pactual->cadena[i]-'A'<26 and pactual->cadena[j]-'a'>=0 and pactual->cadena[j]-'a'<26) {
					char t = pactual->cadena[i];
					pactual->cadena[i] = pactual->cadena[j];
					pactual->cadena[j] = t;
					i = -1;
					break;
				}
				j++;
			}
			i++;
		}
		
		//Minusculas y numeros
		i = 0;
		while (pactual->cadena[i]!='\0') {
			int j = i+1;
			while (pactual->cadena[j]!='\0') {
				if (pactual->cadena[i]-'0'>=0 and pactual->cadena[i]-'0'<=9 and pactual->cadena[j]-'a'>=0 and pactual->cadena[j]-'a'<26) {
					char t = pactual->cadena[i];
					pactual->cadena[i] = pactual->cadena[j];
					pactual->cadena[j] = t;
					i = -1;
					break;
				}
				j++;
			}
			i++;
		}
		
		//Numeros y mayusculas
		i = 0;
		while (pactual->cadena[i]!='\0') {
			int j = i+1;
			while (pactual->cadena[j]!='\0') {
				if (pactual->cadena[i]-'A'>=0 and pactual->cadena[i]-'A'<26 and pactual->cadena[j]-'0'>=0 and pactual->cadena[j]-'0'<=9) {
					char t = pactual->cadena[i];
					pactual->cadena[i] = pactual->cadena[j];
					pactual->cadena[j] = t;
					i = -1;
					break;
				}
				j++;
			}
			i++;
		}
		
		//Minusculas
		i = 0;
		while (pactual->cadena[i]!='\0') {
			int j = i+1;
			while (pactual->cadena[j]!='\0') {
				if (pactual->cadena[i]-'a'>=0 and pactual->cadena[i]-'a'<26 and pactual->cadena[j]-'a'>=0 and pactual->cadena[j]-'a'<26 and pactual->cadena[i]-'a'>pactual->cadena[j]-'a') {
					char t = pactual->cadena[i];
					pactual->cadena[i] = pactual->cadena[j];
					pactual->cadena[j] = t;
					i = -1;
					break;
				}
				j++;
			}
			i++;
		}
		
		//Mayusculas
		i = 0;
		while (pactual->cadena[i]!='\0') {
			int j = i+1;
			while (pactual->cadena[j]!='\0') {
				if (pactual->cadena[i]-'A'>=0 and pactual->cadena[i]-'A'<26 and pactual->cadena[j]-'A'>=0 and pactual->cadena[j]-'A'<26 and pactual->cadena[i]-'A'>pactual->cadena[j]-'A') {
					char t = pactual->cadena[i];
					pactual->cadena[i] = pactual->cadena[j];
					pactual->cadena[j] = t;
					i = -1;
					break;
				}
				j++;
			}
			i++;
		}
		
		//Numeros
		i = 0;
		while (pactual->cadena[i]!='\0') {
			int j = i+1;
			while (pactual->cadena[j]!='\0') {
				if (pactual->cadena[i]-'0'>=0 and pactual->cadena[i]-'0'<=9 and pactual->cadena[j]-'0'>=0 and pactual->cadena[j]-'0'<=9 and pactual->cadena[i]-'0'>pactual->cadena[j]-'0') {
					char t = pactual->cadena[i];
					pactual->cadena[i] = pactual->cadena[j];
					pactual->cadena[j] = t;
					i = -1;
					break;
				}
				j++;
			}
			i++;
		}
		
		pactual = pactual->psigue;
	}
}

void ordenartodas() {
	pactual = pinicio;
	while (pactual!=NULL) {
		bool cambio = false;
		paux = pactual->psigue;
		while (paux!=NULL) {
			//bool flag = false;
			
			//int i = 0;
			
			int l1 = 0;
			while (pactual->cadena[l1]!='\0') l1++;
			int l2 = 0;
			while (paux->cadena[l2]!='\0') l2++;
			
			//while (not flag) {
				//if (pactual->cadena[i]-'a'>paux->cadena[i]-'a') {
				if (l1>l2) {
					//flag = true;
					cambio = true;
					
					int j = 0;
					char t[50];
					while (paux->cadena[j]!='\0') {
						t[j]=paux->cadena[j];
						j++;
					}
					t[j]='\0';
					
					j = 0;
					while (pactual->cadena[j]!='\0') {
						paux->cadena[j]=pactual->cadena[j];
						j++;
					}
					paux->cadena[j]='\0';
					
					j=0;
					while (t[j]!='\0') {
						pactual->cadena[j]=t[j];
						j++;
					}
					pactual->cadena[j]='\0';
					
				} /*else if (pactual->cadena[i]==paux->cadena[i]) {
					i++;
				} else flag = true;*/
			//}
			
			if (cambio) paux = NULL;
			else paux=paux->psigue;
		}
		
		if (cambio) pactual = pinicio;
		else pactual=pactual->psigue;
	}
	
	
}

int main() {
	ifstream a("CADENAS.TXT");
	
	pinicio = NULL;
	char x[50];
	
	while (a.getline(x, 50)) {
		if (pinicio == NULL) {
			pinicio = new reg_nodo;
			pactual = pinicio;
		} else {
			pactual->psigue = new reg_nodo;
			pactual=pactual->psigue;
		}
		
		int i = 0;
		while (x[i]!='\0') {
			pactual->cadena[i] = x[i];
			i++;
		}
		pactual->cadena[i]='\0';
		
		pactual->psigue = NULL;
	}
	
	a.close();
	//Antes
	pactual = pinicio;
	while (pactual!=NULL) {
		int i = 0;
		while (pactual->cadena[i]!='\0') {
			cout<<pactual->cadena[i];
			i++;
		}
		cout<<endl;
		pactual=pactual->psigue;
	}
	
	ordenarcadena();
	cout<<endl;
	//Despues
	cout<<"Ahora: "<<endl<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		int i = 0;
		while (pactual->cadena[i]!='\0') {
			cout<<pactual->cadena[i];
			i++;
		}
		cout<<endl;
		pactual=pactual->psigue;
	}
	cout<<endl;
	
	ordenartodas();
	cout<<"Ahora: "<<endl<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		int i = 0;
		while (pactual->cadena[i]!='\0') {
			cout<<pactual->cadena[i];
			i++;
		}
		cout<<endl;
		pactual=pactual->psigue;
	}
	
	//Guardado
	ofstream f("CADENAS.TXT");
	
	pactual = pinicio;
	while (pactual!=NULL) {
		int i = 0;
		while (pactual->cadena[i]!='\0') {
			f<<pactual->cadena[i];
			i++;
		}
		f<<endl;
		pactual=pactual->psigue;
	}
	f.close();
	
	return 0;
	
}