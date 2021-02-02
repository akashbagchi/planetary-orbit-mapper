#include<process.h>
#include<fstream.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#define G 6.674e-11


class Sys
{
	long double M, m, L, E, major, minor, Vi, Ri;
	float e;

	public:


		long double maj_access()
		{
		return major;
		}



		long double min_access()
		{
		return minor;
		}



		long double factor_access()
		{
		long double n=Ri;

		int no=0;
			 for (;;)
			 {
			 n=n/10;
				  if (n<1)
				  break;
				  else
				  ++no;

			 }

		return no-2;
		}



		void in()
		{
			cout<<endl<<"Enter mass of the sun (kg): ";
			cin>>M;
			cout<<endl<<"Enter mass of the planet (kg): ";
			cin>>m;
			cout<<endl<<"Enter experimentally determined radius of closest approach (m): ";
			cin>>Ri;
			cout<<endl<<"Enter experimentally determined velocity (m/s): ";
			cin>>Vi;


		}



		void calc_parameters()
		{
			major=Ri;
			L=m*Ri*Vi;
			E=(0.5*m*Vi*Vi)-((G*M*m)/Ri);
			e=sqrt(1+((2*E*L*L)/(m*m*m*G*G*M*M)));
			cout<<"e:"<<e;
		}









		/*void plot(float ang, long double r)
		{
		double s_rad=r/(pow(10,9));
		long x=220+(int)(s_rad*cos(ang));
		long y=220-(int)(s_rad*sin(ang));
		circle(x,y,1);
		}*/





		void trajectory()
		{

			cout<<"\n"<<"\n";
			float i,j;
			long double rad;
			fstream trj;
			trj.open("position.txt",ios::app);
			long double r1, r2;
			for(i=0;i<=6.3;i+=0.1)
			{
				j=cos(i);
				rad=(Ri*Ri*Vi*Vi)/((1+(e*j))*G*M);
				trj<<i<<","<<rad<<"  ";
					 if(i==0)
					 r1=rad;
					 if (i<3.2&&i>3.1)
					 r2=rad;

			  //	plot(i,rad);

			}
			cout<<"r1:"<<r1<<" r2:"<<r2;
			major=(r1+r2)/2;
			minor=sqrt(r1*r2);
			cout<<"major:"<<major<<" minor:"<<minor<<"\n";


		trj.close();

		/*fstream trj0;
		trj0.open("position.txt", ios::in);
		char str[10];
			 while (trj0.getline(str,10,' '))
			 {
			 cout<<str<<" ";
			 }

		trj0.close();*/


		}

			 /*	void orbit()            // DYNAMIC
		{
		//fstream trj,orbit;
		//trj.open("positions.txt", ios::in);
		//orbit.open("orbit.txt", ios::out);

		int minor=4;

			 for (int t=0;t<10;++t)
			 {
			 float ang;
			 ang=atan((minor/major)*tan(2*L*t)/(m*major*minor));
			 cout<<t<<":"<<ang<<" ";

			 }

		}*/

		/*void orbit0()               //  STEP BY STEP INCREMENT
		{
		fstream trj, orbit;
		trj.open("positions.txt", ios::in);
		orbit.open("orbit.txt", ios::out);

		float dt=(0.01*Ri)/Vi;
		float const_A=(0.01*Ri*Ri*0.5)/dt;
		char str[10];

			 while (trj.getline((str),10,':'))
			 {


			 }


		}*/

};


void main()
{

	clrscr();
	remove("position.txt");
	int flag=0, choice;
	Sys planet;
	cout<<"Welcome! This is the work of Dhruv Joshi and Akash Bagchi of Class 12-B, DPS Bangalore South \n";
	cout<<"\nThe following program is an attempt to model the orbit of a planet in a given planetary system.\nThe system under consideration will consist of one central star and one orbiting planet.";
	cout<<"\nPress 1 to begin\tPress 2 to terminate\n";

	do{
		cin>>choice;

		switch(choice)
		{
		case 1:
			break;
		case 2: exit(1);
			break;
		default: cout<<"\n Invalid input. Try again.. ";
			flag=1;
			break;
		//Switch case in while loop reruns the choice segment until a valid input is received.
		}
	}
	while(flag==1);

	planet.in();
	planet.calc_parameters();
	planet.trajectory();
	long double ma, mi;
	ma=(int)(planet.maj_access()/pow(10,planet.factor_access()));
	mi=(int)(planet.min_access()/pow(10,planet.factor_access()));
	cout<<"ma:"<<ma<<" mi:"<<mi;
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode,"");
	setbkcolor(BLACK);
	setcolor(WHITE);
	ellipse(220,220,0,360,ma,mi);
	getch();
	//planet.orbit();
	closegraph();
	getch();
	getch();
	getch();
}
