#include <iostream>
#include <stdio.h>
#include <ctype.h>
#define TYPE int
  using namespace std;
  
    typedef struct NODE{  //-----------------in_queue˵���ڵ��Ƿ��ڶ��� 
    	
    	TYPE value;
    	NODE *link;
    	int in_queue;
    	int num;
    	
	}node;
  
  
   class linkedlist{         //--------------------------------------------������ 
   	
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
		
		node* count(node*pt,int n){           //��ĳ���ڵ㿪ʼ�����ĺ��� 
			
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
		
        void incircle(){                      //��һ���������ӳ�ѭ������ 
        	end->link = head;
        	circle = 1;
		}
		
		void showlen(){
			cout<<len<<endl;
		}
		
		node* next(node*pt){               //Ѱ������ڵ���һ��λ�ڶ��еĽڵ� 
			node* read=pt->link;
	        while(1){
	        	if(read->in_queue==1){
	        		break;
				}
				read = read->link;
			}
			return read;
		}
		/*���˼·���ӵ�һ���ڵ㿪ʼ��������������һ���ڵ㣬���in_queue����1��������0����ʾ���У�Ȼ���� next
		�ҵ���һ�����нڵ㣬�Դ�ѭ��ֱ�������� outline Ϊ���г��� ��˵�����еĽڵ��Ѿ�����*/ 
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
   	
   	linkedlist& operator+(linkedlist& a,int n){ //---����+���㽫Ԫ���������� 
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
        cout<<"ʹ��Ĭ�ϲ������ݻ����Լ��������ݣ�1.Ĭ�� 2.����\n";		    
        int choice = 0;
        cin>>choice;
        if(choice == 1){
        	joseph+3+1+7+2+4+8+4;        //�������� 
		    joseph.incircle();
		    cout<<"���Ϊ��"<<endl;
            joseph.joseph_problem(20);  //ʵ�ַ��������� 
		}
		else if(choice == 2){
			fflush(stdin);
			int len = 0;
			int value;
			int initial;
			cout<<endl<<"���ݸ�����";
			if(!scanf("%d",&len)){cout<<"��������!";return 0;}
			
			cout<<endl<<"��ʼֵ��\n";
		    if(!scanf("%d",&initial)){cout<<"��������!";return 0;}
		    
			cout<<endl<<"������������\n";
			for(int i=0;i<len;i++){
				if(!scanf("%d",&value)){cout<<"��������!";return 0;}
                joseph+value;
			}
			joseph.incircle();
			cout<<endl<<"���Ϊ��\n";
            joseph.joseph_problem(initial);
		}
		else{
			cout<<"����ѡ������"; 
		}
        
   		return 0;
	   }
