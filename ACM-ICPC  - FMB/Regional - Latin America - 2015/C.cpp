#include <bits/stdc++.h>

using namespace std;


long long v[200007][2];
long long acum[200007];

long long areaTriangulo(int i,int j){
	if(i==0||j==0)return 0;
	long long agregado=0;
	if( v[1][0]*v[j][1] + v[j][0]*v[i][1] + v[i][0]*v[1][1] > v[1][1]*v[j][0] + v[j][1]*v[i][0] + v[i][1]*v[1][0]){
		agregado=(v[1][0]*v[j][1] + v[j][0]*v[i][1] + v[i][0]*v[1][1]) - (v[1][1]*v[j][0] + v[j][1]*v[i][0] + v[i][1]*v[1][0]);
	}
	else {
		agregado=(v[1][1]*v[j][0] + v[j][1]*v[i][0] + v[i][1]*v[1][0]) - (v[1][0]*v[j][1] + v[j][0]*v[i][1] + v[i][0]*v[1][1]); 
	}
	return agregado;
}



int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ///Indexare desde 1
  int N;
  while(cin>>N){
  
	  for(int i=1;i<=N;i++){
	  	cin>>v[i][0]>>v[i][1];
	  }
	  for(int i=N+1;i<=N+N;i++){
	  	v[i][0]=v[i-N][0];
	  	v[i][1]=v[i-N][1];
	  }
	  ///Ya guarde los vertices y su copia
	  ///Recuerda que los vertices son dados en orden antihorario
	  ///Hare el precalculo
	  acum[1]=0;
	  acum[2]=0;
	  for(int i=3;i<=N;i++){
	  	acum[i]=acum[i-1];
	  	long long agregado=0;
		if( v[1][0]*v[i-1][1] + v[i-1][0]*v[i][1] + v[i][0]*v[1][1] > v[1][1]*v[i-1][0] + v[i-1][1]*v[i][0] + v[i][1]*v[1][0]){
			agregado=(v[1][0]*v[i-1][1] + v[i-1][0]*v[i][1] + v[i][0]*v[1][1]) - (v[1][1]*v[i-1][0] + v[i-1][1]*v[i][0] + v[i][1]*v[1][0]);
		}
		else {
			agregado=(v[1][1]*v[i-1][0] + v[i-1][1]*v[i][0] + v[i][1]*v[1][0]) - (v[1][0]*v[i-1][1] + v[i-1][0]*v[i][1] + v[i][0]*v[1][1]);
		}
		///cout<<agregado<<"\n";
		acum[i]+=agregado;
	
	  }
	 
	  for(int i=N+1;i<=N+N;i++)acum[i]=acum[i-N];
	  ///Ya tengo el acumulado y su copia en acum
	  ///Ahora iterare todos los vertices y buscare la respuesta optima para cada uno
	  long long Mitad=acum[N]/2;
	  long long resp=-1;
	  long long Carol, Carla;
	  long long area=0;
	  for(int i=1;i<=N;i++){
	  	///Dado el vertice i
	  	int ini=i;
	  	int fin=i+N-1;
	  	
	  	while(ini<fin-1){
	  		int m=(ini+fin)/2;
			///Si el area de i hasta m es menor al area total sobre dos (piso) entonces subo ini a m+1
			if(acum[m]>acum[i])area=acum[m]-acum[i];
			else area=acum[i]-acum[m];
			area=area-areaTriangulo(i,m); 
			if(m<=N){
			
				if(area<Mitad)ini=m;       ///Hacer que el area sea menor a la mitad no sirve, necesito otro indicador
				else fin=m;
			}
			else {
				area=acum[N]-area;
				if(area<Mitad)ini=m;       ///Hacer que el area sea menor a la mitad no sirve, necesito otro indicador
				else fin=m;
			}
			///cout<<area<<" "<<ini<<" "<<fin<<" "<<m<<" "<< i<< "\n";
		}
		///Ya se que elegir ini me minimiza la diferencia
		///cout<<acum[N];
		///return 0;
		
		///m = ini o m=fin es la buena, pivoteando en i 
		
		///cout<<acum[N]<<"\n\n";
		
		int m=fin;
		if(acum[m]>acum[i])area=acum[m]-acum[i];
		else area=acum[i]-acum[m];
		area=area-areaTriangulo(i,m);
		///cout<<"Papu "<<area<<"\n";
		long long dif=abs(acum[N]-area-area);
		///cout<<dif<<"\n";
		long long areaux=area;
		m=ini;
		if(acum[m]>acum[i])area=acum[m]-acum[i];
		else area=acum[i]-acum[m];
		area=area-areaTriangulo(i,m);
		if(abs(acum[N]-area-area)>dif){
			area=areaux;
			///cout<<"Papu "<<area<<"\n";
		}
		
		
		
		if(abs(area+area-acum[N]) > resp){
			Carol=area;
			Carla=acum[N]-area;
			resp=abs(Carol-Carla);
		}
		
		
		
		
		
	  }
	  cout<<max(Carol,Carla)<<" "<<min(Carla,Carol)<<"\n";
	  
  
  }
}
