#include <iostream>
#define TYPE int
  using namespace std;
  
    typedef struct NODE{
    	
    	TYPE value;
    	NODE *link;
    	
	}node;
  
  
   class linkedlist{
   	
   	 private:
   	 	
   	 	node *head;
   	 	node *end;
   	 	node *pt;
   	 	int len;
   	 	
   	 public:
   	 	
   	 	
   	 	linkedlist(){
   	 		
   	 		head = NULL;
   	 		end = NULL;
   	 		pt = NULL;
   	 		len = 0;
   	 		
			}
   	 	int operator +(TYPE n_value){
   	 		
   	 		node* temp = new node;
   	 		if(temp == NULL){
   	 			cout<<"no memory";
   	 			return 0;
				}
			else{
				temp->value = n_value;
				temp->link = NULL;
			}
			
			if(len == 0){
			    head = temp;
				end = temp;	
			}
			else{
				end->link = temp;
				end = temp;
			}
			len ++;
   	 		
			}
		
		void show_headandend(){
			cout<<head->value<<endl<<end->value;
		}
		
		void traverse(){
			
		    for(node *read = head;read != NULL;read=read->link){
		    	cout<<read->value<<endl;
			}
		}

		
		node* showhead(){
			return head;
		}
   	};
   	
   	int main(){
   		
   		linkedlist testing;
   		testing+5;
   		testing+8;
   		testing+19;
   		testing+123;
   		testing+12530;
   		testing.traverse();
   		testing.reverse();
        testing.traverse();
        testing.show_headandend();
   		return 0;
	   }
