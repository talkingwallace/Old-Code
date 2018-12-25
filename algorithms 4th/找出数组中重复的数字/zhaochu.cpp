#include <iostream>
	
	using namespace std;
	
	int main(){
		
		int a[10] = {1,2,3,3,4,4,4,5,6,9};
		int hash[10];
		for(int i=0;i<10;i++)hash[i] = 0;
		
		for(int i=0;i<10;i++){
			hash[a[i]]+=1;
		}
		
		for(int i=0;i<10;i++){
			if(hash[i]>1)cout<<i<<' ';
		}
		
		return 0;
	} 
