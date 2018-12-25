#include <iostream>
#include <fstream>

	using namespace std;
	
	struct mydata{
		
		int key;
		string value;
	};
	
	int main(){
		
		ifstream fin("data.txt");
		mydata a[30];
		for(int i=0;i<30;i++){
			fin>>a[i].value>>a[i].key;
		}
		int count[5];
		for(int i=0;i<5;i++){
			count[i] = 0;
		}
		
		//---------------------------------Ëã·¨²¿·Ö 
		for(int i=0;i<30;i++){
			count[a[i].key]++;
		}
		for(int i=0;i<4;i++){
			count[i+1] += count[i];
		}
		mydata aux[30];
		for(int i=0;i<30;i++){
			aux[count[a[i].key-1]++] = a[i];
		}
		for(int i=0;i<30;i++){
			cout<<aux[i].key<<aux[i].value<<endl;
		}
		
		return 0;
	} 
