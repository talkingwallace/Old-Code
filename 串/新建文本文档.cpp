#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "MyString.h"

   void caonima(hstring a){
   	 hstring j = a;
   	 free(j.ch);
   	 printf("%s",j.ch);
   }
   
   int main(){

    using namespace std;
    hstring a;
    strassign(&a,"abaabcac");
    int next[8];
    get_next(a,next);
    
   	return 0; 
   }
