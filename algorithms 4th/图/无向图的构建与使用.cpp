#include <iostream>
#include "BST.h"

	using namespace std;
	
	class graph{
		
		private:
			const int v; 
			int e;
			bst *adj;
		
		public:
			
			int V(){
				return v; 
			}
			
			int E(){	
				return e;
			}	
			
			void addedge(int v,int w){
				
			}
			
			void is_adj(){
				
			}
			
			graph(int numofv):v(numofv){ //goujian kongtu
				
			}
			
			graph(int numofv,int numofe):v(numofv){
				
				e = numofe;
				adj = new bst[e];
				for(int i=0;i<e;i++){
					int a,b;
					cin>>a>>b;
					addedge(a,b);
				}
			}
	};
	
	int main(){
		

		return 0;
	}
