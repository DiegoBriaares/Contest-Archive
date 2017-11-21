int Solution::cntInc(vector<int> &A) {
    int n=A.size(),r=0;
    for(int i=0;i<n;i++){
        int uso=1;
        for(int j=i;j<n-1&&A[j]<A[j+1];j++)uso++,i++;
        if(uso>1){
            r+=((uso*(uso-1))/2);
        }
    }
    return (r+n);
}
