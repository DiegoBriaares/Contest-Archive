#include <cstdio>
#include <algorithm>
#include <cmath>
#include <stack>
#define MAX 500002

using namespace std;

stack< pair<double, long long> >p1;///altura,posicion en el arreglo
stack< pair<double, long long> >p2;


long long N;

pair<double, double>T  [MAX];
pair<long , long >ans[MAX];

double distancia( double x1, double y1, double x2, double y2 ){

    return (double)(sqrt( ((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));

}

int main(){

    scanf( "%lld", &N );

    for(long long int i=0; i<=N+1; i++){

        scanf( "%lf%lf", &T[i].first, &T[i].second);

    }

    p1.push(   {T[0].second, 0}   );
    p2.push( {T[N+1].second, N+1} );

    for(long long int i=1; i<=N+1; i++){

        while( !p1.empty() and T[i].second>p1.top().first ){

            ans[ p1.top().second ].first = i; p1.pop();

        }

        while( !p2.empty() and T[N-i+1].second>p2.top().first ){

            ans[ p2.top().second ].second = N-i+1; p2.pop();

        }

        p1.push(     {T[i].second, i}     );
        p2.push( {T[N-i+1].second, N-i+1} );

    }

    for(int i=1; i<=N; i++){

        printf( "%lld %lld %.04lf %.04lf\n", ans[i].second, ans[i].first, distancia( T[i].first,T[i].second,T[ ans[i].second ].first,T[ ans[i].second ].second ), distancia( T[i].first,T[i].second,T[ ans[i].first ].first,T[ ans[i].first ].second ) );

    }

}
