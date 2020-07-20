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

int read_player(char *str, int line, int nb, int j)
{
    int nb_l = count_match_line(j, str);
    int larg = count_larg_line(str);
    int i = 0;
    int k = 0;

    if (line > larg || line < 1) {
        my_putstr("Error: this line is out of range\n");
        i = 1;
        k = 1;
    } else if (nb < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        i = 1;
        k = 1;
    }
    if (nb > nb_l && k == 0) {
        my_putstr("Error: not enough matches on this line\n");
        i = 1;
    }
    return (i);
}

int read_ai(char *str, int line, int nb, int j)
{
    int nb_l = count_match_line(j, str);
    int larg = count_larg_line(str);
    int i = 0;

    if (line > larg || line < 1)
        i = 1;
    else if (nb < 1 || nb > nb_l)
        i = 1;
    return (i);
}

int strline(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}

int ia_line(char *str)
{
    int line = 1;
    int a = strline(str);
    int j = (line + 1) * a + (line -1);
    int nb_l = count_match_line(j, str);

    for (int f = 0; f != 1;) {
        if (read_ai(str, line, 1, j) == 1) {
            line++;
            j = (line + 1) * a + (line -1);
            nb_l = count_match_line(j, str);
        } else
            f++;
    }
    return (line);
}

int check_line_error(int line, char *str, char *line_char)
{
    int larg = count_larg_line(str);
    int i = 0;

    if (line > larg || line < 1) {
        my_putstr("Error: this line is out of range\n");
        i = 1;
    }
    return (i);
}