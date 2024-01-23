/*
** EPITECH PROJECT, 2023
** Merge_Sort
** File description:
** Merge_Sort
*/

#include "../include/my.h"
#include "../libshell/shell.h"
#include "workshop.h"

void split_list(hardware *source, hardware **front, hardware **back)
{
    hardware *fast;
    hardware *slow;

    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

hardware *sorted_merge(hardware *a, hardware *b, sort_p *params)
{
    hardware *result = NULL;

    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }
    if (compare_criteria(a, b, params) <= 0) {
        result = a;
        result->next = sorted_merge(a->next, b, params);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next, params);
    }
    return result;
}

void merge_sort_linked_list(hardware **head_ref, sort_p *params)
{
    hardware *head = *head_ref;
    hardware *a;
    hardware *b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    split_list(head, &a, &b);
    merge_sort_linked_list(&a, params);
    merge_sort_linked_list(&b, params);
    *head_ref = sorted_merge(a, b, params);
}
