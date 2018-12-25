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
//----------------------------------------------��
  
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
		   
          /*���¶�Ϊ��������*/        
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
   
//-------------------------------------------------------������� 
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
			if(findanother(a,pt)==t)mark=0;//�ҵ���t ��ômark = 0,pt������һ���� 
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
			return findanother(a,pt);  //Ȼ�󷵻������ߵ���һ�� �͵õ�nextadj 
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
    //------------�������ݳ�ʼ��--------------------------- 
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
    //-------------------����------------------------- 
    cout<<"--------------------------------------------\n\n";
    cout<<"��ӭʹ��ͼ���������������ղ˵�����ʾ������\n\n";
    cout<<"--------------------------------------------\n";
    cout<<"���Ĳ����ǣ�\n1.ʹ��Ĭ�ϲ������ݣ���ͨ����ͼ)\n2.�Լ�����ͼ\n"
	      "(�����1 2�����ַ���������)\n";
    cout<<"�����������:\n";
    int choice = 0;
    amlgraph mine;
    cin>>choice;
    
    if(choice == 1){
    	
    	while(1){
    		
    		system("cls");
    		int ch1;
    		cout<<"��ӭʹ�ò������ݣ�\n���㰴����ʾ����\n"
    		      "1.�鿴�������\n"
    		      "2.������ȱ���������ӡ����˳����߼�\n"
				  "3.���й�ȱ���������ӡ����˳����߼�\n"
				  "4.�˳�\n";
			
			cin>>ch1; 
			if(ch1 == 1)thedata(&map);
			
		    else if(ch1==2||ch1==3){
            	
				cout<<"����ָ����ʼ��:\n����:";
			    int start;
			    cin>>start;
			    if(start>=25){
			    	cout<<"������Χ��";system("pause");continue;
				}
			    
			    cout<<"\n\n��㣺   �߼�:\n";
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
		cout<<"������������ĸ���:\n";
		cin>>vnums;
		cout<<"��������ߵĸ���:\n";
		cin>>arcnums;
		mine.set(vnums);
		cout<<"������������������ͼ(���������0���1��ı� ����0 1)\n";
		for(int i=0,a,b;i<arcnums;i++){
			 cout<<"��"<<i+1<<':'<<endl; 
			 cin>>a;
			 cin>>b;
			 mine.insertarc(a,b);
		}
		cout<<"\n������ϣ�\n";
		system("pause");
		
		while(1){
			
			system("cls");
			int ch2;
			cout<<"��������ͼҪ����ʲô����??\n"
			      "1.������ȱ���������ӡ����˳����߼�\n"
			      "2.���й�ȱ���������ӡ����˳����߼�\n"
				  "3.����������������\n"
				  "4.�鿴�����������ݺ����\n"
				  "5.����\n����:\n";
				  
		    cin>>ch2;
            if(ch2==1||ch2==2){
            	
				cout<<"����ָ����ʼ��:\n����:";
			    int start;
			    cin>>start;
			    if(start>=vnums){
			    	cout<<"������Χ��";system("pause");continue;
				}
			    
			    cout<<"��㣺   �߼�:\n";
			    if(ch2==1)mine.DFStraverse(start);
			    else if(ch2==2)mine.BFStraverse(start);
				cout<<endl; 
			} 
		    else if(ch2 == 3){
		    	vexbox* pt = mine.showlist();
		    	for(int i=0;i<mine.showvnums();i++){
		    		cout<<"\n����"<<i+1<<':';
		    		cin>>pt[i].data;
				}
				cout<<"�������!\n";
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
