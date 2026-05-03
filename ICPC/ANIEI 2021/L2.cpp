#include <bits/stdc++.h>
using namespace std;
#define MAX 500002
int A[MAX];
int ST[MAX * 4];
int ST2[MAX * 4];

int tamn;
int tamst;
void build(int lo,int hi,int n){
	if(lo==hi){
		ST[n]=A[lo];
		return;
	}
	int mid=(lo+hi)/2;
	int left=n*2+1;
	int right=n*2+2;
	build(lo,mid,left);
	build(mid+1,hi,right);
	ST[n]=min(ST[left],ST[right]);
}
int query(int qlo,int qhi,int lo,int hi,int n){
	if(qlo<=lo&&qhi>=hi){  //Total Overlap
		return ST[n];
	}
	if(qlo>hi||qhi<lo) return (1<<30);  //No Overlap
	//Partial Overlap
		int mid=(lo+hi)/2;
		int left=n*2+1;
		int right=n*2+2;
		return min(query(qlo,qhi,lo,mid,left),query(qlo,qhi,mid+1,hi,right));
}
void update(int lo, int hi, int n, int i,int val){
		if(i<=lo&&i>=hi){  //Total Overlap
		ST[n] = val;
		return;
	}
	if(i>hi||i<lo) return;  //No Overlap
	//Partial Overlap
		int mid=(lo+hi)/2;
		int left=n*2+1;
		int right=n*2+2;
		update(lo,mid,left,i, val);
		update(mid+1,hi,right, i, val);
		ST[n] = min(ST[left], ST[right]);
}

void build2(int lo,int hi,int n){
	if(lo==hi){
		ST2[n]=A[lo];
		return;
	}
	int mid=(lo+hi)/2;
	int left=n*2+1;
	int right=n*2+2;
	build2(lo,mid,left);
	build2(mid+1,hi,right);
	ST2[n]=max(ST2[left],ST2[right]);
}
int query2(int qlo,int qhi,int lo,int hi,int n){
	if(qlo<=lo&&qhi>=hi){  //Total Overlap
		return ST2[n];
	}
	if(qlo>hi||qhi<lo) return -(1<<30);  //No Overlap
	//Partial Overlap
		int mid=(lo+hi)/2;
		int left=n*2+1;
		int right=n*2+2;
		return max(query2(qlo,qhi,lo,mid,left),query2(qlo,qhi,mid+1,hi,right));
}
void update2(int lo, int hi, int n, int i,int val){
		if(i<=lo&&i>=hi){  //Total Overlap
		ST2[n] = val;
		return;
	}
	if(i>hi||i<lo) return;  //No Overlap
	//Partial Overlap
		int mid=(lo+hi)/2;
		int left=n*2+1;
		int right=n*2+2;
		update2(lo,mid,left,i, val);
		update2(mid+1,hi,right, i, val);
		ST2[n] = max(ST2[left], ST2[right]);
}


	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>tamn;
		int q;
		cin >> q;
		for (int i = 0; i < tamn; i++) cin >> A[i];
		build(0,tamn - 1,0);
		build2(0,tamn - 1,0);
		while (q--) {
			string op;
			int l, r;
			cin >> op;
			cin >> l >> r;
			if (op == "MAX") {
				cout << query2(l - 1,r-1,0,tamn-1,0) << "\n";
			}
			else if (op == "MIN") {
				cout << query(l - 1,r-1,0,tamn-1,0)<< "\n";
			}
			else {
				update(0, tamn-1, 0, l - 1, r);
				update2(0, tamn-1, 0, l - 1, r);
			}

		}
	}