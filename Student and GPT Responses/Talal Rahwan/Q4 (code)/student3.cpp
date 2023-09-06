#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<sstream>
using namespace std;
//====================================
class Node
{
	private:
		int elem; //data element
		Node* next; //Link (pointer) to the next Node

	public:
		Node(int elem) : elem(elem), next(NULL)
		{}
		friend class MyLinkedList ;
};
//=====================================
class MyLinkedList
{
	private:
		Node* head; // pointer to the head of list
	public:
		MyLinkedList (); // empty list constructor
		~MyLinkedList (); // destructor to clean up all nodes
		bool empty() const; // is list empty?
		void addFront(int elem); // add a new Node at the front of the list
		void removeFront(); // remove front Node from the list
		unsigned int countElem(int elem); //count frequency of an element in the list
		int getIndexOf(int elem); //returns first index of an element in the list, -1 if the element is not present
		void display() const;
		const int& front() const;
		void loadData(string); //read a file and load it into the linked list
		void dumpData(string) const; //write the linked list to a file
		void sort();  // sort the elements of the list
};
//=====================================
class empty_list_error {
	private:
		string errMsg;
	public:
		empty_list_error(const string& err) : errMsg(err) { }
		string getError() { return errMsg; }
};
//=====================================
void listCommands()
{
	cout<<"List of available Commands:"<<endl
		<<"display            : Display the Linked List"<<endl
		<<"addFront <element> : Add <element> to the front of the Linked List"<<endl
		<<"removeFront        : Remove the front node of the Linked List"<<endl
		<<"count              : count frequency of an element in the list"<<endl
		<<"indexOf            : return first index of an elemenent in the list (-1 of not present)"<<endl
		<<"load <file_name>   : Load the data from <file> and add it into the Linked List"<<endl
		<<"dump <file_name>   : Dump the contents of the Linked list to <file>"<<endl
		<<"sort               : Sort the Linked List using Bubble Sort Algorithm"<<endl
		<<"help               : Display the list of available commands"<<endl
		<<"exit               : Exit the Program"<<endl;
}
//=======================================
// main function
int main()
{

	MyLinkedList myList;

	listCommands();
	string user_input;
	string command;
	string parameter;

	do
	{
		cout<<">";
		getline(cin,user_input);

		// parse userinput into command and parameter(s)
		stringstream sstr(user_input);
		getline(sstr,command,' ');
		getline(sstr,parameter);


		if(command=="display")
		{
			try {
				if (myList.empty())
					throw(empty_list_error("the list is empty\n"));
				myList.display();
			}
			catch (empty_list_error& obj) {
				cout << obj.getError();
			}
		}
		else if(command=="addFront" or command=="add")
			myList.addFront(stoi(parameter)),myList.display();
		else if(command=="removeFront" or command=="remove")
		{
			try {
				if (myList.empty())
					throw(empty_list_error("the list is empty\n"));
				myList.removeFront(),myList.display();
			}
			catch (empty_list_error& obj) {
				cout << obj.getError();
			}
		}
		else if(command=="count") {
			try {
				if (myList.empty())
					throw(empty_list_error("the list is empty\n"));
				cout<<parameter<<" occurs "<<myList.countElem(stoi(parameter))<<" time(s) in the list"<<endl;
			}
			catch (empty_list_error& obj) {
				cout << obj.getError();
			} }
		else if(command=="indexOf")
		{
			try {
				if (myList.empty())
					throw(empty_list_error("the list is empty\n"));
				cout<<"First index of "<<parameter<<" in the list is: "<<myList.getIndexOf(stoi(parameter))<<endl;
			}
			catch (empty_list_error& obj) {
				cout << obj.getError();
			}
		}
		else if(command=="load")
			myList.loadData(parameter),myList.display();
		else if(command == "dump")
		{
			try {
				if (myList.empty())
					throw(empty_list_error("the list is empty\n"));
				myList.dumpData(parameter);
			}
			catch (empty_list_error& obj) {
				cout << obj.getError();
			}
		}
		else if(command == "sort")
		{
			try {
				if (myList.empty())
					throw(empty_list_error("the list is empty\n"));
				myList.sort(),myList.display();
			}
			catch (empty_list_error& obj) {
				cout << obj.getError();
			}
		}
		else if(command == "help")
			listCommands();
		else if(command == "exit")
			break;
		else
			cout<<"Invalid Commad !!"<<endl;
	}while(command!="exit");

	return EXIT_SUCCESS;
}
//====================================
// constructor
MyLinkedList::MyLinkedList ()
{
	this->head = NULL;
}
//====================================
// destructor to clean up all nodes
MyLinkedList::~MyLinkedList ()
{
	//todo
	while (!empty())
		removeFront();
}
//====================================
// Check if the list is empty or not
bool MyLinkedList::empty() const
{
	//todo
	return (head == NULL);
}
//====================================
// add a node at the front of the list
void MyLinkedList::addFront(int elem)
{
	//todo
	Node *f = new Node(elem);
	(*f).next = head;
	head = f;
}
//====================================
// remove the first node from the list
void MyLinkedList::removeFront()
{
	//todo
	Node* old_front = head;
	head = (*head).next;
	delete old_front;
}
//====================================
// count frequency of an element in the list
unsigned int MyLinkedList::countElem(int elem)
{
	//todo
	unsigned int counter = 0;
	Node* current_node = head;
	while (current_node!= NULL)
	{
		if (current_node->next->elem == elem)
			counter++;
		current_node = current_node->next;
	}
	return (counter);
}
//==============================================
// get first index of an element in the the list.
// returns -1 if the element is not present
int MyLinkedList::getIndexOf(int elem)
{
	//todo
	unsigned int counter = 0;
	Node* current_node = head;
	while (current_node!= NULL)
	{
		if (current_node->elem == elem)
			return counter;
		counter++;
		current_node = current_node->next;
	}
	return (-1);
}
//==============================================
// display all nodes of the linked list
void MyLinkedList::display() const
{
	//todo
	cout << "Head->" << (*head).elem<<"->";
	Node* current_node = (*head).next;
	while ((current_node)!= NULL)
	{
		cout<<(*current_node).elem<<"->";
		current_node = current_node->next;
	}
	cout << "Null\n";
}
//====================================
// sort the elments of the list using bubble_sort
void MyLinkedList::sort()
{
	//todo
	int swap;
	Node* current_node;
	Node* tracker = head;
	while (tracker != NULL)
	{
		current_node = tracker -> next;
		while (current_node != NULL)
		{
			if (current_node -> elem < tracker -> elem)
			{
				swap = tracker -> elem;
				tracker -> elem = current_node -> elem;
				current_node -> elem = swap;
			}
			current_node = current_node->next;
		}
		tracker = tracker-> next;
	}
}
//==============================================
//Load data from a file and add it to the Linked List

// returns the element at the front
const int& MyLinkedList::front() const {
	return (head->elem);
}

void MyLinkedList::loadData(string path)
{
	//todo
	ifstream info(path);
	if (info.is_open())
	{
		int a;
		MyLinkedList rev;
		if (!(info >> a))
		{
			cout << "file is empty\n";
			return ;
		}
		rev.addFront(a);
		while (info>>a)
			rev.addFront(a);
		while (!empty())
			removeFront();
		while (!rev.empty())
		{
			addFront(rev.front());
			rev.removeFront();
		}
		info.close();
	}
	else
		cout << "Error opening file";
}
//=============================================
//Dump/write the contents of the list to a file
void MyLinkedList::dumpData(string path) const
{
	//todo
	ofstream info(path);
	if (info.is_open())
	{
		Node* current_node = head;
		while ((current_node)!= NULL)
		{
			info<<(*current_node).elem<<endl;
			current_node = current_node->next;
		}
		info.close();
	}
	else
		cout << "Error opening file";
}
//==================================================
