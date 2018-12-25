#include <iostream>
#include <stdio.h>
#include <ctype.h>
#define TYPE int
  using namespace std;
  
    typedef struct NODE{  //-----------------in_queue说明节点是否在队中 
    	
    	TYPE value;
    	NODE *link;
    	int in_queue;
    	int num;
    	
	}node;
  
  
   class linkedlist{         //--------------------------------------------链表类 
   	
   	 private:
   	 	
   	 	node *head;
   	 	node *end;
   	 	node *count_pt;
   	 	int outline;
   	 	int len;
   	 	int circle;
   	 	
   	 public:
   	 	
   	 	
   	 	linkedlist(){
   	 		
   	 		head = NULL;
   	 		end = NULL;
   	 		len = 0;
   	 		circle = 0;
   	 		count_pt = NULL;
   	 		outline = 0;
   	 		
			}

   	   friend linkedlist& operator+(linkedlist&a,int n);
		
		void show_headandend(){
			cout<<head->value<<endl<<end->value;
		}
		
		void traverse(){
			
			if(!circle){
		    for(node *read = head;read != NULL;read=read->link){
		    	cout<<read->value<<endl;
			}
		    }
		    else{
		    int n =0;
		    for(node *read = head;n<len;n++,read = read->link){
		    	cout<<read->value<<" "<<read->in_queue<<endl;
			}
		    }
		}
		
		node* count(node*pt,int n){           //从某个节点开始报数的函数 
			
	       if(circle){
	       	node *read = pt;
	        int i =n;
	        while(i-1){
	        	if(read->in_queue==1){
	        		i--;
				}
			    read=next(read);
			}
	        return read;
		   }
		}
		
        void incircle(){                      //将一个链表连接成循环链表 
        	end->link = head;
        	circle = 1;
		}
		
		void showlen(){
			cout<<len<<endl;
		}
		
		node* next(node*pt){               //寻找这个节点后第一个位于队中的节点 
			node* read=pt->link;
	        while(1){
	        	if(read->in_queue==1){
	        		break;
				}
				read = read->link;
			}
			return read;
		}
		/*解决思路：从第一个节点开始数数，当数到了一个节点，如果in_queue等于1，则将其置0，表示出列，然后用 next
		找到下一个队中节点，以此循环直到计数量 outline 为队列长度 即说明所有的节点已经出列*/ 
		void joseph_problem(int n){            
			int num = n;
			node *read = head;
		    while(1){
		        read = count(read,num);
		        if(read->in_queue==1){
		        	cout<<read->num<<' ';
		        	read->in_queue = 0;
		        	++outline;
		        	if(outline == len){ 
		        		break;
					}
		        	num = read->value;
		        	read = next(read); 
			    }
			} 	
		}
		

        
   	};
   	
   	linkedlist& operator+(linkedlist& a,int n){ //---重载+方便将元素添加入表中 
   		   	node* temp = new node;
   	 		if(temp == NULL){
   	 			cout<<"no memory";
				}
			else{
				temp->value = n;
				temp->in_queue = 1;
				temp->link = NULL;
				temp->num = a.len+1;
			}
			
			if(a.len == 0){
			    a.head = temp;
				a.end = temp;	
			}
			else{
				a.end->link = temp;
				a.end = temp;
			}
			a.len ++;
			return a;
	   }
   	
   	int main(){
   		
   	    linkedlist joseph;
        cout<<"使用默认测试数据还是自己输入数据？1.默认 2.输入\n";		    
        int choice = 0;
        cin>>choice;
        if(choice == 1){
        	joseph+3+1+7+2+4+8+4;        //测试数据 
		    joseph.incircle();
		    cout<<"结果为："<<endl;
            joseph.joseph_problem(20);  //实现方法在类中 
		}
		else if(choice == 2){
			fflush(stdin);
			int len = 0;
			int value;
			int initial;
			cout<<endl<<"数据个数？";
			if(!scanf("%d",&len)){cout<<"数据有误!";return 0;}
			
			cout<<endl<<"初始值？\n";
		    if(!scanf("%d",&initial)){cout<<"数据有误!";return 0;}
		    
			cout<<endl<<"输入所有数据\n";
			for(int i=0;i<len;i++){
				if(!scanf("%d",&value)){cout<<"数据有误!";return 0;}
                joseph+value;
			}
			joseph.incircle();
			cout<<endl<<"结果为：\n";
            joseph.joseph_problem(initial);
		}
		else{
			cout<<"您的选择有误"; 
		}
        
   		return 0;
	   }
