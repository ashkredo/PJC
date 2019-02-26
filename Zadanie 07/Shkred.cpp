/**
*
*  @author Shkred Artur S15444
*
*/

#include <iostream>

using namespace std;

//---------------------------------------------------------//
struct Node {
	int   data;
	Node* next;
};

Node* arrayToList(const int arr[], size_t size) {
	if (size == 0) { return nullptr; }
	Node* head = NULL;
	for (int i = size - 1; i>= 0; i--) {
		Node *p = new Node;
		p->data = arr[i];
		p->next = head;
		head = p;
	}
	return head;
}

Node* removeOdd(Node* head) {
	if (!head) { return nullptr; }
	bool trueOrFalse = false;
	Node* value1 = 0; Node* value2 = 0;
	while (head) {
		if (0 != (head->data % 2)) {
			cout << "DEL:" << head->data << " ";
			if(value2) { value2 -> next = head -> next; } 
			head = head->next;
			trueOrFalse = true;
		} else {
			value2 = head;
			if (!value1) { value1 = value2; }
			head = head->next;
		}
	} if (trueOrFalse) { cout << endl; }
	return value1;
}

void showList(const Node* head) {
	if (head) {
		while (head) {
			cout << head->data << " ";
			head = head->next;
		} cout << endl;
	}
	else { cout << "Empty list" << endl; }
}

void deleteList(Node*& head) {
	Node* node = head;
	while(head) {
		node = head;
		cout << "del:" << node -> data << " ";
		head = head->next;
		delete node;
	} cout << endl;
	head = nullptr; 
}
//---------------------------------------------------------//

//........................Zadanie_07.......................// 
int main() {
	int arr[] = { 1,2,3,4,5,6 };
	size_t size = sizeof(arr) / sizeof(*arr);
	Node* head = arrayToList(arr, size);
	showList(head);
	head = removeOdd(head);
	showList(head);
	deleteList(head);
	showList(head);

	system("pause");
	return 0; }
//---------------------------------------------------------//