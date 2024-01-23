/*
** EPITECH PROJECT, 2023
** Organized
** File description:
** Main
*/

#include "../include/my.h"
#include "../libshell/shell.h"

int main(void)
{
    workshop ws = { .head = NULL, .next_id = 0, .max_name_length = 500 };

    return workshop_shell(&ws);
}
