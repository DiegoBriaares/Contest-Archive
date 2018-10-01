#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
#define ll long long

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

int main(){
	
	return 0;
}
