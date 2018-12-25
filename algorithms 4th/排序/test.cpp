#include <iostream>

	using namespace std;
	
	int plus(int a){
		return a;
	}
	
	int caonima(int a,int b){
		return a+b;
	}
	
	int main(){
		
		int a = 5,b = 6;
		int c = 12;
		a = b = c;
		cout<<a<<b<<c;
	} 
