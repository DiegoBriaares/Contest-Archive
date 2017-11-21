#include <bits/stdc++.h>
using namespace std;
int ok=0;
string a,b,c;
void solveA(int i,int i2,int j){  //Ver si con mi primera string lo logro.
	if(ok)return;
	if(i==a.size()&&i2==b.size()){
		ok=1;
		return;
	}
	if(j==c.size())return;
	if(a[i]==c[j]&&b[i2]!=c[j]){
		solveA(i+1,i2,j+1);
	}
	else if(a[i]!=c[j]&&b[i2]==c[j]){
		solveA(i,i2+1,j+1);
	}
	else if(a[i]==c[j]&&b[i2]==c[j]){
		solveA(i,i2+1,j+1);
		solveA(i+1,i2,j+1);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b>>c;
		solveA(0,0,0);
		if(ok)cout <<"SI\n";
		else cout <<"NO\n";
	}
