#include <bits/stdc++.h>
using namespace std;
#define MAX 1004

pair<char,pair<int,int> > p[MAX];
bool visitados[MAX];
string s;

void swap(int &a, int &b){
	int aux;
	aux=a;
	a=b;
	b=aux;
}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int x,y;
	stack<pair<int,int> > pila;
	pair<int,int> a;
	
	cin>>s;
	for (int i=0; i<s.size(); i++){
		p[i].first=s[i];
	}
	sort(p,p+s.size());
	for (int i=0; i<s.size(); i++){
		for (int j=0; j<s.size(); j++){
			if (p[j].first==s[i]&&visitados[j]==false){
				p[i].second.first=j;
				visitados[j]=true;
				break;
			}
		}
	}
	for (int i=0; i<s.size(); i++){
		p[i].second.second=i;
		visitados[i]=false;
	}
	for (int i=0; i<s.size(); i++){
		if (visitados[i]==false){
			visitados[i]=true;
			x=i;
			y=p[x].second.first;
			while(visitados[y]==false){
				visitados[y]=true;
				pila.push(pair<int,int>(x,y));
				x=y;
				y=p[x].second.first;
			}
		}
	}
	while (!pila.empty()){
		a=pila.top();
		pila.pop();
		for (int i=0; i<s.size(); i++){
			if (p[i].second.second==a.first) x=i;
			if (p[i].second.second==a.second) y=i;
		}
		if (p[x].first>=p[y].first) cout<<x+1<<" "<<y+1<<"\n";
		else cout<<y+1<<" "<<x+1<<"\n";
		swap(p[x],p[y]);
	}
	return 0;
}
