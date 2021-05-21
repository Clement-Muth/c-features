/*
** EPITECH PROJECT, 2021
** c-features
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Example d'utilisation d'un block code.
    Nous verrons des cas d'utilisation concrète et utilse dans le 05Lambda.
*/

int main(void)
{
    char *str = ({
        str = strdup("hello");
        if(NULL == str) exit(84);
        str;
    });
    printf("%s\n", str);
    free(str);
}