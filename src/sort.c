/*
** EPITECH PROJECT, 2023
** Organized
** File description:
** Sort
*/

#include "../include/my.h"
#include "../libshell/shell.h"
#include "workshop.h"

int sort(void *data, char **args)
{
    workshop *ws = (workshop *)data;
    sort_p params = {{0}, {0, 0, 1}, 0, SORT_BY_TYPE};
    int invalid_arg = 0;

    if (args[0] == NULL) {
        return 84;
    }
    parse_sort_arguments(args, &params, &invalid_arg);
    if (invalid_arg || params.num_criteria == 0) {
        return 84;
    }
    merge_sort_linked_list(&(ws->head), &params);
    return 0;
}
