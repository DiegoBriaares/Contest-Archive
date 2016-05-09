#include "guessnum.h"
#include <bits/stdc++.h>
using namespace std;
// Funciones disponibles:
//   adivinar(i) (o guess(i))
bool ha[1000002];
void eval(int n) {
	srand(time(NULL));
	int a=1,b=n+1,y,uso;
	n=rand()%b+a;
	while(1){
		y=guess(n);
		switch(y){
				case 0:
					answer(n);
					break;
				case -1:
					b=(a+b-1)-n;
	         		a=n+1;
	         		n=rand()%b+a;
					break;
				case 1:
					uso=(a+b-1)-n;
					b-=uso;
					n=rand()%b+a;
					break;
			}
	}
}
