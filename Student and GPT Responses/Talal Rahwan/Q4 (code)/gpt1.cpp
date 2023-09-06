#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class MyLinkedList
{
    private:
        struct Node
        {
            int data;
            Node* next;

            Node(int d) : data(d), next(nullptr) {}
        };

        Node* head;
        int size;

    public:
        MyLinkedList() : head(nullptr), size(0) {}

        bool empty() const
        {
            return head == nullptr;
        }

        void addFront(int elem)
        {
            Node* newNode = new Node(elem);
            newNode->next = head;
            head = newNode;
            size++;
        }

        void removeFront()
        {
            if (empty())
            {
                cout << "Error: List is already empty." << endl;
                return;
            }

            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }

        int countElem(int elem)
        {
            int count = 0;
            Node* current = head;
            while (current != nullptr)
            {
                if (current->data == elem)
                {
                    count++;
                }
                current = current->next;
            }
            return count;
        }

        int getIndexOf(int elem)
        {
            int index = 0;
            Node* current = head;
            while (current != nullptr)
            {
                if (current->data == elem)
                {
                    return index;
                }
                current = current->next;
                index++;
            }
            return -1;
        }

        void display()
        {
            Node* current = head;
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void loadData(string file)
        {
            ifstream inFile(file);
            int elem;
            while (inFile >> elem)
            {
                addFront(elem);
            }
            inFile.close();
        }

        void dumpData(string file) const
        {
            ofstream outFile(file);
            Node* current = head;
            while (current != nullptr)
            {
                outFile << current->data << endl;
                current = current->next;
            }
            outFile.close();
        }

        ~MyLinkedList()
        {
            while (!empty())
            {
                removeFront();
            }
        }

        // Optional Bonus Task
        void sort()
        {
            bool swapped;
            Node* current;
            Node* last = nullptr;
            do
            {
                swapped = false;
                current = head;
                while (current->next != last)
                {
                    if (current->data > current->next->data)
                    {
                        swap(current->data, current->next->data);
                        swapped = true;
                    }
                    current = current->next;
                }
                last = current;
            } while (swapped);
        }
    };

int main()
    {
    MyLinkedList list;
    list.addFront(5);
    list.addFront(10);
    list.addFront(2);
    list.addFront(7);
    list.addFront(1);

    cout << "Original List: ";
    list.display();

    cout << "Is the list empty? " << (list.empty() ? "yes" : "no") << endl;
    cout << "Frequency of element 2: " << list.countElem(2) << endl;
    cout << "First index of element 10: " << list.getIndexOf(10) << endl;

    list.removeFront();
    cout << "List after removing front element: ";
    list.display();

    list.sort();
    cout << "List after sorting: ";
    list.display();

    list.loadData("data.txt");
    cout << "List after loading data from file: ";
    list.display();

    list.dumpData("out.txt");
    cout << "Data dumped to out.txt" << endl;

    return 0;
}
