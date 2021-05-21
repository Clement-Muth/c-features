/*
** EPITECH PROJECT, 2021
** c-features
** File description:
** header
*/

#pragma once

#include <stdio.h>
#include <string.h>

/* Stoper l'extansion d'une fonction et la remplacer par une macro
    Une utilisation très intéressante des macros est la combinaison de cette dernière
    avec une fonction du même nom.

    Stoper l'extansion d'une fonction et la remplacer par une macro peut vous
    permettre de rentre des arguments implicites.
*/

#define print_error(message, func, file, line) printf("%s %s:%d %s\n", file, func, line, message)

/* Length est la macro que vous allez appeler. Elle prend en paramètre une string
    la macro length va appeler la fonction length, entourée de parenthèses afin de
    stoper son expansion. Ainsi lorsque vous appelerez length, la macro sera executée,
    ainsi que la fonction qui y est associée en lui envoyant implicitement func, file et line.
*/
#define length(string) length(string, __func__, __FILE__, __LINE__)

static int (length)(char const *restrict _string, char const *_func, char *_file, int _line)
{
    if (NULL == _string) {
        print_error("_string variable is empty.", _func, _file, _line);
        return -1;
    }
    return strlen(_string);
}

/* Utilisation avec une structure object */

typedef struct object object;
struct object
{
    int (*length)(char const *restrict _string, char const *_func, char *_file, int _line);
};
