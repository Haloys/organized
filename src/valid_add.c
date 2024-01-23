/*
** EPITECH PROJECT, 2023
** Organized
** File description:
** Valid_Add
*/

#include "../include/my.h"
#include "../libshell/shell.h"

int is_valid_type(const char *type)
{
    const char *valid_types[] = {"ACTUATOR", "DEVICE",
    "PROCESSOR", "SENSOR", "WIRE"};
    int num_valid_types = sizeof(valid_types) / sizeof(valid_types[0]);

    for (int i = 0; i < num_valid_types; i++) {
        if (my_strcmp(type, valid_types[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int validate_arg_count(char **args)
{
    int arg_count;

    for (arg_count = 0; args[arg_count] != NULL; arg_count++);
    if (args[0] == NULL || arg_count % 2 != 0) {
        return 84;
    }
    return 0;
}

int validate_types(char **args)
{
    for (int i = 0; args[i] != NULL; i += 2) {
        if (contains_lowercase(args[i]) || !is_valid_type(args[i])) {
            return 84;
        }
    }
    return 0;
}

int validate_args(char **args)
{
    int result;

    result = validate_arg_count(args);
    if (result != 0) {
        return result;
    }
    return validate_types(args);
}
