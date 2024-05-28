#include <iostream>
#include <string>

struct Department {
    int number;
    std::string name;
    std::string specialization;
    int employeeCount;
    std::string head;
};

struct Node {
    Department data;
    Node* next;
    Node* prev;

    Node(int num, const std::string n, const std::string spec, int empCount, const std::string h)
        : data{ num, n, spec, empCount, h }, next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertOrdered(int number, const std::string name, const std::string specialization, int employeeCount, const std::string headName) {
        Node* newNode = new Node(number, name, specialization, employeeCount, headName);

        if (head == nullptr || head->data.number >= newNode->data.number) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data.number < newNode->data.number) {
            current = current->next;
        }

        newNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Number: " << current->data.number << "\n";
            std::cout << "Name: " << current->data.name << "\n";
            std::cout << "Specialization: " << current->data.specialization << "\n";
            std::cout << "Employee Count: " << current->data.employeeCount << "\n";
            std::cout << "Head: " << current->data.head << "\n";
            std::cout << "-----------------------------\n";
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.insertOrdered(1, "IT Department", "Software Development", 50, "John Doe");
    list.insertOrdered(3, "HR Department", "Human Resources", 20, "Jane Smith");
    list.insertOrdered(2, "Finance Department", "Accounting", 30, "Mike Johnson");

    std::cout << "List of Departments:\n";
    list.display();

    return 0;
}
