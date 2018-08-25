#include <bits/stdc++.h>
using namespace std;
#define MAX 100002

int N;
long double F,c[MAX];

bool sepuede1(long double t){
	long double s=0;
	for (int i=0; i<N-1; i++){
		if (F*t>=c[i]||s>=c[i]-F*t) s+=F*t-c[i];
		else s=0;
	}
	if (F*t>=c[N-1]||s>=c[N-1]-F*t) return true;
	else return false;
}

bool sepuede2(long double t){
	long double s=0;
	for (int i=0; i<N; i++){
		if (F*t>=c[i]||s>=c[i]-F*t) s+=F*t-c[i];
		else return false;
	}
}

long double binaria1(){
	long double a=0,b=1e9;
	while (1){
		if (b-a<=1e-7) return (a+b)/(double)2;
		if (sepuede1((a+b)/(double)2)) b=(a+b)/(double)2;
		else a=(a+b)/(double)2;
	}
}
long double binaria2(){
	long double a=0,b=1e9;
	while (1){
		if (b-a<=1e-7) return (a+b)/(double)2;
		if (sepuede2((a+b)/(double)2)) b=(a+b)/(double)2;
		else a=(a+b)/(double)2;
	}
}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>N>>F){
		for(int i=0;i<N;i++){
			cin>>c[i];
		}
		cout<<setprecision(8)<<fixed<<binaria1()<<" "<<binaria2()<<"\n";
	}
}
