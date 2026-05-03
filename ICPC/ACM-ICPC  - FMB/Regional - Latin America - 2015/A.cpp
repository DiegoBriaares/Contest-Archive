#include <bits/stdc++.h>

using namespace std;


int visit[20];
int visitaux[20];
int vecresp[20];
int t;
int vec[20];
void imprime(){
	for(int i=0;i<t;i++){
		cout<<vecresp[i];
	}
	cout<<"\n";
}

int main () {
  	ios_base::sync_with_stdio(0);
  	cin.tie(0);
	cout.tie(0);
	string num;
	
	while(cin>>num){	
		
		t=num.size();
		for(int i=0;i<t;i++)vec[i]=num[i]-'0';
		bool auxi=true;
		for(int i=0;i<t;i++){
			visitaux[vec[i]]++;
			if(visitaux[vec[i]]>2){
				auxi=false;
				break;
			}
		}
		if(auxi==true){
			cout<<num<<endl;
			
			for(int i=0;i<t;i++){
				vecresp[i]=0;
				vec[i]=0;
			}
			for(int i=0;i<10;i++){
				visit[i]=0;
				visitaux[i]=0;
			}
		}
		else {
			for(int k=0;k<10;k++)visitaux[k]=0;
			for(int i=0;i<t;i++){
				int x=num[i]-'0';
				///cout<<x<<" ";
				for(int j=x-1;j>=0;j--){
					if(visit[j]<2){
						///Mi respuesta cambia, actualizo
						for(int k=0;k<i;k++)vecresp[k]=vec[k];
						vecresp[i]=j;
						/// Mi indice chingon
						int ind=9;
						for(int k=0;k<10;k++)visitaux[k]=visit[k];
						visitaux[j]++;
						for(int k=i+1;k<t;k++){
							while(visitaux[ind]>1)ind--;
							vecresp[k]=ind;
							visitaux[ind]++;
						}
						///Ya esta mi respuesta
						break;
					}
				}
				///imprime();
				visit[x]++;
				if(visit[x]>2)break;
				for(int k=0;k<10;k++)visitaux[k]=0;
			}
			
			int indi=0;
			while(vecresp[indi]==0)indi++;
			for(int i=indi;i<t;i++){
				cout<<vecresp[i];
			}
			cout<<endl;
			
			
			for(int i=0;i<t;i++){
				vecresp[i]=0;
				vec[i]=0;
			}
			for(int i=0;i<10;i++){
				visit[i]=0;
				visitaux[i]=0;
			}
		}
	}
}
