#include <bits/stdc++.h>
using namespace std;
#define MAX 11
#define ll long long
ll r,p,cont;
int v[MAX];
ll solve(ll a,ll k){
    int r=(a/p)%10;
    if(r==k){
        return (a%p)+1+(a/(p*10))*p;
    }
    if(r<k){
        return (a/(p*10))*p;
    }
    return (a/(p*10)+1)*p;
}
ll give(ll mid,int idx){
	cont=0;
			p=1;
			while(p<mid){
        		cont+=solve(mid,idx);
        		p*=10;
    		}
    		return cont;
}
int bs(int ocrr,int idx){
	ll in=1,fin=(10000000000000000),mid;
		while(in<fin){
			mid=(in+fin)/2;
    		//cout <<"USO: "<<mid<<" "<<cont<<" "<<idx<<"\n";
			if(give(mid,idx)<=ocrr){
				in=mid+1;
			}
			else fin=mid;
		}
		while(give(fin,idx)>ocrr)fin--;
		return fin;
}
ll solve0(ll n)
{
   
    return ((9*(n-1)-1)*(pow(10,n-1)+1))/9;
}
int bs2(int ocrr){
	ll in=1,fin=(10000000000000000),mid;
		while(in<fin){
			mid=(in+fin)/2;
    		//cout <<"USO: "<<mid<<" "<<cont<<" "<<idx<<"\n";
			if(solve0(mid)<=ocrr){
				in=mid+1;
			}
			else fin=mid;
		}
		while(solve0(fin)>ocrr)fin--;
		return fin;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		for(int i=0;i<=9;i++){
			cin>>v[i];
		}
		ll n;
		r=bs2(v[0]);
		for(int i=1;i<=9;i++){
			n=bs(v[i],i);
			//cout <<"R: "<< i<<" "<<n<<"\n";
			r=min(r,n);
		}
		cout << r<<"\n";
	}
