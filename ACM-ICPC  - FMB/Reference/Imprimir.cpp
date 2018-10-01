//Aho-corasick---------------------------------------------------------------

typedef pair<int,int> pii;

int trie[MAX][26], fail[MAX], go[MAX][26], total;
bool end[MAX];

void insert(string &s){
	int u=0,idx;
	for (int i=0; i<s.size(); i++){
		idx=(int)(s[i]-'a');
		if (!trie[u][idx]) trie[u][idx]=total++;
		u=trie[u][idx];
	}
	end[u]=true;
}

void construye(){
	int v,u,f,fv;
	pii aux;
	queue<pii > q;
	
	for (int u=0; u<26; u++){
		if (trie[0][u]){
			v=trie[0][u];
			go[0][u]=v;
			q.push(pii(v,0));
		}
		else go[0][v]=0;
	}
	
	while (!q.empty()){
		aux=q.front();
		u=aux.first;
		f=aux.second;
		for (int t=0; t<26; t++){
			if (trie[u][t]!=0){
				v=trie[u][t];
				go[u][t]=v;
				fv=go[f][t];
				q.push(pii(v,fv));
				fail[u]=f;
			}
			else go[u][t]=go[f][t];
		}
	}
}

//BIT---------------------------------------------------------------


template <class T>
class BIT{
	int n;
	T *arr;
	BIT(int x){
		n=x;
		arr=new T[n+1];
		for (int i=0; i<=n; i++) arr[i]=T();
	}
	void add(int i, int val){
		while(i<=n){
			arr[i]+=val;
			i+=(i&-i);
		}
	}
	T query(int i){
		T suma();
		while(i>0){
			suma+=arr[i];
			i-=(i&-i);
		}
		return suma;
	}
	void del(){
		delete[] arr;
	}
};

//DP---------------------------------------------------------------

ll Acu[MAX], Acu2[MAX], dp[MAX][20];
ll a;
ll n, k;

ll costo(ll I, ll J){
    I++; J++;
    return Acu2[J] - Acu2[I] + (I-1)*(Acu[J] - Acu[I]);
}

void res(ll r, ll a, ll b, ll opa, ll opb){
    if (a>b) return;

    ll m=(a+b)/2,posicion=-1,M=1e12,v;

    for (ll i=opa; i<=min(opb,m); i++){
        v=(i-1>= 0 ? dp[i-1][r-1] : 0) + costo(i,m);
        if (v<M){
            M=v;
            posicion=i;
        }
    }
    dp[m][r]=M;
    res(r,a,m-1,opa,posicion);
    res(r,m+1,b,posicion,opb);
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a;
        Acu[i+1] = Acu[i] + a;
        Acu2[i+1] = Acu2[i] + a*i;
    }

    for (ll i=0; i<n; i++) dp[i][1]=costo(0,i);

    for (ll i=2; i<=k; i++) res(i,0,n-1,0,n-1);
    return 0;
}

//FFT---------------------------------------------------------------

typedef complex<double> point;

void fft(vector<point> &a, int sign = +1)
{
	int n = a.size();

	for (int i = 1, j = 0; i < n - 1; ++i)
	{
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);

		if (i < j) swap(a[i], a[j]);
	}

	double theta = 2 * atan2(0, -1) * sign;

	for (int m, mh = 1; (m = mh << 1) <= n; mh = m)
	{
		point wm(cos(theta / m), sin(theta / m)), w(1, 0);

		for (int i = 0; i < n; i += m, w = point(1, 0))
			for (int j = i, k = j + mh; j < i + mh; ++j, ++k, w = w * wm)
			{
				point x = a[j], y = a[k] * w;
				a[j] = x + y;
				a[k] = x - y;
			}
	}

	if (sign == -1)
		for (int i=0; i<a.size(); i++) a[i] = a[i] / (1. * n);
}

void fix(vector<point> &a, int M){
	while (a.size()<M) a.push_back(point(0,0));
}

