#include <iostream>
#include <algorithm>
using namespace std;
#define LOCAL 0

int t[10000];


bool f(int x,int y){
	double tmp1,tmp2;
	int a,b;
	a = x/10000;
	b = x%10000;
	tmp1 = (double)a/(double)b;
	a = y/10000;
	b = y%10000;
	tmp2 = (double)a/(double)b;
	if(tmp1 > tmp2)
		return true;
	return false;
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
	cout << "#########################"<< endl;
#endif
	cout << sizeof(int) << endl;
	int m,n;
	while((cin >> m >> n && m != -1)){	
		for(int i = 0;i < n;i++){
			int a,b;
			cin >> a >> b;
			t[i] = a*10000 + b;
		}
		sort(t,t+n,f);
		double sum = 0.0;
		for(int i = 0;i < n;i++){
//			cout << t[i] << endl;
			int a = t[i]/10000;
			int b = t[i]%10000;
//			cout << "#" << a << " " << b << endl;
			if(m > b){
				m -= b;
				sum += a;
			}else{
				double tmp = (double)a/(double)b;
				sum += (tmp * m);
				printf("%0.3f\n",sum);
				break;
			}
		}
	}
	
	return 0;
}
