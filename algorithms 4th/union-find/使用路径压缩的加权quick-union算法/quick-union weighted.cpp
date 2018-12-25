#include <iostream>
	
	using namespace std;
	
	typedef struct	NODE{
		
		int a;
		NODE* next;
		
	}node;
	
	class UF{
		
		private:
			
		public:
			
			int *id;
			int *sz;
			int count;
			int component_num;
			int stack[10];
			int stack_num;
			
			UF(int n){
				
				count = n;
				component_num = n;
				id = new int[count];
				sz = new int[count];
				stack_num = 0;
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
			
			int find(int a){ //在寻找根节点的同时顺带对路径压缩 数据量大时应该有用
			//目前看来貌似没什么卵用 
				
			/*	while(a != id[a]){
					stack[stack_num] = a;
					stack_num++;
					a = id[a];
				} 
				for(int i =0;i<stack_num;i++){
					id[stack[i]] = a;
				}
				stack_num = 0;*/
				
				//书本方法 ,更为合理简单，不过不能一次处理长度的路径 
				//我毕竟还是图样图森破 
				while(a != id[a]){
					id[a] = id[id[a]];
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
	};
	
	int main(){
		
		UF a(10);
		a.un(4,3);
		a.un(3,8);
		a.un(6,5);
		a.un(9,4);
		a.un(2,1);
		a.un(5,0);
		a.un(7,2);
		a.un(6,1);
		a.un(8,9);
		a.un(1,3);
		for(int i=0;i<10;i++){
			a.find(i);
		}
		a.showall();
		a.showweight();
		
		
		return 0;
	} 
