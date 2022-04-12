#include<iostream>
#include<graphics.h>
#include<string>
#include<math.h>
void Draw(int*,int*,int);
void DrawTranslate(int*,int*,int);
void Translate(int*,int*,int,int,int);
void Scale(int*,int*,int,int,int);
void ClockWiseRotatation(int*,int*,int,float);
void AntiClockWiseRotatation(int*,int*,int,float);
void ReflectionOnXAxis(int*,int*,int);
void ReflectionOnYAxis(int*,int*,int);
void ReflectionOnOrigin(int*,int*,int);
void ReflectionOnLine(int*,int*,int);
void ShearOnXAxis(int*,int*,int,int);
void ShearOnYAxis(int*,int*,int,int);
void FillingPolygon();
int n, x[100],y[100];
using namespace std;
int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,(char*)"");

 line(getmaxx()/2,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

    while(1)
    {
        int ch ;
        again:
        //cleardevice();
        cout<<"1. Polygon"<<endl;
        cout<<"2. Color Filling"<<endl;
        cout<<"3. Transformatio"<<endl;
        cout<<"4. Zoom in"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"============================"<<endl;
        cin>>ch;
        if(ch == 1)
        {
            //int n, x[100],y[100];

            cout<<"Enter the no of sides of a polygon/line"<<endl;
            cin>>n;

            cout<<"Enter coordinates:(x,y)"<<endl;
            for(int i =0; i<n; i++)
            {
                cin>>x[i]>>y[i];

            }

            getchar();


            setcolor(YELLOW);
            Draw(x,y,n);
            getchar();
        }
        if(ch==2)
        {
            FillingPolygon();

        }
        if(ch==3)
        {
            while(1)
            {
                int ch0 ;
                //again:
                //cleardevice();
                cout<<"1. Translation"<<endl;
                cout<<"2. Scaling"<<endl;
                cout<<"3. Rotation"<<endl;
                cout<<"4. Reflection"<<endl;
                cout<<"5. Shearing"<<endl;
                cout<<"6. Exit"<<endl;
                cout<<"============================"<<endl;
                cin>>ch0;

                /// start translation
                if(ch0==1)
                {
                    int Tx, Ty;

                    //cout<<"Enter the no of sides of a polygon/line"<<endl;
                    //cin>>n;

                    //cout<<"Enter coordinates:(x,y)"<<endl;
                    //for(int i =0; i<n; i++)
                    //{
                        //cin>>x[i]>>y[i];

                    //}
                    cout<<"Enter the distance (Tx, Ty)"<<endl;
                    cin>>Tx>>Ty;
                    getchar();


                    setcolor(YELLOW);
                    //Draw(x,y,n);
                    Translate(x,y,n,Tx,Ty);
                    setcolor(WHITE);
                    DrawTranslate(x,y,n);
                    getchar();
                } /// End Translation

                /// Start Scaling
                if(ch0==2)
                {
                    //int n, x[100],y[100];
                    float Sx, Sy;
                    //cout<<"Enter the no of sides of a polygon/line"<<endl;
                    //cin>>n;
                    //cout<<"Enter coordinates:(x,y)"<<endl;
                    //for(int i =0; i<n; i++)
                    //{
                        //cin>>x[i]>>y[i];

                    //}
                    cout<<"Enter the scale factors (Sx, Sy)"<<endl;
                    cin>>Sx>>Sy;
                    getchar();


                    setcolor(YELLOW);
                    Draw(x,y,n);
                    Scale(x,y,n,Sx,Sy);
                    setcolor(WHITE);
                    Draw(x,y,n);
                    getchar();



                } /// End Scaling
                /// Start Rotation
                if(ch0==3)
                {
                    while(1)
                    {
                        int ch1;
                        cout<<"1.Rotation on Clockwise:"<<endl;
                        cout<<"2.Rotation on AntiClockwise:"<<endl;
                        cout<<"3.Break:"<<endl;
                        cout<<"======================"<<endl;
                        cin>>ch1;
                        if(ch1==1)
                        {
                            //cleardevice();
                            //int n, x[100],y[100];

                            float angle=0;

                            //cout<<"Enter the no of sides of a polygon/line"<<endl;
                            //cin>>n;
                            //cout<<"Enter coordinates:x,y"<<endl;
                            //for(int i =0; i<n; i++)
                            //{
                                //cin>>x[i]>>y[i];

                           // }
                            setcolor(YELLOW);
                            Draw(x,y,n);
                            cout<<"Enter the rotation angle:"<<endl;
                            cin>>angle;

                            angle=(angle*3.1416)/180;
                            getchar();

                            ClockWiseRotatation(x,y,n,angle);
                            setcolor(WHITE);
                            Draw(x,y,n);

                            getchar();
                        }

                        if(ch1==2)
                        {
                            //cleardevice();
                            //int n, x[100],y[100];

                            float angle=0;

                            //cout<<"Enter the no of sides of a polygon/line"<<endl;
                            //cin>>n;
                            //cout<<"Enter coordinates:x,y"<<endl;
                            //for(int i =0; i<n; i++)
                            //{
                                //cin>>x[i]>>y[i];

                            //}
                            setcolor(YELLOW);
                            Draw(x,y,n);
                            cout<<"Enter the rotation angle:"<<endl;
                            cin>>angle;

                            angle=(angle*3.1416)/180;
                            getchar();

                            AntiClockWiseRotatation(x,y,n,angle);
                            setcolor(WHITE);
                            Draw(x,y,n);

                            getchar();
                        }

                        if(ch1==3)
                        {
                            goto again;
                        }
                    }
                    getchar();
                    closegraph();
                }

                /// End Rotation
                /// Start Reflection
                if(ch0==4)
                {
                    while(1)
                    {
                        int ch2;
                        cout<<"1.Reflection on x-axis:"<<endl;
                        cout<<"2.Reflection on y-axis:"<<endl;
                        cout<<"3.Reflection on Origin:"<<endl;
                        cout<<"4.Reflection on line(y=x):"<<endl;
                        cout<<"5.Break:"<<endl;
                        cout<<"======================"<<endl;

                        cin>>ch2;

                        if(ch2==1)
                        {
                            //int n, x[100],y[100];

                            //cout<<"Enter the no of sides of a polygon/line"<<endl;
                            //cin>>n;
                            //cout<<"Enter coordinates:x,y"<<endl;
                            //for(int i =0; i<n; i++)
                            //{
                                //cin>>x[i]>>y[i];

                            //}

                            getchar();

                            //cleardevice();
                            setcolor(YELLOW);
                            Draw(x,y,n);
                            ReflectionOnXAxis(x,y,n);
                            setcolor(WHITE);
                            Draw(x,y,n);

                            getchar();
                        }///end x-axis

                        if(ch2==2)
                        {
                            //int n, x[100],y[100];

                            //cout<<"Enter the no of sides of a polygon/line"<<endl;
                            //cin>>n;
                            //cout<<"Enter coordinates:x,y"<<endl;
                            //for(int i =0; i<n; i++)
                            //{
                               //cin>>x[i]>>y[i];

                            //}

                            getchar();
                            //cleardevice();
                            setcolor(YELLOW);
                            Draw(x,y,n);
                            ReflectionOnYAxis(x,y,n);
                            setcolor(WHITE);
                            Draw(x,y,n);

                            getchar();
                        }///end y-axis

                        if(ch2==3)
                        {
                            //int n, x[100],y[100];

                            //cout<<"Enter the no of sides of a polygon/line"<<endl;
                            //cin>>n;
                            //cout<<"Enter coordinates:x,y"<<endl;
                            //for(int i =0; i<n; i++)
                            //{
                                //cin>>x[i]>>y[i];

                            //}
                            getchar();
                            //
                            //cleardevice();
                            setcolor(YELLOW);
                            Draw(x,y,n);
                            ReflectionOnOrigin(x,y,n);
                            setcolor(WHITE);
                            Draw(x,y,n);

                            getchar();
                        }///end origin

                        if(ch2==4)
                        {
                            //int n, x[100],y[100];

                            //cout<<"Enter the no of sides of a polygon/line"<<endl;
                            //cin>>n;
                            //cout<<"Enter coordinates:x,y"<<endl;
                            //for(int i =0; i<n; i++)
                            //{
                                //cin>>x[i]>>y[i];

                            //}

                            getchar();

                            //cleardevice();
                            setcolor(YELLOW);
                            Draw(x,y,n);
                            ReflectionOnLine(x,y,n);
                            setcolor(WHITE);
                            Draw(x,y,n);

                            getchar();
                        }///end Line

                        if(ch2==5)
                        {
                            goto again;
                        }
                    }
                    ///end while
                    getchar();
                    closegraph();

                }///end reflection
                /// Start Shear
                if(ch0==5)
                {
                    while(1)
                    {
                        int ch3;
                        cout<<"1.Shearing on x-axis:"<<endl;
                        cout<<"2.Shearing on y-axis:"<<endl;
                        cout<<"3.Break:"<<endl;
                        cout<<"======================"<<endl;
                        cin>>ch3;
                        if(ch3==1)
                        {
                            //int n, x[100],y[100]
                            int shy;

                            //cout<<"Enter the no of sides of a polygon/line"<<endl;
                            //cin>>n;
                            //cout<<"Enter coordinates:x,y"<<endl;
                            //for(int i =0; i<n; i++)
                            //{
                                //cin>>x[i]>>y[i];

                            //}
                            cout<<"Enter the shearing factor(shy)"<<endl;
                            cin>>shy;

                            getchar();
                            //cleardevice();
                            setcolor(YELLOW);
                            Draw(x,y,n);
                            ShearOnXAxis(x,y,n,shy);
                            setcolor(WHITE);
                            Draw(x,y,n);

                            getchar();
                        }///end x-axis

                        if(ch3==2)
                        {
                            //int n, x[100],y[100];
                            int shx;

                            //cout<<"Enter the no of sides of a polygon/line"<<endl;
                            //cin>>n;
                            //cout<<"Enter coordinates:x,y"<<endl;
                            //for(int i =0; i<n; i++)
                            //{
                                //cin>>x[i]>>y[i];

                            //}
                            cout<<"Enter the shearing factor(shx): "<<endl;
                            cin>>shx;

                            getchar();
                            //cleardevice();
                            setcolor(YELLOW);
                            Draw(x,y,n);
                            ShearOnYAxis(x,y,n,shx);
                            setcolor(WHITE);
                            Draw(x,y,n);

                            getchar();
                        }///end y-axis


                        if(ch3==3)
                        {
                            goto again;
                        }
                    }
                    ///end while
                    getchar();
                    closegraph();
                } /// End Shear

                if(ch0==6)
                {
                    exit(0);
                }
            } /// end while
        }
        if(ch==4)
        {
            //int n, x[100],y[100];
            float Sx, Sy;
            //cout<<"Enter the no of sides of a polygon/line"<<endl;
            //cin>>n;
            //cout<<"Enter coordinates:(x,y)"<<endl;
            //for(int i =0; i<n; i++)
            //{
                //cin>>x[i]>>y[i];

            //}
            cout<<"Enter the zooming factors (Sx, Sy)"<<endl;
            cin>>Sx>>Sy;
            getchar();


            setcolor(YELLOW);
            Draw(x,y,n);
            Scale(x,y,n,Sx,Sy);
            setcolor(WHITE);
            Draw(x,y,n);
            getchar();


        }
        if(ch==5)
        {
            exit(0);
        }


    }/// end outer while
    return 0;
}

