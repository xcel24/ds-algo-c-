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

void insertAtTail(node* &head,int data){

	if(head==NULL){
		head = new node(data);
		return;
	}

	node* tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}

	tail->next = new node(data);

}

node* mergeLists(node* h1, node* h2){

	//base case
	if(h1 == NULL) return h2;
	if(h2 == NULL) return h1;
	if(h1 == NULL and h2 == NULL) return NULL;

	//recursive case
	node* c = NULL;
	if(h1->data < h2->data){
		c = h1;
		c->next = mergeLists(h1->next,h2);
	}else{
		c = h2;
		h2->next = mergeLists(h1,h2->next);
	}

	return c;

}

void printList(node* head){
	while(head != NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}

	cout<<endl;
}


int main(){


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* head1 = NULL;
	node* head2 = NULL;

	insertAtTail(head1,1);
	insertAtTail(head1,5);
	insertAtTail(head1,7);
	insertAtTail(head1,10);

	insertAtTail(head2,2);
	insertAtTail(head2,3);
	insertAtTail(head2,6);

	

	node* sortedHead = mergeLists(head1,head2);

	printList(sortedHead);

	return 0;
}