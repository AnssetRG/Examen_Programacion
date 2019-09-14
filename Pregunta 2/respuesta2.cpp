#include <iostream>
#include <string>
#include <iostream>

using namespace std;

struct Rec{
    int x;
    int y;
    int height;
    int width;
    Rec(int x, int y, int width, int height){
        this-> x = x;
        this-> y = y;
        this-> width = width;
        this-> height = height;
    }
};

void print(int val){
    cout<<val<<endl;
}

void Collision(Rec *rec1, Rec *rec2){
    print(rec1->x);
    print(rec2->x);
    print(rec2->width);
    print(rec2->x + rec2->width);
    if(rec1->x < rec2->x + rec2->width &&
    rec2->x < rec1->x + rec1->width &&
    rec1->y < rec2->y + rec2->height &&
    rec2->y < rec1->y + rec1->height){
        cout<<"Collision detected"<<endl;
    }else{
        cout<<"None collision detected"<<endl;
    }
}

int main()
{
    Rec *rectangleA = new Rec(2,1,4,2);
    Rec *rectangleB = new Rec(8,3,4,2);
    Rec *rectangleC = new Rec(4,4,2,4);
    Collision(rectangleA, rectangleB);
    Collision(rectangleA, rectangleC);
    Collision(rectangleC, rectangleB);
}