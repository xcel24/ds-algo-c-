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
}

void printList(node* head){
	while(head != NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<endl;
}

node* reverseList(node* head){

	//base case
	if(head->next == NULL or head == NULL){
		return head;
	}

	//recursive case
	node* sHead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;

	return sHead;

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

	printList(head);

	head = reverseList(head);

	printList(head);


	return 0;
}