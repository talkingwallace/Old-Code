#include <iostream>
#include <fstream> 

	using namespace std;
	
	typedef struct NODE{
		
		int key;
		string value;
		int numofchl;
		NODE *lpt,*rpt;
	}node;
	
	node safenode;
	
	class btree{
		
		private:
			node* root;
			int node_num;
			
			int for_put(int &key,string &value,node *&pt){
				
				if(!pt){
					node *tmp = new node;
					if(tmp){
						node_num++;
						pt = tmp;
						pt->key = key;
						pt->value = value;
						pt->rpt = pt->lpt = NULL;
						pt->numofchl = 1;
						return 0;
					}	
					return -1;
				}
				else{
					if(key == pt->key){
						pt->value = value;
						return 1;
					}
					else{
						if(key>pt->key){
							for_put(key,value,pt->rpt);
						}
						else{
							for_put(key,value,pt->lpt); 
						}
						pt->numofchl = size(pt->lpt)+size(pt->rpt)+1;
					}
				}
			}
			
			node* floor(int key,node* pt){
				
				if(pt==NULL)return NULL;
				if(key==pt->key)return pt;
				if(key<pt->key)return floor(key,pt->lpt);
				node *t = floor(key,pt->rpt);
				if(t!=NULL) return t;
				else return pt; 
			}
			
			node* myfloor(int key,node *pt){
				
				if(pt==NULL)return NULL;
				if(key==pt->key)return pt;
				if(pt->key>key){
					pt = myfloor(key,pt->lpt);
				}
				if(pt->key<key){
					if(pt->rpt){
						node*tmp = myfloor(key,pt->rpt);
						if(!tmp)return pt;
						else return tmp;
					}
					else{
						return pt;
					}
				}
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
			
			node* deletion(node *pt,int key){
				
				if(pt==NULL)return NULL;
				if(key>pt->key)pt->rpt=deletion(pt->rpt,key);
				else if(key<pt->key)pt->lpt=deletion(pt->lpt,key);
				else{
					if(pt->rpt==NULL){
						node* tmp = pt->lpt;
						delete pt;
						return tmp;
					}
					if(pt->lpt==NULL){
						node* tmp = pt->rpt;
						delete pt;
						return tmp; 
					}
					else{
						node* tmp = findmin(pt->rpt);
						pt->key = tmp->key;
						pt->value = tmp->value;
						pt->rpt = delmin(pt->rpt);
					}
				} 
				
				pt->numofchl = size(pt->lpt)+size(pt->rpt)+1;
				return pt;
			}
			
			node* findmax(node* pt){
				
				if(!pt)return NULL;
				while(1){
					if(!pt->rpt){
						break;
					}
					pt = pt->rpt;
				}
				return pt;
			}

			node* findmin(node* pt){
				
				if(!pt)return NULL;
				while(1){
					if(!pt->lpt){
						break;
					}
					pt = pt->lpt;
				} 
				return pt;
			}
			
		public://--------------------------以上私有以下共有 --------------------------------------------
			
			btree(){
				root = NULL;
				node_num = 0;	
			}
			
			node* findmin(){
				findmin(root);
			}
			
			void deletion(int key){
				root = deletion(root,key);
			}
			
			int put(int key,string value){
				for_put(key,value,root);
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
				root = delmin(root);
			}
			
			void delmax(){
				root = delmax(root);
			}
//---------------------------------------查找系列	
			node* floor(int key){
				
				node* pt = floor(key,root);
				if(pt==NULL)return &safenode;
				return pt;
			}	
			
			node* myfloor(int key){
				
				node* pt = myfloor(key,root);
				if(!pt)return &safenode;
				return pt;
			}
			
			node* ceiling(int key){
				
				node* pt = ceiling(key,root);
				if(pt==NULL)return &safenode;
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
	                cout<<'|'<<pt->key<<' '<<pt->value<<'|'<<endl; 
					print_tree(pt->lpt,space+6);
					return 1;
				}
			 else{
			 	return 0;
			 }
		   }
	   
	};
	
	int main(){
		
		safenode.key = 0;safenode.lpt=safenode.rpt = NULL;safenode.value = "NULL";
		
		btree a;
		ifstream fin("data.txt");
		string b;int c;
		for(int i=0;i<9;i++){
			fin>>b>>c;
			a.put(c,b);
		}
		int index;
		while(1){
			cin>>index;
			a.deletion(index);
			a.printtree();
			cout<<endl<<endl;
		}
		return 0;
	}
