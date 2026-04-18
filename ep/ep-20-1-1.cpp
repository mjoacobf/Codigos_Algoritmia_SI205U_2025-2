#include<iostream>

using namespace std;

int main() {
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	
	do {
		cout<<"n1: ";cin>>n1;
	} while (n1<=0 or n1>=16);
	do {
		cout<<"n2: ";cin>>n2;
	} while (n2<=0 or n2>=16);
	do {
		cout<<"n3: ";cin>>n3;
	} while (n3<=0 or n3>=16);
	do {
		cout<<"n4: ";cin>>n4;
	} while (n4<=0 or n4>=16);
	
	int bin1 = 0;
	int bin2 = 0;
	int bin3 = 0;
	int bin4 = 0;
	
	int conteo = 1;
	int t = n1;
	while (t>0) {
		int c = t%2;
		bin1+=c*conteo;
		conteo*=10;
		
		t-=c;
		t/=2;
	}
	
	conteo = 1;
	t = n2;
	while (t>0) {
		int c = t%2;
		bin2+=c*conteo;
		conteo*=10;
		
		t-=c;
		t/=2;
	}
	
	conteo = 1;
	t = n3;
	while (t>0) {
		int c = t%2;
		bin3+=c*conteo;
		conteo*=10;
		
		t-=c;
		t/=2;
	}
	
	conteo = 1;
	t = n4;
	while (t>0) {
		int c = t%2;
		bin4+=c*conteo;
		conteo*=10;
		
		t-=c;
		t/=2;
	}
	
	cout<<"Numeros en binario: "<<endl<<bin1<<endl<<bin2<<endl<<bin3<<endl<<bin4<<endl;
	
	int newbin1 = 0;
	int newbin2 = 0;
	int newbin3 = 0;
	int newbin4 = 0;
	
	int c1 = bin1%10;
	int c2 = bin2%10;
	int c3 = bin3%10;
	int c4 = bin4%10;
	
	newbin1 = c1*1000 + c2*100 + c3*10 + c4;
	
	bin1-=c1;
	bin2-=c2;
	bin3-=c3;
	bin4-=c4;
	
	bin1/=10;
	bin2/=10;
	bin3/=10;
	bin4/=10;
	
	c1 = bin1%10;
	c2 = bin2%10;
	c3 = bin3%10;
	c4 = bin4%10;
	
	newbin2 = c1*1000 + c2*100 + c3*10 + c4;
	
	bin1-=c1;
	bin2-=c2;
	bin3-=c3;
	bin4-=c4;
	
	bin1/=10;
	bin2/=10;
	bin3/=10;
	bin4/=10;
	
	c1 = bin1%10;
	c2 = bin2%10;
	c3 = bin3%10;
	c4 = bin4%10;
	
	newbin3 = c1*1000 + c2*100 + c3*10 + c4;
	
	bin1-=c1;
	bin2-=c2;
	bin3-=c3;
	bin4-=c4;
	
	bin1/=10;
	bin2/=10;
	bin3/=10;
	bin4/=10;
	
	c1 = bin1%10;
	c2 = bin2%10;
	c3 = bin3%10;
	c4 = bin4%10;
	
	newbin4 = c1*1000 + c2*100 + c3*10 + c4;
	
	cout<<"Al girar:"<<endl<<newbin1<<endl<<newbin2<<endl<<newbin3<<endl<<newbin4<<endl;
	
	conteo = 1;
	t = 0;
	while (newbin1 > 0) {
		int digito = newbin1%10;
		t+=digito*conteo;
		conteo*=2;
		newbin1/=10;
	}
	cout<<t<<endl;
	
	conteo = 1;
	t = 0;
	while (newbin2 > 0) {
		int digito = newbin2%10;
		t+=digito*conteo;
		conteo*=2;
		newbin2/=10;
	}
	cout<<t<<endl;
	
	conteo = 1;
	t = 0;
	while (newbin3 > 0) {
		int digito = newbin3%10;
		t+=digito*conteo;
		conteo*=2;
		newbin3/=10;
	}
	cout<<t<<endl;
	
	conteo = 1;
	t = 0;
	while (newbin4 > 0) {
		int digito = newbin4%10;
		t+=digito*conteo;
		conteo*=2;
		newbin4/=10;
	}
	cout<<t<<endl;
}