#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
int n;
int p;
string s,r;
char pila[MAX];
vector<pair<char,int> >v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>s;
		n=s.size();
		for(int i=0;i<n;i++){
			v.push_back(make_pair(s[i],i));
		}
		sort(v.begin(),v.end());
		for(int i=0,j=0;i<n;i++){
			while(p&&pila[p]<=v[i].first)r+=pila[p--];
			if(j>v[i].second)continue;
			while(j<v[i].second)pila[++p]=s[j++];
			if(j==v[i].second)r+=v[i].first,j++;
		}
		while(p)r+=pila[p--];
		cout << r<<"\n";
	}
