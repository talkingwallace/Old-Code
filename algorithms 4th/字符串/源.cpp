#include <iostream>

using namespace std;

typedef struct NODE {

	double value;
	NODE *next[256];

}node;

class trie {

private:
	node* root;
	int R;

	node* put(string a,int d,double value,node* pt) {

		
	}
public:
	trie() {
		R = 256;
		root = NULL;
	}

};

int test() {

}

int main() {

	

	return 0;
}