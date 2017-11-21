#include <bits/stdc++.h>
using namespace std;
string wrd(int x){
    string r="";
    while(x>0){
        r+=((x%10)+'0');
        x/=10;
    }
	reverse(r.begin(),r.end());
    return r;
}
bool cmp(const string &a,const string &b){
	return a+b>b+a;
}
string re(vector<int> v) {
    string r[v.size()+2];
    for(int i=0;i<v.size();i++){
    	r[i]="";
        r[i]+=wrd(v[i]);
    }
    sort(r,r+v.size(),cmp);
    string re="";
    for(int i=0;i<v.size();i++)re+=r[i];
    if(re=="")re+='0';
    return re;
}

	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n;
		cin>>n;
		vector<int>v;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			v.push_back(a);
		}
		cout << re(v);
	}
