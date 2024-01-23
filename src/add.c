/*
** EPITECH PROJECT, 2023
** Organized
** File description:
** Add
*/

#include "../include/my.h"
#include "../libshell/shell.h"
#include "workshop.h"

int contains_lowercase(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

hardware *cre_item(int id, const char *type, const char *descrip, int length)
{
    hardware *new_item = (hardware *)malloc(sizeof(hardware));

    if (new_item == NULL) {
        return NULL;
    }
    new_item->id = id;
    new_item->type = (char *)malloc(length * sizeof(char));
    new_item->description = (char *)malloc(length * sizeof(char));
    if (!new_item->type || !new_item->description) {
        free(new_item->type);
        free(new_item->description);
        free(new_item);
        return NULL;
    }
    my_strncpy(new_item->type, type, length);
    my_strncpy(new_item->description, descrip, length);
    new_item->next = NULL;
    return new_item;
}

int add_hardware_item(workshop *ws, const char *type, const char *description)
{
    int id;
    hardware *new_item;

    id = ws->next_id;
    ws->next_id++;
    new_item = cre_item(id, type, description, ws->max_name_length);
    if (new_item == NULL) {
        return 1;
    }
    new_item->next = ws->head;
    ws->head = new_item;
    mini_printf("%s n°%d - \"%s\" added.\n", new_item->type, new_item->id,
    new_item->description);
    return 0;
}

int add(void *data, char **args)
{
    workshop *ws = (workshop *)data;
    int result = validate_args(args);

    if (result != 0) {
        return result;
    }
    for (int i = 0; args[i] != NULL && args[i + 1] != NULL; i += 2) {
        result = add_hardware_item(ws, args[i], args[i + 1]);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}
