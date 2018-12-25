#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>

	using namespace std;
	
	string lastname[505];
	string firstname[3875];
	
	void initial(){
		
		ifstream fin("lastname.txt");
		ifstream fin_2("firstname.txt");
		for(int i=0;fin>>lastname[i];i++);
		for(int i=0;fin_2>>firstname[i];i++);
		fin.close();fin_2.close();
		
	}
	
	void getname_data(string &a,int &num){
		
		int b =rand()%505;
		int c =rand()%3875;
		num = rand()%8000;
		a = lastname[b]+firstname[c];
	}
	
	int main(){
		
		initial();
		ofstream fout("data.txt");
		fout>"lastname.txt"; 
		int num;
		string a;
		srand(time(0));
		for(int i=0;i<8000;i++){
			getname_data(a,num);
			fout<<a<<' '<<num<<endl;
		}
		fout.close();
		
		return 0;
	}
