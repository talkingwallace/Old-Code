#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "ADT.h"  //���ж���,ջ,ջ����ṹ���ļ� 

   using namespace std;
   
   
   /* t�� d�� s�� aһֻ e�� z׷ g�� x�� n�� h��
   */
   
   string glossary(char CH){  //�ʻ�� 
   	   
   	   switch(CH){
   	   	
   	   	  case 't':
   	   	  	return "��";
   	   	  	break;
   	   	  case 'd':
   	   	  	return "��";
   	   	  	break;
   	   	  case 's':
			return "��";
			break;
		  case 'a':
		    return "һֻ";
			break;
		  case 'e':
		    return "��";
			break;
		  case 'z':
		    return "׷";
			break;
		  case 'g':
		    return "��";
		    break;
		  case 'x':
		    return "��";
			break;
		  case 'n':
		    return "��";
			break;
		  case 'h':
		    return "��";
			break;
		  default:
		  	return " ��ƥ�䣡 ";
		    break; 
   	   	  }
   }
   
   string  translator(const char* STR){  //���ԡ���ѹ������Ϊ���� 
   	
   	  string result;//��ŷ���Ľ��
		
	  for(int i =0;STR[i]!='\0';i++){
	  	result += glossary(STR[i]);
	  }

      return result; 
   }
   
   
   int main(){
   	 
   show_pic("p1.txt");                                   //��ʼ���� 
   cout<<endl<<endl<<"ħ�����Է�����!"<<endl;
   system("pause");
   fflush(stdin);
   system("cls");
   	 
   string A ="sae";                         //��ʼ�趨 
   string B = "tsaedsae";	
   queue b;
   stacklist a;
   for(int i =0;i<3;i++){                 //Ĭ��������ջ 
   	++a;
   }
   
   cout<<"��ӭʹ��ħ����������������Ҫ�޸Ĺ��������޸�����1����������2\n"; 
   int choice;                                    // choice �����ж��Ƿ�ı����  
   cin>>choice;
   fflush(stdin);
   
	if(choice == 1){                            //����ı� 
   		cout<<"�µĹ���B=\n"<<endl;
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
   cout<<"ħ������˵��ʲô�أ�\n" ;
   string str;
   cin>>str;                  
   if(a[0].is_compared(str)){
   	cout<<endl<<"���Ų�ƥ�䣡�����������";
   	return 0;
   }
   
   
   
   int mark = 0;
   int i =0;                                         //i�����ַ������� 
   int len = str.length();
   while(1){                                        //��ʽ������� 
   	
   if(str[i]=='('){                                 //mark++���ɽ��ַ�¼����һ��ջ 
     mark++;
	 ++i;
	  if(mark>a.showlen()){                          //���ջ���������һ��ջ 
	 	++a;
	  }
	  continue;                                     //���������ַ� 
	 }	
    else if(str[i]==')'){                           
   
     if(mark == 1){                                  //�������������mw_output�ܽ�ջ�е����������ǰһ��ջ 
   	  b.in_queue(a[mark].mw_output());               //�������ջ�ÿ� 
     }
     else{
   	    a[mark-1].push(a[mark].mw_output());
     }
     --mark;
     ++i;
     continue;
   }
   
   if(mark == 0){                                   //¼����� ���ᴦ��B 
   	 if(str[i] == 'B'){
   	 	b.in_queue(B);
		}
	 else{
	 	b+str[i];
	 }
   }
   else if(mark>0){                               //¼��ջ ���ᴦ��B 
   	 if(str[i]=='B'){
   	 	a[mark].push(B);
		}
	  else{
	  	a[mark]+str[i];
	  }
   }
 
   ++i;	
   
   if(i>len-1){                                      //�������������ַ����˳� 
   	break;
   }
   }
   
   cout<<"������ɣ��������£�";
   b.traverse();
   cout<<translator(b.output().c_str());
     
      return 0;
   }
