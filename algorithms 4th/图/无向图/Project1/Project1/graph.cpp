#include <iostream>
#include <string>
#include "BST.h"
#include <cstdlib>
using namespace std;

typedef struct q_NODE{
	
	int value;
	q_NODE* link = NULL; 
}q_node;

class queue{
	
private:
	q_node *head = NULL;
	q_node *end = NULL;
	int num;
		
	void in(int i,q_node *&pt){
		
		pt->link = new q_node;
		pt->link->value = i;
		pt->link->link = NULL; 
		pt = pt->link;
	}

public:
	queue(){
		num = 0;
	} 
	
	queue& operator+(int i){
		
		if(!num){
			head = new q_node;
			head->value = i;
			head->link = NULL;
			end = head;
		}
		else{
			in(i,end);
		}
		num++;
		return *this;
	}
	
	int operator--(){
		
		int a = -1;
		if(num == 0){}
		else{
			if(num == 1){end = NULL;}
			q_node *tmp = head;
			a = head->value;
			head = head->link;
			delete tmp;
			num--;
		}
		return a;
	}
	
	void read(){
		
		if(head){
			for(q_node* read = head;read;read = read->link){
				cout<<read->value<<' ';
			}
		}
	}
	
	int is_empty(){
		return num==0;
	}
	
	int show_num(){
		return num;
	}
};

class graph {

private:
	
	const int v;
	int e;

	bst *path_graph;
	
	bool *marked = NULL;

	void dfs(int position) {

		if (marked == NULL) {
			cout << "error!!";
		}
		if (marked[position]) {

		}
		else {
			marked[position] = 1;
			cout << position << endl;
			int num = adj[position].shownodenum();
			int *next = new int[num];
			adj[position].intoarray(next);
			for (int i = 0; i < num; i++) {
				if (!marked[next[i]]) {
					dfs(next[i]);
				}
			}
			delete []next;
		}
	}
	
	void path(int position,bst &tree){
		
		if (marked == NULL) {
			cout << "error!!";
		}
		if (marked[position]) {

		}
		else {
			marked[position] = 1;
			tree.put(position," ");
			int num = adj[position].shownodenum();
			int *next = new int[num];
			adj[position].intoarray(next);
			for (int i = 0; i < num; i++) {
				if (!marked[next[i]]) {
					path(next[i],tree);
				}
			}
			delete []next;
		}
	}

public:
    bst *adj;
	int V() {
		return v;
	}

	int E() {
		return e;
	}

	void addedge(int v, int w) {
		
		if(adj[v].find(w)){
			//do nothing
		} 
		else{
			adj[v].put(w," ");
			adj[w].put(v," ");
		}
	}

	int is_adj(int v, int w) {
		return adj[v].find(w);
	}

	graph(int numofv) :v(numofv) { //goujian kongtu

	}

	graph(int numofv, int numofe) :v(numofv) {

		e = numofe;
		adj = new bst[e];
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			addedge(a, b);
		}
	}

	graph(int numofv, int numofe, int value):v(numofv){

		e = numofe;
		adj = new bst[v];
		path_graph = new bst[v];
	}

	void showall() {

		for (int i = 0; i < v; i++) {
			adj[i].preorder();
			cout << endl;
		}
	}

	void DFS() {

		int count = 0;
		marked = new bool[v];
		for (int i = 0; i < v; i++) {
			marked[i] = 0;
		}
		for (int i = 0; i < v; i++) {
			if (!marked[i])count++;
			dfs(i);
		}
		cout << count<< endl;
		delete []marked;
	}
	
	void PATH(int position){
		
		marked = new bool[v];
		for(int i=0;i<v;i++){
			marked[i] = 0;
		}
		path(position,path_graph[position]);
		
	}
	
	void showpath(int position){
		path_graph[position].printtree();
	}
	
	int pathto(int v,int w){
		
		return path_graph[v].find(w);	
	}
	
	void BFS(int start){
		
		marked = new bool[v];
		for(int i=0;i<v;i++){
			marked[i] = 0;
		}
	
	}
	
	void test(){
		
		for(int i=0;i<v;i++){
			int *next;
			int num;
			num = adj[i].shownodenum();
			next = new int[num];
			adj[i].intoarray(next);
			for(int k=0;k<num;k++){
				cout<<next[k]<<' ';
			}
			delete []next;
			cout<<endl;
		}
	}
};

int main() {

	graph a(8,9,1);
	a.addedge(0,2);
	a.addedge(0,5);
	a.addedge(0,1);
	a.addedge(1,2);
	a.addedge(2,3);
	a.addedge(2,4);
	a.addedge(3,4);
	a.addedge(3,5);
	a.addedge(6,7);
    for(int i=0;i<a.V();i++){
    	a.adj[i].showarray();
    	cout<<endl;
	}
    
	return 0;
}
