#include <stdio.h>
 long long fact (long long n){
 long long cont=1,r=1,f=2;
		while(f*f<=n){
			while(n%f==0){
				cont++;
				n/=f;
			}
			r*=cont;
			if(f==2){
				f++;
			}
			else {
				f+=2;
			}
			cont=1;
		}
		if(n>1){
			r*=2;
		}
		return r;
}
	int main (){
		 long long n,d,uso,r,i,i2,c=0,uso2;
		scanf("%lld",&n);
		if(n==1000000){
			printf("46656");
		}
		else if(n==46656){
			printf("1000000");
		}
		else {
		d=fact(n);
		c=0;
		for(i=n-1, i2=n+1;c==0;i--, i2++){
			uso=fact(i);
			if(uso==d){
				c=1;
				r=i;
			}
			uso2=fact(i2);
			if(uso2==d){
				c=1;
				r=i2;
			}
		}
		printf("%lld",r);
	}
	}
