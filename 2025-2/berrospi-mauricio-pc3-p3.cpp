#include<iostream>

using namespace std;

string text(char cad[], int i, char simb, bool reemp) {
	if (cad[i]=='\0') return "";
	if ((cad[i]-'a'>=0 and cad[i]-'a'<=26) or (cad[i]-'A'>=0 and cad[i]-'A'<=26)) {
		reemp = false;
		return cad[i]+text(cad,i+1,simb,reemp);
	} else if ((cad[i] - '0' >= 0 and cad[i] - '0'<=9)) {
		if (reemp) {
			return simb + text(cad, i+1, simb, reemp);
		} else {
			return cad[i] + text(cad, i+1, simb, reemp);
		}
	} else {
		simb = cad[i];
		reemp = true;
		return simb + text(cad, i+1, simb, reemp);
	}
}

int main() {
	char cad[200];
	cin.getline(cad,200);
	int i = 0;
	char simb = ' ';
	bool reemp = false;
	cout<<text(cad,i, simb, reemp);
	
	return 0;
}