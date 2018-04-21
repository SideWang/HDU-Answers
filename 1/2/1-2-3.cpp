#include <iostream> 
using namespace std;

#define LOCAL 1
#if LOCAL
#include <fstream>
#include <ctime>
#endif

int t[100];

int main(){
#if LOCAL
	fstream cin("datain.txt",fstream::in);
	fstream cout("dataout.txt",fstream::app);
	cout << endl << "time:"<< time(0)%1000 << endl;
#endif
	int n,m = 0;
	while((cin >> n),n){
		m++;
		int sum = 0,avg;
		for(int i = 0;i < n;i++){
			cin >> t[i];
			sum += t[i];
		}
		avg = sum / n;
		sum = 0;
		for(int i = 0;i < n;i++){			
			if(t[i] > avg)
				sum += (t[i] - avg);
		}
		if(m != 1)
			cout << endl;
		cout << "Set #" << m << endl;
		cout << "The minimum number of moves is " << sum << ". " << endl;
	}
	
	return 0;
}
