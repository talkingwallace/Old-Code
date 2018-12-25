#include <iostream>
#include <string>
 using namespace std;

  
   template <class T>
   class any{
   	
   	private:
   		T value;
   		any* link;
   	public:
   	    void get(int a){
   	         value = a;
       	   }
       	void get(char a){
       		 value = a;
		   }
       	void show_to_you(){
       		  cout << value;
		   }
        T show(){
        	return value;
		}
		any* showpt(any &n){
			link = &n;
		}
   };
   

  int main(){
  	
  	char k = 's';
  	any<char> hi;
  	any<int> test;
  	hi.get(k);
  	test.get(12);
  	hi.show_to_you();
  	cout<<endl;
  	test.show_to_you();
    hi.showpt(test);
  	
   	  	
  	return 0;
  }
