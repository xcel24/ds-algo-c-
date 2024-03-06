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

void printList(node* head){

	while(head != NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}

	cout<<endl;
}

node* merge(node* h1, node* h2){

	//base case
	if(h1 == NULL) return h2;
	if(h2 == NULL) return h1;
	if(h1 == NULL and h2 == NULL) return NULL;

	//recursive case
	node* c = NULL;

	if(h1->data < h2->data){
		c = h1;
		c->next = merge(h1->next,h2);
	}else{
		c = h2;
		c->next = merge(h1,h2->next);
	}

	return c;
}

node* findMid(node* head){

	node* slow = head;
	node* fast = head->next;

	while(fast != NULL and fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}


node* mergeSort(node* head){

	//base case
	if(head == NULL or head->next == NULL){
		return head;
	}

	//recursive case
	node* mid = findMid(head);

	//Recursive sorting
	node* left = head;
	node* right = mid->next;

	mid->next = NULL;

	left = mergeSort(left);
	right = mergeSort(right);


	//Merge
	node* merged = merge(left,right);

	return merged;

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* head = NULL;

	insertAtHead(head,7);
	insertAtHead(head,8);
	insertAtHead(head,4);
	insertAtHead(head,5);
	insertAtHead(head,6);
	insertAtHead(head,1);
	insertAtHead(head,2);
	insertAtHead(head,3);

	printList(head);

	node* merged = mergeSort(head);

	printList(merged);



	return 0;
}