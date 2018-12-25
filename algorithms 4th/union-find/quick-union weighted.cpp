#include <iostream>
#define TOP -2
#define BUTTOM -3

	using namespace std;
	
	class UF{
		
		private:
			
		public:
			
			int *id;
			int *sz;
			int count;
			int component_num;
			
			UF(int n){
				
				count = n;
				component_num = n;
				id = new int[count];
				sz = new int[count];
				for(int i = 0;i<n;i++){
					id[i] = i;
					sz[i] = 1;
				}
				
			}
			
			inline int show_count(){
				return count;
			}
			
			int un(int a,int b){
				
				int aROOT = find(a);
				int bROOT = find(b);
				
				if(aROOT == bROOT){
					return 1; 
				} 
				
				if(sz[aROOT]>=sz[bROOT]){
					id[bROOT] = aROOT;
					sz[aROOT] +=sz[bROOT];
				} 
				else{
					id[aROOT] = bROOT;
					sz[bROOT] += sz[aROOT];
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
			
			void showweight(){
				
				for(int i = 0;i<count;i++){
					cout<<i<<'('<<sz[i]<<')'<<' ';
					if((i+1)%5==0){
						cout<<'\n';
					}
				}
			}
			
			void showall(int n){
				
				int endofline = n;
				for(int i=0;i<count;i++){
					if(endofline%n==0)cout<<endl;
					cout<<find(i)<<' ';
					endofline++;
				}
			}
	};
    
    class Percolation{
    	
    	private:
    		UF *uf;
    		int *id;
    		int n;
    		int total;
    	public:
    		
    		Percolation(int N){
    			
    			n = N;
    			cout<<total;
    			uf = new UF(total+2);//还有一个头 一个底 
    			id = new int[total];
    			for(int i=0;i<total;i++){
    				id[i] = 0;
				}
			}
			
			void open(int i,int j){
				
				if(i>=0&&i<n&&j>0&&j<n){
					id[i+j*5] = 1;
				}
			}
			
			int isopen(int i,int j){
				
				if(i>=0&&i<n&&j>0&&j<n){
					return id[i+j*5];
				}
				else{
					cout<<"out of bounds!";
					return -1;
				}	
			}
			
			bool isfull(int i,int j){//i dont think it's necessary to use it    skip it
			
				
			}
			
			bool canpercolate(){
				
			}
			
			void process(){
				uf->showall();
			}
	};

	int main(){
		
	
		
		
		return 0;
	} 
