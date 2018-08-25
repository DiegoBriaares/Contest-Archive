#include <bits/stdc++.h>
#define  MAX 1000001

using namespace std;

unsigned long long cases,n;

unsigned long long primes[MAX], top;

unsigned long long factores[MAX], t;
unsigned long long exponentes[MAX];

bool usados[MAX];

void criba(){

    primes[top++] = 2;

    for(unsigned long long int i=3; i<1000; i++){

        if( !usados[i] ){

            primes[top++] = i;

            for(unsigned long long int j=i*i; j<MAX; j+=2*i){
                usados[j] = true;
            }

        }

    }

    for(unsigned long long int i = 1001; i<MAX; i+=2){
        if( !usados[i] ){
            primes[top++] = i;
        }
    }

}

void funcion(unsigned long long x, unsigned long long p){

    unsigned long long ans=p;

    while( x%ans==0 ){
        ans*=p;
    }

    ans/=p;

    factores[t++] = ans;
    exponentes[t-1] = p;

}

unsigned long long factoriza(unsigned long long x){

    t=0;

    for(int i=0; primes[i]*primes[i]<=x; i++){

        if( x%primes[i]==0 ){

            funcion(x, primes[i]);

            x/=factores[t-1];

        }

    }

    if(x!=1){
        factores[t++]  = x;
        exponentes[t-1]= x;
    }

    unsigned long long ans = 1;

    for(int i=0; i<t; i++){

        ans*=( ((factores[i]*exponentes[i])-1)/(exponentes[i]-1) );

    }

    return ans;

}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>cases;

    criba();

    while(cases--){

        cin>>n;

        unsigned long long ans = factoriza(n);

        if( ans<(2*n) ){
            cout << "deficient\n";
        }else if( ans==2*n ){
            cout << "perfect\n";
        }else{
            cout << "abundant\n";
        }

    }
}
