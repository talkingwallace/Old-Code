#include <iostream>
#include <cstdlib>
#include <fstream>
#define red 1
#define black 0

	using namespace std;
	
	typedef struct NODE{
		
		int key;
		string value;
		NODE *lpt,*rpt;
		int numofsub;
		bool color;
		
	}node;
	
	class mytree{
		
		private:
			
			node* forput(node *pt,int key,string &value){
				
				if(pt==NULL){
					node* tmp = new node;
					if(tmp){
						pt = tmp;					
						pt->color = red;
						pt->key = key;
						pt->value = value;
						pt->lpt = pt->rpt = NULL;
						pt->numofsub = 1;
						return pt;
					}
					return NULL;
				}
				if(key>pt->key) pt->rpt = forput(pt->rpt,key,value);
				if(key<pt->key)	pt->lpt = forput(pt->lpt,key,value);
				else{
					pt->value = value;
				} 
				if(is_red(pt->lpt)&&is_red(pt->lpt->lpt)){
					pt = rotate_right(pt);
				}
				if(is_red(pt->rpt)&&!is_red(pt->lpt)){
					pt = rotate_left(pt);
				}
				if(is_red(pt->lpt)&&is_red(pt->rpt)){
					flipcolor(pt);
				}
				pt->numofsub = size(pt->lpt)+size(pt->rpt)+1;
				return pt;
			}
			
			void print_tree(node *pt,int space){
				
				if(pt){
					print_tree(pt->rpt,space+6);
					for(int i=0;i<space;i++) cout<<" ";
					cout<<pt->color<<' '<<pt->numofsub<<' '<<pt->key<<' '<<pt->value<<'\n'<<'\n';
					print_tree(pt->lpt,space+6);
				}
			}
			
			node* rotate_left(node *pt){
				
					node *tmp = pt->rpt;
					pt->rpt = tmp->lpt;
					tmp->lpt = pt;
					tmp->color = pt->color;
					pt->color = red;
					tmp->numofsub = pt->numofsub;
					pt->numofsub = size(pt->lpt)+size(pt->rpt)+1;
					return tmp;
			};
			
			node* rotate_right(node *pt){
				
					node *tmp = pt->lpt;
					pt->lpt = tmp->rpt;
					tmp->rpt = pt;
					tmp->color = pt->color;
					pt->color = red;
					tmp->numofsub = pt->numofsub;
					pt->numofsub = size(pt->lpt)+size(pt->rpt)+1; 
					return tmp;
			};
			
			void flipcolor(node *pt){
				
				if(pt){
					pt->color = red;
					if(pt->rpt)pt->rpt->color = black;
					if(pt->lpt)pt->lpt->color = black;
				}
			}; 
			
		public:
			node* root;
			int num_of_node;
			
			mytree(){
				
				root = NULL;
				num_of_node = 0;
			}
			
			void put(int key,string &value){
				root = forput(root,key,value);
				root->color = black;
			}
			
			void print_tree(){
				print_tree(root,6);
			}
			
			bool is_red(node *pt){
				
				if(pt)return pt->color;
				else return 0;
			}
			
			int size(node *pt){
				if(pt == NULL){
					return 0;
				}
				else{
					return pt->numofsub;
				}
			}
	};
	
	int main(){
		
		mytree a;
		ifstream fin("data.txt");
		int key;
		string value;
		for(int i=0;i<10;i++){
			fin>>value>>key;
			a.put(key,value);
		}
		a.print_tree();
		return 0;
	} 
