#include <bits/stdc++.h>
using namespace std;
int main(){
	string v;
    cin >> v;
    int maxi=0,maxo = 1;
    stack<int> pila;
    pila.push(-1);
    for (int i=0;i<v.size();i++) {
        if (v[i] =='(')pila.push(i);
        else {
            if (pila.top()!=-1&&v[pila.top()]=='('){
                pila.pop();
                if (i-pila.top()>maxi){
                    maxi=i-pila.top();
                    maxo=1;
                }
                else if (i-pila.top()==maxi)
                    maxo++;
            }
            else { 
                pila.push(i);
            }
        }
    }
    if(maxi>0)cout << maxi << " " << maxo;
    else cout << 0<<" "<<1;
}
