#ifndef TREE
#define TREE
#include <iostream>
#include <cmath>
#define TYPE char

   
    using namespace std;
    
    typedef struct t_NODE{
    	
    	TYPE value;
    	t_NODE* l_link;
    	t_NODE* r_link;
    	t_NODE* parent;
    	int num;
    	
	}t_node;
	
	int is_odd(int n){
		
		if(n == 1){
			return 1;
		}
		else if(n == 2){
			return 0;
		}
		else{
			return n%2;
		}
	}

    class tree{
    	
    	private:
    	int depth;
    	int num_of_node;
    	t_node *root;
    	
    	public:
    		
    		 tree(){
    		 	depth = 0;
    		 	num_of_node = 0;
    		 	root = NULL;
			 }
			 
			 int is_empty(){
			 	return num_of_node == 0;
			 }
			 
			 int show_depth(){
			 	return depth;
			 }
			 
			 t_node* show_root(){
				 return root;
			 }
			 
			 int creat_tree(TYPE n){             //创建一个表 
			 	if(is_empty()){
			 		
			 		t_node *temp = new t_node;
			 		if(temp!=NULL){
			 		    root = temp;
			 		    root->l_link = NULL;
			 		    root->r_link = NULL;
			 		    root->parent = NULL;
			 		    root->value = n;
			 		    root->num = 1;
			 		    depth = 1;
			 		    num_of_node =1;
			 		    return 1;
					 }
					else{
						return 0;
					}
				 }
				 else{
				 	return 0;
				 }
			 }
			 
			 
			 t_node* find(int n){    //找到编号为n的节点,有简化空间，有出错可能，待修改 
			 	
			 	if(n>pow(2,depth)-1){       //处理特殊情况 
			 		cout<<"NULL\n";
			 		return NULL;
				 }
				 else if(n<=0){
				 	cout<<"NULL\n";
				 	return NULL;
				 }
				else{
					
					if(n==1){                           //1和2的情况 
						return root;
					}
					if(n==2){
						if(root->l_link == NULL){
							cout<<"NULL\n";
						}
						else{
							return root->l_link;
						}
					}
					
					int bearing[10];                //bearing数组用于记录路线 1向右 0向左 
					int j = 0;              
					for(int i =n;i!=1;i=i/2){
						++j;
						bearing[j] = is_odd(i);       //isodd 判断奇偶 奇数为1 偶数为0 
					}
					
					t_node* read = root;
					while(j>0){                     //路线记录完毕后就开始沿着路线查找 如果发现这个节点是没有的return NULL 
						
						if(bearing[j]==1){
							if(read->r_link!=NULL){
								read = read->r_link;
							}
							else{
								cout<<"NULL\n";
								return NULL;
							}
						}
						else if(bearing[j]==0){
							if(read->l_link!=NULL){
								read = read->l_link;
							}
							else{
								cout<<"NULL\n";
								return NULL;
							}
						}
						--j;
					}
					
					return read;
				}
			 }
			 
			 int l_insert(t_node *pt,TYPE n){      //对一个点进行左插入 
			 	
			 	if(pt->l_link==NULL){
			 		 
			 		t_node *temp = new t_node;
			 		if(temp==NULL){
			 			return 0;
					 }
					temp->parent = pt;
					temp->l_link = NULL;
					temp->r_link = NULL;
					temp->value = n;
					temp->num = 2*pt->num;
					++num_of_node;
					if(temp->num>=pow(2,depth)){
						++depth;
					}
					pt->l_link = temp;
					return 1;
				 }
			 	else{
			 		return 0;
				 }
			 }
			 
			 int r_insert(t_node*pt,TYPE n){                          //对一个点进行右插入 
			 	
			 	if(pt->r_link == NULL){
			 		
			 		t_node *temp = new t_node;
			 		if(temp == NULL){
			 			return 0;
					 }
					 temp->parent = pt;
					 temp->l_link = NULL;
					 temp->r_link = NULL;
					 temp->value = n;
					 temp->num = 2*pt->num + 1;
					 ++num_of_node;
					 if(temp->num>=pow(2,depth)){
					 	++depth;
					 }
					 pt->r_link = temp;
					 return 1;
				 }
				 else{
				 	return 0;
				 }
			 	 
			 }
			 
			 int assign(t_node* pt,TYPE n){
			 	pt->value = n;
			 	return 1;
			 }
			 
			 t_node* parent(t_node *pt){
			 	if(pt->parent!=NULL){
			 		return pt->parent;
				 }
			 } 
			 
			 int value(int n){  //访问并找出值 
			 	
			 	t_node *pt = this->find(n);
			 	if(pt==NULL){
			 		cout<<"\nNULL\n";
			 		return 0;
				 }
				 else{
				 	cout<<' '<<pt->value;
				 	return 1;
				 }
			 }
			 
			 int show_num(){
			 	return num_of_node; 
			 }
			 
			 //-----------------遍历的设计 
			 			 
			 int visit(t_node *pt){
			 	
			 	if(pt==NULL){
			 		return 0;
				 }
				else{
					cout<<pt->value;
					return 1;
				}
			 }
			 
			 int preorder(t_node *pt){
			 	
			 	if(this->show_num()!=0){
			 		
			 		if(this->visit(pt)){
			 		    preorder(pt->l_link);
			 		    preorder(pt->r_link);
					 }
				 }
			 }
			 
			 int inorder(){
			 	
			 }
			 
			 int postorder(t_node*pt);
			
			 int levelorder(); 
	};
	
	
#endif
