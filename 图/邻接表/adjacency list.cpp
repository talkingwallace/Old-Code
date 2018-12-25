#include <iostream>
#include <stdio.h>
#include "queue.h"
#define MAX_V_NUM 20
#define Vtype char

    using namespace std;
    
    enum{
       DG =1,UDG = 0
	};
    
    typedef struct Arcnode{
    	
    	int adjvex;
    	Arcnode *next;
    	void *info;
    	
	}arcnode;
	
	typedef struct Vnode{
		
		Vtype data;
	    arcnode *arc;
	    
	}vnode,adjlist[MAX_V_NUM];
	
	class algraph{
		
		private:
			
			adjlist vertices;
			int vnums,arcnums;
			int kind;
			bool visited[MAX_V_NUM];
			
			int insertarc(int a,int b){
				
				if(a==b||a>=vnums||b>=vnums){
			       cout<<"no can do";
				   return 0;	
				}
				
				arcnode* temp = new arcnode;
				if(temp!=NULL){
					temp->adjvex = b;
					temp->next = NULL;
					temp->info = &vertices[b];
				}
				else{
					delete temp; return 0;
				}
				
                if(vertices[a].arc==NULL){
                	vertices[a].arc = temp;
				}
				else{
					arcnode* read = vertices[a].arc;
	                while(1){
	                	if(read->adjvex == b){
	                		delete temp; return 0;
						}
						if(read->next==NULL){
							break;
						}
						else{
							read = read->next;
						}
					}
					read->next = temp;
				}
				return 1;
			}
			
			int p_delarc(int a,int b){
				
				if(a>=vnums){
					return 0;
				}
				arcnode **read = &vertices[a].arc;
				for(;(*read)!=NULL;read =&((*read)->next)){ //??
					if((*read)->adjvex==b){
						arcnode* temp =*read;
						*read = temp->next;
						delete temp;
						break;
					}
				}
				return 1;
			}
			
		public:
			
			algraph(){
				vnums =0;
				arcnums =0;
				kind = 0;
				for(int i=0;i<MAX_V_NUM;i++){
					vertices[i].arc = NULL;
				}
			}
			
			int createUDG(){
				
				kind = UDG;
				cout<<"nums of v?";
				cin>>vnums;
				fflush(stdin);
				
				if(vnums<=MAX_V_NUM){
					for(int i=0;i<vnums;i++){
						cout<<"data of "<<i<<": ";
						cin>>vertices[i].data;
						cout<<endl;
					}
				}
				else{
					return 0;
				}
				
				cout<<"\nnums of arc?";
				cin>>arcnums;
				fflush(stdin);
				if(arcnums<=vnums*(vnums-1)){
                      for(int i=0;i<arcnums;i++){
                      	
                      	 int a,b;
					     cout<<"realation?\n";
					     cin>>a>>b;
					     insertarc(a,b);
					     insertarc(b,a);
					  }
				}
				else{
					return 0;
				}
				
				return 1;
			}
			
			
			int locate(Vtype value){
				
				for(int i=0;i<vnums;i++){
					if(value == vertices[i].data){
						return i;
					}
				}
				return -1;
			}
			
			Vtype getvex(int i){
				
				if(i<vnums){
					return vertices[i].data;
				}
			}
			
			void putvex(int i,Vtype value){
				if(i<vnums){
					vertices[i].data = value;
				}
			}
			
			int firstadj(int i){
				
				if(i<vnums){
					if(vertices[i].arc!=NULL){
						return vertices[i].arc->adjvex;
					}
				}
			}	
			
			int nextadj(int a,int b){
				
				if(a<vnums&&b<vnums){
				    arcnode *read = vertices[a].arc;
				    for(;read!=NULL;read = read->next){
				    	if(read->adjvex==b&&read->next!=NULL){
				    		return read->next->adjvex;
						}
					}
				}
				    return -1;
			}
			
			void addarc(int a,int b){
				 
                 if(a<vnums&&b<vnums){
                    insertarc(a,b);
	                if(kind == UDG){
	             	  insertarc(b,a);
				   }
				   arcnums++;
				 }
			}
			
			void delarc(int a,int b){
				
				if(a<vnums&&b<vnums){
					p_delarc(a,b);
					if(kind == UDG){
						p_delarc(b,a);
					}
					arcnums--;
				}
			}
			
			//---------------------------------------±éÀú
			
			 void visit(int i){
			 	 
			 	 cout<<vertices[i].data<<'('<<i<<')'<<' ';
			 }
			 
			 void DFS(int i){
			 	
			 	visited[i] = 1;
			 	visit(i);
			 	for(int j =firstadj(i);j>=0;j=nextadj(i,j)){
			 		if(!visited[j]){
			 			DFS(j);
					 }
				 }
			 }
			 
			 void DFStraverse(){
			 	
			 	for(int i=0;i<vnums;i++){
			 		visited[i] = 0;
				 }
				for(int i=0;i<vnums;i++){
					if(!visited[i]){
						DFS(i);
					}
				}
			 }
			 
			 void BFStraverse(){
			 	
			 	for(int i=0;i<vnums;i++){
			 		visited[i] = 0;
				 } 
				 queue assist;
				 for(int i=0;i<vnums;i++){
				 	if(!visited[i]){
				 		visited[i] = 1;
				 		visit(i);
				 		assist+i;
				 		while(!assist.is_empty()){
				 			int u=--assist;
				 			for(int j=firstadj(u);j>=0;j=nextadj(u,j)){
				 				if(!visited[j]){
				 					visited[j] = 1;
				 					visit(j);
				 					assist+j;
								 }
							 }
						 }
					 }
				 }
				 delete assist;
			 }
	};
    
    int main(){
    	    
	    algraph test;
		test.createUDG();
		test.DFStraverse();	
    	cout<<endl;
    	test.BFStraverse();
    	return 0;
	}
