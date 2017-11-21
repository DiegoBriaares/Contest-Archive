#define MOD 1000000007
bool fin[52];
int a[52],b[52];
int memo[10002][52];
int n;
int dp(int i,int j){
    if(i==n&&fin[j])return 1;
    if(i==n&&!fin[j])return 0;
    if(memo[i][j])return memo[i][j];
    return memo[i][j]=(dp(i+1,a[j])+dp(i+1,b[j]))%MOD;
}
int Solution::automata(vector<int> &A, vector<int> &B, vector<int> &C, int D, int N) {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(fin,0,sizeof(fin));
    memset(memo,0,sizeof(memo));
    n=N;
    for(int i=0;i<A.size();i++){
        a[i]=A[i];
    }
    for(int i=0;i<B.size();i++){
        b[i]=B[i];
    }
    for(int i=0;i<C.size();i++){
        fin[C[i]]=true;
    }
    return dp(0,D)%MOD;
}
