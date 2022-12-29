#include<iostream>
using namespace std;


class Node {
public :
	Node* previous;
	Node* next;
	int key, data;

	Node() {
		previous = NULL;
		next = NULL;
		key = data = 0;
	}

	Node(int k, int d) {

		key = k;
		data = d;


	}
};


class DoublyLinkedList {
public:
	Node* head;

	DoublyLinkedList() {
		head = NULL;

	}

	DoublyLinkedList(Node* n) {

		head = n;
	}


	//check if node exists

	Node* checkIfNodeExists(int k) {

		Node* temp = NULL;
		Node* ptr = head;

		while (ptr != NULL) {
			if (ptr->key == k) {
				temp = ptr;

			}
			ptr = ptr->next;
		}

		return temp;
	}

	//Append node to a list

	void appendNode(Node * n) {

		if (checkIfNodeExists(n->key) != NULL) {
			cout << "Node Already Exists with the key value : " << n->key << " > Append another node with differrnt key value" << endl;

		}
		else {
			if (head == NULL) {
				head = n;
				cout << "Node Appended as Head Node " << endl;
			}
			else {
				Node* ptr = head;
				while (ptr->next != NULL) {

					ptr = ptr->next;
				}

				ptr->next = n;
				n->previous = ptr;
				cout << "Node Appended " << endl;
			}
		}

	}

	//prepend node

	void prependNode(Node* n) {
		if (checkIfNodeExists(n->key)!=NULL) {

			cout << "Node Already Exists with the key value : " << n->key << " > Append another node with differrnt key value" << endl;

		}
		else {

			if (head == NULL) {
				head = n;
				cout << "Node prepended as Head Node " << endl;

			}
			else {

			head->previous = n;
			n->next = head;
			head = n;
			cout << "Node prepended" << endl;
			}
		}
	}

	//inserting node after particular node
	void insertNodeAfter(int k, Node* n) {

		Node* ptr = checkIfNodeExists(k);
			if(ptr == NULL) {
				cout << "No Node Existx with key value : " << k << endl;

			}
			else {
				if (checkIfNodeExists(n->key) != NULL) {

					cout << "Node Already Exists with the key value : " << n->key << " > Append another node with differrnt key value" << endl;

				}
				else {
					//inserting at the end
					Node* nextNode = ptr->next;

					if (nextNode == NULL) {
						ptr->next = n;
						n->previous = ptr;
						cout << "Node inserted at the END " << endl;

					}

					//inserting in between
					else {
						n->next = nextNode;
						nextNode->previous = n;
						n->previous = ptr;
						ptr->next = n;

						cout << "Node inserted in between " << endl;
					}

				}
			}
	}

	//deleting a particular node by key
	void deleteNodeByKey(int k){

		Node* ptr = checkIfNodeExists(k);
		if (ptr == NULL) {
			cout << "No Node Existx with key value : " << k << endl;
		}
		else {
			if (head->key == k) {

				head = ptr->next;
				cout << "Node unlinked with key values : " << k << endl;
			}
			else {
				Node* nextNode = ptr->next;
				Node* prevNode = ptr->previous;

				//deleting at the end
				if (nextNode == NULL) {
					prevNode->next = NULL;
					cout << "Node Deleted at the END" << endl;
				}

				//deleting in between
				else {
					prevNode->next = nextNode;
					nextNode->previous = prevNode;

					cout << "Node Deleted in Between " << endl;
				}
			}
		}

		

	}

	//update node
	void updateNodeByKey(int k, int d) {
		Node* ptr = checkIfNodeExists(k);
		if (ptr != NULL) {
			ptr->data = d;
			cout << "Node data Updated Successfully" << endl;
		}
		else {
			cout << "Node Doesn't exist with the key " << k << endl;
		}

	}


	//printing
	void printList() {

		if (head == NULL) {
			cout << "No Node in Doubly Linked List";

		}
		else {
			cout << endl << "Dubly linke d list ";
			Node* temp = head;
			while (temp != NULL) {
				cout << "(" << temp->key << "," << temp->data << ")<-->";
				temp = temp->next;
			}
		}
	}
};


int main() {

	DoublyLinkedList obj;
	int option;
	int key1, k1, data1;

	do {
		cout << "\nWhat operation do you want to perform? Select Option number. Enter to exit." << endl;
		cout << "1. appendNode()" << endl;
		cout << "2. prependNode ()" << endl;
		cout << "3. insertNodeAfter ()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
		cout << "6. print ()" << endl;
		cout << "7. Clear Screen" << endl << endl;

		cin >> option;

		Node* n1 = new Node();

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "Append node Operation \n Enter key and data of the node to be Appended" << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			obj.appendNode(n1);
			break;
		case 2:
			cout << "Prepend Node Operations \n Enter key and data to be prepended" << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			obj.prependNode(n1);
			break;

		case 3:
			cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
			cin >> k1;
			cout << "Enter key & data of the New Node first: " << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;

			obj.insertNodeAfter(k1, n1);
			break;

		case 4:
			cout << "Delete Node By key Opeartion - \n Enetr key of the node to be deleted " << endl;
			cin >> k1;
			obj.deleteNodeByKey(k1);
			break;


		case 5:
			cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
			cin >> key1;
			cin >> data1;
			obj.updateNodeByKey(key1, data1);
			break;

		case 6:
			obj.printList();
			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Enter Proper Option number " << endl;

		}

		

	} while (option != 0);

	return 0;
}