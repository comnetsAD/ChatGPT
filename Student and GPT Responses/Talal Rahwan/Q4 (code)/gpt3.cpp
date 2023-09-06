#include <iostream>
#include <fstream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class MyLinkedList {
    private:
        Node *head;
    public:
        MyLinkedList() {
            head = NULL;
        }

        // method to check if the linked list is empty
        bool empty() const {
            return (head == NULL);
        }

        // method to add a new node to the front of the linked list
        void addFront(int elem) {
            Node *newNode = new Node;
            newNode->data = elem;
            newNode->next = head;
            head = newNode;
        }

        // method to remove the first element of the linked list
        void removeFront() {
            if (empty()) {
                cout << "Error: linked list is already empty" << endl;
            } else {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }

        // method to count the frequency of a specific element in the linked list
        int countElem(int elem) {
            Node *current = head;
            int count = 0;
            while (current != NULL) {
                if (current->data == elem) {
                    count++;
                }
                current = current->next;
            }
            return count;
        }

        // method to get the index of a specific element in the linked list
        int getIndexOf(int elem) {
            Node *current = head;
            int index = 0;
            while (current != NULL) {
                if (current->data == elem) {
                    return index;
                }
                current = current->next;
                index++;
            }
            return -1;
        }

        // method to display the entire linked list
        void display() {
            Node *current = head;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        // method to load data from a text file into the linked list
        void loadData(string file) {
            ifstream inFile(file);
            int elem;
            while (inFile >> elem) {
                addFront(elem);
            }
            inFile.close();
        }

        // method to write the contents of the linked list to a text file
        void dumpData(string file) const {
            ofstream outFile(file);
            Node *current = head;
            while (current != NULL) {
                outFile << current->data << endl;
                current = current->next;
            }
            outFile.close();
        }

        // destructor to delete all nodes of the linked list
        ~MyLinkedList() {
            Node *current = head;
            while (current != NULL) {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }

        // Optional Bonus Task: method to sort the linked list in ascending order
        void sort() {
            bool swapped;
            Node *current;
            do {
                swapped = false;
                current = head;
                while (current->next != NULL) {
                    if (current->data > current->next->data) {
                        int temp = current->data;
                        current->data = current->next->data;
                        current->next->data = temp;
                        swapped = true;
                    }
                    current = current->next;
                }
            } while (swapped);
        }
};

int main() {
    MyLinkedList list;
    list.addFront(5);
    list.addFront(7);
    list.addFront(3);
    list.addFront(9);
    cout << "Linked list: ";
    list.display();
    cout << "Is list empty? " << list.empty() << endl;
    cout << "Frequency of 7: " << list.countElem(7) << endl;
    cout << "Index of 3: " << list.getIndexOf(3) << endl;
    list.removeFront();
    cout << "Linked list after removing first element: ";
    list.display();
    list.loadData("data.txt");
    cout << "Linked list after loading data from file: ";
    list.display();
    list.dumpData("list_data.txt");
    cout << "Linked list after sorting: ";
    list.sort();
    list.display();
    return 0;
}
