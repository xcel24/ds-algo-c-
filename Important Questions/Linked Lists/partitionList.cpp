#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

void insertAtHead(node* &head,int data){
	if(head==NULL){
		head = new node(data);
		return;
	}

	node* n = new node(data);
	n->next = head;
	head = n;

	return;
}

void printLL(node* head){
	while(head != NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}

	cout<<endl;
}

node* partitionList(node* head,int B){

	node* p = new node(0);
	node* q = new node(0);

	node* a = p;
	node* b = q;

	node* s = head;

	while(s != NULL){
		if(s->data < B){
			a->next = s;
			a = a->next;
		}else{
			b->next = s;
			b = b->next;
		}

		s = s->next;
	}

	b->next = NULL;
	a->next = q->next;

	return p->next;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* head = NULL;
	insertAtHead(head,2);
	insertAtHead(head,5);
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtHead(head,4);
	insertAtHead(head,1);

	int B = 3;

	printLL(head);

	node* modifiedHead = partitionList(head,B);

	printLL(modifiedHead);



	return 0;
}