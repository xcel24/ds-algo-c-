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
	if(head== NULL){
		head = new node(data);
		return;
	}

	node* n = new node(data);
	n->next = head;
	head = n;

	return ;
}

void printLL(node* head){
	while(head != NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}

	cout<<endl;
}

node* insertionSortHelper(node* sortedHead,node* curr){
	//base case i.e insert at the head of the sorted List part
	if(sortedHead == NULL || sortedHead->data > curr->data){
		curr->next = sortedHead;
		sortedHead = curr;
	}else{
		node* tail = sortedHead;

		while(tail->next and tail->next->data < curr->data){
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
		sortedHead = insertionSortHelper(sortedHead,curr);
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
	insertAtHead(head,5);
	insertAtHead(head,8);
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtHead(head,7);
	insertAtHead(head,6);
	insertAtHead(head,4);
	insertAtHead(head,1);

	printLL(head);

	node* sortedHead = insertionSort(head);
	printLL(sortedHead);



	return 0;
}