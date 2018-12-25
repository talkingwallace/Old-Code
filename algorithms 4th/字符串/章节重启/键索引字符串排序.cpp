#include <iostream>
#include <cstdlib>
#include <fstream>

	using namespace std;
	
	struct String{
		
		string value;
		int key;		
	};
	
	int main(){
	
		ifstream fin("data.txt");
		String a[20];
		for(int i=0;i<20;i++){
			fin>>a[i].value>>a[i].key;
		}
		
		return 0;
	} 
