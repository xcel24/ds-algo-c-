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
		cout<<head->data<<"-->";
		head = head->next;
	}

	cout<<endl;
}

void insertAtTail(node* &head, int data){
	if(head == NULL){
		head = new node(data);
		return;
	}

	node* tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}

	tail->next = new node(data);
	return;
}

node* reverseListRecursion(node* head){

	//base case
	if(head == NULL or head->next == NULL){
		return head;
	} 

	//recursive case
	node* sHead = reverseListRecursion(head->next);

	head->next->next = head;
	head->next = NULL;

	return sHead;
}

void reverseListIteration(node* &head){

	node* curr = head;
	node* prev = NULL;
	node* temp = NULL;

	while(curr != NULL){
		temp = curr->next;
		curr->next = prev;

		prev = curr;
		curr = temp;
	}

	head = prev;

	return ;
}

node* findMid(node* head){
	node* fast = head;
	node* slow = head;

	while(fast != NULL and fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

node* insertAtMiddle(node* head,int data){
	node* mid = findMid(head);
	node* temp = mid->next;

	node* n = new node(data);
	mid->next = n;
	n->next = temp;

	return head;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif


	node* head1 = NULL;
	node* head2 = NULL;
	insertAtHead(head1,7);
	insertAtHead(head1,8);
	insertAtHead(head1,4);
	insertAtHead(head1,5);
	insertAtHead(head1,6);
	insertAtHead(head1,1);
	insertAtHead(head1,2);
	insertAtHead(head1,3);

	printList(head1);

	insertAtTail(head2,3);
	insertAtTail(head2,2);
	insertAtTail(head2,1);
	insertAtTail(head2,6);
	insertAtTail(head2,5);
	insertAtTail(head2,4);
	insertAtTail(head2,8);
	insertAtTail(head2,7);

	printList(head2);

	node* reversedRecursion = reverseListRecursion(head1);
	printList(reversedRecursion);

	// reverseListIteration(head2);
	// printList(head2);

	node* headWithMid = insertAtMiddle(head2,24);
	printList(headWithMid);


	return 0;
}