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
    char str[] = "ye";
    char str2[] = "yo";

    print((int)compare(str, str2));
    print(typename(str));
}