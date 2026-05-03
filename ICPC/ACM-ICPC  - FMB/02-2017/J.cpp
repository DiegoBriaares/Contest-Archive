#include <bits/stdc++.h>
using namespace std;
#define MAX 2000001
#define ll long long
#define MOD 1000000007
ll res=1,s=0;
ll n,x,y;
ll pot[MAX];
 ll sum[MAX];
bool c[MAX+1];
void criba(){
    for(unsigned long long i=2; i<=1500; i++){
        if( !c[i] ){
            for(unsigned long long j = i; j<MAX; j+=i) c[j]++;
        }
    }

    for(unsigned long long i=2; i<MAX; i++){

        if( !c[i] ){

            for(unsigned long long j = i; j<MAX; j+=i) c[j]++;

        }

    }


}
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t;
        criba();
        pot[0]=1;
        for(int i=0;i<MAX;i++){
                res*=2;
                res%=MOD;
                pot[i+1]=res;
            }
            for(int i=2;i<MAX;i++){
                sum[i]=sum[i-1]+c[i];
                sum[i]%=MOD;
            }
        while(cin>>n>>x>>y){
        if(n==0&&y==0&&x==0)return 0;
            cout << ((pot[y-x-1]*sum[y-x])%MOD)<<"\n";

        }
    }
