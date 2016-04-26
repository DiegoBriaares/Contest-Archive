#include <stdio.h>
#include <time.h>
#include <stdlib.h>
	int main (){
		srand(time(NULL));
		int i,j,k,n,g,h;
		n=rand()%31+45;
		k=75-n+1;
		for(i=0;i<10;i++){
			while(n!=(45+k-1)){
				n=rand()%k+45;
			}
			printf("%d\n",n);
			k--;
			if(k<=0)k=31;
		}
		
}
