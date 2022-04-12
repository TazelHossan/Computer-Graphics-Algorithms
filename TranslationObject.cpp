#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;
void Draw(int*,int*,int);
void Translate(int*,int*,int,int,int);

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int n, x[100],y[100],Tx, Ty;

    cout<<"Enter the no of sides of a polygon/line"<<endl;
    cin>>n;

    cout<<"Enter coordinates:(x,y)"<<endl;
    for(int i =0; i<n; i++)
    {
        cin>>x[i]>>y[i];

    }
    cout<<"Enter the distance (Tx, Ty)"<<endl;
    cin>>Tx>>Ty;
    getchar();


    setcolor(YELLOW);
    Draw(x,y,n);
    Translate(x,y,n,Tx,Ty);
    setcolor(WHITE);
    Draw(x,y,n);
    getchar();

    return 0;

}

void Draw(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {
        line(x[i],y[i],x[ (i+1)%n ], y[ (i+1)%n ]);
    }
}
void Translate(int x[],int y[],int n,int Tx, int Ty)
{
    for(int i =0; i<n; i++)
    {
        x[i] = x[i]+Tx;
        y[i] = y[i]+Ty;

    }
}
