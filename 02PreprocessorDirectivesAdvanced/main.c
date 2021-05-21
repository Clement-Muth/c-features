/*
** EPITECH PROJECT, 2021
** c-features
** File description:
** main
*/

#include "header.h"

int main(void)
{
    char *str = "hello world.";
    object object = {.length = length};

    printf("length of str = %d\n", length(str));
    printf("length of str = %d\n", length(NULL));
    printf("%d\n", object.length(str));
}