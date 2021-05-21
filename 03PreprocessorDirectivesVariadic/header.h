/*
** EPITECH PROJECT, 2021
** c-features
** File description:
** header
*/

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

/* Les macro variadique
    Il existe ce qu'on nomme communénemnt des listes variadique utilisable avec des macros.
    L'identificateur de remplacement __VA_ARGS__ peut être utilisé dans la définition
    pour insérer les arguments supplémentaires. __VA_ARGS__ est remplacé par tous les
    arguments qui correspondent aux points de suspension, y compris les virgules entre eux.
*/

/* This macro will count the number of element in the list */
#define _N__ARG(...) _N__ARGS(, ##__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)
#define _N__ARGS(z, a, b, c, d, e, f, cnt, ...) cnt

/* ## avec __VA_ARGS__ est une syntaxe non portable introduite par gcc pour traiter spécifiquement
    ce cas critique de ne passer aucun argument. Sans le ##, il se plaindrait que la
    virgule de fin soit une erreur de syntaxe.
*/
#define my_free(ptr, ...) my_free(ptr, _N__ARG(__VA_ARGS__), ##__VA_ARGS__)

/* my_free itere sur la liste et free chaque element
    Une fonction inline sera remplacée lors de la compilation. Elle est tout aussi
    opti et rapide qu'une macro.
    Ici on retrouve aussi _args_count qui est implicite.
*/
static inline void (my_free)(void *_ptr, int _args_count, ...)
{
    va_list ptr_list;

    free(_ptr);
    for (va_start(ptr_list, _args_count); _args_count; --_args_count)
        free(va_arg(ptr_list, void *));
}