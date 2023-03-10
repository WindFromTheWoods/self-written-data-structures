#include "list.h"
// Для реализации функций для роботы с остальными элементами листа мы реализуем еще три вспомогательные функции

/*
 * Реализация функции _getLastNode, которая:
 * 1) Возвращает нам указатель на последний элемент листа
 */
static Node* _getLastNode(Node *head)
{
    if (head == nullptr)       // Проверяем есть ли у нас элементы в листе
        return nullptr;        // Выходим из функции ничего не возвращая
    while (head->next) {       // Перебираем указатели, пока не найдем последний
        head = head->next;     // Переходим по указателям
    }
    return head;               // Возвращаем указатель на последний элемент листа
}

/*
 * Реализация функции _getNthNode, которая:
 * 1) Возвращает нам указатель на N элемент листа
 */
static Node* _getNthNode(Node* head, int n)
{
    if(head == nullptr || n < 0)       // Проверяем есть ли у нас элементы в листе и
        return nullptr;                // Выходим с функции, ничего не возвращая
    int counter = 0;                   // Обьявляем счетчик
    while (counter < n && head) {      // Перебираем указатели заданное количество раз
        if(head->next != nullptr)      // Проверям есть ли у нас такое количество элементов
        {
            head = head->next;         // Переходим по указателям
            counter++;                 // Инкрементируем счетчик
        }
    }
    return head;                       // Возвращаем указатель на N элемент листа
}

/*
 * Реализация функции _getLastButOne, которая
 * 1) Возвращает указатель на предпоследний элемент
 */
static Node* _getLastButOne(Node* head)
{
    if (head == nullptr)
        return nullptr;
    Node* current = head;
    while (current->next && current->next->next) {
        current = current->next;
    }
    return current;
}

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
int pop(Node **head)                              // Так как head изменяется в процессе, указываем указатель на него
{
    if (head == nullptr || *head == nullptr)      // Проверяем есть ли у нас элемент в листе
        exit(-1);                           // Выходим из функции, если у нас нету элемента в листе
    int val = (*head)->value;                     // Обьявляем пременную и записываем значение которое хранилось в листе
    Node* temp = *head;                           // Локальная переменная, которая хранит адрес первого обьекта
    *head = (*head)->next;                        // Запись адреса первого обьекта
    free(temp);                           // Удалили узел и освободили память
    return val;                                   // Вернули значение
}

// Реализация функии pushBack
void pushBack(Node **head, int value)
{
    Node *tmp = (Node*) malloc(sizeof(Node));   // Выделяем память для элемента листа
    if(tmp == nullptr)                               // Проверяем выделилась ли память
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
