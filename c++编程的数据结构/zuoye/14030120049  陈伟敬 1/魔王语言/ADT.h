#ifndef QUEUE
#define QUEUE
#include <iostream>
#define TYPE char

  using namespace std;
  
  typedef struct Node{  //�ڵ�------------------------------------------- 
  	
  	TYPE value;
  	Node *link;
  	
  }node;
  

   //------------------------------------------------------����-�� 
  class queue{
  	
  	private:
  	  	
  	  	int len;       //ͷ��β������ 
  	  	node *head;
  	  	node *end;
  		
  	public:
  		
		  int operator +(TYPE n){           //�� class + TYPE ��һ�� TYPE ��ӵ������� ------------------------------
  			if(len == 0){
  				head = new node;
  				if(head == NULL){
  					cout<<"no memory!!";
  					return 0;
				  }
  				end = head;
  				head->link = NULL;
  				head->value = n;
			  }
			else{
				node *temp;
				temp = new node;
				if(temp == NULL){
					cout<<"no memory!!";
				    return 0;
				}
				temp->link = NULL;
				temp->value = n;
				end->link = temp;
				end = temp;
			}
			++ len;
			return 1;
		  }
		  
		  void in_queue(string str){
		  	for(int i = 0;str[i]!='\0';i++){
		  		*(this)+str[i];
			  }
		  }
		  
		int operator --(){                      //�� '--' �˵�һ���ڵ� ------------------------------
			if(len == 0){
				cout<<"I got nothing to do!";
				return 0;
			}
			node *temp = head;
			head = head->link;
			delete temp;
			-- len;
			if(len == 0){
				end = NULL;
			}
		}
		
		// һЩ���ܺ��� --------------------------------------
		 int showlen(){
		 	return len;
		 }
		 
		 int isempty(){
		 	return len == 0;
		 }
		 
		 node* showhead(){
		      if(!isempty()){
		      	return head;
			  }
		 }
		
		 node* showend(){
			 if(!isempty()){
			 	return end;
			 }
	     }
	     
	    void traverse(){
			for(node *read = head;read!=NULL;read = read->link){
				cout<<read->value;
			}
			cout<<endl;
		 }
	     
		queue(){
			len = 0;
			head = NULL;
			end = NULL;
		}
		queue(node *first){
			head = first;
			end = first;
			len = 1;
		}
		
		void empty_queue(){
			for(;len!=0;--*(this));
		}
		
	    string output(){
		 	string result;
		 	for(node* read = head;read != NULL;read =read->link){
		 		result += read->value;
			 }
            return result;
		 }
  	
   };
   
   
    //--------------------------------------------------------------------------------ջ-��
	 
    class stack{
      	
      	private:
      		
      	  int len;       //ͷ��β������ 
  	  	  node *head;
  	  	  node *end;
  	  	  
  	  	public:
  	  		
  	  		
  	  	 // ��ջ�ĺ�����������------------------------------------------------------ 
            int push(TYPE n){          
  			if(len == 0){
  				head = new node;
  				if(head == NULL){
  					cout<<"no memory!!";
  					return 0;
				  }
  				end = head;
  				head->link = NULL;
  				head->value = n;
			  }
			else{
				node *temp;
				temp = new node;
				if(temp == NULL){
					cout<<"no memory!!";
				    return 0;
				}
				temp->link = NULL;
				temp->value = n;
				end->link = temp;
				end = temp;
			}
			++ len;
			return 1;
		  }
		  
		   int operator +(TYPE n){
		   	  	
			if(len == 0){
  				head = new node;
  				if(head == NULL){
  					cout<<"no memory!!";
  					return 0;
				  }
  				end = head;
  				head->link = NULL;
  				head->value = n;
			  }
			else{
				node *temp;
				temp = new node;
				if(temp == NULL){
					cout<<"no memory!!";
				    return 0;
				}
				temp->link = NULL;
				temp->value = n;
				end->link = temp;
				end = temp;
			}
			++ len;
			return 1;
		   }
		   
		   void push(string str){
		   	 for(int i =0;str[i]!='\0';i++){
		   	 	  *(this) + str[i];
				}
		   }
		  
		  //��ջ�ĺ�����������----------------------------------------------------------------------------- 
		  
		  int pop(){               
		  	if(len == 0){
		  		cout<<"empty";
		  		return 0;
			  }
			else{
				node* read = head;
                if(read == end){
                	delete read;
                	end = NULL;
                	head = NULL;
				}
				else{
		           while(1){
		           	 if(read->link == end){
		           	 	break;
						}
					 read = read->link;
				   }
				   delete end;
				   end = read;
				   read->link = NULL;
				}
				--len;
				return 1;
			}
		  }
		  
		  int operator --(){
		  	
			  if(len == 0){
		  		cout<<"empty";
		  		return 0;
			  }
			else{
				node* read = head;
                if(read == end){
                	delete read;
                	end = NULL;
                	head = NULL;
				}
				else{
		           while(1){
		           	 if(read->link == end){
		           	 	break;
						}
					 read = read->link;
				   }
				   delete end;
				   end = read;
				   read->link = NULL;
				}
				--len;
			}
		  }
		  
		  
		  //һЩ���ܺ���------------------------------------------------------------------------------------ 
		  
		 void traverse(){
			for(node *read = head;read!=NULL;read = read->link){
				cout<<read->value<<' ';
			}
			cout<<endl;
		 }
		
		 int showlen(){
		 	return len;
		 }
		 
		 int isempty(){
		 	return len == 0;
		 }
		 
		 node* showhead(){
		      if(!isempty()){
		      	return head;
			  }
		 }
		
		 node* showend(){
			 if(!isempty()){
			 	return end;
			 }
	     }
		  
		  stack(){
		  	len = 0;
		  	head = NULL;
		  	end = NULL;
		  }
		 
		 string output(){
		 	string result;
		 	for(node* read = head;read != NULL;read =read->link){
		 		result += read->value;
			 }
            return result;
		 }
		   
         int is_compared(string a){
		 	
		 	for(int i =0;i<a.length();i++){
		 		if(a[i]=='('){
				     *(this)+a[i];
				 }
				if(a[i]==')'){
					
					if(this->len == 0){
						return 1;
					}
					else  if(this->end->value=='('){
						--(*this);
					}
					else{
						return 1;
					}
				} 
			}
			return this->len;
          }		 
		 //--------------------------------------------------------------------ħ��������
		 
		 string mw_output(){
		 	
		 	string result;
		 	result += head->value;
		 	for(int i = len;i >1;i--){
		 		result += end->value;
				result += head->value;
				--(*this); 
			 }
			 --(*this);
			 return result;
		 } 
      		
	     };
	     
	     void show_pic(const char *p){
	
	      ifstream fin;
	     fin.open(p);
	     char chuan[300];
         while(fin.good()){
    	
    	 fin.getline(chuan,300);
    	 cout<<chuan<<endl;
    	
	     }
        }
        
        typedef struct S_node{
  	
  	    stack  m_stack;
  	    S_node *link;
  	
        }s_node;
        
        
        
        class stacklist{           //----------------------ջ���� 
        	
        	private:
        		s_node* head;
        		s_node* end;
        		int len;
        		
        	public:          
        		
        		stacklist(){
        			head = NULL;
        			len = 0;
				}
        		
        		void operator ++(){         //-----------��� 
        			s_node *temp;
        			temp = new s_node;
        			if(temp != NULL){
        				
        				temp->link = NULL;
        				
        				if(len == 0){
        					head = temp;
        					end = temp;
						}
						else{
							end->link = temp;
							end = temp;
						}
						++len;
					}
				}
				
				void operator --(){             //ȥ�� 
					s_node *read = head;
					if(len == 0){;}
					else if(len == 1){
						delete read;
						head = NULL;
						end = NULL;
					}
					else{
						for(;read->link!=end;read=read->link){}
						delete end;
						end = read;
						read->link = NULL;
					}
					
				}
				
				stack& operator[](int n){       //������������� 
					
					s_node* read = head;
					for(int i=0;i<n;i++){
						read = read->link;
					}
					return read->m_stack;
				}
				
				int showlen(){
					return len;
				}
				
				void traverse(){
					
					s_node *read = head;
					for(;read!=NULL;read=read->link){
						read->m_stack.traverse();
					}
				}
				
		};
  
#endif
