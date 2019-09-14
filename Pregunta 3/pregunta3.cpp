#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
 
using namespace std;

struct coordenada{
	int x, y;
	coordenada(int x, int y){
		this->x = x;
		this->y = y;
	}
};

coordenada* generar_puntos(int r, int x, int y){
	coordenada *dummy = new coordenada(rand() % (2*x) -x, rand() % y + 1);
	return dummy;
}
 
int hipotenusa (int x,int y)  {
    return sqrt (pow(x,2)+pow(y,2));
 }
 
bool comparar(coordenada* c1, coordenada* c2){
	return c1->y - c1->x > c2->y - c2->x;
}

 
void Dibujar(int r, int Pos_x, int Pos_y, int n){
	
	cout<<"Radio: "<<r<<endl;
	cout<<"X: "<<Pos_x<<endl;
	cout<<"Y: "<<Pos_y<<endl;
	
    int width = Pos_y;
    int length = Pos_x;
    
	cout<<"\nPuntos: "<<endl;
	coordenada *puntos [n];
	vector<coordenada *> puntos_validos;
	for(int i=0; i<n; i++){
		puntos[i] = generar_puntos(r,length,width);
		cout<<i+1<<") "<<puntos[i]->x<<" "<<puntos[i]->y<<endl;
		if(hipotenusa(puntos[i]->x, puntos[i]->y) <= r){
			puntos_validos.insert(puntos_validos.begin(),puntos[i]);
		}
	}
	sort(puntos_validos.begin(),puntos_validos.end(),comparar);
	
	cout<<"\n*: perimetro"<<endl;
	cout<<"o: punto"<<endl;
	cout<<"#: punto en perimetro\n"<<endl;
 
 	bool saltar = false;
    for (int y = width; y >= 0; y--)  {
        for (int x = -length; x <= length;x++)  {
        	saltar = false;
        	for(int i = 0; i < puntos_validos.size(); i++){
        		if(y == puntos_validos[i]->y && x == puntos_validos[i]->x){
        			if (hipotenusa(x,y)==r) cout<<"#";
					else cout<<"o";
					puntos_validos.erase(puntos_validos.begin()+i);
					saltar = true;
					break;
				}
			}
			if(saltar) continue;
            if (hipotenusa(x,y)==r) cout << "*";
            else cout << " ";
 
         }
         cout << "\n";
     }
     cin.get();
}

int main ( )  {
	srand (time(NULL));
	int x; cout <<"Centro x:"; cin >> x;
	int y; cout <<"Centro y:"; cin >> y;
	int r; 
	do{
		cout <<"Radio r:"; cin >> r;
	}while(r > x || r > y);
	int n; cout <<"Puntos n:"; cin >> n;
	system("cls");
	
	Dibujar(r,x,y,n);
	 return 0;
 }
 
