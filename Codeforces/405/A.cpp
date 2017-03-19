#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
ll a,b;
ll r;
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>a>>b;
   while(a<=b){
   	a*=3;
   	b*=2;
   	r++;
   }
   cout << r<<"\n";
}
