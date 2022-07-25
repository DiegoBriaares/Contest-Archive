/**

   * author:    Diego Briaares
   * At:   24.07.2022 14:19:19
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

// Randal

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	node* L;
	node* R;
	int key, pry;
	int sz;
	int cnt;
};

const int MAXNODES = 100002;
node treap[MAXNODES];
int nodes;

int size(node* T) {
	if (T == NULL) {
		return 0;
	}
	return T->sz;
}

void Merge(node* &T, node* A, node* B) {
	if (A == NULL) {
		T = B;
		return;
	}
	if (B == NULL) {
		T = A;
		return;
	}

	if (A->pry >= B->pry) {
		Merge(A->R, A->R, B);
		T = A;
	}
	else {
		Merge(B->L, A, B->L);
		T = B;
	}
	T->sz = (size(T->L) + size(T->R) + T->cnt);
	return;
}

void Split(node* T, int k, node* &A, node* &B) {
	if (T == NULL) {
		A = B = NULL;
		return;
	}
	if (T->key > k) {
		Split(T->L, k, A, T->L);
		B = T;
		B->sz = (size(B->L) + size(B->R) + B->cnt);
	}
	else {
		Split(T->R, k, T->R, B);
		A = T;
		A->sz = (size(A->L) + size(A->R) + A->cnt);
	}
	return;
}

node* new_node(int v = 0) {
	if (nodes >= MAXNODES) {
		cout << "NEL PASTEL (muchos nodos)\n";
		return NULL;
	}
	node* NewT = &treap[nodes++];
	NewT->sz = 1;
	NewT->cnt = 1;
	NewT->L = NULL;
	NewT->R = NULL;
	NewT->key = v;
	NewT->pry = uniform_int_distribution<int>(0, MAXNODES * 10)(rng);
	return NewT; 
}

bool Find(node* T, int v) {
	if (T == NULL) {
		return false;
	}
	else if (T->key == v) {
		return true;
	}
	else if (T->key < v) {
		return Find(T->R, v);
	}
	else {
		return Find(T->L, v);
	}
}

/* - */
vector<int> inorder(node* T) {
	if (T == NULL) {
		return vector<int>();
	}
	vector<int> order;
	vector<int> L = inorder(T->L);
	order.insert(order.end(), L.begin(), L.end());
	order.push_back(T->key);
	vector<int> R = inorder(T->R);
	order.insert(order.end(), R.begin(), R.end());
	return order;
} /* -- */


// No debe haber un v
void Insert(node* &T, int v = 0) {
	node* T1;
	node* T2;
	Split(T, v, T1, T2);
	Merge(T1, T1, new_node(v));
	Merge(T, T1, T2);
	return;
}


// Debe haber un v 
void Erase(node* &T, int v) {
	node* T1;
	node* T2;
	node* T3;
	Split(T, v, T1, T2);
	Split(T1, v - 1, T1, T3);
	Merge(T, T1, T2);
	return;
}


// Debe haber un k-esimo elemento
int OrdK(node* &T, int k) {
	if (T == NULL) {
		return 420;
	}
	if (size(T->L) < k && size(T->L) + T->cnt >= k) {
		return T->key;
	}
	if (size(T->L) + T->cnt < k) {
		return OrdK(T->R, k - size(T->L) - T->cnt);
	}
	else {
		return OrdK(T->L, k);
	}
}

int Count(node* &T, int x) {
	if (T == NULL) {
		return 0;
	}
	node* T1;
	node* T2;
	Split(T, x, T1, T2);
	int amt = size(T1);
	Merge(T, T1, T2);
	return amt;
}

// Si ya v esta en el Treap usa Upd pa "meterlo" (multiset el pedo)
void Upd(node* &T, int v) {
	if (T == NULL) {
		return;
	}
	if (T->key == v) {
		T->cnt++;
	}
	else if (T->key < v) {
		Upd(T->R, v);
	}
	else {
		Upd(T->L, v);
	}
	T->sz = size(T->L) + size(T->R) + T->cnt;
}


	int main () {
		optimize();
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}	
		// Transform array
		for (int i = 0; i < n; i++) {
			if (a[i] < k) {
				a[i] = -1;
			}
			else {
				a[i] = 1;
			}
		}
		// Acumulate sums
		vector<int> acum(1, a[0]);
		for (int i = 1; i < n; i++) {
			acum.push_back(acum[i - 1] + a[i]);
		}
		//There are segments [], fix each right end ] once and count number of previous right ends that ends in a lower or equal acum sum.
		// Proof Median of range [i, j] is \geq k \iff acum[j] >= acum[i] 

		// Number of distinct segments \in O(n^2),
		 // Number of distinct segment right ends \in O(n)
		 // Distributed sums with Multiset Treap to efficiently check condition.
		node* T = NULL;
		node* T1 = NULL;
		node* T2 = NULL;
		long long Sum = 0;
		Insert(T, 0);
		for (int i = 0; i < n; i++) {
			Split(T, acum[i], T1, T2);
			Sum += size(T1);
			Merge(T, T1, T2);
			if (!Find(T, acum[i])) {
				Insert(T, acum[i]);
			}
			else {
				Upd(T, acum[i]);
			}
		}
		// 1 0 1 0 -> T(0 1 0 1 0)
		// 1 + 1 + 3 + 2 = 7
		cout << Sum << "\n";
	}
