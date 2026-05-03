// Fibonnaci

const long long MOD = 1e9 + 7;

map<long long, long long> F;

long long f(long long n) {
	if (F.count(n)) return F[n];
	long long k = (n >> 1);
	if (!(n & 1LL)) {
		return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % MOD;
	} else { 
		return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % MOD;
	}
	}


	// LCA

	// LCA(u, v)

// need precalc_lca()

int high[500002];
const int root = 0;
vector<int> edg[500002];

void calc_highs(int deep, int node) {
	high[node] = deep;
	for (auto s : edg[node]) {
		calc_highs(deep + 1, s);
	}
}

const int LOG = 20;
int anc[LOG + 1][500002];

void precalc_lca(int nodes) {
	calc_highs(0, root);
	for (int dist = 1; dist < LOG; dist++) {
		for (int node = 0; node < nodes; node++) {
			anc[dist][node] = anc[dist - 1][anc[dist - 1][node]];
		}
	}
}

int calc_anc(int k, int node) {
	for (int i = LOG - 1; i >= 0; i--) {
		if (k & (1 << i)) {
			node = anc[i][node];
		}
	}
	return node;
}

bool common_ancestor(int deep, int u, int v) {
	return calc_anc(high[v] - deep, calc_anc(high[u] - high[v], u)) == calc_anc(high[v] - deep, v);
}

int queryLCA(int u,int v) {
	if (high[u] < high[v]) swap(u, v);
	int d = 0;
	for (int i = LOG - 1; i >= 0; i--) {
		if (d + (1 << i) <= high[v] && common_ancestor(d + (1 << i), u, v)) {
			d += (1 << i);
		}
 	}
	return calc_anc(high[v] - d, v);
}


// Pascal

bool comb_ini;
long long Comb[52][52];

void ini_comb() {
  comb_ini = true;
  Comb[0][0] = 1;
  for (int i = 1; i < 52; i++) {
    Comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      Comb[i][j] = Comb[i - 1][j - 1] + Comb[i - 1][j];
    }
  }
}

long long comb(int n, int k) {
  if (n == 0) return 1;
  if (k == 0) return 1;
  if (!comb_ini) {
    ini_comb();
  }
  return Comb[n][k];
}

// 	Implicit Treap

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	node* L;
	node* R;
	int key, pry;
	int sz;
	int swp;
	int id;
};

const int MAXNODES = 1000002;
node treap[MAXNODES];
int nodes;

int size(node* T) {
	if (T == NULL) {
		return 0;
	}
	return T->sz;
}

void Push(node* &T) {
	swap(T->L, T->R);
	if (T->L) {
		T->L->swp ^= 1;
	}
	if (T->R) {
		T->R->swp ^= 1;
	}
	T->swp = 0;
}

void Merge(node* &T, node* A, node* B) {
	if (T && T->swp) {
		Push(T);
	}	
	if (A == NULL) {
		T = B;
		return;
	}
	if (B == NULL) {
		T = A;
		return;
	}
	if (A->swp) {
		Push(A);
	}
	if (B->swp) {
		Push(B);
	}

	if (A->pry >= B->pry) {
		Merge(A->R, A->R, B);
		T = A;
	}
	else {
		Merge(B->L, A, B->L);
		T = B;
	}
	T->sz = (size(T->L) + size(T->R) + 1);
	return;
}

void Split(node* T, int k, node* &A, node* &B) {
	if (T == NULL) {
		A = B = NULL;
		return;
	}
	if (T->swp) {
		Push(T);
	}
	T->key = size(T->L) + 1;
	if (T->key > k) {
		Split(T->L, k, A, T->L);
		B = T;
		B->sz = (size(B->L) + size(B->R) + 1);
	}
	else {
		Split(T->R, k - T->key, T->R, B);
		A = T;
		A->sz = (size(A->L) + size(A->R) + 1);
	}
}

node* new_node(int v = 0) {
	if (nodes >= MAXNODES) {
		cout << "NEL PASTEL (muchos nodos)\n";
		return NULL;
	}
	node* NewT = &treap[nodes++];
	NewT->sz = 1;
	NewT->swp = 0;
	NewT->id = v;
	NewT->L = NULL;
	NewT->R = NULL;
	NewT->pry = uniform_int_distribution<int>(0, MAXNODES * 10)(rng);
	return NewT; 
}

vector<int> inorder(node* T) {
	if (T == NULL) {
		return vector<int>();
	}
	if (T->swp) {
		Push(T);
	}
	vector<int> order;
	vector<int> L = inorder(T->L);
	order.insert(order.end(), L.begin(), L.end());
	order.push_back(T->id);
	vector<int> R = inorder(T->R);
	order.insert(order.end(), R.begin(), R.end());
	return order;
}

