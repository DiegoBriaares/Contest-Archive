#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
int idx;
int n,k;
vector<string>notes;
vector<string>DN;
vector<string>res;
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>k;
   for(int i=0;i<(n-k)+1;i++){
   	string aux;
   	cin>>aux;
   	notes.push_back(aux);
   }
   char uso='a';
   string aux="";
   for(int i=0;i<n*2;i++){
   		aux+=uso;
   		DN.push_back(aux);
   		if(aux.size()>=8){
   			aux="";
   			uso++;
		   }
   }
   for(int i=0;i<n;i++){
   	res.push_back(DN[idx++]);
   }
   idx=0;
   for(int i=k-1,j=0;i<n;i++,j++,idx++){
		if(notes[j]=="NO"){
			res[i]=res[idx];
		}
   }
   for(int i=0;i<res.size();i++){
   	cout <<"D";
   	cout << res[i]<<" ";
   }
}
