#include<bits/stdc++.h>
using namespace std;
long long v1[300005],v2[300005];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N,M;
    cin>>N;
    long long suma1=0,suma2=0;
    for(int i=0;i<N;i++){
        cin>>v1[i];
        suma1+=v1[i];
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>v2[i];
        suma2+=v2[i];
    }
    if(suma1!=suma2){
        cout<<-1;
        return 0;
    }
    suma1=suma2=0;
    int ind1=0,ind2=1;
    suma2=v2[0];
    int longitud=0;
    while(ind1<N&&ind2<=M){
        ///cout<<ind1<<" "<<ind2<<" "<<suma1<<" "<<suma2<<"\n";
        while(suma1<suma2){
            suma1+=v1[ind1];
            ind1++;
        }
        if(suma1==suma2){
            longitud++;
            suma1=0;
            suma2=v2[ind2];
            ind2++;
        }
        else {
            while(suma2<suma1){
                suma2+=v2[ind2];
                ind2++;
            }
            if(suma1==suma2){
                longitud++;
                suma1=0;
                suma2=v2[ind2];
                ind2++;
            }
        }
    }
    cout<<longitud;
    return 0;
}
