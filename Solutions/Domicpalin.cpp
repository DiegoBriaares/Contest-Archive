#include <bits/stdc++.h>
	
	using namespace std;

#define ll unsigned long long


ll N, T;
string S;
ll R[1002];

bool Jala(ll A, ll B)
{
	ll C = A^B;
	ll HM = 0;
	for(int i=0; i<27; i++)
		if((C&(1LL<<i)))HM++;
		
	if(HM <= 1) return 1;
	return 0;
}

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> T;
		
	for(int t=0; t<T; t++)
	{
		cin >> S;
		
		R[0] = 0;
		for(int i=1; i<=S.size(); i++)
			R[i] = R[i-1] ^ (1LL << (S[i-1]-'a'));
			
		
			
		ll SUM = 0;
		int N=S.size();
		for(int i=0; i<=N; i++)
		{
			for(int j = i+1; j<=N; j++){
			//	cout << "AUX: "<<R[i]<<" "<<R[j]<<"\n";
				if(Jala(R[i], R[j])) SUM++;
			}
		}
		
		cout << "Case " << t+1 << ": " << SUM << "\n";
	}

	return 0;
}
