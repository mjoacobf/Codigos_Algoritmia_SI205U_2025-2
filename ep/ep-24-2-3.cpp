#include<iostream>
#include<cmath>

using namespace std;

/*float distancia(float x1, float x2, float y1, float y2) {
	float sumacuad = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	float dist = pow(sumacuad,0.5);
	return dist;
}*/

float area(float x1, float x2, float x3, float y1, float y2, float y3) {
	float sum = x1*y2 + x2*y3 + x3*y1;
	float res = y1*x2 + y2*x3 + y3*x1;
	float S = abs((sum - res)*0.5);
	return S;
}

int main() {
	bool convexo = false;
	float x[4];
	float y[4];
	do {
		cout<<"A: ";cin>>x[0]>>y[0];
		cout<<"B: ";cin>>x[1]>>y[1];
		cout<<"C: ";cin>>x[2]>>y[2];
		cout<<"D: ";cin>>x[3]>>y[3];
		
		
		convexo = true;
		for (int i = 0; i<4; i++) {
			float areatotal = area(x[(i+1)%4],x[(i+2)%4],x[(i+3)%4],y[(i+1)%4],y[(i+2)%4],y[(i+3)%4]);
			
			float s1 = area(x[i],x[(i+1)%4],x[(i+2)%4],y[i],y[(i+1)%4],y[(i+2)%4]);
			float s2 = area(x[i],x[(i+2)%4],x[(i+3)%4],y[i],y[(i+2)%4],y[(i+3)%4]);
			float s3 = area(x[i],x[(i+3)%4],x[(i+1)%4],y[i],y[(i+3)%4],y[(i+1)%4]);
			//cout<<areatotal<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
			if (areatotal == s1 + s2 + s3) {
				convexo = false;
			};
		}
		
		if (not convexo) cout<<"No es convexo, ingrese los datos nuevamente"<<endl;
	} while (not convexo);
	
	
	float px,py;
	cout<<"P: ";cin>>px>>py;
	
	//Verificar que este adentro de uno de los dos triangulos ABC o ACD
	
	float areatotal1 = area(x[0],x[1],x[2],y[0],y[1],y[2]);
			
	float s1 = area(px,x[0],x[1],py,y[0],y[1]);
	float s2 = area(px,x[1],x[2],py,y[1],y[2]);
	float s3 = area(px,x[0],x[2],py,y[0],y[2]);
	
	
	
	float areatotal2 = area(x[0],x[2],x[3],y[0],y[2],y[3]);
			
	float s4 = area(px,x[0],x[2],py,y[0],y[2]);
	float s5 = area(px,x[2],x[3],py,y[2],y[3]);
	float s6 = area(px,x[0],x[3],py,y[0],y[3]);
	
	if (areatotal1 == s1 + s2 + s3 or areatotal2 == s4 + s5 + s6) {
		cout<<"El punto se encuentra dentro de la region";
	} else cout<<"El punto se encuentra fuera de la region";

	return 0;
}