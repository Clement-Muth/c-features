/*
** EPITECH PROJECT, 2021
** c-features
** File description:
** header
*/

#pragma once

/* Le preprocesseur
    C'est la première phase de la compilation.

    On y retrouve différentes directives prefixé par '#':
        - #include - Incorporation de fichiers source.
        - #define - Définition de constantes symboliques et de macros.
        - #if/#ifdef - Compilation conditionnelle.
*/

/* Incorporation du header stdio.h

    Lors de la phase du préprocesseur, toutes les directives sont remplacées
    par leurs valeurs textuelle

    "#include <stdio.h>" sera donc remplacé par son contenu
    De ce fait, prenez conscience de l'importance de la logique d'inclusion d'un header.

    L'inclusion de header inutile dans un fichier ne fera que surchager ce dernier.

    Pour visualiser ce qui suit, vous pouvez utiliser `gcc [file].c -E`
*/
#include <stdlib.h> /* Pour la fonction exit */
#include <stdio.h> /* Pour la fonction printf */

/* Constantes symboliques
    Elle demande a votre compilateur de substituer toutes ses occurences par la valeur qui lui est assignée.

    Elle est utiliser pour déclarer des constantes dans le but de lui apporté un nom explicite
    et facile a comprendre lors de la lecture

    Elle rend également plus facile la modification d'une valeur ayant plusieurs occurences dans votre code.
*/
#define MAX_CLIENT 10

/* Macros
    Une macro est une define ayant des paramètres.

    Son but initial est le même que la constante symbolique.
    Toutefois, la valeur d'une macro sera plus de l'ordre d'une fonction, d'un block de code, que d'une constante

    #define prints(message) printf("%s\n", message)

    Gardez a l'ésprit qu'une macro n'est qu'une substitution lors de la compilation.
    De ce fait, il est plus optimiser de créer un macro afin de réaliser un calcul ou une fonction
    simple que de créer une fonction à part entière et d'avoir des coûts d'appels.
    Un appel de function correspond a un saut conditionnelle d'une zone a une autre.

    Aussi, prenez garde au parenthèses dans votre macro, son comportement pourrait ne pas être
    celui que vous pensez.
*/
#define max(a, b) (a > b ? a : b)

/* Compilation conditionnelle
    Incorporer/exclure des parties de code sources créer lors de la compilation
*/

#define PROCESSEUR ALPHA

// static int taille_long = 0;

#if PROCESSEUR == ALPHA
    int taille_long = 64;
#elif PROCESSEUR == PC
    int taille_long = 32;
#endif

/* Condition liée a une expression
    Si lors de la compilaton vous spécifiez le flag -DDEBUG, le compilateur prendra en compte
    la partie du if, et affichera une erreur destiner aux développeurs.
    Autrement il générera le code du else.
*/
static inline int error(void)
{
    #if DEBUG
        printf("%s %s:%d %s\n", __FILE__, __func__, __LINE__, "invalid read.");
        exit(84);
    #else
        printf("An error occured.\n");
        return -1;
    #endif
}