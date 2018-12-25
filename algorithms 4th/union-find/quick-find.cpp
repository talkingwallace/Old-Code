#include <iostream>
	
	using namespace std;
	
	class UF{
		
		private:
			
		public:
			
			int *id;
			int count;
			
			UF(int n){
				
				count = n;
				id = new int[count];
				for(int i = 0;i<n;i++){
					id[i] = i;
				}
			}
			
			inline int show_count(){
				return count;
			}
			
			inline void showall(){
				
				for(int i= 0;i<count;i++){
					cout<<i<<'('<<id[i]<<')'<<' ';
					if((i+1)%5==0){
						cout<<'\n';
					}
				}
			}
			
			int un(int a,int b){ //此处用的是quick-union的方法 
				
				int aID = find(a);
				int bID = find(b);
				
				if (aID == bID) return 0;
				else{
					for(int i =0;i<count;i++){
						
						if(id[i] == aID){
							id[i] = bID;
						}
					}
				}
				
				return 1;
			}
			
			inline int find(int a){
				return id[a];
			}
			
			inline bool connected(int a,int b){
				return id[a] == id[b]; 
			}
		
	};
	
	int main(){
		
		UF a(10);
		int b,c;
		
		a.un(9,0); 
		a.un(3,4); 
		a.un(5,8); 
		a.un(7,2); 
		a.un(2,1); 
		a.un(5,7); 
		a.un(0,3); 
		a.un(4,2); 
		a.showall();
		
		
		return 0;
	} 
