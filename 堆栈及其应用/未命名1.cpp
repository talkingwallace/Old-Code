#include <iostream>

 using namespace std;

 template <class any>

 
 void swap(any &a,any &b){
 	
 	any temp;
 	temp = a;
 	a = b;
 	b = temp;
 	
 }
 
 int main(){
 	
 	int a = 10;
 	int b = 20;
 	swap(a,b);
 	return 0;
 }
