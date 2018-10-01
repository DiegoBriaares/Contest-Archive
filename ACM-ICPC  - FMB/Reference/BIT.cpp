
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
