#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "ADT.h"  //含有队列,栈,栈链表结构的文件 

   using namespace std;
   
   
   /* t天 d地 s上 a一只 e鹅 z追 g赶 x下 n蛋 h恨
   */
   
   string glossary(char CH){  //词汇表 
   	   
   	   switch(CH){
   	   	
   	   	  case 't':
   	   	  	return "天";
   	   	  	break;
   	   	  case 'd':
   	   	  	return "地";
   	   	  	break;
   	   	  case 's':
			return "上";
			break;
		  case 'a':
		    return "一只";
			break;
		  case 'e':
		    return "鹅";
			break;
		  case 'z':
		    return "追";
			break;
		  case 'g':
		    return "赶";
		    break;
		  case 'x':
		    return "下";
			break;
		  case 'n':
		    return "蛋";
			break;
		  case 'h':
		    return "恨";
			break;
		  default:
		  	return " 不匹配！ ";
		    break; 
   	   	  }
   }
   
   string  translator(const char* STR){  //语言“解压”后翻译为中文 
   	
   	  string result;//存放翻译的结果
		
	  for(int i =0;STR[i]!='\0';i++){
	  	result += glossary(STR[i]);
	  }

      return result; 
   }
   
   
   int main(){
   	 
   show_pic("p1.txt");                                   //初始界面 
   cout<<endl<<endl<<"魔王语言翻译器!"<<endl;
   system("pause");
   fflush(stdin);
   system("cls");
   	 
   string A ="sae";                         //初始设定 
   string B = "tsaedsae";	
   queue b;
   stacklist a;
   for(int i =0;i<3;i++){                 //默认有三个栈 
   	++a;
   }
   
   cout<<"欢迎使用魔王翻译器，请问需要修改规则吗？若修改输入1，否则输入2\n"; 
   int choice;                                    // choice 用于判断是否改变规则  
   cin>>choice;
   fflush(stdin);
   
	if(choice == 1){                            //规则改变 
   		cout<<"新的规则？B=\n"<<endl;
		cin>>B;
		string result;
		for(int i =0;B[i]!='\0';i++){
			if(B[i] == 'A'){
				result += A;
			}
			else{
				result += B[i];
			}
		}
		
		B = result;
	   }
   cout<<"魔王对你说了什么呢？\n" ;
   string str;
   cin>>str;                  
   if(a[0].is_compared(str)){
   	cout<<endl<<"括号不匹配！请您检查输入";
   	return 0;
   }
   
   
   
   int mark = 0;
   int i =0;                                         //i用于字符串计数 
   int len = str.length();
   while(1){                                        //正式进入计算 
   	
   if(str[i]=='('){                                 //mark++即可将字符录入下一个栈 
     mark++;
	 ++i;
	  if(mark>a.showlen()){                          //如果栈不够就添加一个栈 
	 	++a;
	  }
	  continue;                                     //忽略括号字符 
	 }	
    else if(str[i]==')'){                           
   
     if(mark == 1){                                  //两种情况，其中mw_output能将栈中的内容清出给前一个栈 
   	  b.in_queue(a[mark].mw_output());               //并且这个栈置空 
     }
     else{
   	    a[mark-1].push(a[mark].mw_output());
     }
     --mark;
     ++i;
     continue;
   }
   
   if(mark == 0){                                   //录入队列 ，会处理B 
   	 if(str[i] == 'B'){
   	 	b.in_queue(B);
		}
	 else{
	 	b+str[i];
	 }
   }
   else if(mark>0){                               //录入栈 ，会处理B 
   	 if(str[i]=='B'){
   	 	a[mark].push(B);
		}
	  else{
	  	a[mark]+str[i];
	  }
   }
 
   ++i;	
   
   if(i>len-1){                                      //当读完了所有字符就退出 
   	break;
   }
   }
   
   cout<<"翻译完成！译文如下：";
   b.traverse();
   cout<<translator(b.output().c_str());
     
      return 0;
   }
