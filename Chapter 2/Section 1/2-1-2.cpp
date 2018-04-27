#include <iostream>
using namespace std;
#define LOCAL 1

struct Data{
	int a;
	int b;
};

int gcd(int x,int y){
	int tmp = x % y;
	if(tmp == 0)
		return y;
	return gcd(y,tmp);
}

Data muti(Data x,Data y){
	Data tmp;
	tmp.a = x.a * y.a;
	tmp.b = x.b * y.b;
	int t;
	if(tmp.a > tmp.b){
		t = gcd(tmp.a,tmp.b);
	}else{
		t = gcd(tmp.b,tmp.a);
	}
	tmp.a = tmp.a / t;
	tmp.b = tmp.b / t;
	return tmp;
}

Data mod(Data x,Data y){
	Data t1,t2;
	t1.a = x.a % y.a;
	t1.b = x.a % y.b;
	t2.a = x.b % y.b;
	t2.b = x.b % y.a;
	return muti(t1,t2);
}

Data gcdf(Data x,Data y){
	Data tmp = mod(x,y);
	if(tmp.a == 0)
		return y;
	return gcdf(y,tmp);
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		Data x,y;
		char tmp;
		cin >> x.a;
		cin >> tmp;
		cin >> x.b;
		cin >> y.a;
		cin >> tmp;
		cin >> y.b;
		
		Data t;
		if(double(x.a)/x.b > double(y.a)/y.b)
			t = gcdf(x,y);
		else{
			t = gcdf(y,x);
		}
		if(t.b == 1)
			cout << t.a << endl;
		else{
			cout << t.a << "/" << t.b << endl;
		}
//		cout << "#" << x.a << "/" << x.b << " ";
//		cout << "#" << y.a << "/" << y.b << endl;
	}
	
	return 0;
}
