#include <iostream>
#include <time.h>
#include <cstdlib>

	using namespace std;
	
	int CMP(int *a,int *b){
		
		if(*a==*b)return 0;
		else if(*a>*b)return 1;
		else return -1;
	}
	
	void exch(int *a,int *b){
		
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
	
	void showall(int *a,int n){ //չʾ�������ȫ������ 
		
		for(int i=0;i<n;i++){
			cout<<a[i]<<' ';
			if(i+1%20==0){
				cout<<'\n';
			}
		}
	}
	
	int random(int *a,int n){	//�������һ������ 	
		for(int i = 0;i<n;i++)
			a[i] = rand()%8001-4000;
	}
	
	int is_sorted(int *a,int n){
		int i=0;
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1]){
				cout<<i<<' '<<a[i]<<' '<<a[i+1];
				return 0;
			}
		}
		return 1;
	}
	
	//insertion�ϳ������� ���������ڴ�С�� 
	int insertion(int *a,int lo,int hi){
		
		int tmp;
		for(int i=lo+1;i<=hi;i++){
			for(int j=i;j>lo&&a[j]<a[j-1];j--){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}

	int partition(int *a,int lo,int hi){
		
		int pivot = a[lo];
		int i =lo, j=hi;
		while(1){
			while(a[j]>=pivot){
				j--;
				if(j<=i)break;
			}
			a[i] = a[j];
			while(a[i]<pivot){
				i++;
			}
			a[j] = a[i];
			if(i>=j)break;
		}
		a[j] = pivot;

		return j;
	}
	
	int quick_sort(int *a,int lo,int hi){
		
		if(hi<=lo+3){
			insertion(a,lo,hi);return 0; 
		}
		int pivot = partition(a,lo,hi);
		quick_sort(a,lo,pivot-1);
		quick_sort(a,pivot+1,hi);
	} 
	
	int quick3way(int *a,int lo,int hi){
		
		if(hi<=lo)return 1;
		int lt =lo,i =lo+1,gt = hi;
		int pivot = a[lo];
		while(i<=gt){
			int cmp = CMP(&pivot,&a[i]);
			if(cmp>0){
				exch(&a[lt],&a[i]);
				lt++;i++;
			}
			else if(cmp<0){
				exch(&a[i],&a[gt]);
				gt--;
			}
			else{
				i++;
			}
		}
		quick3way(a,lo,lt-1);
		quick3way(a,gt+1,hi);
	}
	
	void insertion_sort(int *a,int n){	//���������� 
		
		int tmp;
		for(int i=1;i<n;i++){
			for(int j=i;j>0&&a[j]<a[j-1];j--){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
	
		int tmp[20000];//ÿ����Ҫ�޸Ĵ�С 
	int merge(int lo,int mid,int hi,int *a,int n){//tmpΪ�����ռ� 
		
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
	
	int merge_sort(int *a,int lo,int hi){	//�������϶��µݹ飨�����⣬���޸ģ� 
		
		if(lo>=hi)return 0;
		int mid = lo+(hi-lo)/2;
		merge_sort(a,lo,mid);
		merge_sort(a,mid+1,hi);
		merge(lo,mid,hi,a,hi);
	}
	
	int merge_sort(int *a,int n){ 	//	���¶��� 
		
		for(int sz=1;sz<n;sz+=sz){
			for(int lo =0;lo<n-sz;lo+=(sz+sz)){
				merge(lo,lo+sz-1,min(lo+sz+sz-1,n-1),a,n);
			}
		}
	}
	
	int min(int a,int b){// �������¶��ϵĹ鲢 
		
		if(a<=b)return a;
		else return b;
	}
	
	void Q2P(int *a, int left, int right){
		
    int i = left - 1, j = right;
    int v = a[right];

    if (right <= left)
        return;

    while(true)
    {
        while (a[++i] < v) ;
        while(v < a[--j])
        {
            if (j == left)
                break;
        }
        if (i >= j)
            break;

        int c1 = a[i];
        a[i] = a[j];
        a[j] = c1;
    }

    int c2 = a[i];
    a[i] = a[right];
    a[right] = c2;

    Q2P(a, left, i - 1);
    Q2P(a, i + 1, right);
    }	
    
    int shell[6] =
	{1,4,13,40,121,364};
	int bn = 6;

	
	int selection_sort(int *a,int n){	//ѡ������ 
		
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
	

	
	void insertion_sort(int *a,int n,int type){	//��������,�����˸��ڱ� 
		
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
	
	void shell_sort(int *a,int *b,int n,int bn){ //ϣ������ 
		
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
	
	int main(){        //�˴��������� 
		
		cout<<"shell";
		srand(time(0));
		int *a,*b;
		int times[5]={ 2000,4000,8000,10000,16000};
		for(int i=0;i<5;i++){
		a = new int[times[i]];
		random(a,times[i]);
		
		/*copy(b,a,n);
		cout<<test(2,a,n)<<' '<<test(3,b,n);*/
		
		clock_t start,final;
		start = clock();
		cout<<endl;
		Q2P(a,0,times[i]-1);//�����������ͬ���㷨 
		final = clock();
		cout<<(double)(final-start)/CLOCKS_PER_SEC;
		}
		
		return 0;
	}
