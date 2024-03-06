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
	if(head == NULL){
		head = new node(data);
		return;
	}

	node* tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}

	tail->next = new node(data);
}

void printList(node* head){
	while(head != NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}

	cout<<endl;
	return;
}

node* kReverse(node* head,int k){

	//base case
	if(head==NULL){
		return NULL;
	}

	//recursive case

	//first reverse the k nodes
	node* prev = NULL;
	node* curr = head;
	node* temp = NULL;

	int count = 1;

	while(curr != NULL and count<=k){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;

		count++;
	}

	if(temp != NULL){
		head->next = kReverse(temp,k);
	}

	return prev;

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n,k;
	cin>>n>>k;

	node* head = NULL;

	for(int i=1;i<=n;i++){
		insertAtTail(head,i);
	}

	printList(head);

	node* rHead = kReverse(head,k);

	printList(rHead);

	return 0;
}