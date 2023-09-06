#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<sstream>
using namespace std;
//====================================
class Errors {
private:
	string errorMsg;
public:
	Errors(const string& error) : errorMsg(error) { }
	string getError() {return errorMsg;}
};
//======================================
class Node
{
	private:
		int elem; //data element
		Node* next; //Link (pointer) to the next Node

	public:
		Node(int elem) : elem(elem), next(NULL) // constructor initilizer
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
		//void loadData(string); //read a file and load it into the linked list
		//void dumpData(string) const; //write the linked list to a file

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


		if(command=="display") {
		try {
				if (myList.empty())
					throw(Errors("Empty list!"));

				myList.display();
			}
			catch (Errors& obj) {
				cout << obj.getError();
			}
		}
		else if (command=="addFront" or command=="add")
			myList.addFront(stoi(parameter)),myList.display();

		else if (command=="removeFront" or command=="remove")
		{
			try {

				if(myList.empty())
					throw(Errors("Empty list!"));
				myList.removeFront(),myList.display();
			}
			catch (Errors& obj) {
				cout << obj.getError();
			}
		}

		else if(command=="count")
		{
			try {
				if (myList.empty())
					throw(Errors("Empty list!"));
			cout<<parameter<<" occurs "<<myList.countElem(stoi(parameter))<<" time(s) in the list"<<endl;
			}
			catch (Errors& obj) {
				cout << obj.getError();
			}
		}

		else if (command=="indexOf")
		{
			try {
				if(myList.empty())
					throw(Errors("Empty list!"));
			cout <<"First index of "<<parameter<<" in the list is: "<<myList.getIndexOf(stoi(parameter))<<endl;
			}
			catch (Errors& obj) {
				cout << obj.getError();
			}
		}
		//else if(command=="load")			myList.loadData(parameter),myList.display();
		/*else if(command == "dump") {
			try { if(myList.empty())
				throw(Errors("Empty list!"));
			myList.dumpData(parameter);
		    }
		catch (Errors& obj){
				cout<<obj.getError();}
		}*/
		else if(command == "help")			listCommands();
		else if(command == "exit")			break;
		else 								cout<<"Invalid Command!!"<<endl;
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
	while (!empty()) removeFront();
}
//====================================
// Check if the list is empty or not
bool MyLinkedList::empty() const
{
	return head == NULL;
}
//====================================
// add a node at the front of the list
void MyLinkedList::addFront(int elem)
{
	Node* tmp = new Node(elem); // creating a new node
	tmp->next = head; // head and next pointing in the same direction;
	head=tmp;
	return;
}
//====================================
// remove the first node from the list
void MyLinkedList::removeFront()
{
	Node* tmp = head; // temporary pointer pointing in the same direction
	head = head->next; // head points to the second node

	delete tmp;
}
//====================================
// count frequency of an element in the list
unsigned int MyLinkedList::countElem(int elem)
{
	Node* tmp = head;
	unsigned int counter=0;
	while (tmp != NULL) {// starts from head and continues checking unitl it reaches null or the end of the linkedlist

		if(tmp->elem == elem)
			counter++;
		tmp = tmp->next;
	}
	return counter;
}
//==============================================
// get first index of an element in the the list.
// returns -1 if the element is not present
int MyLinkedList::getIndexOf(int elem)
{
	int count=0;
	for(Node* tmp = head; tmp != NULL; tmp=tmp->next)
	{
		if(tmp->elem==elem)
			return count;
		count++;
	}
	return -1;
}
//==============================================
//display all nodes of the linked list
void MyLinkedList::display() const
{
	cout<<"Head->";
	for(Node* tmp = head; tmp!= NULL; tmp = tmp->next)
		cout<<tmp->elem<<"->";
	cout<<"NULL"<<endl;
}
//====================================
//Load data from a file and add it to the Linked List
/*void MyLinkedList::loadData(string path)
{
	ifstream myFile(path);

	int elem;
	MyLinkedList reverse;
	while (getline(myFile, elem))
		{
			reverse.addFront(elem);
		}
	while (!reverse.empty())
	myFile.close();
}
//=============================================
//Dump/write the contents of the list to a file
void MyLinkedList::dumpData(string path) const
{
	ofstream newfile; newfile.open(path);
	Newfile.close();
}
//================================================== */
