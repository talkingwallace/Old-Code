#include <iostream>
#include <fstream>

	using namespace std;
	
	void sort(string *a,int n){
		
		string aux[n];
		int r = 256;
		int length = a[0].length();
		for(int d = length-1;d>=0;d--){
			int count[r+1];
			for(int i=0;i<r;i++){
				count[i] = 0;
			}
			for(int i=0;i<n;i++){
				count[a[i][d]+1]++;
			}
			for(int i=0;i<r-1;i++){
				count[i+1] += count[i];
			}
			for(int i=0;i<n;i++){
				aux[count[a[i][d]]++] = a[i];
			} 
			for(int i=0;i<n;i++){
				a[i] = aux[i];
			}

		}
	}
	
	int main(){
		
		ifstream fin("data2.txt");
		string a[30];
		for(int i=0;i<30;i++){
			fin>>a[i];
		}
		sort(a,30);
		for(int i=0;i<30;i++){
			cout<<a[i]<<endl;
		}
		return 0;
	} 
