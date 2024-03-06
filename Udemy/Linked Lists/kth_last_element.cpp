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
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<endl;
	return;
}

int getKthLast(node* head,int k){

	node* first = head;
	node* second = head;

	for(int i=1;i<k;i++){
		first = first->next;
	}

	while(first != NULL and first->next != NULL){
		first = first->next;
		second = second->next;
	}

	return second->data;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int k;
	cin>>k;

	node* head = NULL;
	insertAtHead(head,7);
	insertAtHead(head,6);
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);

	printList(head);

	cout<<getKthLast(head,k)<<endl;


	return 0;
}