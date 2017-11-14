#include <bits/stdc++.h>
using namespace std;
#define MAX 500002
#define ll long long
ll n,r;
bool ok;
string v,res,ans;
bool ist[MAX],ciclo;
bool memo[100002];
deque<char>cola;
pair<char,char>h[30];
void dfs1(int nodo){
	if(memo[nodo]){
		ciclo = true;
		return;
	}
	memo[nodo] = true;
	char m=(char)(nodo+'a');
	ok=true;
	ans.push_back(m);
	if(h[nodo].second!='0'){
		dfs1(h[nodo].second);
		
	}
	memo[nodo]=false;
}
void dfs(int nodo){

	char m=(char)(nodo+'a');
	ok=true;
	ans.push_back(m);
	cout << m;
	if(h[nodo].second!='0')dfs(h[nodo].second);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		res="";
		for(int i=0;i<26;i++){
			h[i].first='0';
			h[i].second='0';
		}
		for(int i=0;i<n;i++){
			cin>>v;
			for(int j=0;j<v.size();j++){
				ist[v[j]-'a']=true;
				
				if(j<v.size()-1&&h[v[j]-'a'].second=='0'){
					h[v[j]-'a'].second=v[j+1]-'a';
				}
				else if(j<v.size()-1&&h[v[j]-'a'].second!='0'){
					if(h[v[j]-'a'].second!=v[j+1]-'a'){
						cout << "NO\n";
						return 0;
					}
				}
				if(j>0&&h[v[j]-'a'].first=='0'){
					h[v[j]-'a'].first=v[j-1]-'a';
				}
				else if(j>0&&h[v[j]-'a'].first!='0'){
					if(h[v[j]-'a'].first!=v[j-1]-'a'){
						cout << "NO\n";
						return 0;
					}
				}
			}
		}
		for(int i=0;i<26;i++){
			if(h[i].first==h[i].second&&h[i].first!='0'){
				cout << "NO\n";
				return 0;
			}
		}
		for(int i=0; i<26; i++){
			ciclo = false;
			dfs1(i);
			if(ciclo){
				cout << "NO";
				return 0;
			}
		}
		for(int i=0;i<26;i++){
			if(ist[i]&&h[i].first=='0'&&h[i].second=='0'){
				char aq=(char)(i+'a');
				ok=true;
				res+=aq;
				ans.push_back(aq);
				cout << aq;
			}
			ciclo = false;
			if(h[i].first=='0'&&h[i].second!='0')dfs(i);
			if(ciclo){
				cout << "NO";
				return 0;
			}
		}
		return 0;
		cout << ans;
		return 0;
	
		if(!ok){
			cout << "NO\n";
		}
		else {
			cout << res<<"\n";
		}
	}
