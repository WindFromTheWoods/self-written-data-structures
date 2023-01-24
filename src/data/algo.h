#ifndef LIST_ALGO_H
#define LIST_ALGO_H

#include "list.h"
#include "vector.h"

class algo
{

private:

    struct Node
    {
        int value;
        Node* next;
    };
    Node* head;

public:

    void push(int data)
    {
        Node *tmp = (Node*) malloc(sizeof(Node));
        if(tmp == nullptr)
            exit(-1);
        tmp->value = data;
        tmp->next = head;
        head = tmp;
    }

    int pop()
    {
        if (head == nullptr)
            exit(-1);
        int val = head->value;
        Node* temp = head;
        head = head->next;
        free(temp);
        return val;
    }

    void pushBack(int value)
    {
        Node *tmp = (Node*) malloc(sizeof(Node));
        if(tmp == nullptr)
            exit(-1);
        tmp->value = value;
        tmp->next = nullptr;
        if (head == nullptr)
            head = tmp;
        else
        {
            Node *current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = tmp;
        }
    }

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
};
#endif //LIST_ALGO_H
