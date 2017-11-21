#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
char c;
int x,q;
set<int>S;
int h[MAX];
deque<int>cola;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>q;
		while(q--){
			cin>>c;
			if(c=='A'){
				cin>>x;
				cola.push_back(x);
				S.insert(x);
				h[x]++;
			}
			if(c=='B'&&!cola.empty()){
				cout <<cola.front()<<"\n";
				h[cola.front()]--;
				cola.pop_front();
			}
			if(c=='C'&&!cola.empty()){
				cout <<cola.back()<<"\n";
				h[cola.back()]--;
				cola.pop_back();
			}
			if(c=='D'&&!cola.empty()){
				for(set<int>::iterator it=S.begin();it!=S.end();++it){
					int aux=h[*it];
					while(aux>0){
						cout << *it<<" ";
						aux--;
					}
				}
				cout << "\n";
			}
			if(c=='E'){
				cout << cola.size()<<"\n";
			}
		}
	}
