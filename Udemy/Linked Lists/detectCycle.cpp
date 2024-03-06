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

bool detectCycle(node* head){

	node* slow = head;
	node* fast = head;

	while(fast != NULL and fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast){
			return true;
		}
	}

	return false;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* head = NULL;

	insertAtHead(head,1);
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtHead(head,4);
	insertAtHead(head,5);
	insertAtHead(head,6);

	//making a loop
	node* tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}

	tail->next = head;

	cout<<detectCycle(head)<<endl;


	return 0;
}