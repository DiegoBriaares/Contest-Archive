#include <cstdio>
#define MAX 1000000
using namespace std;

long long int N, t;

bool c[MAX+1];

long long primes[MAX], top=0;

void criba(){

    primes[top] = 2; top++;

    for(long long i=3; i<1000; i+=2){

        if( !c[i] ){

            primes[top] = i; top++;

            for(long long j = i*i; j<MAX; j+=2*i) c[j] = true;

        }

    }

    for(long long i=1001; i<MAX; i+=2){

        if( !c[i] ){

            primes[top] = i; top++;

        }

    }

}

long long phi( long long n ){

    long long i = 0, pf = primes[i], ans = n;

    while( pf*pf<=n ){

        if( n%pf==0 ) ans-=ans/pf;

        while( n%pf==0 ) n/=pf;

        pf = primes[++i];

    }

    if( n!=1 ) ans-=ans/n;

    return ans;

}


int main(){

    long long int t, ans;

    criba();

    scanf( "%lld", &t );

    while(t--){

        scanf( "%lld", &N );

        ans = phi(N);

        printf( "%lld %lld", ans, (ans/2) );

        if( ans%2==1 ){
            printf( ".5000\n" );
        }else{
            printf( ".0000\n" );
        }

    }
}