void multiplica(vector<point> &a, vector<point> &b, vector<point> &c){
	int M=1,N;
	vector<point> A,B;
	
	N=a.size()+b.size()+1;
	while (M<N) M*=2;
	
	for (int i=0; i<a.size(); i++) A.push_back(a[i]);
	for (int i=0; i<b.size(); i++) B.push_back(b[i]);
	
	fix(A,M);
	fix(B,M);
	
	fft(A,1);
	fft(B,1);
	
	c.erase(c.begin(),c.end());
	for (int i=0; i<M; i++) c.push_back(A[i]*B[i]);
	
	fft(c,-1);
}

//Segment Tree---------------------------------------------------------------

template <class T>
struct nodo{
	T x;
	int i,j;
	nodo *p,*l,*r;
};

template <class T>
class ST{
	nodo<T> *root;
	public:
	void inicia(nodo<T> *P){
		if (P->i==P->j) return;
		int c=(P->i+P->j)/2;
		P->l=new nodo<T>;
		P->r=new nodo<T>;
		P->l->p=P;
		P->l->i=P->i;
		P->l->j=c;
		P->r->p=P;
		P->r->i=c+1;
		P->r->j=P->j;
		inicia(P->l);
		inicia(P->r);
	}
	ST(int n){
		root=new nodo<T>;
		root->i=0;
		root->j=n-1;
		inicia(root);
	}
	T compara(T x, T y){
		T z;//especificar comparacion
		return z;
	}
	void update(int i, T x, nodo<T> *P=NULL){
		if (P==NULL) P=root;
		if (P->i==P->j) {
			P->x=x;
			return;
		}
		int c=(P->i+P->j)/2;
		if (i<=c) update(i,x,P->l);
		else update(i,x,P->r);
		P->x=compara(P->l->x,P->r->x);
	}
	T query(int i, int j, nodo<T> *P=NULL){
		if (P==NULL) P=root;
		if (i<=P->i&&P->j<=j) return P->x;
		int c=(P->i+P->j)/2;
		if (j<=c) return query(i,j,P->l);
		else if (i>c) return query(i,j,P->r);
		else return compara(query(i,j,P->l),query(i,j,P->r));
	}
	void del(nodo<T> *P=NULL){
		if (P==NULL) P=root;
		if (P->i==P->j) delete P;
		else {
			del(P->l);
			del(P->r);
			delete P;
		}
	}
};

//Treap---------------------------------------------------------------

template <class T>
struct nodo{
    T v;
    ll key,s;
    ll sum;
    ll lazy
    nodo<T> *left,*right;
    nodo<T>(T x){
        v=x;
        left=NULL;
        right=NULL;
        s=1;
        key=rand();
        lazy = 0;
        sum = 0;
    }
};

template <class T>
class treap{
    public:
    nodo<T> *root=NULL;
    treap(){root=NULL;}
    void update(nodo<T> *P){
        if (P!=NULL) {
            
            P->s=1;
            
            P->sum = (P->left!=NULL ? P->left->sum : 0) + P->v + (P->right!=NULL ? P->right->sum : 0);
            
            if (P->left!=NULL) P->s+=P->left->s;
            if (P->right!=NULL) P->s+=P->right->s;
        }
    }
    nodo<T> *Merge(nodo<T> *P,nodo<T> *Q){
        push(P);
        push(Q);
        if (P==NULL) return Q;
        if (Q==NULL) return P;
        if (P->key > Q->key){
            P->right=Merge(P->right,Q);
            update(P);
            return P;
        }
        else {
            Q->left=Merge(P,Q->left);
            update(Q);
            return Q;
        }
    }
    void push(node<T> *P){
        if(P != NULL && P->lazy != 0){
            if(P->left != NULL)
                P->left->lazy += P->lazy;
            if(P->right != NULL)
                P->right->lazy += P->lazy;
            P->sum += P->lazy * P->s;
            P->lazy = 0;
        }
    }
    
