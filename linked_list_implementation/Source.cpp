#include<iostream>

using namespace std;

//to create a llinked list:
class list {
private:

	//to define a single node:
	struct node {
		int data;
		node * next;
	};
	node * head, *curr, * tail;

	//all fuctions goes here:
public:
	list() {
		//to avoid any garbage value:
		head = NULL;
		tail = NULL;
	}
	void createNode(int addData);
	void addNode(int data);
	void delNode(int delData);
	void printAll();
	bool sortedEmpty();
	int sortedGetLength();
	void sortedList();
	int sortedSearch(int key);
	


};

//to create node:
void list::createNode(int addData) {
	node* nnode = new node;
	nnode->data = addData;
	nnode->next = NULL;

	//if empty linked list:
	if (head == NULL)
	{
		head = nnode;
		tail = nnode;
		nnode = NULL;

	}

	//if only one node:
	else {
		tail->next = nnode;
		tail = nnode;
	}
}


//to print out the list:
void list::printAll() {
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "   ";
		temp = temp->next;

	}
}

//to check whether the list is empty:
bool list::sortedEmpty() {
	if (head == NULL && tail == NULL)
		
		return true;
	else
		return  false;
}

//to return the length of the list:
int list::sortedGetLength() {
	int count = 0;

	node* temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return count;


}

//to sort your list:
void list::sortedList() {
	node *i, *j;
	int temp;

	for (i = head; i->next != NULL; i = i->next) {

		for (j = i->next; j != NULL; j = j->next) {

			if (i->data > j->data) {
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}



}

//to search a key and return it's position:
int list::sortedSearch(int key) {
	node * pre = head;
	int position = 1;

	if (key == head->data) 
		return 1;

		while (pre != NULL) {
			position++;
			pre = pre->next;
			if (pre->data == key) {
				return position;
				break;
			}
			if (pre->next == NULL)
				return 0;
		}
	
}


//to delete the k'th element:
void list::delNode(int delData) {

	node * temp;
	temp = head;
	node *prev;

	if (temp == NULL)
	{
		cout << "List is empty, deletion is not possible" << endl;
	}
	else
	{
		if (temp->next == NULL)
		{
			if (temp->data == delData)
			{
				delete temp;
				head = NULL;
			}
			else
			{
				cout << "Entered Data value is not available in the List" << endl;
			}
		}
		else if (temp->data == delData)
		{
			head = temp->next;
			delete temp;
		}
		else
		{
			while (temp->next != NULL)
			{
				prev = temp;
				temp = temp->next;
				if ((temp->data == delData) && (temp->next != NULL))
				{
					prev->next= temp->next;
					delete temp;
				}
				else if (temp->data == delData && temp->next == NULL)
				{
					prev->next = NULL;
					delete temp;
				}
			}
		}
	}

	cout << "\n\nAfter deleting " << delData << endl;

	 }


 
int main() {

	list link;

	link.createNode(5);
	link.createNode(7);
	link.createNode(9);
	link.createNode(11);
	link.createNode(5);
	link.sortedList();

	cout << "printing out your list:\n ";
	link.printAll();
	cout << endl;
	link.createNode(7);
	link.sortedList();
	cout << "\nprinting out your list after your new insertion:\n ";
	link.printAll();
	link.sortedEmpty();
	cout << "\n\nthe length of your list is: " << link.sortedGetLength();
	cout << "\n\nprinting your sorted list: \n";
	link.sortedList();
	link.printAll();
	cout << "\n\nposition of the key 7: ";
	cout << link.sortedSearch(7);
	link.delNode(5);
	link.printAll();
	
    cout << "\n\n";
	system("pause");
	return 0;
}