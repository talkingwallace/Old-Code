#include <iostream>
#include <time.h>
#include <cstdlib>
	using namespace std;

	void showall(int *a,int n){ //展示数组里的全部内容 
		
		for(int i=0;i<n;i++){
			cout<<a[i]<<' ';
			if(i+1%20==0){
				cout<<'\n';
			}
		}
	}
	
	int shell[6] =
	{1,4,13,40,121,364};
	int bn = 6;
	
	int random(int *a,int n){	//随机产生一个数组 
		
		for(int i = 0;i<n;i++){
			a[i] = rand()%8001-4000;
		}
		
	}
	
	void copy(int *b,int *a,int n){	//复制数组内容 
		
		b = new int[n]; 
		for(int i=0;i<n;i++){
			b[i] = a[i];
		}
	}
	
	int selection_sort(int *a,int n){	//选择排序 
		
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
	
	void insertion_sort(int *a,int n){	//插入排序啦 
		
		int tmp;
		for(int i=1;i<n;i++){
			for(int j=i;j>0&&a[j]<a[j-1];j--){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
	
	void insertion_sort(int *a,int n,int type){	//插入排序,增加了个哨兵 
		
		int tmp;
		int min=0;
		for(int i=0;i<n;i++){
			if(a[i]<a[min])
				min = i;
		}
		tmp = a[0];
		a[0] = a[min];
		a[min] = a[0];
		for(int i=1;i<n;i++){
			for(int j=i;a[j]<a[j-1];j--){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
	
	void shell_sort(int *a,int *b,int n,int bn){ //希尔排序 
		
		while(bn--){
			for(int i=b[bn];i<n;i++){
				for(int j=i;j>=b[bn]&&a[j]<a[j-b[bn]];j-=b[bn]){
					int tmp =a[j];
					a[j] = a[j-b[bn]];
					a[j-b[bn]] = tmp;
				}
			}
		}
	}
	//推荐使用 1 4 13 40 121 364...递增序列 
	//还有一个序列1 5 19 41 109 209 505 929 2126 ...... 


//-----------------------------------------------merge	
	
	int tmp[20000];//每次用要修改大小 
	int merge(int lo,int mid,int hi,int *a,int n){//tmp为辅助空间 
		
		int i=lo,j =mid+1;
		if(a[mid]<a[mid+1]){
			return 1;
		}
		for(int i=lo;i<=hi;i++){
			tmp[i] = a[i];
		}
		for(int k=lo;k<=hi;k++){
			if(i>mid)a[k] = tmp[j++];
			else if(j>hi) a[k] = tmp[i++];
			else if(tmp[j]<tmp[i]) a[k] = tmp[j++];
			else a[k] = tmp[i++];
		}
		
	}
	
	int merge_sort(int *a,int lo,int hi){	//用于自上而下递归（有问题，待修改） 
		
		if(lo>=hi)return 0;
		int mid = lo+(hi-lo)/2;
		merge_sort(a,lo,mid);
		merge_sort(a,mid+1,hi);
		merge(lo,mid,hi,a,hi);
	}
	
	int merge_sort(int *a,int n){ 	//	自下而上 
		
		for(int sz=1;sz<n;sz+=sz){
			for(int lo =0;lo<n-sz;lo+=(sz+sz)){
				merge(lo,lo+sz-1,min(lo+sz+sz-1,n-1),a,n);
			}
		}
	}
	
	int min(int a,int b){// 用于自下而上的归并 
		
		if(a<=b)return a;
		else return b;
	}
	
	//-------归并排序的三种改进 
	
	//改进1 a[mind]<a[mid+1] 则略过merge
	//改进2 先使用小组进行选择排序，然后在一起归并
	
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
	
	int merge_sort_plus(int *a,int n){ 	
		
		int lo_a = 0,hi_a=0,flag = 0;
		while(1){
			hi_a = lo_a+8;
			if(hi_a>n)hi_a = n,flag = 1;
			selection_for_merge(a,lo_a,hi_a);
			lo_a+=8;
			if(flag == 1)break;
		}
		for(int sz=8;sz<n;sz+=sz){
			for(int lo =0;lo<n-sz;lo+=(sz+sz)){
				merge(lo,lo+sz-1,min(lo+sz+sz-1,n-1),a,n);
			}
		}
	}
	//改进3 交换体位
	
	int merge_plus(int lo,int mid,int hi,int *a,int *tmp,int n){//tmp为辅助空间 
		
		int i=lo,j =mid+1;
		for(int k=lo;k<=hi;k++){
			if(i>mid)a[k] = tmp[j++];
			else if(j>hi) a[k] = tmp[i++];
			else if(tmp[j]<tmp[i]) a[k] = tmp[j++];
			else a[k] = tmp[i++];
		}
	}
	
	int merge_sort_pluss(int *a,int *tmp,int n){
		
		int ownership = 1;
		
		for(int sz=1;sz<n;sz+=sz){
			for(int lo =0;lo<n-sz;lo+=(sz+sz)){
				if(ownership == 1){
					merge_plus(lo,lo+sz-1,min(lo+sz+sz-1,n-1) ,tmp,a,n);
				}
				else{
					 merge_plus(lo,lo+sz-1,min(lo+sz+sz-1,n-1),a,tmp,n);
				}
			}
			ownership = !ownership;
		}
		if(ownership!=1){
			for(int i=0;i<n;i++){
				a[i] = tmp[i];
			}
		}
	}
	
//---------------------------------------------------------------------
//------------------快速排序
	
	int partition(int *a,int lo,int hi){
		
		int pivot = a[lo];
		int i =lo, j=hi;
		while(1){
			while(a[j]>pivot)j--;if(j<lo)break;
			a[i] = a[j];
			while(a[i]<pivot)i++;if(i>hi)break;
			a[j] = a[i];
		}
	}

	int quick_sort(int *a,int lo,int hi){
		
		if(hi<=lo)return 0;
		int pivot = partition(a,lo,hi);
		quick_sort(a,lo,pivot-1);
		quick_sort(a,pivot+1,hi);
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
	
	double test(int type,int *a,int n){ //对各种算法进行测试 
		
		clock_t start,end;
		start = clock();
		if(type == 1){
			selection_sort(a,n);
		}
		else if(type == 2){
			insertion_sort(a,n);
		}
		else if(type == 3){
			shell_sort(a,shell,n,bn);
		}
		end = clock();
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
	
	int main(){
		
		srand(time(0));
		int *a,*b;
		int n = 1000;
		a = new int[n];
		random(a,n);
		/*copy(b,a,n);
		cout<<test(2,a,n)<<' '<<test(3,b,n);*///前两个算法的测试 
		clock_t start,final;
		start = clock();
		merge_sort_pluss(a,tmp,1000);
		final = clock();
		cout<<(double)(final-start)/CLOCKS_PER_SEC<<' '<<is_sorted(a,n);//归并排序的速度测试 
		
		return 0;
	} 
