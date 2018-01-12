#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
ll n,sum;
string v;
string res="",res2="";
void solve(){
	int idx=0;
	if(res.size()==0){
		cout << "-1\n";
		return;
	}
		while(idx<res.size()&&res[idx]=='0')idx++;
		if(idx>=res.size()){
			cout << "0\n";
			return;
		}
	while(idx<res.size())cout << res[idx++];
	cout << "\n";
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		n=v.size();
		for(int i=0;i<n;i++){
			int aux=v[i]-'0';
			sum+=aux;
		}
		if(sum%3==0){
			cout << v<<"\n";
			return 0;
		}
		if(sum%3==1){
			int q=-1,q2=-1;
			for(int i=n-1;i>0;i--){
				int aux=v[i]-'0';
				if(aux%3==1){
					q=i;
					break;
				}
			}
			if((v[0]-'0')%3==1&&v[1]!='0'&&n>1){
				q=0;	
			}
			if(q!=-1){
				for(int i=0;i<n;i++){
					if(i!=q)res.push_back(v[i]);
				}
				solve();
				return 0;
			}
			for(int i=n-1;i>0;i--){
				int aux=v[i]-'0';
				if(aux%3==2){
					if(q==-1)q=i;
					else {
						q2=i;
						break;
					}
				}
			}
			if(q!=-1&&q2!=-1){
				for(int i=0;i<n;i++){
					if(i!=q&&i!=q2)res.push_back(v[i]);
				}
				solve();
				return 0;
			}
			//Ahora hasta >=0
			q=-1,q2=-1;
			for(int i=n-1;i>=0;i--){
				int aux=v[i]-'0';
				if(aux%3==1){
					q=i;
					break;
				}
			}
			if(q!=-1){
				for(int i=0;i<n;i++){
					if(i!=q)res2.push_back(v[i]);
				}
				res=res2;
				solve();
				return 0;
			}
			for(int i=n-1;i>=0;i--){
				int aux=v[i]-'0';
				if(aux%3==2){
					if(q==-1)q=i;
					else {
						q2=i;
						break;
					}
				}
			}
			if(q!=-1&&q2!=-1){
				for(int i=0;i<n;i++){
					if(i!=q&&i!=q2)res2.push_back(v[i]);
				}
				res=res2;
				solve();
				return 0;
			}
			cout << "-1\n";
		}
		else if(sum%3==2){
			int q=-1,q2=-1;
			for(int i=n-1;i>0;i--){
				int aux=v[i]-'0';
				if(aux%3==2){
					q=i;
					break;
				}
			}
			if((v[0]-'0')%3==2&&v[1]!='0'&&n>1){
				q=0;	
			}
			if(q!=-1){
				for(int i=0;i<n;i++){
					if(i!=q)res.push_back(v[i]);
				}
				solve();
				return 0;
			}
			for(int i=n-1;i>0;i--){
				int aux=v[i]-'0';
				if(aux%3==1){
					if(q==-1)q=i;
					else {
						q2=i;
						break;
					}
				}
			}
			if(q!=-1&&q2!=-1){
				for(int i=0;i<n;i++){
					if(i!=q&&i!=q2)res.push_back(v[i]);
				}
				solve();
				return 0;
			}
			// Ahora hasta >=0
			q=-1,q2=-1;
			for(int i=n-1;i>=0;i--){
				int aux=v[i]-'0';
				if(aux%3==2){
					q=i;
					break;
				}
			}
			if(q!=-1){
				for(int i=0;i<n;i++){
					if(i!=q)res2.push_back(v[i]);
				}
				res=res2;
				solve();
				return 0;
			}
			for(int i=n-1;i>=0;i--){
				int aux=v[i]-'0';
				if(aux%3==1){
					if(q==-1)q=i;
					else {
						q2=i;
						break;
					}
				}
			}
			if(q!=-1&&q2!=-1){
				for(int i=0;i<n;i++){
					if(i!=q&&i!=q2)res2.push_back(v[i]);
				}
				res=res2;
				solve();
				return 0;
			}
			cout << "-1\n";
		}
	}
