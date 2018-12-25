#include <iostream>

   int hello(int &a){
   	a +=a;
   	return a;
   	
   }
   int main(){
   	
   	using namespace std;
   	int a = 10;
   	hello(a);
   	cout<<a;
   	return 0;
   }
