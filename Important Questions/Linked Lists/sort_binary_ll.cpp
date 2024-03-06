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

void printLL(node* head){
	while(head != NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}

	cout<<endl;
}

node* sortBinaryList(node* head){
	node* prev = head;

	while(prev->next){
		node* curr = prev->next;

		if(curr->data == 0){

			//basically position this node at the head
			prev->next = curr->next;
			curr->next = head;
			head = curr;
		}else{
			prev = prev->next;
		}
	}

	return head;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* head = NULL;
	insertAtHead(head,0);
	insertAtHead(head,1);
	insertAtHead(head,1);
	insertAtHead(head,0);
	insertAtHead(head,0);

	printLL(head);

	node* sortedHead = sortBinaryList(head);

	printLL(sortedHead);



	return 0;
}