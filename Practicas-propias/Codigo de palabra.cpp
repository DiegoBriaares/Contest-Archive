#include <bits/stdc++.h>
using namespace std;
map<string,int>memo;
void solve (int n){
	int i,j,k=1,g,h,q,w,e=1;
		char v[6];
		if(n==6)e=0;
		if(n>=1)for(v[0]='a';v[0]<='z';v[0]++,k++){
			v[1]='\0';
			if(e==1)memo[string(v)]=k;
		}
		if(n>=2)for(v[0]='a';v[0]<='z';v[0]++){
			for(v[1]=v[0]+1;v[1]<='z';v[1]++,k++){
				v[2]='\0';
				if(e==1)memo[string(v)]=k;
			}
		}
		if(n>=3)for(v[0]='a';v[0]<='z';v[0]++){
			for(v[1]=v[0]+1;v[1]<='z';v[1]++){
				for(v[2]=v[1]+1;v[2]<='z';v[2]++,k++){
					v[3]='\0';
					if(e==1)memo[string(v)]=k;
				}
			}
		}
		if(n>=4)for(v[0]='a';v[0]<='z';v[0]++){
			for(v[1]=v[0]+1;v[1]<='z';v[1]++){
				for(v[2]=v[1]+1;v[2]<='z';v[2]++){
					for(v[3]=v[2]+1;v[3]<='z';v[3]++,k++){
						v[4]='\0';
						if(e==1)memo[string(v)]=k;
					}	
				}
			}
		}
		if(n>=5)for(v[0]='a';v[0]<='z';v[0]++){
			for(v[1]=v[0]+1;v[1]<='z';v[1]++){
				for(v[2]=v[1]+1;v[2]<='z';v[2]++){
					for(v[3]=v[2]+1;v[3]<='z';v[3]++){
						for(v[4]=v[3]+1;v[4]<='z';v[4]++,k++){
							v[5]='\0';
							if(e==1)memo[string(v)]=k;
						}	
					}	
				}
			}
		}
		if(n>=6)for(v[0]='a';v[0]<='z';v[0]++){
			for(v[1]=v[0]+1;v[1]<='z';v[1]++){
				for(v[2]=v[1]+1;v[2]<='z';v[2]++){
					for(v[3]=v[2]+1;v[3]<='z';v[3]++){
						for(v[4]=v[3]+1;v[4]<='z';v[4]++){
							for(v[5]=v[4]+1;v[5]<='z';v[5]++,k++){
								v[6]='\0';
								memo[string(v)]=k;
							}
						}	
					}	
				}
			}
		}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		string uso;
		cin>>uso;
		solve(uso.size());
		cout << memo[uso]<<"\n";
	}
