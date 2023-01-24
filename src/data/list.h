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

// Self implementation of
// the Linked List Class in C++

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include "algo.h"
#include <iostream>

// Узел между обьектами листа
template <typename T> class linkedList
{
private:
    struct Node
    {
        int value;
        Node *next;
    };
    Node *head;
public:
    linkedList(){head = nullptr;} // Конструктор класса
    ~linkedList(){delete(&head);} // Деконструктор класса

/*
 * Обьявляем функцию fromArrayToList, она должна:
 * 1) Создать лист из элементов массива
 */
    void fromArrayToList(Node **head, int *arr, size_t size)
    {
        if (head == nullptr || arr == nullptr || size == 0) {
            return;
        }
        for (int i = size - 1; i >= 0; i--) {
            push(head, arr[i]);
        }
    }

/*
 * Обьявляем функцию fromArrayToList, она должна:
 * 1) Возвращает нам указатель на N элемент листа
 */
    Node* getNthNode(Node* head, int n)
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
 * Обьявляем функцию getLastButOne, она должна:
 * 1) Возвращает указатель на предпоследний элемент
 */
    Node* getLastButOne(Node* head)
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
 * Обьявляем функцию getLastNode, она должна:
 * 1) Возвращает нам указатель на последний элемент листа
 */
    Node* getLastNode(Node *head)
    {
        if (head == nullptr)       // Проверяем есть ли у нас элементы в листе
            return nullptr;        // Выходим из функции ничего не возвращая
        while (head->next) {       // Перебираем указатели, пока не найдем последний
            head = head->next;     // Переходим по указателям
        }
        return head;               // Возвращаем указатель на последний элемент листа
    }
};

#endif //LIST_LIST_H
