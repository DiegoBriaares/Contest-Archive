#include <bits/stdc++.h>
using namespace std;
#define MAX 50002
int n,m,idx=1,mix=1;
bool v[MAX];
    int main (){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin>>n>>m;
        int i,j,k,g,h,uso,iy;
        for(iy=1;iy<=m;iy++){
            cin>>g;
            if(g==1){
                cin>>h;
                k=0;
                //cout <<"R: "<<mix<<"\n";
                for(i=idx=mix,uso=0;i<=n;i++){
                	if(!v[i] and idx!=0)uso++;
                	else if(!v[i]){
                		idx=i;
                		uso++;
					}
                	else {
                		uso=0;
                		idx=0;
					}
                	if(uso==h){
                		for(j=idx;j<=i;j++)v[j]=true;
                		k++;
                		break;
					}
				}
				if(k==0)cout << 0<<"\n";
				else cout <<mix<<"\n";
				if(idx<=mix)mix=idx+h;
            }
            else {
                cin>>h>>uso;
                for(i=h;i<=uso;i++)v[i]=false;
                if(h<=mix)mix=h;
            }
        }
    }
