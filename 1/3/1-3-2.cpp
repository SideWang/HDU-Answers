#include <iostream>
#include <algorithm>
#include <string.h> 
using namespace std;
#define LOCAL 1

struct tim{
	int s;
	int e;
	int flag;
}t[205];

bool f(tim x, tim y){
	if(x.s < y.s){
		return true;
	}else if(x.s > y.s){
		return false;
	}else{
		if(x.e > y.e){
			return true;
		}else{
			return false;
		}
	}
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
	cout << "#########################" << endl;
#endif
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int m;
		cin >> m;
		for(int j = 0;j < m;j++){
			int a,b;
			cin >> a >> b;
			if(a > b){
				swap(a,b);
			}
			t[j].s = a;
			t[j].e = b;
		}
		sort(t,t+m,f);
		for(int k = 0;k < m;k++){
			t[k].flag = 0;
		}
		int sum = 0;
		for(int j = 0;j < m;j++){
			cout << t[j].s << " " << t[j].e << endl;
			if(t[j].flag == 0){
				t[j].flag = 1;
				int tmp = t[j].e;
				for(int k = j+1;k < n;k++){
					if(t[k].s-tmp == 1){
						if(tmp%2 == 0){
							t[k].flag = 1;
							tmp = t[k].e;
						}
					}else if(t[k].s-tmp >= 2){
						t[k].flag = 1;
						tmp = t[k].e;
					}
				}
				sum++;				
			}
		}
		cout << "#" << sum*10 << endl; 
	}
	
	return 0;
}
