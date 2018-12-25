#include <iostream>
#include <cstdlib>
#include <fstream>

	using namespace std;
	
	struct mydata{
		
		int num;
		string str;
		
		friend ostream& operator<<(ostream& os,mydata a){
			os<<a.str<<' '<<a.num<<'\n';
		}
	};
	
	int m_less(mydata &a,mydata &b){
		return a.num<b.num;
	}
	
	void exch(mydata &a,mydata &b){
		mydata tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	class PQ{

		private:
			
		public:
			
			mydata *data;
			int length;
			int num;
			
			PQ(int n){
				data = new mydata[n];
				length = n;
			}
			
			PQ(int n,string filename){
				
				data = new mydata[n+1];
				length = num =n;
				ifstream fin(filename.c_str());
				int a;string str;
				for(int i=1;i<n+1;i++){
					fin>>str>>a;
					data[i].str = str;
					data[i].num = a;
				}
				fin.close();
			}
			
			int extend(){
				int tmp = length;
				length *=2;
				mydata* ptr = new mydata[length];
				if(ptr!=NULL){
					for(int i=0;i<tmp;i++){
						ptr[i] = data[i];
					}
					data = ptr;
				}
				else{
					return 0;
				}
				return 1;
			}
			
			void showall(){
				for(int i=1;i<num+1;i++){
					cout<<data[i];
				}
			}
			
			int swim(int k){
				
				if(k>length)return 0;
				while(k>1&&m_less(data[k/2],data[k])){
					exch(data[k/2],data[k]);
					k = k/2;
				}
				return 1;
			}
			
			void sink(int k,int n){
				
				while(2*k<=n){
					int j =2*k;
					int a=data[j].num,b=data[k].num,c=data[j+1].num;
					if(j<n&&data[j].num<data[j+1].num){
						j++;
					}
					if(data[k].num>=data[j].num){
						break;
					}
					exch(data[k],data[j]);
					k = j;
				} 
			}
			
			mydata delmax(){
				
				mydata tmp = data[1];
				exch(data[1],data[num]);
				data[num].num = 0;data[num].str="NULL";
				num--;
				sink(1,num);
				return tmp;
			}
			
			void insert(mydata a){
				
				if(num+1>length){
					extend();
				}
				num++;
				data[num] = a;
				swim(num);
			}
			
			void insertandkeep(mydata a){
				
				if(num+1>length){
					delmax();
				}
				num++;
				data[num] = a;
				swim(num);
			}
			
			void heap_sort(){
				
				for(int i=num/2;i>=1;i--){
					sink(i,num); 
				}
				int n =num;
				while(n>1){
					exch(data[1],data[n]);
					n--;
					sink(1,n);
				}	
			}
	};
	
	

	int main(){
		
		PQ a(2000,"data.txt");
		a.heap_sort();
		a.showall();
		return 0;
	} 
