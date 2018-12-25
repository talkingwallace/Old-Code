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
	
	int *longlist;
	
	void initial_longlist(int *a,int n){
		
		longlist = (int*)calloc(2001,sizeof(int));
		for(int i=0;i<n;i++){
			longlist[a[i]+1000]=1;
		}
	}
	
	void showall(int *a,int n){
		
		for(int i=0;i<n;i++){
			cout<<a[i]<<' ';
			if(i%10==0){
				cout<<'\n';
			}
		}
	}
	
	int selection_sort(int *a,int n){	//Ñ¡ÔñÅÅÐò 
		
		int tmp;
		for(int i=0;i<n;i++){
			int min = i;
			for(int j=i+1;j<n;j++){
				if(a[j]<a[min]){
					min = j;
				}
			}
			tmp = a[i];
			a[i] = a[min];
			a[min] = tmp; 
		}
		
		return 1;
	}
	
	int find(int *a,int lo,int hi,int key){
		
		if(lo>hi){
			return -1;
		}
		int mid = lo+(hi-lo)/2;
		if(key>a[mid]){
			find(a,mid+1,hi,key);
		}
		else if(key<a[mid]){
			find(a,lo,mid-1,key);
		}
		else{
			return mid;
		}
	}
	
	int main(){
		
		char *test = NULL;
		char ttt[] = "nimmafa";
		char *bbb;
		bbb = ttt;
		int n =50;
		int a[n];
		random(a,n);
		initial_longlist(a,n);
		int sum = 0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int k = -(a[i]+a[j])+1000;
				if(k>=2001){
					continue;
				}
				int d = longlist[k];
				if(d>0){
					cout<<endl<<a[i]<<' '<<a[j]<<' '<<k-1000<<' ';
					sum++;
				}
			}
		}
		cout<<sum;
		
		return 0;
	} 
