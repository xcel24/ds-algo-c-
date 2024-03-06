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
		tail=tail->next;
	}

	tail->next = new node(data);
	return;
}

void printList(node* head){

	while(head != NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<endl;
}

void reverseList(node* &head){

	node* prev = NULL;
	node* curr = head;
	node* temp = NULL;

	while(curr != NULL){
		temp = curr->next;
		curr->next = prev;

		prev = curr;
		curr = temp;
	}
	head = prev;
	return;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	node* head = NULL;

	for(int i=0;i<n;i++){
		insertAtTail(head,i);
	}

	printList(head);
	reverseList(head);
	printList(head);

	return 0;
}