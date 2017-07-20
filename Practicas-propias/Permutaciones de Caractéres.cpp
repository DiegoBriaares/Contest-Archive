#include <bits/stdc++.h>
using namespace std;
int n;
string v;
vector<char>lib;
vector<string>arr;
map<char,bool>app;
map<char,bool>us;
map<char,char>conv;
map<string,bool>memo;
bool prim(char a,char b){
	for(int i=0;i<n;i++){
		if(v[i]==b)return false;
		if(v[i]==a)return true;
	}
}
bool men(string a,string b){
	if(a.size()<b.size()){
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){
				return prim(a[i],b[i]);
			}
		}
		return true;
	}
	else {
		for(int i=0;i<b.size();i++){
			if(a[i]!=b[i]){
				return prim(a[i],b[i]);
			}
		}
		return false;
	}
}
bool cmp(string a,string b){
	return men(a,b);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		getline(cin,v);
		n=v.size();
		for(int i=0;i<n;i++)app[v[i]]=true;
		for(int i=33;i<=126;i++){
			if(!app[(char)(i)])lib.push_back((char)(i));
		}
		int p=0;
		app.clear();
		for(int i=0;i<n;i++){
			if(app[v[i]]){
				us[lib[p]]=true;
				conv[lib[p]]=v[i];
				v[i]=lib[p];
				p++;
			}
			app[v[i]]=true;
		}
		for(int i=1;i<(1<<n);i++){
			string aux="";
			for(int j=0;j<n;j++){
				if((i&(1<<j)))aux+=v[j];
			}
			arr.push_back(aux);
		}
		sort(arr.begin(),arr.end(),cmp);
		cout << " \n";
		for(int i=0;i<arr.size();i++){
			for(int j=0;j<arr[i].size();j++){
				if(us[arr[i][j]])arr[i][j]=conv[arr[i][j]];
			}
			cout << arr[i]<<"\n";
		}
	}
