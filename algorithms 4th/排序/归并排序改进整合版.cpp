#include <iostream>
#include <time.h>
#include <cstdlib>

	using namespace std;
	
	int random(int *a,int n){	//随机产生一个数组 	
		for(int i = 0;i<n;i++)
			a[i] = rand()%8001-4000;
	}

	int tmp[8000];//---------------!!!!
	
	void selection_for_merge(int *a,int lo,int high){ //为归并准备的选择排序 
		
		int tmp;
		for(int i=lo;i<high;i++){
			int min = i;
			for(int j=i+1;j<high;j++){
				if(a[j]<a[min]){
					min = j;
				}
			}
			tmp = a[i];
			a[i] = a[min];
			a[min] = tmp; 
		}	
	} 

	int merge_plus(int lo,int mid,int hi,int *a,int *tmp,int n){//tmp为辅助空间 
		
		int i=lo,j =mid+1;
		for(int k=lo;k<=hi;k++){
			if(i>mid)a[k] = tmp[j++];
			else if(j>hi) a[k] = tmp[i++];
			else if(tmp[j]<tmp[i]) a[k] = tmp[j++];
			else a[k] = tmp[i++];
		}
	}
	
	int merge_sort_plus(int *a,int *tmp,int n){
		
		int lo_a = 0,hi_a=0,flag = 0;
		while(1){
			hi_a = lo_a+8;
			if(hi_a>n)hi_a = n,flag = 1;
			selection_for_merge(a,lo_a,hi_a);
			lo_a+=8;
			if(flag == 1)break;
		}
		
		int ownership = 1;
		for(int sz=1;sz<n;sz+=sz){
			for(int lo =0;lo<n-sz;lo+=(sz+sz)){
				if(ownership == 1) merge_plus(lo,lo+sz-1,min(lo+sz+sz-1,n-1) ,tmp,a,n);
				else merge_plus(lo,lo+sz-1,min(lo+sz+sz-1,n-1),a,tmp,n);
			}
			ownership = !ownership;
		}
		if(ownership!=1){
			for(int i=0;i<n;i++)
				a[i] = tmp[i];
		}
	}
	
	int is_sorted(int *a,int n){
		int i=0;
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1]){
				return 0;
			}
		}
		return 1;
	}
	
	int main(){
		
		srand(time(0));
		int *a,*b;
		int n = 8000;
		a = new int[n];
		random(a,n);
		/*copy(b,a,n);
		cout<<test(2,a,n)<<' '<<test(3,b,n);*///前两个算法的测试 
		clock_t start,final;
		start = clock();
		merge_sort_plus(a,tmp,8000);
		final = clock();
		cout<<(double)(final-start)/CLOCKS_PER_SEC<<' '<<is_sorted(a,n);//归并排序的速度测试 
		
		return 0;
	} 
