#include <bits/stdc++.h>

using namespace std;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N,M,a,sum=0;
  while(cin>>N>>M){
  	int B;
  	int amount=0;
  	int aux;
  	for(int j=0;j<M;j++){
		cin>>B>>aux;
		sum=0;
	  	for(int i=1;i<N;i++){
	  		cin>>a;
	  		sum+=a;
		}
		B-=sum;
		if(B>0){
			if(B>9){
				if(B>99){
					if(B>999){
						if(B>9999){
							amount+=10000;
						}
						else {
							amount+=1000;
						}
					}
					else {
						amount+=100;
					}
				}
				else {
					amount+=10;
				
				}
			}
			else {
				amount+=1;
			}
		}
		if(B-aux>=0)amount-=aux;
	}
	cout<<amount<<endl;
  }
  return 0;
}
