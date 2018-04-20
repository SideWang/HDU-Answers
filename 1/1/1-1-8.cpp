#include <iostream> 
using namespace std;

#define LOCAL 0
#if LOCAL
#include <fstream>
#include <ctime>
#endif

int main(){
#if LOCAL
	fstream cin("datain.txt",fstream::in);
	fstream cout("dataout.txt",fstream::app);
	cout << endl << "time:"<< time(0)%1000 << endl;
#endif
	int m,n;
	cin >> m;
	while(m--){
		cin >> n;
		int sum = 0,num;
		for(int i = 0;i < n;i++){
			cin >> num;
			sum += num;
		}
		cout << sum;
		if(m)
			cout << endl << endl;
	}
		
	return 0;
}
