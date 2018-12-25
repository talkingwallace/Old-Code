#include <iostream>
#include <stdlib.h>
#include "queue.h"
#include <fstream>
#define Vtype string
#define MAX 30
#define infinite -1

   using namespace std;
   
   typedef struct EBOX{
   	
   	 int visited;
   	 int avex,bvex;
   	 EBOX *alink,*blink;
   	 int info;
   	 
   }ebox;
   
   typedef struct VexBox{
   	
   	   Vtype data;
   	   ebox* frist;
   	   ebox **head;
   	   
   }vexbox;
//----------------------------------------------类
  
   class amlgraph{
   	
   	private:
   		vexbox list[MAX];
   		int vnums,arcnums;
   		bool visited[MAX];
   		
   	public:
   		
   		   amlgraph(){
   			
   			vnums = 0;
   			arcnums = 0;
   			for(int i=0;i<MAX;i++){
   				list[i].frist = NULL;
   				list[i].head = &(list[i].frist);
			   }
		   }
   		   
		   inline int showvnums(){
		   	return vnums;
		   }
		   
		   inline int showarcnums(){
		   	return arcnums;
		   }
		   
		   inline vexbox* showlist(){
		   	    return list;
		   }
		   
		   int set(int n){
		   	vnums = n;
		   }
		   
		   int findnext(int n,ebox* pt);
		   
		   int findanother(int n,ebox*pt);

		   bool insertarc(int a,int b,int info);
		   
		   int firstadj(int i);
		   
		   int nextadj(int a,int t);
		   
          /*以下都为遍历所用*/        
           void visit(int n){
           	   cout<<list[n].data<<'('<<n+1<<')'<<"     ";
		   }
		   
		   void DFS(int i){
			 	
			 	visited[i] = 1;
			 	visit(i);
			 	for(int j =firstadj(i);j>=0;j=nextadj(i,j)){
			 		if(!visited[j]){
			 			cout<<" ("<<i+1<<','<<j+1<<") "<<endl;
			 			DFS(j);
					 }
				 }
			 }
			 
		   void DFStraverse(int n){
			 	
			 	int limit = vnums;
			 	for(int i=0;i<limit;i++){
			 		visited[i] = 0;
				 }
				for(int i=n;i<limit;i++){
					if(!visited[i]){
						DFS(i);
					}
					if(i+1==limit){
						limit = n;
						n = 0;
						i = 0;
					}
				}
			 }
			 
		  	void BFStraverse(int n){
			 	
			 	int limit = vnums;
			 	for(int i=0;i<vnums;i++){
			 		visited[i] = 0;
				 } 
				 queue assist;
				 for(int i=n;i<limit;i++){
				 	if(!visited[i]){
				 		visited[i] = 1;
				 		visit(i);
				 		assist+i;
				 		while(!assist.is_empty()){
				 			int u=--assist;
				 			for(int j=firstadj(u);j>=0;j=nextadj(u,j)){
				 				if(!visited[j]){
				 					cout<<" ("<<u+1<<','<<j+1<<") "<<endl;
				 					visited[j] = 1;
				 					visit(j);
				 					assist+j;
								 }
							 }
						 }
					 }
					 if(i+1==limit){
					 	limit = n;
					 	n = 0;
					 	i = 0;
					 }
				 }
			 }
   	
   };
   
//-------------------------------------------------------具体设计 
   bool amlgraph::insertarc(int a,int b,int info){
   	
   	    if(a>vnums||b>vnums)return 0;
   	
   	    ebox* temp = new ebox;
   	    if(temp==NULL)return 0;
   	    
   	    temp->alink = NULL;temp->blink = NULL;
   	    temp->avex = a;temp->bvex = b;
   	    temp->info = info;
   	    temp->visited = 0;
   	    
   	    *(list[a].head) = temp;list[a].head = &(temp->alink);
        *(list[b].head) = temp;list[b].head = &(temp->blink);
        arcnums ++;
        
        return 1;
   }
   
    int amlgraph::findnext(int n,ebox* pt){
    	
		if(pt!=NULL){
		   	if(n==pt->avex){
		   	     return 0;
			 }
			else if(n==pt->bvex){
				 return 1;
			}
		}
		return -1;
	}
    
    int amlgraph::findanother(int n,ebox* pt){
    	
    	if(n>vnums)return 0;
    	if(pt->avex==n){
    		return pt->bvex;
		}
		else{
			return pt->avex;
		}
		
	}
	
	int amlgraph::firstadj(int i){
   			
   	  ebox *pt = list[i].frist;
   	  if(i<vnums&&pt!=NULL){
   		if(i==pt->avex){
   			return pt->bvex;
		}
	   else{
			return pt->avex;
		}
	  }
	}
	
	int amlgraph::nextadj(int a,int t){
		
		if(t>vnums||a>vnums)return -1;
		
		int mark = 1;
		ebox *pt = list[a].frist;
		for(;pt!=NULL;){
			if(findanother(a,pt)==t)mark=0;//找到了t 那么mark = 0,pt移至下一条边 
	        if(findnext(a,pt)){
           	  	pt = pt->blink;
			}
			else{
				pt = pt->alink;
			}
			if(mark==0)break;
		}
		if(pt==NULL){
			return -1;
		}
		else{
			return findanother(a,pt);  //然后返回这条边的另一端 就得到nextadj 
		}
	}
    
//--------------------------------------------------------  
    
    void thedata(amlgraph *graph){
    	
    	vexbox* pt = graph->showlist();
    	for(int i=0;i<graph->showvnums();i++){
    		cout<<pt[i].data<<'='<<i<<' ';
    		if(i%5==0&&i!=0)cout<<endl;
		}
	}
    
   int main(){
    //------------测试数据初始化--------------------------- 
    amlgraph map;
    map.set(25);
    ifstream inFile,inArc;
    inFile.open("city.txt");
    inArc.open("arc.txt");
    vexbox* initial = map.showlist();
    for(int i=0;inFile>>initial[i].data;i++);
    map.insertarc(0,9,1892);
    map.insertarc(1,2,668);
    map.insertarc(1,9,1145);
    map.insertarc(8,9,216);
    map.insertarc(9,10,676);
    map.insertarc(10,11,511);
    map.insertarc(11,12,349);
    map.insertarc(2,6,137);
    map.insertarc(2,11,695);
    map.insertarc(5,6,704);
    map.insertarc(5,7,397);
    map.insertarc(4,5,305);
    map.insertarc(3,4,242);
    map.insertarc(21,18,672);
    map.insertarc(23,24,140);
    map.insertarc(10,13,842);
    map.insertarc(13,16,1100);
    map.insertarc(13,17,967);
    map.insertarc(16,17,639);
    map.insertarc(17,18,902);
    map.insertarc(11,14,534);
    map.insertarc(14,18,409);
    map.insertarc(18,19,367);
    map.insertarc(12,15,651);
    map.insertarc(15,19,825);
    map.insertarc(19,20,622);
    map.insertarc(17,21,672);
    map.insertarc(22,21,255);
    map.insertarc(18,23,675);
   

   	return 0;
   }
