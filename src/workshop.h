/*
** EPITECH PROJECT, 2023
** Struct
** File description:
** Workshop
*/

#ifndef WORKSHOP_H
    #define WORKSHOP_H

typedef struct hardware {
    int id;
    char *type;
    char *description;
    struct hardware *next;
} hardware;

typedef enum {
    SORT_BY_TYPE,
    SORT_BY_NAME,
    SORT_BY_ID
} sort_criteria;

typedef struct {
    sort_criteria criteria[3];
    int rev[3];
    int num_criteria;
    sort_criteria current_criterion;
} sort_p;

typedef struct {
    hardware *head;
    int next_id;
    int max_name_length;
} workshop;

void merge_sort_linked_list(hardware **head_ref, sort_p *params);
int contains_lowercase(const char *str);
int is_valid_type(const char *type);
int validate_arg_count(char **args);
int validate_types(char **args);
int validate_args(char **args);
void parse_sort_arguments(char **args, sort_p *par, int *invalid_arg);
int compare_criteria(const hardware *item1, const hardware *item2, sort_p *p);

#endif /* WORKSHOP_H */
