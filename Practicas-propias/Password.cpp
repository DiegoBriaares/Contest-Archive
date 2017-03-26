#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int k;
bool ok;
string q;
int KMP[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>q;
		for(int i=1,j=0;i<q.size();){
			if(q[i]==q[j]){
				KMP[i]=j+1;
				j++;
				i++;
			}
			else if(j) {
				j=KMP[j-1];
			}
			else {
				KMP[i]=0;
				i++;
			}
		}
		for(int i=0;i<q.size()-1;i++){
			k=max(k,KMP[i]);
		}
		int j;
		for(j=KMP[q.size()-1];j&&j>k;j=KMP[j-1]);
		if(!j){
			cout << "Just a legend\n";
			return 0;
		}
		for(int i=0;i<j;i++)cout << q[i];
	}