void Erase(node* &T, int i) {
	if (T == NULL) {
		return;
	}
	node* T1;
	node* T2;
	node* T3;
	Split(T, i, T1, T3);
	Split(T1, i - 1, T1, T2);
	T2 = NULL;
	Merge(T, T1, T3);
}

int Find(node* &T, int i) {
	if (T == NULL) {
		return 420;
	}
	T->key = size(T->L) + 1;
	if (T->key == i) {
		return T->id;
	}
	else if (T->key < i) {
		return Find(T->R, i - T->key);
	}
	else {
		return Find(T->L, i);
	}
}

// MultiTreap

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

// Si ya v esta en el Treap puedes "meterlo" por aqui
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


// Random

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

uniform_int_distribution<int>(0, 100000)(rng)

// ordered set

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

//Segment tree


const int INF = (int) 1e9;

const int MAX = (int) 1e5;

int A[MAX];

int ST[4 * MAX];

void build(int l, int r, int node) {
	if (l == r) {
		ST[node] = A[l];
		return;
	}
	if (l > r) return;
	int mid = (l + r) / 2;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	build(l, mid, left);
	build(mid + 1, r, right);
	ST[node] = min(ST[left], ST[right]);
}

void update(int l, int r, int node, int i, int v) {
	if (l > r || l > i || r < i) return;
	if (i <= l && r <= i) {
		ST[node] = v;
		return;
	}
	int mid = (l + r) / 2;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	update(l, mid, left, i, v);
	update(mid + 1, r, right, i, v);
	ST[node] = min(ST[left], ST[right]);
}

int query(int l, int r, int node, int ql, int qr) {
	if (l > r || l > qr || r < ql) return INF;
	if (ql <= l && r <= qr) return ST[node];
	int mid = (l + r) / 2;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	return min(query(l, mid, left, ql, qr), query(mid + 1, r, right, ql, qr));
}


// Treap

// Randal

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	node* L;
	node* R;
	int key, pry;
	int sz;
};

const int MAXNODES = 200002;
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
	T->sz = (size(T->L) + size(T->R) + 1);
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
		B->sz = (size(B->L) + size(B->R) + 1);
	}
	else {
		Split(T->R, k, T->R, B);
		A = T;
		A->sz = (size(A->L) + size(A->R) + 1);
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
	if (size(T->L) + 1 == k) {
		return T->key;
	}
	if (size(T->L)  + 1 < k) {
		return OrdK(T->R, k - size(T->L) - 1);
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


// Debug

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false"); 
}                                  

string to_string(vector<bool> v) {
	string s = "{";
	bool in = true;
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!in) {
			s += ", ";
		}
		in = false;
		s += to_string(v[i]);
	}
	s += "}";
	return s;
}

template <typename A>
string to_string(A v) {
	string s = "{";
	bool in = true;
	for (const auto &x : v) {
		if (!in) {
			s += ", ";
		}
		in = false;
		s += to_string(x);
	}
	s += "}";
	return s;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() {
	cerr << "\n";
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)	
#else
#define debug(...) 46
#endif

// Pragma

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

// Clock

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif


// Big integer

const int base = 1000000000;
const int base_digits = 9;
 
struct bigint {
    vector<int> a;
    int sign;
 
    bigint() :
        sign(1) {
    }
 
    bigint(long long v) {
        *this = v;
    }
 
    bigint(const string &s) {
        read(s);
    }
 
    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }
 
    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }
 
    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;
 
            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }
 
    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
 
    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }
 
    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }
 
    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());
 
        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }
 
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
 
    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }
 
    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }
 
    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }
 
    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }
 
    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }
 
    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }
 
    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }
 
    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }
 
    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }
 
    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }
 
    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }
 
    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }
 
    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }
 
    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint maxx(const bigint &a, const bigint &b) {
        if (a >= b) return a;
        return b;
    }

    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }
 
    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
 
    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
 
    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }
 
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }
 
    typedef vector<long long> vll;
 
    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
 
        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());
 
        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);
 
        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];
 
        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];
 
        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }
 
    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};


// Articulation Points

https://codeforces.com/blog/entry/71146

// Strong componentes

https://cp-algorithms.com/graph/strongly-connected-components.html

// Bellman ford

https://cp-algorithms.com/graph/bellman_ford.html

// FFT

https://cp-algorithms.com/algebra/fft.html#implementation

// Polynomials

https://cp-algorithms.com/algebra/polynomial.html

// HLD

https://cp-algorithms.com/graph/hld.html#description

// Euclides

https://codeforces.com/blog/entry/79167