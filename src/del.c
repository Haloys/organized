/*
** EPITECH PROJECT, 2023
** Organized
** File description:
** Del
*/

#include "../include/my.h"
#include "../libshell/shell.h"

int is_numeric(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

hardware *find_hardware_item(workshop *ws, int id, hardware **prev)
{
    hardware *current = ws->head;

    *prev = NULL;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        *prev = current;
        current = current->next;
    }
    return NULL;
}

int delete_hardware_item(workshop *ws, int id_to_delete)
{
    hardware *prev;
    hardware *item_to_delete = find_hardware_item(ws, id_to_delete, &prev);

    if (item_to_delete == NULL) {
        return 0;
    }
    if (prev == NULL) {
        ws->head = item_to_delete->next;
    } else {
        prev->next = item_to_delete->next;
    }
    mini_printf("%s n°%d - \"%s\" deleted.\n", item_to_delete->type,
                id_to_delete, item_to_delete->description);
    free(item_to_delete);
    return 1;
}

int del(void *data, char **args)
{
    workshop *ws = (workshop *)data;
    int id_to_delete;
    int found;

    if (args[0] == NULL) {
        return 84;
    }
    for (int i = 0; args[i] != NULL; i++) {
        if (!is_numeric(args[i])) {
            return 84;
        }
        id_to_delete = my_getnbr(args[i]);
        found = delete_hardware_item(ws, id_to_delete);
        if (!found) {
            return 84;
        }
    }
    return 0;
}
