#include <iostream>
#include "tree.h"

   int main(){
   	
    //-----------------initial
	tree a;
	a.creat_tree('-');
	a.l_insert(a.show_root(),'+');
	a.r_insert(a.show_root(),'/');
	a.l_insert(a.find(2),'a');
	a.r_insert(a.find(2),'*');
	a.l_insert(a.find(5),'b');
	a.r_insert(a.find(5),'-');
    a.l_insert(a.find(11),'c');
    a.r_insert(a.find(11),'d');
    a.l_insert(a.find(3),'e');
    a.r_insert(a.find(3),'f');
    //-----------------------------------
    
    a.preorder(a.show_root());
    cout<<endl;
	 
   	return 0;
   }
