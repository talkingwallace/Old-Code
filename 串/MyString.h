#ifndef MyString
#define MyString

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

   typedef struct{ //使用 堆 方法的string 结构 
   	
   	char *ch;
   	int length;
   	
   }hstring; 
   
   int strassign(hstring *pt,const char *str){
   	
   	int n = strlen(str);  //记录串长度 
   	char *temp = (char*)(malloc((n+1)*sizeof(char)));
   	
   	if(temp == NULL){
   		return 0;
	   } 
	   
	free(pt->ch);
	pt->ch = temp;
    pt->length = n;
    
	for(int i =0;i<n;i++){   //串拷贝 
		
		pt->ch[i] = str[i];
	}
	pt->ch[n] = '\0';     //添加一个结束符号 
	
   	return 1;
   	
   }
   
   int strlen(const hstring *pt){  //返回串长 
   	return pt->length;
   }
   
   int StrCompare(const hstring *pt1,const hstring *pt2){
   	
   	 if(pt1->length!=pt2->length){
   	 	return 0;
		}
		
	 else{
	 	
	 	for(int i=0,n = pt1->length;i<n;i++){
	 		if(pt1->ch[i]!=pt2->ch[i]){
	 			return 0;
			 }
		 }
		 return 1;
	 }	
   }
   
   int ClearString(hstring *pt){   //清除串内容 
   	  
   	  free(pt->ch);
   	  pt->length = 0;
   	  
   	  return 1;
   }
   
   int Concat(hstring *pt1,hstring *pt2,hstring *result){
   	  
   	  int t_len = pt1->length + pt2->length;
   	  char *temp = (char*)malloc((t_len+1)*sizeof(char));
   	  
   	  if(temp == NULL){
   	  	  return 0;
		 }
		
	  result->ch = temp;
	  	 
	  for(int i = 0;i<t_len;i++){
	  	 if(i<pt1->length){
	  	  result->ch[i] = pt1->ch[i];
	     }
		 else{
		  result->ch[i] = pt2->ch[i-pt1->length];        //麻痹日了狗了 为什么分开来录入就有问题？？？ 待解决!! 
		 }
		}
	  
	  
	  result->length = t_len;
	  result-> ch[ t_len ] = '\0';
	  
	  return 1;
   }
   
   int SubString(hstring *pt,hstring *result,int pos,int len){
   	
   	  int temp = pos - 1;  //转换为方便计算的值;
      if(pos<0||pos>len||len<0||len > pt->length - temp ){
      	return 0;
	  } 
	  
	  char *ch_temp = (char*)malloc((len+1)*sizeof(char));
	  if(ch_temp!=NULL);
	  result->ch = ch_temp;
	  
	  for(int i = 0;i<len;i++){
	  	result->ch[i] = pt->ch[i+pos]; 
	  }
	  result->ch[len] = '\0';
	  result->length = len; 
	  return 1;
   }
   
   int Index1(hstring *S,hstring *T,int pos){
   	
   	 int i = pos,j = 0;
   	 while(i<=S->length&&j<=T->length){
   	 	  
   	 	  if(S->ch[i] ==  T->ch[j]){
   	 	  	  ++i;
   	 	  	  ++j;
			  }
		  else{i = i-j+1;j=0;}  
		}
	 if(j>T->length){
	 	return i - T->length;
	 }	
	 else{
	 	return 0;
	 }
   }
   
   void show_str(hstring *pt){
   	
   	  printf("%s\n",pt->ch);
   	  
   	  printf("%d",pt->length);
   }
   
   void get_next(hstring T,int next[]){  //basic
   	 
   	 int i = 0;
   	 next[0] = 0;
   	 int j = -1;
   	 while(i<T.length){
   	 	if(j == -1||T.ch[i] == T.ch[j]){
   	 		i++; j++; next[i] = j;
			}
		else{
			j = next[j]-1;
		}
		}
   	 
   }


#endif
