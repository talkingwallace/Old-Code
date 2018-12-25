#include <iostream>
#include <fstream>

	using namespace std;
	
	typedef struct NODE{
		
		int num;
		string key;
		NODE *link;
		
	}node;
	
	class ST{
		
		private:
			node* root;
			int num;
		public:
			ST(){
				root = NULL;
				num = 0;
			}
			int put(string &a){
				
				if(num==0){
					node* tmp = new node;
					if(tmp!=NULL)
						root = tmp;
					root->key = a;root->num=0;
					root->link = NULL;num++; 
				}
			}
			
	}; 
	
	int main(){
		
		ifstream fin("tales.txt");
		string a;
		for(int i=0;i<100;i++){
			fin>>a;
			cout<<a<<' ';
		}	
		return 0;
	} 
