#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,k,t, aux;
ll v[MAX];

bool busca(int x, int a, int b){

    int m;

    while( a<=b ){

        m = (a+b)/2;

        if( v[m]==x ){
            return true;
        }
        if( v[m]<x ){
            a = m+1;
        }else{
            b = m-1;
        }

    }

    return false;

}

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin>>t;
        while(t--){
            cin>>n>>k;
            cin>>v[0];
            for(int i=1;i<n;i++){
                cin>>aux;
                v[i]=v[i-1]+aux;
            }
            cout << "Yes.\n";

        }
    }
