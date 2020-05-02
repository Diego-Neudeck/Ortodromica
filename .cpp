/*La ortodromica es el camino mas corto (distancia) entre dos puntos de
la superficie terrestre, es el arco del circuito maximo que los une,
menor de 180 grados, si el radio de la tierra es de 6361km la ortodromica
es d=radio*deltatita, donde 
deltatita=arcos(sen(latA)*sen(latB)+cos(latA)*cos(latB)*cos(longmax-longmin))*/

#include <iostream>
#define pi 3.14159
using namespace std;
double seno(float x);
double cos(float x);
double arccos(float x);
double potencia(float x,int y);
double factorial(float a);
int main(int argc, char *argv[]) {
	float latA,latB,lonA,lonB,alfa,aux1;
	double ort,si,sf,ci,cf,ca,arc,distancia;
	cout<<"La ortodromica es el camino mas corto (distancia) entre dos puntos de la superficie terrestre,"<<endl;
	cout<<"es el arco del circuito maximo que los une, menor de 180 grados. Para calcular la ortodromica:"<<endl<<endl;
	do{
		cout<<"ingrese latitud a A en grados"<<endl;
		cin>>aux1;
		latA=(aux1*pi)/180.0;
	}while(latA<(-pi/1.99) || latA>(pi/1.99));
	
	do{
		cout<<"ingrese la latitud de B en grados"<<endl;
		cin>>aux1;
		latB=(aux1*pi)/180.0;
	}while(latB<(-pi/1.99) || latB>(pi/1.99));
	
	do{
		cout<<"ingrese la longitud de A en grados"<<endl;
		cin>>aux1;
		lonA=(aux1*pi)/180.0;
	}while(lonA<(-pi/1.99) || lonA>(pi/1.99));
	
	do{
		cout<<"ingrese la longitud de B en grados"<<endl;
		cin>>aux1;
		lonB=(aux1*pi)/180.0;
		
	}while(lonB>(pi/1.99) || lonB<(-pi/1.99));
	
	if(lonA>lonB){
		alfa=lonA-lonB;
	}
	else{
	
		alfa=lonB-lonA;
	}

	si=seno(latA);
	
	sf=seno(latB);
	
	ci=cos(latA);
	
	cf=cos(latB);
		
	ca=cos(alfa);
	
	arc=(si*sf+ci*cf*ca);
	
	ort=arccos(arc);
	
	distancia=ort*6371;
	cout<<endl<<"la distancia ortodromica es: "<<distancia<<" :)"<<endl;
	return 0;
}

//las funciones seno, coseno, arcoseno, potencia y factorial 
//fueron calculadas con funciones, aunque se podria calcular
//con la libreria cmath. Esto se hizo con fin didactico

double seno(float x){
	
	float a,aux4;
	double sen=0,aux1,aux2,aux3;
	

	for(a=0;a<6;a++){

		aux1=potencia(-1,a);
	
		aux4=2*a+1;
		aux2=factorial(aux4);
	
		aux3=potencia(x,(2*a+1));
		sen=sen+((aux1*aux3)/aux2);
	}

	return(sen);
}

double cos(float x){
	int a;
	double cos=0,aux1,aux2,aux3;
	for(a=0;a<6;a++){
		aux1=potencia(-1,a);
		aux2=factorial(2*a);
		aux3=potencia(x,2*a);
		cos=cos+((aux1*aux3)/aux2);
	}

	return(cos);
}

double arccos(float x){
	int a;
	
	double ac=0,arccos=0,aux1,aux2,aux3,aux4,aux5;
	for(a=0;a<6;a++){
		aux1=factorial(2*a);
		aux2=potencia(x,(2*a+1));
		aux3=potencia(4,a);
		aux4=potencia(factorial(a),2);
		aux5=2*a+1;
		ac=ac+((aux1*aux2)/(aux3*aux4*aux5));
	}
	arccos=(pi/2)-ac;
	
	return(arccos);
}

double factorial(float a){
	double fac=a;
	float b=a;
	if(a!=0 && a!=1){
	do{
		b=b-1;
		fac=fac*b;
	}while(b>1);
	}
	else
	fac=1;

	return(fac);
}
//pepe
double potencia(float x,int y)
   {
   double acum=1;
   for(int i=1;i<=y;i++)
      acum*=x;
      if(x=0)
      acum=1;
   return(acum);
   }
//diego neudeck

//hola lo vagociciicaacs