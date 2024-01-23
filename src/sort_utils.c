/*
** EPITECH PROJECT, 2023
** Organized
** File description:
** Sort_Utils
*/

#include "../include/my.h"
#include "../libshell/shell.h"

int compare_criteria(const hardware *item1, const hardware *item2, sort_p *p)
{
    int result = 0;

    for (int i = 0; i < p->num_criteria; i++) {
        switch (p->criteria[i]) {
            case SORT_BY_TYPE:
                result = my_strcmp(item1->type, item2->type);
                break;
            case SORT_BY_NAME:
                result = my_strcmp(item1->description, item2->description);
                break;
            case SORT_BY_ID:
                result = item1->id - item2->id;
                break;
        }
        if (result != 0) {
            return p->rev[i] ? -result : result;
        }
    }
    return 0;
}

int is_valid_sort_criterion(const char *arg, sort_criteria *criterion)
{
    if (my_strcmp(arg, "TYPE") == 0) {
        *criterion = SORT_BY_TYPE;
        return 1;
    }
    if (my_strcmp(arg, "NAME") == 0) {
        *criterion = SORT_BY_NAME;
        return 1;
    }
    if (my_strcmp(arg, "ID") == 0) {
        *criterion = SORT_BY_ID;
        return 1;
    }
    return 0;
}

int reverse_arg(const char *arg, int index, sort_p *par, int *invalid_arg)
{
    if (my_strcmp(arg, "-r") == 0) {
        if (index > 0 && par->num_criteria > 0) {
            par->rev[par->num_criteria - 1] = !par->rev[par->num_criteria - 1];
            return 1;
        } else {
            *invalid_arg = 1;
            return 0;
        }
    }
    return 0;
}

int set_argument(const char *arg, int index, sort_p *par, int *invalid_arg)
{
    if (is_valid_sort_criterion(arg, &(par->current_criterion))) {
        par->criteria[par->num_criteria] = par->current_criterion;
        par->num_criteria++;
        return 1;
    } else if (reverse_arg(arg, index, par, invalid_arg)) {
        return 1;
    }
    *invalid_arg = 1;
    return 0;
}

void parse_sort_arguments(char **args, sort_p *par, int *invalid_arg)
{
    int i = 0;

    while (args[i] != NULL && par->num_criteria < 3) {
        if (!set_argument(args[i], i, par, invalid_arg)) {
            return;
        }
        i++;
    }
}
