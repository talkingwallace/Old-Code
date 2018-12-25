#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERR 0
#define TYPE char
#include <ctype.h>

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
   		printf(" %c ",read->value);
   	}
    }
   
   int choperate(int a1,char op,int a2,int *result){
   	
     switch(op){
     	
     	case '+':*result = a1+a2; break;
     	case '-':*result = a1-a2; break;
     	case '*':*result = a1*a2; break;
     	case '/':*result = a1/a2; break;
     	default :printf("error"); return 0;
     }
     
   	 return 1;
   	 
   }
   
   void charmanage(char *a){
   	
   	  int sum = 0;
   	  for(int i=0;a[i]!='\0';i++){
   	  	 if(isdigit(a[i])){
   	  	 	  sum = sum*10+a[i]-'0';
   	  	 }
   	  	 else{
   	  	 	  printf(" %d ",sum);
   	  	 	  sum = 0;
   	  	 	  putchar(a[i]);
   	  	 }
   	  }
   	  printf(" %d ",sum);
   }
   
   int empowerment(char op){
   	 
   	 switch(op){
   	 	case '+': return 1;break;
   	 	case '-': return 0;break;
   	 	case '*': return 2;break;
   	 	case '/': return 3;break;
   	 	case '#': return -2;break;
   	 	case '(': return 5;break;
   	 	case ')': return -1;break;
   	 	default: printf("operator error");
   	 }
   }
   
   int op_compare(char op1,char op2){
   	 
   	 int value1 = empowerment(op1);
   	 int value2 = empowerment(op2);
   	 if(op1 == '('&&op2== ')'){
   	 	return 0;
   	 }
     if(value1>value2){
     	return -1;
     }
     else if(value1<value2){
     	return 1;
     }
     else{
     	if(value2=='#'){
     		return 0;
     	}
     	else{
     		return 1;
     	}
     }
     
   }
   
   int main(){
   	
     stack OPRT;
     stack OPND;
     initstack(&OPRT);
     initstack(&OPND);
     char c;
     char top;
     push(&OPRT,'#');
     traverse(&OPRT);
     c = getchar();
     while(c!='#'){
     	
		 if(isdigit(c)){
     		push(&OPND,c);
     		c = getchar();
     	}
     	else{
     		gettop(&OPTR,&top);
     		int result = op_compare(top,c);
     		if(result){
     			push(&OPRT,c);
     			c=getchar();
     		}
     		else if(result == 0){
     			pop(&OPRT);
     			c = getchar();
     		}
     		else if(result == -1){
     			char a1,a2;
     			gettop(&OPND,&a1);pop(&OPND);
     			gettop(&OPND,&a2);pop(&OPND);
     			int b1 = a1 - '0',b2 = a2 - '0';
     			
     		}
     	}
     	
     }
     
   	
   	return 0;
   }
