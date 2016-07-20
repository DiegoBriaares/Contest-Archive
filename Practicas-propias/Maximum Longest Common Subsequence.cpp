string v,a,b;
int memo[502][502];
int n2;
void substr(int i,int j){
    a=b="";
    for(int x=0;x<=i;x++){
        a+=v[x];
    }
    for(;j<v.size();j++){
        b+=v[j];
    }
    reverse(b.begin(),b.end());
}
int dp(int i,int j){
    if(i==a.size()||j==n2)return 0;
    if(memo[i][j])return memo[i][j];
    for(int k=i;k<a.size();k++){
        if(a[k]==b[j])return memo[i][j]=max(1+dp(k+1,j+1),dp(i,j+1));
    }
    return memo[i][j]=dp(i,j+1);
}
vector<int> Solution::maxLCS(string A) {
    v=A;
    int r=0,r2=0;
    substr(0,1);
    n2=b.size();
    r=dp(0,0);
    for(int i=1;i<v.size();i++){
        a+=v[i];
        n2--;
        memset(memo,0,sizeof(memo));
        int uso=dp(0,0);
        if(uso>r){
            r=uso;
            r2=i;
        }
    }
    vector<int>res;
    res.push_back(r2+1);
    res.push_back(r);
    return res;
}
