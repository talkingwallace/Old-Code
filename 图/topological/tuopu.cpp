#include <iostream>
#define MAX 10
#define TYPE int
   using namespace std;
   
   typedef struct NODE{
   	
        int value;
		NODE* link;
		   	  
   }node;
   
   class stack{
   	
   	  public:
   	  	node *root;
   	    node *top;
   	    int nums;
   	    
   	    stack(){
   	    	
   	    	root = NULL;
   	    	top = NULL;
   	    	nums = 0;
		   }
		
		stack& operator +(TYPE n_value){
			
			node* tmp = new node;
			if(!tmp)return *this;
			tmp->value = n_value;
			
			if(nums == 0){
				root = tmp;
				tmp->link = NULL;
			}
			else{
			    tmp->link = top;
			}
			top = tmp;
			nums++;
			
			return *this;
		}
		
		int operator --(){
			
			if(nums==0){
				return 0;
			}
			int feedback = top->value;
			node* tmp = top;
			top = top->link;
			delete tmp;
	        nums--;
	        if(nums==0)root = NULL;
			return feedback;
		}

   };
   
   struct Nodelist{
   	
   	    node* first;
   	    int in;
   	    node** head;
   };
   
   class adj{
   	
   	    public:
   	       Nodelist list[MAX];
		   int nums;
		   
		adj(int n){
			nums = n;
			for(int i=0;i<MAX;i++){
				list[i].head = &(list[i].first);
				list[i].in = 0;
				list[i].first = NULL;
			}
		}
		
		void insert(int a,int b){
			
			if(a<nums&&b<nums){
				list[b].in+=1;
				node* tmp = new node;
				tmp->value = b;
				tmp->link = NULL;
				*(list[a].head) = tmp;
				list[a].head = &(tmp->link);
			}
		}
		
		void traverse_all(){
			
			for(int i=0;i<nums;i++){
				cout<<list[i].in<<' ';
				for(node* read = list[i].first;read!=NULL;read=read->link)
				   cout<<read->value<<' ';
				cout<<endl;
			}
		}	
		
		void topologicalsort(){
			
			stack S;
			int indegree[nums];
			for(int i=0;i<nums;i++){
				indegree[i] = list[i].in;
				if(!list[i].in)S+i;
			}
			int count = 0;
			while(S.nums){
				int n = --S;
				cout<<n<<' ';
				count++;
		     	for(node* read =list[n].first;read!=NULL;read=read->link){
		     	    --indegree[read->value];
		     	    if(!indegree[read->value]){
		     	    	S+(read->value);
					 }
				 }  
			}
			
			if(count<nums)cout<<"\nyouhuilu!";
		}
   };
   
   int main(){
   	
   	adj mine(3);
    mine.insert(0,1);mine.insert(1,2);
    mine.topologicalsort();
   	
   	return 0;
   }
