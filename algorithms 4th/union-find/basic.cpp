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
			
			void un(int a,int b){
				
			}
			
			inline int find(int a){
				return id[a];
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
		cout<<a.count<<endl;
		for(int i=0;i<a.count;i++){
		 	cout<<a.id[i]<<' ';
		} 
		
		return 0;
	} 