    NN split(nodo<T> *P,int k){
        push(P);
        if (P==NULL) return NN(NULL,NULL);
        if (k==P->s) return NN(P,NULL);
        if (k==0) return NN(NULL,P);
        if (P->left!=NULL && P->left->s >= k){
            push(P->left);
            NN aux=split(P->left,k);
            P->left=NULL;
            update(P);
            P=Merge(aux.second,P);
            return NN(aux.first,P);
        }
        else {
            push(P->right);
            if (P->left!=NULL) k-=P->left->s;
            NN aux=split(P->right,k-1);
            P->right=NULL;
            update(P);
            P=Merge(P,aux.first);
            return NN(P,aux.second);
        }
    }
    ll cont(nodo<T> *P, T x){
        push(P);
        if (P==NULL) return 0;
        if (P->v >= x) return cont(P->left,x);
        if (P->left==NULL) return 1+cont(P->right,x);
        else return cont(P->right,x)+P->left->s+1;
    }
    ll posicion(T x){
        if (root==NULL) return -2;
        ll k1,k2;
        k1=cont(root,x);
        k2=root->s-cont(root,x+1);
        if (k1+k2==root->s) return -2;
        else return k1;
    }
    T busca(int k, nodo<T> *P){
        if (root==NULL) return -1;
        if (k<=0 || k > root->s) return -1;
        //if (P==NULL) P=root;
        if ((P->left!=NULL ? P->left->s : 0) +1 == k) return P->v;
        if ((P->left!=NULL ? P->left->s : 0)>=k) return busca(k,P->left);
        else return busca(k-(P->left!=NULL ? P->left->s : 0)-1, P->right);
    }
    void inser(T x){
        NN aux=split(root,cont(root,x));
        nodo<T> *P=new nodo<T>(x);
        root=Merge(Merge(aux.first,P),aux.second);
    }
    void elimina(nodo<T> *P){
        if (P==NULL) return;
        elimina(P->left);
        elimina(P->right);
        delete P;
    }
    void del(T x){
        int k=cont(root,x);
        NN aux=split(root,k);
        int kx=cont(aux.second,x+1);
        NN aux2=split(aux.second,kx);
        elimina(aux2.first);
        root=Merge(aux.first,aux2.second);
    }
    void print(nodo<T> *P=NULL, int s=0){
        if (root==NULL) return;
        if (P==NULL) P=root;
        if (P->left!=NULL)
            print(P->left, s+1
            );
        for(int i=0; i<s; i++) cout << " ";
        cout<<P->v<<'\n';
        if (P->right!=NULL) print(P->right, s+1);
    }
};

//UnionFind---------------------------------------------------------------

//Indexado en 1.
class UnionFind{

public:
    int Size;
    int* id;
    int* wh;

    UnionFind(void)
    {
        Size = 0;
        id = (int*)malloc((1)*sizeof(int));
        wh = (int*)malloc((1)*sizeof(int));
        id[0] = 0;
        wh[0] = 1;
    }

    UnionFind(int n)
    {
        Size = n;
        id = (int*)malloc((n+1)*sizeof(int));
        wh = (int*)malloc((n+1)*sizeof(int));
        for(int i=0; i<=n; i++)
        {
            id[i] = i;
            wh[i] = 1;
        }
    }

    int Root(int x)
    {
        if(x == 0 || x > Size+1)
            return -1;
        if(x == id[x])
            return x;
        return id[x] = Root(id[x]);
    }

    bool Find(int x, int y)
    {
        return Root(x) == Root(y);
    }

    bool Union(int x, int y)
    {
        if(!Find(x, y))
        {
            x = Root(x);
            y = Root(y);
            if(wh[x] > wh[y])
            {
                id[y] = x;
                wh[x] += wh[y];
            }
            else
            {
                id[x] = id[y];
                wh[y] += wh[x];
            }
        }
    }

};
