/*
** EPITECH PROJECT, 2021
** c-features
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

int main(int ac, char **av)
{
    int a = 0;
    int b = 5;

    somthing(a, b, {
        a += 3;
        b -= 1;
        printf("%d - %d\n", a, b);
    });
}