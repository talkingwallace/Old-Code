#ifndef BST
#define BST
#include <iostream>
#include <fstream> 
#include <string>

	using namespace std;
	
	typedef struct NODE{
		
		int key;
		string value;
		int numofchl;
		NODE *lpt,*rpt;
	}node;
	
	node safenode;
	
	class bst{
		
		private:
			node* root;
			int node_num;
			int *array;
			int constraint;
			
			int for_put(int &key,string &value,node *&pt){
				
				if(!pt){
					node *tmp = new node;
					if(tmp){
						array[node_num] = key;
						node_num++;
						if(node_num>=constraint){
							expand();
						}
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
				return 1;
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

			int preorder(node *pt) {

				if (pt) {
					visit(pt);
					preorder(pt->lpt);
					preorder(pt->rpt);
				}
				return 1;
			}
			
			 void gotodie(node *pt){
			 	
			 	if(!pt){
			 		//donoting
				 }
				 gotodie(pt->lpt);
				 gotodie(pt->rpt);
				 delete pt;
				 pt = NULL;
			 }
			 
			 void expand(){
			 	
			 	constraint*=2;
			 	int *tmp = new int[constraint];
			 	for(int i=0;i<node_num;i++){
			 		tmp[i] = array[i];
				 }
				 delete []array;
				 array = tmp;
			 }
		public://--------------------------以上私有以下共有 --------------------------------------------
			
			bst(){
				root = NULL;
				node_num = 0;
				constraint = 5;
				array = new int[5];	
			}
			
			~bst(){
				gotodie(root);
			}

			node* findmin(){
				findmin(root);
			}
			
			int find(int key){
				
				node *pt = root;
				while (1) {
					if (!pt)return 0;
					if (key < pt->key) {
						pt = pt->lpt;
					}
					else if (key > pt->key) {
						pt = pt->rpt;
					}
					else if (key == pt->key) {
						return 1;
					}
				}
			} 
			
			void deletion(int key){
				root = deletion(root,key);
			}
			
			void put(int key,string value){
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
				return 1;
			}

			void pullout(node *pt,int *&a,int &i) {

				if (pt) {
					a[i] = pt->key;
					i++;
				}
			}

			void pull(node *pt,int *&a,int &i) {
				if (pt) {
					pullout(pt, a, i);
					pull(pt->lpt, a, i);
					pull(pt->rpt, a, i);
				}
			}

			void intoarray(int *&a) {
				int i;
				pull(root, a, i);
			}
			
			int preorder(){
				preorder(root);
				return 1;
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
		   
		   void showarray(){
		   		
		   		for(int i=0;i<node_num;i++){
		   			cout<<array[i]<<' ';
				   }
		   }
	   
	};
	
#endif
