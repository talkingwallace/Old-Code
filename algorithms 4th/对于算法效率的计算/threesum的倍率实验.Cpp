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
	
	int main(){
		
		/*clock_t start,finish;
		double totaltime;
		int *a;
		double lasttime = 1;
		for(int n=125;n<=8000;n*=2)
		{
		
		a = new int[n];
		random(a,n);
		start = clock();
		int cnt = count(a,n);
		finish = clock();
		totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
		cout<<"\n"<<totaltime<<"s\n"<<' '<<totaltime/lasttime;
		lasttime = totaltime;
		if(lasttime == 0 )lasttime = 1;
		
		delete []a;*/
		for(int i=0;i<3;i++){
			cout<<rand();
		}
		
	
		
		return 0;
	} 
