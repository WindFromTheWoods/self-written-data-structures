/*
 * Лист - Это структура данных, которая содержит в себе элемент (узел) и указатель на последующий элемент
 * Последний элемент листа указывает на nullptr (Нулевой указатель)
 *
 * Что бы реализовать односвязный список нам необходимо:
 * 1) Выделить под него память.
 * 2) Задать ему значение
 * 3) Сделать так, чтобы он ссылался на предыдущий элемент (или на NULL, если его не было)
 * 4) Перекинуть указатель head на новый узел.
 */

#include <iostream>
#include <conio.h>

using namespace std;

// Узел между обьектами листа
typedef struct Node
{
    int value;
    struct Node *next;
} Node;

// В самом начале листа не существует по-этому мы устанавливаем указатель нулевым
Node *head = nullptr;

/*
 * Обьявляем функцию push, она должна:
 * 1) Выделить память для элемента
 * 2) Добавлять значение в начало листа
 */
void push(Node **head, int dataq);

/*
 * Обьявляем функцию pop, она должна:
 * 1) Удалить указатель на первый элемент
 * 2) Вернуть значение первого элемента
 */
void pop();

// Для реализации функций для роботы с остальными элементами листа мы реализуем еще две вспомогательные функции

/*
 * Реализация функции _getLastNode, которая:
 * 1) Возвращает нам указатель на последний элемент листа
 */
static Node* _getLastNode(Node *head)
{
    if (head == nullptr)       // Проверяем есть ли у нас элементы в листе
        return nullptr;        // Выходим из функции ничего не возвращая
    while (head->next) {    // Перебираем указатели, пока не найдем последний
        head = head->next;  // Переходим по указателям
    }
    return head;            // Возвращаем указатель на последний элемент листа
}

/*
 * Реализация функции _getNthNode, которая:
 * 1) Возвращает нам указатель на N элемент листа
 */
static Node* _getNthNode(Node* head, int n)
{
    if(head == nullptr || n < 0)       // Проверяем есть ли у нас элементы в листе и
        return nullptr;                // Выходим с функции, ничего не возвращая
    int counter = 0;                // Обьявляем счетчик
    while (counter < n && head) {   // Перебираем указатели заданное количество раз
        if(head->next != nullptr)      // Проверям есть ли у нас такое количество элементов
        {
            head = head->next;      // Переходим по указателям
            counter++;              // Инкрементируем счетчик
        }
    }
    return head;                    // Возвращаем указатель на N элемент листа
}

static Node* getLastButOne(Node* head)
{
    if (head == nullptr)
        return nullptr;
    Node* current = head;
    while (current->next && current->next->next) {
        current = current->next;
    }
    return current;
}

/*
 * Обьявляем функцию pushBack, она должна:
 * 1) Выделить память для элемента
 * 2) Добавить значение в конец листа
 */
void pushBack();

/*
 * Обьявляем функцию popBack, она должна:
 * 1) Удалить указатель на последний элемент
 * 2) Вернуть значение последнего элемента
 */
void popBack();

void


// Реализация функции push
void push(Node **head, int data)                     // Так как head изменяется в процессе, указываем указатель на него
{
    Node *tmp = (Node*) malloc(sizeof(Node));   // Выделяем память для элемента и создаем новый узел
    if(tmp == nullptr)                                  // Проверяем была ли выделена память
        exit(-1);                              // Выходим из функции, если у нас не была выделена память
    tmp->value = data;                               // Записываем значение
    tmp->next = *head;                               // Указатель на предыдущий узел
    *head = tmp;                                     // Присваиваем указатель на адрес нового узла
}

// Реализация функции pop
int pop(Node **head)                        // Так как head изменяется в процессе, указываем указатель на него
{
    if (head == nullptr || *head == nullptr)      // Проверяем есть ли у нас элемент в листе
        exit(-1);                     // Выходим из функции, если у нас нету элемента в листе
    int val = (*head)->value;               // Обьявляем пременную и записываем значение которое хранилось в листе
    Node* temp = *head;                     // Локальная переменная, которая хранит адрес первого обьекта
    *head = (*head)->next;                  // Запись адреса первого обьекта
    free(temp);                     // Удалили узел и освободили память
    return val;                             // Вернули значение
}

// Реализация функии pushBack
void pushBack(Node **head, int value)
{
    Node *tmp = (Node*) malloc(sizeof(Node));   // Выделяем память для элемента листа
    if(tmp == nullptr)                                  // Проверяем выделилась ли память
        exit(-1);                              // Выходим из функции
    Node *last = _getLastNode(*head);                // Получаем указатель на последний элемент, при помощи функции реализованой выше
    tmp->value = value;
    tmp->next = nullptr;
    if(last) {
        last->next = tmp;
    } else {
        *head = tmp;
    }
}

// Реализация функии popBack
void popBack(Node **head)
{
    if (!head || !(*head))
        return;
    Node *current = *head;
    if(current->next == nullptr) {
        free(current);
        *head = nullptr;
    } else {
        while(current->next->next != nullptr) {
            current = current->next;
        }
        free(current->next);
        current->next = nullptr;
    }
}

void insert(Node **head, unsigned n, int val) {
    if(head == nullptr || *head == nullptr || n < 0)
        return;
    Node *current = *head;
    Node *tmp = nullptr;
    for (unsigned i = 0; i < n && current->next; i++)
    {
        current = current->next;
    }
    tmp = (Node*) malloc(sizeof(Node));
    if(tmp == nullptr)
        exit(-1);
    tmp->value = val;
    tmp->next = current->next;
    current->next = tmp;
}

int deleteNth(Node **head, int n) {
    if (head == nullptr || *head == nullptr || n < 0)
        return -1;
    if (n == 0)
        return pop(head);
    else
    {
        Node *prev = _getNthNode(*head, n-1);
        if(prev == nullptr || prev->next == nullptr)
            return -1;
        Node *elm  = prev->next;
        int val = elm->value;
        prev->next = elm->next;
        free(elm);
        return val;
    }
}

void deleteList(Node **head) {
    if(head == nullptr || *head == nullptr)
        return;
    Node *current = *head;
    Node *temp;
    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = nullptr;
}

void printLinkedList(const Node *head) {
    if (head == nullptr) {
        printf("List is empty\n");
        return;
    }
    for (const Node *current = head; current != nullptr; current = current->next) {
        printf("%d ", current->value);
    }
    printf("\n");
}

void fromArray(Node **head, int *arr, size_t size) {
    if (head == nullptr || arr == nullptr || size == 0) {
        return;
    }
    for (int i = size - 1; i >= 0; i--) {
        push(head, arr[i]);
    }
}

// Мейн функция
int main() {
    head = nullptr;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    //Создаём список из массива
    fromArray(&head, arr, 10);

    printLinkedList(head);

    //Вставляем узел со значением 333 после 4-го элемента (станет пятым)
    insert(&head, 4, 333);
    printLinkedList(head);

    pushBack(&head, 11);
    pushBack(&head, 12);
    pushBack(&head, 13);
    pushBack(&head, 14);
    printLinkedList(head);

    printf("%d\n", pop(&head));

    printLinkedList(head);
    //Удаляем пятый элемент (индексация с нуля)
    deleteNth(&head, 4);
    printLinkedList(head);
    deleteList(&head);

    getch();
}