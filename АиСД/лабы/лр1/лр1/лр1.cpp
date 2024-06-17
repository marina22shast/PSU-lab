#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Функция для создания нового узла списка
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Функция для добавления нового узла в конец списка
void addNode(Node** head, Node* newNode) {
    if (*head == nullptr) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Функция для печати списка
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Функция для смещения элементов списка по кольцу на заданное число позиций
void rotateList(Node** head, int k) {
    if (*head == nullptr || k == 0) {
        return;
    }

    Node* current = *head;
    int count = 1;
    while (count < k && current != nullptr) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        return;
    }

    Node* kthNode = current;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = *head;
    (*head)->prev = current;

    *head = kthNode->next;
    (*head)->prev = nullptr;

    kthNode->next = nullptr;
}

// Функция для удаления списка
void deleteList(Node** head) {
    Node* current = *head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    *head = nullptr;
}

int main() {
    Node* head = nullptr;

    // Создание списка с числами от -50 до +50
    for (int i = -50; i <= 50; i++) {
        Node* newNode = createNode(i);
        addNode(&head, newNode);
    }

    std::cout << "Original list: ";
    printList(head);

    int k;
    std::cout << "Enter the number of positions to offset: ";
    std::cin >> k;

    // Смещение элементов списка по кольцу
    rotateList(&head, k);

    std::cout << "List after offset: ";
    printList(head);

    // Удаление списка
    deleteList(&head);

    return 0;
}