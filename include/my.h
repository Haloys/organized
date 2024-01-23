/*
** EPITECH PROJECT, 2023
** Main Header
** File description:
** Lib principale
*/

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../src/workshop.h"

#ifndef MY_H_
    #define MY_H_

void my_long_to_string(long num, char *str);
int mini_printf(const char *format, ...);
int my_putchar(char c);
int my_put_nbr(int number_put);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strcat(char *dest, char const *src);
int my_strcmp(const char *str1, const char *str2);
int my_getnbr(char const *str);
void reverse_string(char *str);

#endif
