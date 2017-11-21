#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
int n;
int a,b,c;
int v[MAX];
int arr[MAX];
vector<int>d,t;
vector<pair<int,int> >res;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
			arr[i]=v[i];
			if(v[i]==1)a++;
			else if(v[i]==2)b++;
			else c++;
		}	
		c=(a)+b;
		b=(a);
		a=0;
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			if(v[i]==1&&arr[i]>1){
				if(arr[i]==2){
					d.push_back(i);
				}
				else t.push_back(i);
			}
		}
		int p1,p2;
		p1=p2=0;
		for(int i=0;i<n;i++){
			if(arr[i]==1&&v[i]==2&&p1<d.size()){
				swap(v[i],v[d[p1]]);
				res.push_back(make_pair(i,d[p1++]));
			}
			else if(arr[i]==1&&v[i]==3&&p2<t.size()){
				swap(v[i],v[t[p2]]);
				res.push_back(make_pair(i,t[p2++]));
			}
		}
		p1=p2=0;
		d.clear();
		t.clear();
		for(int i=0;i<n;i++){
			if(v[i]==3&&arr[i]==2){
				t.push_back(i);
			}
		}
		for(int i=0;i<n;i++){
			if(v[i]==2&&arr[i]==3&&p1<t.size()){
				swap(v[i],v[t[p1]]);
				res.push_back(make_pair(i,t[p1++]));
			}
		}
		for(int i=b;a<b&&i<n;i++){
			while(a<b&&v[a]==1)a++;
			if(a<b&&v[i]==1){
				swap(v[a],v[i]);
				res.push_back(make_pair(a,i));
			}
		}
		for(int i=c;b<c&&i<n;i++){
			while(b<c&&v[b]==2)b++;
			if(b<c&&v[i]==2){
				swap(v[b],v[i]);
				res.push_back(make_pair(b,i));
			}
		}
		/*cout << "AUX: "<<a<<" "<<b<<"\n";
		cout << "RES:\n";
		for(int i=0;i<n;i++){
			cout << v[i]<<" ";
		}
		cout << "\n";*/
		cout << res.size()<<"\n";
		for(int i=0;i<res.size();i++){
			cout << res[i].first+1<<" "<<res[i].second+1<<"\n";
		}
	}
