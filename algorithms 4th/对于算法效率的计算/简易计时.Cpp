#include <iostream>
#include <stdlib.h>
#include <time.h>

	int main(){
		
		clock_t end,start;
		double totaltime;
		start = clock();
		//chengxuzaici
		end = clock();
		totaltime = (double)(start-end)/CLOCKS_PER_SEC;
		
	} 
