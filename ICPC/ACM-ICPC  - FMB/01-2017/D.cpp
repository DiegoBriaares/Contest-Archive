#include <bits/stdc++.h>
using namespace std;
    int main (){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t,n;
        cin>>t;
        while(t--){
            cin>>n;
            int r=0;
            for(int i=1;i<n;i++){
                if(n%i==0)r+=i;
            }
            if(r==n)cout << "perfect"<<endl;
            if(r<n)cout << "deficient"<<endl;
            if(r>n)cout << "abundant"<<endl;
        }
    }
