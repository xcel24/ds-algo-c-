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

	return;
}

void printList(node* head){
	while(head != NULL){
		cout<<head->data<<" ";

		head = head->next;
	}

	cout<<endl;
}

node* sortedHeadHelper(node* sortedHead, node* curr){

	//base case
	if(sortedHead == NULL || sortedHead->data >= curr->data){
		curr->next = sortedHead;
		sortedHead = curr;
	}else{

		node* tail = sortedHead;

		while(tail->next != NULL and tail->next->data < curr->data){
			tail = tail->next;
		}

		curr->next = tail->next;
		tail->next = curr;
	}

	return sortedHead;
}


node* insertionSort(node* head){

	node* curr = head;
	node* sortedHead = NULL;

	while(curr != NULL){
		node* currNext = curr->next;

		sortedHead = sortedHeadHelper(sortedHead,curr);

		curr = currNext;
	}

	return sortedHead;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* head = NULL;

	insertAtHead(head,6);
	insertAtHead(head,5);
	insertAtHead(head,13);
	insertAtHead(head,11);
	insertAtHead(head,12);
	insertAtHead(head,10);

	node* temp = head;
	printList(temp);

	node* ans = insertionSort(head);
	printList(ans);


	return 0;
}