#include <bits/stdc++.h>
using namespace std;
#define MAX 262002
char base[MAX];
char query[MAX];
int n;
int q;
int m;
int p[200][MAX];
struct entry {
    int a,ba,x;
    bool operator <(const entry &b) const
        {
        if(a==b.a) return ba<b.ba;
        else return a<b.a;
        }
} v[MAX];
void tree(){
	for(int i=0;i<n;i++){
		if(base[i]>='A'&&base[i]<='Z')p[0][i]=base[i]-'A';
		else p[0][i]=base[i]-'a'+26;
	}
	int uso=1;
	for(int exp=1;(exp>>1)<n;uso++,exp<<=1){
		for(int i=0;i<n;i++){
			v[i].a=p[uso-1][i];
			v[i].ba=i+exp<n?p[uso-1][i+exp]:-1;
			v[i].x=i;
		}
		sort(v,v+n);
		for(int i=0;i<n;i++){
			p[uso][v[i].x]=i>0&&v[i].a==v[i-1].a&&v[i].ba==v[i-1].ba?p[uso][v[i-1].x]:i;
		}
	}
}
int sub(int md){
	int i,j;
	for(i=v[md].x,j=0;j<m&&i<n;i++,j++){ 
		if(base[i]==query[j]&&j==(m-1))return 0;
		if(base[i]<query[j])return -1;
		else if(base[i]>query[j])return 1;
	}
	return -1;
}
bool solve(){
	int in=0,fin=n-1;
	int mid;
	int r;
	while(in<=fin){
		mid=(in+fin)/2;
		r=sub(mid);
		if(r==0)return true;
		if(r<0)in=mid+1;
		else fin=mid-1;
	}
	return false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>base){
			n=strlen(base);
			tree();
			cin>>q;
			for(int i=0;i<q;i++){
				cin>>query;
				m=strlen(query);
				if(solve())cout <<"y\n";
				else cout << "n\n";
			}
		}
	}
