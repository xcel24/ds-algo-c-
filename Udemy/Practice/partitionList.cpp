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
	if(head == NULL){
		head = new node(data);
		return;
	}

	node* n = new node(data);
	n->next = head;
	head = n;
}

void printList(node* head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

node* partitionList(node* head, int B){

	//they will act as a dummy starting point
	node* p = new node(0);
	node* q = new node(0);

	node* a = p, *b = q;

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

	//point the ending of list b to NULL
	b->next = NULL;
	a->next = q->next;

	return p->next;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int B;
	cin>>B;

	node* head = NULL;

	insertAtHead(head,2);
	insertAtHead(head,5);
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtHead(head,4);
	insertAtHead(head,1);

	node* temp = head;

	printList(temp);
	cout<<endl;

	node* ans = partitionList(head,B);

	printList(ans);


	return 0;
}