void Draw(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {
        line(x[i],y[i],x[ (i+1)%n ], y[ (i+1)%n ]);
    }
}
void DrawTranslate(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {
        line(x[i],y[i],x[ (i+1)%n ], y[ (i+1)%n ]);
    }
    FillingPolygon();
}
void Translate(int x[],int y[],int n,int Tx, int Ty)
{
    for(int i =0; i<n; i++)
    {
        x[i] = x[i]+Tx;
        y[i] = y[i]+Ty;

    }
    //FillingPolygon();
}

void Scale(int x[],int y[],int n,int Sx, int Sy)
{
    for(int i =0; i<n; i++)
    {
        x[i] = x[0] + (int)( (float)(x[i]-x[0])*Sx );
        y[i] = y[0] + (int)( (float)(y[i]-y[0])*Sy );


    }
    FillingPolygon();
}
void ClockWiseRotatation(int x[],int y[],int n, float radian)
{
    float t1,t2;
    int xp,yp;
    cout<<" Enter pivot point(x,y):"<<endl;
    cin>>xp>>yp;
    for(int i=0; i<n; i++)
    {
        t1=x[i]-xp;
        t2=y[i]-yp;
        x[i]=xp+floor(t1*cos(radian)-t2*sin(radian));
        y[i]=yp+floor(t1*sin(radian)+t2*cos(radian));
    }
    FillingPolygon();
}


