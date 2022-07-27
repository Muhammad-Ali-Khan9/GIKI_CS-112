#include<iostream>
#include<conio.h>
#include<cmath>

#define pi 3.14159
using namespace std;

class donut{
//r1 sets the radius of the circle
//r2 sets the x-coodinate of the centre of the circle in xy-plane
int r1,r2;
//A defines rotation along x-axis
//B defines rotation along z-axis
float A,B;

//i=thetha
//j=phi
float i,j;
char b[100][100];

float sinthetha;
float costhetha;
float sinphi;
float sinA;
float sinB;
float cosphi;
float cosA;
float cosB;
//x and y are parametric equasions of circle
float X;
float Y;
//X3,Y3,and Z3 are equations to get points for a rotating donut
float X3;
float Y3;
float Z3;

//depth gives the distance from viewer to the donut
float depth;
//XC and YC represent projections of a 3-D donut on a 2-D screen
int XC;
int YC;
//Luminance represnt light that falls on donut
int Luminance;
                
public:

donut()
{

r1=1;
r2=2;
A=0;
B=0;

}


void donut_creator()
{

while(1){

  //intializing 2-D array with spaces
    for(int i=0;i<100;i++)
      for(int j=0;j<100;j++)
      {
        b[i][j]=' ';
      }    
//creating the donut
    for(float i=0;i<2*pi;i+=0.07)
    {
        for(float j=0;j<2*pi;j+=0.03)
            {
                 sinthetha=sin(i);
                 costhetha=cos(i);
                 sinphi=sin(j);
                 sinA=sin(A);
                 sinB=sin(B);
                 cosphi=cos(j);
                 cosA=cos(A);
                 cosB=cos(B);

                 X=r2+r1*costhetha;
                 Y=r1*sinthetha;

                 X3=(X*(cosB*cosphi+sinA*sinB*sinphi)-(Y*cosA*sinB));
                 Y3=(X*(cosphi*sinB-cosB*sinA*sinphi)+(Y*cosA*cosB));
                 Z3=(cosA*X*sinphi)+(Y*sinA);

                  //depth
                  //K2 is 5
                depth=1/(Z3+5);
                  //40 and 30 in XC and YC are respectively shifting the centre points of the donut 
                  //K1=25
                 XC=40+30*depth*X3; 
                 YC=30+30*depth*Y3;

                 Luminance=8*((cosphi*costhetha*sinB)-(cosA*costhetha*sinphi)-(sinA*sinthetha)+(cosB*(cosA*sinthetha-costhetha*sinA*sinphi)));
                
                //if depth is very small we won't bother to plot it
                //depending on Luminanace value (between 0-11) we use the character based on the Luminanace  
                if(depth>0)
                b[XC][YC]=".,-~:;=!*#$@"[Luminance>0 ? Luminance : 0 ];
                
            }

     }
    //printing the donut
    for(int i=0;i<100;i++)
      for(int j=0;j<100;j++)
      {
        putchar(b[i][j]);
      }

    A+=0.09;
    B+=0.05;
    putchar('\n');
    //clearing screen after the donut is printed 
    system("CLS");
}

}


};


int main()
{
donut d;

d.donut_creator();
return 0;

}