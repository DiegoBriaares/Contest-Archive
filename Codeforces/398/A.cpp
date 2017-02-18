#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n;
int x;
queue<int>cola;
priority_queue<int>heap;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=n;i;i--)cola.push(i);
		for(int i=0;i<n;i++){
			cin>>x;
			heap.push(x);
			while(cola.front()==heap.top()){
				cout << cola.front()<<" ";
				cola.pop();
				heap.pop();
			}
			cout << "\n";
		}
	}
