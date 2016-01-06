#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
string v;
bool memo[MAX];
int uso=0;
void p(string r){
	if(r.size()==v.size())cout << r<<"\n",uso++;
	for(int i=0;i<v.size();i++){
		if(!memo[i]){
			memo[i]=true;
			p(r+v[i]);
			memo[i]=false;
		}
	}
}
	int main (){
		cin>>v;
		p("");
		cout <<uso<<"\n";
	}
