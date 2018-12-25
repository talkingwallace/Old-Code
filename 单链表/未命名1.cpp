#include <stdio.h>
#include <stdlib.h>
#define TYPE int
   typedef struct NODE{
   	 
   	 TYPE value;
   	 NODE* link;
   	 
   }node;
   
   int insert
   (node**linkpt,TYPE new_value){
   	
   	register node* current;
   	register node* newone;
   	
   	while((current=*linkpt)!=NULL&&current->value<new_value){
   		linkpt = &current->link;
   	}
   	
   	newone = (node*)malloc(sizeof(node));
   	if(newone == NULL){
   		return 0;
   	}
   	newone->value = new_value;
   	newone->link = current;
   	*linkpt = newone;
   	return 1;
   }
   
   
   int main(){
   	
   	node* root = NULL;
   	node** rootpt = &root;
   	insert(rootpt,2);
   	insert(rootpt,3);
   	insert(rootpt,4);
   	
   	node *read;
   	read = root;
   	for(;read!=NULL;read=read->link){
   		printf("%d ",read->value);
   	}
   	
   	return 0;
   }
