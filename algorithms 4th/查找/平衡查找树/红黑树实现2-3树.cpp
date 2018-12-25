#include <iostream>
#include <fstream> 
#define red 1
#define black 0

	using namespace std;
	
	typedef struct NODE{
		
		int key;
		string value;
		int numofchl;
		NODE *rpt,*lpt; 
		bool color;//红1黑0 
	}node;
	
	node safenode;
	
	class btree{
		
		private:

			int node_num;
			node* root;
			
			node* rotateleft(node* pt){
				
				node *tmp = pt->rpt;
				pt->rpt = tmp->lpt;
				tmp->lpt = pt;
				tmp->color = pt->color;
				pt->color = red;
				tmp->numofchl = pt->numofchl;
				pt->numofchl = 1+size(pt->lpt)+size(pt->rpt);
				return tmp;
			}
			
			node* rotateright(node* pt){
				
				node *tmp = pt->lpt;
				pt->lpt = tmp->rpt;
				tmp->rpt = pt;
				tmp->color = pt->color;
				pt->color = red;
				tmp->numofchl = pt->numofchl;
				pt->numofchl = 1+size(pt->lpt)+size(pt->rpt);
				return tmp;
			}
			node* for_put(int &key,string &value,node *&pt){
				
				if(!pt){
					node *tmp = new node;
					if(tmp){
						node_num++;
						pt = tmp;
						pt->key = key;
						pt->value = value;
						pt->rpt = pt->lpt = NULL;
						pt->numofchl = 1;
						pt->color = red;
						return pt;
					}	
					return &safenode;
				}
				if(key>pt->key){
					pt->rpt = for_put(key,value,pt->rpt);
				}
				else{
					pt->lpt = for_put(key,value,pt->lpt); 
				}
				if(key == pt->key){
					pt->value = value;
				}
				
				if(isred(pt->rpt)&&!isred(pt->lpt)){
					pt = rotateleft(pt);
				}
				if(isred(pt->lpt)&&isred(pt->lpt->lpt)){
					pt = rotateright(pt);
				}
				if(isred(pt->lpt)&&isred(pt->rpt)){
					flipcolor(pt); 
				}
				pt->numofchl = size(pt->lpt)+size(pt->rpt)+1;
				return pt;
			}
			
			
			node* floor(int key,node* pt){
				
				if(pt==NULL)return NULL;
				if(key==pt->key)return pt;
				if(key<pt->key)return floor(key,pt->lpt);
				node *t = floor(key,pt->rpt);
				if(t!=NULL) return t;
				else return pt; 
			}
			
			node* ceiling(int key,node* pt){
				
				if(pt==NULL)return NULL;
				if(key==pt->key){
					return pt;
				}
				if(key>pt->key){
					return ceiling(key,pt->rpt);
				}
				node *t = ceiling(key,pt->lpt);
				if(t!=NULL) return t;
				else return pt; 
			}
			
			node* delmin(node*pt){
				
				if(pt->lpt==NULL){
					node*tmp = pt->rpt;
					delete pt;
					return tmp;
				}
				pt->lpt = delmin(pt->lpt);
				pt->numofchl = size(pt->lpt)+size(pt->rpt)+1;
				return pt;
			}
			
			node* delmax(node*pt){
				
				if(pt->rpt==NULL){
					node*tmp = pt->lpt;
					delete pt;
					return tmp;
				}
				pt->rpt = delmin(pt->rpt);
				pt->numofchl = size(pt->lpt)+size(pt->rpt)+1;
				return pt;
			}
			
			bool isred(node *pt){
				
				if(!pt)return 0;
				return pt->color;
			}
			
			
			void flipcolor(node *pt){
				
				if(!pt){
					
				}
				else{
					pt->color = red;
					pt->lpt->color = black;
					pt->rpt->color = black;
				}
			}
				
		public:
			
			btree(){
				root = NULL;
				node_num = 0;	
			}
			
			int put(int key,string value){
				for_put(key,value,root);
				root->color = black;
			}
			
			
			void printtree(){
				print_tree(root,5);  
			}
			
			int shownodenum(){
				return node_num;
			}
			
			int size(node *&pt){
				if(!pt){
					return 0;
				}
				return pt->numofchl;
			}
			
			void delmin(){
				delmin(root);
			}
			
			void delmax(){
				delmax(root);
			}
//---------------------------------------查找系列	
			node* floor(int key){
				
				node* pt = floor(key,root);
				if(pt==NULL)return &safenode;
				return pt;
			}	
			
			node* ceiling(int key){
				
				node* pt = ceiling(key,root);
				if(pt==NULL)return &safenode;
				return pt;
			}
					
			node* findmax(){
				
				node*pt = root;
				while(1){
					if(!pt->rpt){
						break;
					}
					pt = pt->rpt;
				}
				return pt;
			}

			node* findmin(){
				
				node*pt = root;
				while(1){
					if(!pt->lpt){
						break;
					}
					pt = pt->lpt;
				}
				return pt;
			}

//--------------------------------------一下用于遍历与直观的查询 
			int visit(node *pt){
				
				if(pt){
					cout<<pt->value<<pt->key<<'\n';
				}
				else{
					return -1;
				}
			}
			
			int preorder(node *pt){
				
				if(pt){
					visit(pt);
					preorder(pt->lpt);
					preorder(pt->rpt);
				}
				
			}
			
		   int print_tree(node* pt,int space){
		   	
		   	 if(pt!=NULL){
		   	 	    print_tree(pt->rpt,space+6);
		   	 	    for(int i=0;i<space;i++){	    
		   	 	   	    cout<<" ";
					   }
	                cout<<pt->color<<' '<<pt->key<<' '<<pt->value<<endl; 
					print_tree(pt->lpt,space+6);
					return 1;
				}
			 else{
			 	return 0;
			 }
		   }
	   
	};
	
	class test{
		
		public:
			static const int a;
			
		test(int b){
		}
		
		int operator <<(int a){
			
		}
	};
	const int test::a = 12;
	
	int main(){
		
		safenode.key = 0;safenode.lpt=safenode.rpt = NULL;safenode.value = "NULL";
		ifstream fin("data.txt");
		btree a;
		int in;string sin;
		for(int i=0;i<10;i++){
			fin>>sin>>in;
			a.put(i,sin);
		}
		a.printtree();
		
		return 0;
	}
