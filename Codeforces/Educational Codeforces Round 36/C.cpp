#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 999999999999999999
bool ok;
int h[102];
string a,b,res2="";
stack<char>res;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b;
		if(a.size()<b.size()){
			sort(a.begin(),a.end());
			reverse(a.begin(),a.end());
			cout << a<<"\n";
			return 0;
		}
		for(int i=0;i<a.size();i++){
			h[a[i]-'0']++;
		}
		for(int i=0;i<b.size();i++){
			if(h[b[i]-'0']&&!ok){
				h[b[i]-'0']--;
				res.push(b[i]);
				res2+=b[i];
			}
			else if(!ok){
				for(int j=(b[i]-'0')-1;j>=0;j--){
					if(h[j]){
						h[j]--;
						char k=(char)(j+'0');
						res.push(k);
						res2+=k;
						ok=true;
						break;
					}
				}
				if(!ok)break;
			}
			else {
				for(int j=9;j>=0;j--){
					if(h[j]){
						h[j]--;
						char k=(char)(j+'0');
						res.push(k);
						res2+=k;
						break;
					}
				}
			}
		}
		if(res.size()<a.size()||res2>b){
			ok=false;
			for(int i=res.size()-1;i>=0;i--){
				h[res.top()-'0']++;
				res.pop();
				for(int j=9;j>=0;j--){
					if(h[j]&&j<(b[i]-'0')){
						h[j]--;
						char k=(char)(j+'0');
						res.push(k);
						ok=true;
						break;
					}
				}
				if(ok)break;
			}
			for(int i=res.size();i<b.size();i++){
				for(int j=9;j>=0;j--){
					if(h[j]){
						h[j]--;
						char k=(char)(j+'0');
						res.push(k);
						ok=true;
						break;
					}
				}
			}
		}
		res2="";
		while(!res.empty()){
			res2+=res.top();
			res.pop();
		}
		string aux="";
		reverse(res2.begin(),res2.end());
		ok=false;
		for(int i=0;i<res2.size();i++){
			if(!ok&&res2[i]=='0')continue;
			ok=true;
			cout << res2[i];
		}
		
		cout << "\n";
	}
