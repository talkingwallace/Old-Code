#include <iostream>


	using namespace std;
	
	template <class type>                                                                                                                                                                                                                                           
	class bag{
		
		private:
			
		public:
			type *pt; 
			int length;
			int num;
			
			bag(int n){
						
				length = n;
				pt = new type[length];
				num = 0;	
			}	
			
			bag& operator +(type n){		//input
				
				if(num<=length){
					
					pt[num] = n;
					num++;
				}
				
				else{
					cout<<"hey! the bag is full!\n";
				}
				return *this;
			}
			
			void traverse(){
				
				for(int i = 0;i<num;i++){
					cout<<pt[i]<<' ';
				}
			}
			
			void average(){
				
				int sum = 0;
				for(int i=0;i<num;i++){
					sum += pt[i];
				}
				cout<<"the average is:"<<sum/num<<endl;
			}
	};

	int main(){
		
		bag<int> a(10);
		a+5+6+7+2+9+10+11+12+13+14+11+12+13+14;
		a.traverse();
		a.average();
		
		return 0;
	}
