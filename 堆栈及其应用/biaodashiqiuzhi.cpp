#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERR 0
#define TYPE char

   typedef struct NODE{
   	
   	  NODE *link;
   	  TYPE value;
   }node;
   
   struct stack{
   	 
   	 node *root;
   	 node *top;
   	 int len;
   	
   };
   
   int initstack(stack *list){

   	 	list->root = NULL;
   	 	list->top = NULL;
   	 	list->len = 0;
   	 	return 1;
   }
   
   int is_empty(stack *list){
   	
   	 if(list->len == 0){
   	 	return 0;
   	 }
   	 else{
   	 	return 1;
   	 }
  }
   
   int push(stack *list,TYPE value){
   	
   	   node *newbase = (node*)malloc(sizeof(node));
   	   if(newbase == NULL){
   	   	return 0;
   	   }
   	   if(!is_empty(list)){
            list->root = newbase;
   	   	  	newbase->link = NULL;
   	   	  }
   	   else{
   	   	   list->top->link = newbase;
   	   	   newbase->link = NULL;
   	   }
   	   list->len++;
   	   list->top = newbase;
   	   newbase->value = value;
   	    
   	   return 1;
   }
   
   int simple_delet(stack *list,TYPE *a){
   	  
   	  if(!is_empty(list)){
   	  	return 0;
   	  }
   	  else{
   	  	 if(list->len == 1){
   	  	 	free(list->top);
   	  	 	list->top = NULL;
   	  	 	list->root = NULL;
   	  	 }
   	  	 else{
   	  	 	node *read = list->root;
   	  	 	for(int i=1;i<(list->len)-1;i++){
			  read = read->link; 
			}
			*a = read->value;
   	  	 	list->top = read;
   	  	 	free(read->link);
   	  	 	read->link = NULL;
   	  	 }
   	  	 list->len--;
   	  }
   	
   }
   

   int pop(stack *list,TYPE *a){
    
     if(!is_empty(list)){
     	return 0;
     }
     else{
     	simple_delet(list,a);
     	return 1;
     }
   }
   
   TYPE showtop(stack *list){ //without examination
   	 return list->top->value;
   }
   
   TYPE showroot(stack *list){ 
   	 return list->root->value;
   }
   
   int gettop(stack *list,TYPE *value){
   	  if(!is_empty(list)){
   	  	return 0;
   	  }
   	  else{
   	  	 *value = list->top->value;
   	  	 return 1;
   	  }
   }
   
   int len_of_stack(stack *list){
   	 return list->len;
   }
   
   void traverse(stack *list){
   	
   	if(!is_empty(list)){
   		printf("It's empty'");
   	}
   	node *read = list->root;
   	for(;read!=NULL;read = read->link){
   		printf(" %d ",read->value);
   	}
   }
   
   int main(){
   	
   	stack opnd;
   	initstack(&opnd);
   	stack optr;
   	initstack(&optr);
   	
   	printf("请您输入一个运算串，并且，以#开头，以#结尾：\n");
   	char a[100];
   	gets(a);
   	
   	
   	return 0;
   }
