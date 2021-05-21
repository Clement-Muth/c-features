/*
** EPITECH PROJECT, 2021
** c-features
** File description:
** main
*/

#include "header.h"

int main(void)
{
    char *str = strdup("hello world.");
    char *ptr1 = strdup("ptr1.");
    char *ptr2 = strdup("ptr2.");

    my_free(str, ptr1, ptr2);
}