void AntiClockWiseRotatation(int x[],int y[],int n, float radian)
{
    float t1,t2;
    int xp,yp;
    cout<<" Enter pivot point(x,y):"<<endl;
    cin>>xp>>yp;
    for(int i=0; i<n; i++)
    {
        t1=x[i]-xp;
        t2=y[i]-yp;
        x[i]=xp+floor(t1*cos(radian)+t2*sin(radian));
        y[i]=yp+floor(-t1*sin(radian)+t2*cos(radian));
    }
     FillingPolygon();
}
void ReflectionOnXAxis(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {

        y[i]=-y[i]+200;

    }
     FillingPolygon();
}

void ReflectionOnYAxis(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {

        x[i]=-x[i]+200;

    }
     FillingPolygon();
}
void ReflectionOnOrigin(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {

        x[i]=-x[i]+200;
        y[i]=-y[i]+200;

    }
     FillingPolygon();
}

void ReflectionOnLine(int x[],int y[],int n)
{
    int tem[100];
    for(int i =0; i<n; i++)
    {

        tem[i]=x[i];

    }
    for(int i =0; i<n; i++)
    {

        x[i]=y[i];
        y[i]=tem[i];

    }
     FillingPolygon();
}


void ShearOnXAxis(int x[],int y[],int n,int shx)
{
    for(int i =0; i<n; i++)
    {

        x[i]=x[i]+shx*y[i];


    }
     FillingPolygon();
}

