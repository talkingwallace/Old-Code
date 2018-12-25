#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>

	using namespace std;
	
	int main(){
		
		srand(time(0));
		ofstream fout("data2.txt");
		for(int i=0;i<30;i++){
			char a;
			fout<<rand()%4+1;
			for(int k=0;k<6;k++){	
				a = (rand()%26)+'a';
				fout<<a;
			}
			fout<<endl;
		}
		
		return 0;
	} 
