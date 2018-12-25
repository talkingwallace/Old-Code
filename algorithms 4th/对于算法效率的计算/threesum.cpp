#include <iostream>
#include <stdlib.h>
#include <time.h>
	
	using namespace std;
	
	int random(int *a,int n){
		
		for(int i = 0;i<n;i++){
			a[i] = rand()%2001-1000;
		}
		
	}
	
	int count(int *a,int n){
		
		int length = n;
		int cnt = 0;
		for(int i = 0;i<length;i++){
			for(int j = i+1;j<length;j++){
				for(int k = j+1;k<length;k++){
					if(a[i]+a[j]+a[k]==0){
						cnt++;
					}			
				}
			}
		}
		return cnt;
	}
	
	void showall(int *a,int n){
		
		for(int i=0;i<n;i++){
			cout<<a[i]<<' ';
			if(i%10==0){
				cout<<'\n';
			}
		}
	}
	
	int main(){
		
		clock_t start,finish;
		double totaltime;
		int *a;
		int n = 8000;
		a = new int[n];
		random(a,n);
		start = clock();
		int cnt = count(a,n);
		finish = clock();
		totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
		cout<<"\n"<<totaltime<<"s\n"<<' '<<cnt;
		
		return 0;
	} 
