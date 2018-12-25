#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERR 0
#define TYPE int

   typedef struct NODE{
   	
   	  NODE *link;
   	  TYPE value;
   }node;
   
   struct stack{
   	 
   	 node *buttom;
   	 node *top;
   	 int len;
   	
   };
   
   int initstack(stack *list){
   	 
   	 list->buttom = NULL;
   	 list->top = NULL;
   	 list->len = 0;
   	 
   	 return 1;
   }
   
   int in(stack *list , TYPE value){
   	
   	  node *newbase = (node *)malloc(sizeof(node));
   	  if(newbase == NULL){
   	  	return 0;
   	  }
   	  else{
   	  	 if(list->top==NULL){
   	  	     list->top = newbase;
			 list->buttom = newbase;	
			 newbase->link = NULL;
   	  	 }
   	  	 else{
   	  	 	list->top->link = newbase;
   	  	 	list->top = newbase;
   	  	 	newbase->link = NULL;
   	  	 }
   	  	 return 1;
   	  }
   }
  

   int main(){
   	
   	stack list1;
   	initstack(&list1);
   	for(int i =0;i<6;i++){
   		in(&list1,i);
   		
   	}
   	node *read = list1.buttom;
   	for(;read!=NULL;read = read->link){
   		printf(" %d",read->value);
   	}
   	
   	return 0;
   }
