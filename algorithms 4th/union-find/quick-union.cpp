#include <iostream>
	
	using namespace std;
	
	class UF{
		
		private:
			
		public:
			
			int *id;
			int count;
			int component_num;
			
			UF(int n){
				
				count = n;
				component_num = n;
				id = new int[count];
				for(int i = 0;i<n;i++){
					id[i] = i;
				}
			}
			
			inline int show_count(){
				return count;
			}
			
			int un(int a,int b){
				
				int aROOT = find(a);
				int bROOT = find(b);
				
				if(a == b){
					return 1; 
				} 
				else{
					id[aROOT] = bROOT;
				}
				
				--component_num;
			}
			
			int find(int a){
				
				while(a != id[a]){
					a = id[a];
				} 
				return a;
			}
			
			inline bool connected(int a,int b){
				return id[a] == id[b]; 
			}

			inline void showall(){
				
				for(int i= 0;i<count;i++){
					cout<<i<<'('<<id[i]<<')'<<' ';
					if((i+1)%5==0){
						cout<<'\n';
					}
				}
			}
	};
	
	int main(){
		
		UF a(10);
		a.un(0,1);
		a.un(0,3);
		a.un(1,3);
		a.un(1,4);
		a.un(3,4);
		a.un(1,2);
		a.un(2,5);
		a.un(7,8);
		a.un(8,9);
		a.un(9,6);
		a.un(7,6);
		a.showall();
		
		return 0;
	} 
