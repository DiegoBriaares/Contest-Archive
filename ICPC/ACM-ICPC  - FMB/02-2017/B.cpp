#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,k;
ll s,x;
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        while(cin>>n>>k){
        s=0;
        if(n==0&&k==0)return 0;
        for(int i=0;i<n;i++){
            cin>>x;
            s+=x;
        }
        cout << (k/s)<<"\n";
        }

    }
