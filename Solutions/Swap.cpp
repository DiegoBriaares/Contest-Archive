#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,n2;
main (){
ios_base::sync_with_stdio(0);
cin>>n>>n2;
n^=n2,n2^=n,n^=n2;
cout << n<<" "<<n2<<"\n";
}
