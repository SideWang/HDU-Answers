#include <iostream> 
using namespace std;

#define LOCAL 0
#if LOCAL
#include <fstream>
#include <ctime>
#endif

int t[26];

int main(){
#if LOCAL
	fstream cin("datain.txt",fstream::in);
	fstream cout("dataout.txt",fstream::app);
	cout << endl << "time:"<< time(0)%1000 << endl;
#endif
	
	
	return 0;
}
