#include <iostream>
#include <fstream>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int elem;
        Node* next;
    };
    Node* head;
    Node* tail;

public:
    MyLinkedList() : head(nullptr), tail(nullptr) {}
    ~MyLinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    void addFront(int elem) {
        Node* newNode = new Node();
        newNode->elem = elem;
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void removeFront() {
        if (empty()) {
            cout << "Error: List is already empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    int countElem(int elem) {
        int count = 0;
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->elem == elem) {
                count++;
            }
            curr = curr->next;
        }
        return count;
    }

    int getIndexOf(int elem) {
        int index = 0;
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->elem == elem) {
                return index;
            }
            curr = curr->next;
            index++;
        }
        return -1;
    }

    void display() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->elem << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void loadData(string file) {
        ifstream input(file);
        int elem;
        while (input >> elem) {
            addFront(elem);
        }
        input.close();
    }

    void dumpData(string file) const {
        ofstream output(file);
        Node* curr = head;
        while (curr != nullptr) {
            output << curr->elem << endl;
            curr = curr->next;
        }
        output.close();
    }

    // Optional Bonus Task:
    void sort() {
        bool swapped;
        Node* curr;
        Node* last = nullptr;
        do {
            swapped = false;
            curr = head;
            while (curr->next != last) {
                if (curr->elem > curr->next->elem) {
                    int temp = curr->elem;
                    curr->elem = curr->next->elem;
                    curr->next->elem = temp;
                    swapped = true;
                }
                curr = curr->next;
            }
            last = curr;
        } while (swapped);
    }

int main() {
    MyLinkedList list;

    // Add elements to the list
    list.addFront(5);
    list.addFront(2);
    list.addFront(7);
    list.addFront(4);

    // Display the list
    cout << "Original list: ";
    list.display();

    // Remove the first element
    list.removeFront();
    cout << "List after removing the first element: ";
    list.display();

    // Count the frequency of a specific element
    int elem = 4;
    int count = list.countElem(elem);
    cout << "Frequency of element " << elem << ": " << count << endl;

    // Get the first index of a specific element
    elem = 2;
    int index = list.getIndexOf(elem);
    cout << "First index of element " << elem << ": " << index << endl;

    // Load data from a file
    string file = "data.txt";
    list.loadData(file);
    cout << "List after loading data from file: ";
    list.display();

    // Dump data to a file
    file = "output.txt";
    list.dumpData(file);

    //Optional Bonus Task
    list.sort();
    cout << "Sorted list: ";
    list.display();

    return 0;
}
