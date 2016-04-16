#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y){
	HANDLE d;
	d=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD f;
	f.X= x;
	f.Y= y;
	SetConsoleCursorPosition(d,f);
}
int hash[101],i,uso;
int main(){
	system("color 0A");
	char z;
	int n,y,a=0,b=101,salir,uso;
	y=4;
	salir=0;
	srand(time(NULL));
	n=rand()%b+a;
	do{
	system("cls");
	gotoxy(35,6);
	printf("%d",n);
	gotoxy(10,4);
	printf("1.Es mi edad.");
	gotoxy(10,6);
	printf("2.Tengo mas.");
	gotoxy(10,8);
	printf("3.Tengo menos.");
	gotoxy(7,y);
	printf("-->");
	z=getch();
	if(z==-32)
	z=getch();
	switch(z){
		case 80:
			if(y==8)
			y=4;
			else
			y=y+2;
			break;
		case 72:
			if(y==4)
			y=8;
			else
			y=y-2;
		    break;
		case 13:
			switch(y){
				case 4:
					salir=1;
					break;
				case 6:
					b=(a+b-1)-n;
	         		a=n+1;
	         		n=rand()%b+a;
					break;
				case 8:
					uso=(a+b-1)-n;
					b-=uso;
					n=rand()%b+a;
					break;
			}
	break;				
	}
	}while(salir==0);
}
