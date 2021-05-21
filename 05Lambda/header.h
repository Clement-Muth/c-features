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

/* Les lambda
    Les lambda sont une notion vraiment utile.
    Elle vont nous permettre de créer des fonctions sur messure en fonction de
    paramètres donnés par le developpeur.

    Ici _LAMBDA prends le type de retour de la fonction.
    function_body correspond au code devant être dans la dite fonction.
    wrapper function_body permet de créer le prototype de la fonction souhaitée.
*/
#define _LAMBDA(return_type, function_body) \
    ({ return_type __fn__ function_body __fn__; })

#define somthing(l, v, body) ({ \
    int (*lambda)(int, int) = _LAMBDA(int, (int x, int y) body); \
    lambda(l, v); \
})
