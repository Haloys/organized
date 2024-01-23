/*
** EPITECH PROJECT, 2023
** Organized
** File description:
** Disp
*/

#include "../include/my.h"
#include "../libshell/shell.h"

int disp(void *data, char **args)
{
    workshop *ws = (workshop *)data;
    hardware *current = ws->head;

    if (args[0] != NULL) {
        return 84;
    }
    while (current != NULL) {
        mini_printf("%s n°%d - \"%s\"\n",
                    current->type, current->id, current->description);
        current = current->next;
    }
    return 0;
}