void ShearOnYAxis(int x[],int y[],int n,int shy)
{
    for(int i =0; i<n; i++)
    {

        y[i]=x[i]*shy + y[i];

    }
     FillingPolygon();
}

void FillingPolygon()
{
    int k=0,ymin=1000000,ymax=0,Y,dx,dy,xi[100],temp;

    float slope[100];

    //cout<<" Enter the number of vertices :"<<endl;

    //cin>>n;

    //cout<<" Enter the coordinates of vertices :"<<endl;

    for(int i=0; i<n; i++)

    {

        //cin>>x[i]>>y[i];

        if(y[i]>ymax)
        {
            ymax=y[i];
        }

        if(y[i]<ymin)
        {
            ymin=y[i];
        }

    }



    x[n]=x[0];
    y[n]=y[0];

    //draw polygon using all the edges

    for(int i=0; i<n; i++)

    {

        line(x[i],y[i],x[i+1],y[i+1]);

    }

    //

    for(int i=0; i<n; i++)

    {

        dx=x[i+1]-x[i];

        dy=y[i+1]-y[i];

        if(dy==0)
        {
            slope[i]=1.0;
        }


        if(dx==0)
        {
            slope[i]=0.0;
        }


        if(dx!=0 && dy!=0)
        {
            slope[i]=(float)dx/dy;
        }



    }

    for(int j=0; j<=ymax; j++)
    {

        int k=0;

        for(int i=0; i<n; i++)
        {

            if(((y[i]<=j) && (y[i+1]>j)) || ((y[i]>j) && (y[i+1]<=j)))
            {

                xi[k]=(int)(x[i]+slope[i]*(j-y[i]));

                k++;

            }

        }

        for(int m=0; m<k-1; m++)
        {

            for(int i=0; i<k-1; i++)
            {

                if(xi[i]>xi[i+1])
                {

                    temp=xi[i];

                    xi[i]=xi[i+1];

                    xi[i+1]=temp;

                }

            }

            setcolor(WHITE);

            for(int i=0; i<k; i+=2)
            {

                line(xi[i]+getmaxx()/2+80,j,xi[i+1]+1+getmaxx()/2+80,j);
                delay(10);

            }

        }

    }
    //getch();
}///end Polygon
