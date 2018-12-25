#include <iostream>

	using namespace std;
	
	void insertion_sort(int *a,int n){	//≤Â»Î≈≈–Ú¿≤ 
		
		int tmp;
		for(int i=1;i<n;i++){
			for(int j=i;j>0&&a[j]<a[j-1];j--){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
	
	int main(){
		
		int a[20] = {1,2,3,3,7,7,6,2,3,1,2,3,4,5,8,8,9,10,11,12};
		insertion_sort(a,20);
		int count=1;
		for(int i=i;i<20;i++){
			if(i>0&&a[i]!=a[i-1]){
				count++;
			}
		}	
		for(int i=0;i<20;i++){
			cout<<a[i]<<' ';
		}
		cout<<endl<<count;
		return 0;
	} 
