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
#include <stdbool.h>

/* Generics
    Fournit un moyen de choisir l'une des nombreuses expressions au moment de
    la compilation, en fonction d'un type d'expression de contrôle.
*/

/* Retourne le type de x */
#define typename(x) _Generic((x), \
    _Bool: "_Bool", \
    unsigned char: "unsigned char", \
    char: "char", \
    signed char: "signed char", \
    short int: "short int", \
    unsigned short int: "unsigned short int", \
    int: "int", \
    unsigned int: "unsigned int", \
    long int: "long int", \
    unsigned long int: "unsigned long int", \
    long long int: "long long int", \
    unsigned long long int: "unsigned long long int",\
    float: "float", \
    double: "double", \
    long double: "long double", \
    char *: "char *", \
    void *: "void *", \
    int *: "int *", \
    char **: "char **", \
    default: "other")

#define printf_dec_format(x) _Generic((x), \
    char: "%c\n", \
    signed char: "%hhd\n", \
    unsigned char: "%hhu\n", \
    signed short: "%hd\n", \
    unsigned short: "%hu\n", \
    signed int: "%d\n", \
    unsigned int: "%u\n", \
    long int: "%ld\n", \
    unsigned long int: "%lu\n", \
    long long int: "%lld\n", \
    unsigned long long int: "%llu\n", \
    float: "%f\n", \
    double: "%f\n", \
    long double: "%Lf\n", \
    char *: "%s\n", \
    void *: "%p\n")

/* _Generic determine le type de x et renvoie le flag permettant de print le type en question. */
#define print(x) printf(printf_dec_format(x), x)

/* Cet example de _Generic permet d'executer une fonction en fonction de type
    determiner */

static __always_inline bool compare_cc(char a, char b)
{
    return a == b;
}

static __always_inline int compare_ss(char *a, char *b)
{
    return strcmp(a, b);
}

static __always_inline int compare_pp(void *a, void *b)
{
    return a > b ? a - b : b - a;
}

#define _G2_compare(ParamB,ParamA_Type, TypeB1) \
    ParamA_Type: _Generic((ParamB), \
        char *: compare_ss, \
        char: compare_cc, \
        void *: compare_pp, \
        int: compare_cc)

#define _compare(a, b) _Generic((a), \
    _G2_compare(b,char *,char *), \
    _G2_compare(b,char,char), \
    _G2_compare(b,void *,void *), \
    _G2_compare(b,int,int)) (a,b)

#define compare(a, b) _compare(a, b)