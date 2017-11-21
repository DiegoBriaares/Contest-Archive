#include <bits/stdc++.h>
using namespace std;
#define MAX 20
int n,m,c;
int arr[MAX];
int v[MAX][MAX];
int res[MAX][MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>n>>m>>c){
			for(int i=1;i<=c;i++){
				cin>>arr[i];
			}
			int i=0,j=0;
			for(int col=1;col<=c;col++){
				while(arr[col]){
					if(!(i&1)){
						res[i][j++]=col;
						if(j==m){
							i++;
							j=m-1;
						}
					}
					else {
						res[i][j--]=col;
						if(j<0){
							i++;
							j=0;
						}
					}
					arr[col]--;		
				}
			}
			//cout << "AUX: "<<n<<" "<<m<<"\n";
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout << res[i][j];
				}
				cout << "\n";
			}
		}
	}
