#include <bits/stdc++.h>
    using namespace std;

#define MAX 500203
#define ll long long

ll Acu[MAX], Acu2[MAX], dp[MAX][20];
ll a;
ll n, k;

ll costo(ll I, ll J){
    I++; J++;
    return Acu2[J] - Acu2[I] + (I-1)*(Acu[J] - Acu[I]);
}

void res(ll r, ll a, ll b, ll opa, ll opb){
    if (a>b) return;

    ll m=(a+b)/2,posicion=-1,M=1e12,v;

    for (ll i=opa; i<=min(opb,m); i++){
        v=(i-1>= 0 ? dp[i-1][r-1] : 0) + costo(i,m);
        if (v<M){
            M=v;
            posicion=i;
        }
    }
    dp[m][r]=M;
    res(r,a,m-1,opa,posicion);
    res(r,m+1,b,posicion,opb);
}

int main(){

    //Checar costo;

    /*for(ll i=n-1; i>=0; i--){
        for(ll j=1; j<=k; j++){
            for(ll h=(j>1 ? : ); h)
        }
    }*/

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a;
        Acu[i+1] = Acu[i] + a;
        Acu2[i+1] = Acu2[i] + a*i;
    }


    for(int i=0; i<=n; i++)
        cout << Acu[i] << " ";
    cout << "\n";
    for(int i=0; i<=n; i++)
        cout << Acu2[i] << " ";
    cout << "\n";

    for (ll i=0; i<n; i++) dp[i][1]=costo(0,i);

    for (ll i=2; i<=k; i++) res(i,0,n-1,0,n-1);


    // Solve the problem
    cout <<  dp[n-1][k] << "\n";

    // Write output
    //printf("%d\n", answer);


    for (int i=0; i<n; i++){
        for (int j=0; j<=k; j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }


    return 0;
}
