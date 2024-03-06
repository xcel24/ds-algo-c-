#include<bits/stdc++.h>
using namespace std;

class node {

public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

void insertAtHead(node* &head,int data){

	//create a new node
	if(head == NULL){
		head = new node(data);
		return;
	}

	//otherwise
	node* n = new node(data);
	n->next = head;
	head = n;
}

void insertAtMiddle(node* &head, int data){

	//first calculate the length of the ll
	//then iterate till mid is found
	//then insert the element

	int length = 0;
	node* temp = head;
	while(temp != NULL){
		length++;
		temp = temp->next;
	}

	int mid = length/2;

	length=0;
	temp = head;
	while(length != mid-1){
		length++;
		temp = temp->next;
	}

	node* mid_address = temp->next;
	//create new node
	node* n = new node(data);
	temp->next = n;
	n->next = mid_address;
}

void printList(node* head){
	while(head != NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
}


int main(){ 


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	node* head = NULL;

	for(int i=n;i>=0;i--){
		insertAtHead(head,i);
	}

	insertAtMiddle(head,10);

	printList(head);

	return 0;
}