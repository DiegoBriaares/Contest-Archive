#include <bits/stdc++.h>
using namespace std;
long long int M, N, A, D, F, C, num1, num2, num3;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> M >> N >> A >> D >> F >> C;
    num3 = ((((M*A)/__gcd(M, A))/A)*((((N*D)/__gcd(N, D))/D)))/__gcd(max((((M*A)/__gcd(M, A))/A), ((((N*D)/__gcd(N, D))/D))), min((((M*A)/__gcd(M, A))/A), ((((N*D)/__gcd(N, D))/D))));
    cout << num3;
}
