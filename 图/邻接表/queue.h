#ifndef QUEUE
#define QUEUE
#include <iostream>
#define TYPE int

  using namespace std;
  
  typedef struct Node{
  	
  	TYPE value;
  	Node *link;
  	
  }node;

  class queue{
  	
  	private:
  	  	
  	  	int len;
  	  	node *head;
  	  	node *end;
  		
  	public:
  		
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
		  
		int operator --(){
			if(len == 0){
				cout<<"I got nothing to do!";
				return 0;
			}
			node *temp = head;
			head = head->link;
			int result = temp->value;
			delete temp;
			-- len;
			if(len == 0){
				end = NULL;
			}
			return result;
		}
		
		node* showhead(){
		     return head;
		}
		
		node* showend(){
			 return end;
	    }
	    
	    int show_len(){
	    	return len;
		}
		
		void traverse(){
			for(node *read = head;read!=NULL;read = read->link){
				cout<<read->value<<' ';
			}
			cout<<endl;
		}
		
		int is_empty(){
			return len==0;
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
  	
  	
   };
  
#endif
