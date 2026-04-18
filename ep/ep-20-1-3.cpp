#include<iostream>

using namespace std;

int main() {
	int coord[8];
	
	for (int i = 0; i<8; i++) {
		
		int x = 0;
		int y = 0;
		
		do {
			cout<<i+1<<" x:";cin>>x;
		} while (x<1 or x>8);
		
		do {
			cout<<i+1<<" y:";cin>>y;
		} while (y<1 or y>8);
		
		x--;
		y--;
		
		coord[i] = x*10 + y;
	}
	
	bool ataca = false;
	
	for (int i = 0; i<8; i++) {
		for (int j = 7; j>i; j--) {
			int x1 = coord[i]/10;
			int x2 = coord[j]/10;
			int y1 = coord[i]%10;
			int y2 = coord[j]%10;
			
			if (x1 == x2 or y1 == y2 or x1 - y1 == x2 - y2 or x1 + y1 == x2 + y2) {
				ataca = true;
				cout<<"La reina "<<i+1<<" ataca a la reina "<<j+1<<endl;
			}
		}
	}
	
	if (not ataca) {
		cout<<"Nadie ataca a nadie.";
	}
	return 0;
}