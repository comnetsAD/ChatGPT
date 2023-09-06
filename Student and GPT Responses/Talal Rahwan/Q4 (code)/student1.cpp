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
		void loadData(string); //read a file and load it into the linked list
		void dumpData(string) const; //write the linked list to a file
		void sort();  // sort the elements of the list
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


		if(command=="display") 				myList.display();
		else if(command=="addFront" or command=="add")				myList.addFront(stoi(parameter)),myList.display();
		else if(command=="removeFront" or command=="remove")		myList.removeFront(),myList.display();
		else if(command=="count")			cout<<parameter<<" occurs "<<myList.countElem(stoi(parameter))<<" time(s) in the list"<<endl;
		else if(command=="indexOf")         cout<<"First index of "<<parameter<<" in the list is: "<<myList.getIndexOf(stoi(parameter))<<endl;
		else if(command=="load")			myList.loadData(parameter),myList.display();
		else if(command == "dump")			myList.dumpData(parameter);
		else if(command == "sort")			myList.sort(),myList.display();
		else if(command == "help")			listCommands();
		else if(command == "exit")			break;
		else 								cout<<"Invalid Commad !!"<<endl;
	}while(command!="exit");

	return EXIT_SUCCESS;
}
//====================================
// constructor
MyLinkedList::MyLinkedList ()
{
	/* */
	this->head = NULL;
}
//====================================
// destructor to clean up all nodes
MyLinkedList::~MyLinkedList ()
{
	//todo
	while (!empty()) {
        removeFront();
	}
	/*the destructor deletes the linked list created at the end of the program running by removing
	the front one by one */
}
//====================================
// Check if the list is empty or not
bool MyLinkedList::empty() const
{
	//todo
    return head==NULL;
    /* if the head is null this function returns true*/

}
//====================================
// add a node at the front of the list
void MyLinkedList::addFront(int elem)
{
	//todo
	Node* temp = new Node(elem); // create new node, “temp”

    temp -> next = head; // Now, “temp” points to the front of the list
    head = temp;//now temp becomes the new head
}
//====================================
// remove the first node from the list
void MyLinkedList::removeFront()
{
	//todo
    Node* temp = head; // create new node, “temp” and set it equal to headd
    head = head -> next; // Now, head points to the next element
    delete temp;//delete temp

}
//====================================
// count frequency of an element in the list
unsigned int MyLinkedList::countElem(int elem)
{
	int ctr = 0;
	Node* temp = head;
	while(temp!= NULL) {

        if (temp -> elem == elem) {
            ctr++;
        }

        temp = temp -> next;
	}
    return ctr;
    /* this function creates a temporary node and sets it to the head. it then gets set to the next element till the end
    of the list. every time the element is the same as the one entered by the user, a ctr variable gets incremented */
}
//==============================================
// get first index of an element in the the list.
// returns -1 if the element is not present
int MyLinkedList::getIndexOf(int elem)
{
	//todo
	int ctr = 0;
	Node* temp = head;
	while(temp -> elem != elem) {

        if (temp -> elem != elem) {
            ctr++;
        }

        temp = temp -> next;
	}
    return ctr;
    /*this function creates a temporary node and sets it to the head. it then gets set to the next element till the end
    of the list. every time the element is not the same as the one entered by the user, a ctr variable gets incremented*/
}
//==============================================
// display all nodes of the linked list
void MyLinkedList::display() const
{
	//todo
	Node* temp = head;
	cout << "Head -> ";
	while (temp != NULL) {
        cout << temp -> elem << " -> " ;
        temp = temp -> next;
	}
	cout << "NULL" << endl;
	/* This function creates a temporary node and sets it to each element of the list and then outputs them to the console for
	each of them*/
}
//====================================
// sort the elements of the list using bubble_sort
void MyLinkedList::sort()
{
	//todo
    //sorrryyyy
}
//==============================================
//Load data from a file and add it to the Linked List
void MyLinkedList::loadData(string path)
{
	//todo
	string filename = path;
	ifstream file1;
    file1.open(filename, ios::in);
    if (file1.fail()) {
        cerr << "file1 failed to open, exiting..";
        exit(1);

    }
    int x = 0;

    while(!file1.eof()) {
        file1 >> x;
        addFront(x);
    }
    /* this function opens a file, it takes numbers from it line by line and uses the addfront function to add them to the linked list*/
}
//=============================================
//Dump/write the contents of the list to a file
void MyLinkedList::dumpData(string path) const
{
	//todo
	string filename = path;
	ofstream file2(filename);
    if (file2.fail()) {
        cerr << "file2 failed to open, exiting..";
        exit(1);
    }

    Node* temp = head;

	while (temp != NULL) {
        file2 << temp -> elem << endl ;
        temp = temp -> next;
	}
    /*this function creates a new file and puts each element of the linked list in it with a new line after each element*/
}
