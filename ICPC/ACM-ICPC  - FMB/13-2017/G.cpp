#include <bits/stdc++.h>
using namespace std;
#define MAX 2000002
int res;
int n,k;
int h[MAX];
int dp[MAX];
int tipos[MAX];
vector<vector<int> >arr,v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>n>>k){
			res=(1<<30);
			arr.clear();
			v.clear();
			for(int i=0;i<=n;i++)dp[i]=0;
			for(int i=1;i<=k;i++)tipos[i]=h[i]=0;
			for(int i=0;i<n;i++){
				int n_0;
				cin>>n_0;
				vector<int>aux;
				for(int j=0;j<n_0;j++){
					int x;
					cin>>x;
					aux.push_back(x);
					tipos[x]=true;
				}
				v.push_back(aux);
			}
			arr=v;
			for(int i=0;i<v.size();i++){
				arr.push_back(v[i]);
			}
			for(int i=0;i<arr.size();i++){
				if(i)dp[i]=dp[i-1];
				dp[i]+=arr[i].size();
			}
			bool en=false;
			for(int i=1;i<=k;i++){
				if(!tipos[i]){
					cout << "-1\n";
					en=true;
					break;
				}
			}
			if(en)continue;
			int i=-1,c=0;
			int idx=-1;
			while(idx<n-1){
				idx++;
				while(i<((int)arr.size())&&c<k){
					if(c<k)i++;
					for(int j=0;j<arr[i].size();j++){
						if(!h[arr[i][j]]){
							c++;
						}
						h[arr[i][j]]++;
					}
				}
			
				
				if(c==k)
				res=min(res,dp[i]-(idx?dp[idx-1]:0));
				for(int j=0;j<arr[idx].size();j++){	
					h[arr[idx][j]]--;
					if(h[arr[idx][j]]<1){
						c--;
					}
				}
				
			}
			cout << res<<"\n";
		}	
	}
