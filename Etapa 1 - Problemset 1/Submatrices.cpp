#include <bits/stdc++.h>
using namespace std;

	int main (){
		int ren,col,r,c,uso,uso2,cont=0,i,j,uso3,uso4;
		cin >>ren>>col;
		int m[ren][col];
		bool ma[ren][col];
		for(i=0;i<ren;i++){
			for(j=0;j<col;j++){
				cin >>m[i][j];
				ma[i][j]=false;
			}
		}
		cin>>r>>c;
		int b[r][c];
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				cin >>b[i][j];
			}
		}
		for(i=0;i<ren;i++){
			for(j=0;j<col;j++){
			//BUSQUEDA
			if((j+(c-1))<col&&(i+(r-1))<ren&&m[i][j]==b[0][0]){
			uso3=i;
			uso4=j;
				for(uso=0;uso<r;uso++){
					uso4=0+j;
					for(uso2=0;uso2<c;uso2++){
						if(m[uso3][uso4]==b[uso][uso2]){
							cont++;
						}
						else {
							uso2=c;
						}
						uso4++;
					}
					uso3++;
				}
				if(cont==(r*c)){
					uso3=i;
					uso4=j;
				for(uso=0;uso<r;uso++){
					uso4=j;
					for(uso2=0;uso2<c;uso2++){
						ma[uso3][uso4]=true;
						uso4++;
					}
					uso3++;
				}	
				}
				cont=0;
			}
		}
		}
		for(i=0;i<ren;i++){
			for(j=0;j<col;j++){
			cout<<ma[i][j]<<" ";
			}
			cout <<"\n";
		}
	}
