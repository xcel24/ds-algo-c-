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

node* removeDuplicates(node* head){

	node* curr = head;

	while(curr != NULL and curr->next != NULL){
		if(curr->data == curr->next->data){
			node* toDelete = curr->next;
			node* temp = toDelete->next;

			delete(toDelete);
			curr->next = temp;
		}else{
			curr = curr->next;
		}
	}

	return head;
}


//remove all duplicates i.e no occurrence should be left
node* removeDuplicates2(node* head){
	node* dummy = new node(0);
	dummy->next = head;

	node* curr = head;
	node* prev = dummy;

	while(curr != NULL){
		if(curr->next != NULL and curr->data == curr->next->data){

			while(curr->next != NULL and curr->data == curr->next->data){
				curr = curr->next;
			}

			prev->next = curr->next;

		}else{
			prev = prev->next;
		}

		curr = curr->next;
	}

	return dummy->next;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* head = NULL;
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);

	printLL(head);

	// node* newHead = removeDuplicates(head);
	// printLL(newHead);

	node* newHead2= removeDuplicates2(head);
	printLL(newHead2);


	return 0;
}