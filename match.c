/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick
*/

#include "./include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int check_c(char *str, char c)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            a++;
    }
    return (a);
}

int count_match_line(int j, char *str)
{
    int a = 0;

    for (; str[j] != '\n'; j--) {
        if (str[j] == '|')
            a++;
    }
    return (a);
}

int count_larg_line(char *str)
{
    int a = 1;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            a++;
    }
    a -= 2;
    return (a);
}

int help_game_board(char *str, int *i, int *k, int *line)
{
    str[*i] = '*';
    *i = *i + 1;
    for (; *k < *line * 2 - 1; *k = *k + 1) {
        str[*i] = ' ';
        *i = *i + 1;
    }
    *k = 0;
    str[*i] = '*';
    str[*i + 1] = '\n';
    *i = *i + 2;
}

char *print_game_board(int line, char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int mod = line % 2;
    int m = 0;

    for (; i < line * 2 + 1; i++)
        str[i] = '*';
    str[i] = '\n';
    i++;
    for (; j < line; j++) {
        help_game_board(str, &i, &k, &line);
    }
    k = i;
    for (; i < k + line * 2 + 1; i++)
        str[i] = '*';
    return (print_final_board(str, line, m));
}