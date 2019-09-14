#include <iostream>
#include <string>

using namespace std;

struct Rec{
    int x,y;
    int height, width;
    int Ox, Oy, Fx, Fy;
    Rec(int x, int y, int width, int height){
        this-> x = x;
        this-> y = y;
        this-> width = width;
        this-> height = height;
        Ox = x - width/2;
        Fx = x + width/2;
        Oy = y - height/2;
        Fy = y + width/2;
    }
};

void Collision(Rec *rec1, Rec *rec2){
    if(rec1->Ox < rec2->Fx &&
    rec2->Ox < rec1->Fx &&
    rec1->Oy < rec2->Fy &&
    rec2->Oy < rec1->Fy){
        cout<<"Collision detected"<<endl;
    }else{
        cout<<"None collision detected"<<endl;
    }
}

int main()
{
    Rec *rectangleA = new Rec(2,1,4,2);
    Rec *rectangleB = new Rec(8,3,4,2);
    Rec *rectangleC = new Rec(4,3,2,4);
    Collision(rectangleA, rectangleB);
    Collision(rectangleA, rectangleC);
    Collision(rectangleC, rectangleB);
}