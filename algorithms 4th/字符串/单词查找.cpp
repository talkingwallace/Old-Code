#include <iostream>

	using namespace std;
	
	typedef struct NODE{
		
	public:
		double value;
		NODE *next[256];
		
		NODE(){
			value = 0;
			for(int i=0;i<256;i++){
				next[i] = NULL;
			}
		}	
	}node;
	
	class Trie{
		
		private:
			int R;
			
		public:
			
			node *root;
			
			Trie(){
				
				root = 0;
				R = 256;
			}
			
			node* put(string a,int d,node *pt,double value){
				
				if(pt==NULL){
					node *tmp = new node;
					if(tmp){
						pt = tmp;
					}
				}
				if(d+1==a.length()){
					pt->value = value; return pt;
				}
				int next = a[d];
				pt->next[next] = put(a,d+1,pt->next[next],value);
			}
	};
	
	int main(){
		
		Trie test;
		node* pt = test.put("nima",0,test.root,12);
		cout<<pt->value;
		
		return 0;
	}
