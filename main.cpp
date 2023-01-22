#include <conio.h>

#include "src/data/list.h"
#include "src/data/vector.h"

using namespace std;

// В самом начале листа не существует по-этому мы устанавливаем указатель нулевым
Node *head = nullptr;

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