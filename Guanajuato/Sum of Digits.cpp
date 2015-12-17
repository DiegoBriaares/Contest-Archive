#include<bits/stdc++.h>
using namespace std;
long long solve(long long n){
    if(n<9)return (n*(n+1))/2;
    long long uso,i;
    for(uso=n;uso/10!=0;uso/=10){
        i++;
    }
    int p=pow(10,i);
    return ((uso*45*i*p/10)+ uso*(uso-1)*p/2+uso*(n%p+1)+solve(n%p));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b;
    cin>>a>>b;
    while(a!=-1 || b!=-1){
        cout<<solve(b)-solve(a-1)<<"\n";
        cin>>a>>b;
    }
}
