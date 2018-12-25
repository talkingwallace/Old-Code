#include <iostream>
#include <stdlib.h>
#include "queue.h"
#include <fstream>
#define Vtype string
#define MAX 30

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

		   bool insertarc(int a,int b);
		   
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
   bool amlgraph::insertarc(int a,int b){
   	
   	    if(a>vnums||b>vnums)return 0;
   	
   	    ebox* temp = new ebox;
   	    if(temp==NULL)return 0;
   	    
   	    temp->alink = NULL;temp->blink = NULL;
   	    temp->avex = a;temp->bvex = b;
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
    map.insertarc(0,9);
    map.insertarc(1,2);
    map.insertarc(1,9);
    map.insertarc(8,9);
    map.insertarc(9,10);
    map.insertarc(10,11);
    map.insertarc(11,12);
    map.insertarc(2,6);
    map.insertarc(2,11);
    map.insertarc(5,6);
    map.insertarc(5,7);
    map.insertarc(4,5);
    map.insertarc(3,4);
    map.insertarc(21,18);
    map.insertarc(23,24);
    map.insertarc(10,13);
    map.insertarc(13,16);
    map.insertarc(13,17);
    map.insertarc(16,17);
    map.insertarc(17,18);
    map.insertarc(11,14);
    map.insertarc(14,18);
    map.insertarc(18,19);
    map.insertarc(12,15);
    map.insertarc(15,19);
    map.insertarc(19,20);
    map.insertarc(17,21);
    map.insertarc(22,21);
    map.insertarc(18,23);
    //------------------------------------------------
    //-------------------界面------------------------- 
    cout<<"--------------------------------------------\n\n";
    cout<<"欢迎使用图遍历程序！请您按照菜单的提示来操作\n\n";
    cout<<"--------------------------------------------\n";
    cout<<"您的操作是？\n1.使用默认测试数据（交通网络图)\n2.自己构建图\n"
	      "(输入除1 2以外字符结束程序)\n";
    cout<<"请你输入序号:\n";
    int choice = 0;
    amlgraph mine;
    cin>>choice;
    
    if(choice == 1){
    	
    	while(1){
    		
    		system("cls");
    		int ch1;
    		cout<<"欢迎使用测试数据！\n请你按照提示操作\n"
    		      "1.查看城市序号\n"
    		      "2.进行深度遍历，并打印访问顺序与边集\n"
				  "3.进行广度遍历，并打印访问顺序与边集\n"
				  "4.退出\n";
			
			cin>>ch1; 
			if(ch1 == 1)thedata(&map);
			
		    else if(ch1==2||ch1==3){
            	
				cout<<"请您指定起始点:\n输入:";
			    int start;
			    cin>>start;
			    if(start>=25){
			    	cout<<"超出范围！";system("pause");continue;
				}
			    
			    cout<<"\n\n结点：   边集:\n";
			    if(ch1==2)map.DFStraverse(start);
			    else if(ch1==3)map.BFStraverse(start);
				cout<<endl; 
			}
			
			else return 0;
            
            system("pause");
		}
	}
	
	if(choice == 2){
		
		int vnums,arcnums;
		cout<<"请您先输入结点的个数:\n";
		cin>>vnums;
		cout<<"请您输入边的个数:\n";
		cin>>arcnums;
		mine.set(vnums);
		cout<<"请您逐个输入边来构架图(例：构造点0与点1间的边 输入0 1)\n";
		for(int i=0,a,b;i<arcnums;i++){
			 cout<<"边"<<i+1<<':'<<endl; 
			 cin>>a;
			 cin>>b;
			 mine.insertarc(a,b);
		}
		cout<<"\n构造完毕！\n";
		system("pause");
		
		while(1){
			
			system("cls");
			int ch2;
			cout<<"请问您对图要进行什么操作??\n"
			      "1.进行深度遍历，并打印访问顺序与边集\n"
			      "2.进行广度遍历，并打印访问顺序与边集\n"
				  "3.给各个结点添加数据\n"
				  "4.查看各个结点的数据和序号\n"
				  "5.结束\n输入:\n";
				  
		    cin>>ch2;
            if(ch2==1||ch2==2){
            	
				cout<<"请您指定起始点:\n输入:";
			    int start;
			    cin>>start;
			    if(start>=vnums){
			    	cout<<"超出范围！";system("pause");continue;
				}
			    
			    cout<<"结点：   边集:\n";
			    if(ch2==1)mine.DFStraverse(start);
			    else if(ch2==2)mine.BFStraverse(start);
				cout<<endl; 
			} 
		    else if(ch2 == 3){
		    	vexbox* pt = mine.showlist();
		    	for(int i=0;i<mine.showvnums();i++){
		    		cout<<"\n数据"<<i+1<<':';
		    		cin>>pt[i].data;
				}
				cout<<"处理完成!\n";
			}
			else if(ch2 == 4){
				thedata(&mine);
			}
		    else{
		    	return 0;
			}
			
			system("pause"); 
		}
	}

   	return 0;
   }
