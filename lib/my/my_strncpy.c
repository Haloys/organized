/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** My_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}
