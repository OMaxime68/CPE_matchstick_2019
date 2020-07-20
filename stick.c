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

int on_final_board(char *str, int *i, int middle)
{
    for (; str[*i] != '\n'; *i = *i + 1) {
    }
    *i = *i + 1;
    str[*i + middle] = '|';
    for (; str[*i] != '\n'; *i = *i + 1) {
    }
    *i = *i + 1;
}

char *print_final_board(char *str, int line, int i)
{
    int k = 0;
    int m = 1;
    int g = 0;
    int temp;
    int middle = (line * 2 + 1) / 2;

    on_final_board(str, &i, middle);
    for (; k < line - 1; k++) {
        temp = m;
        for (; -2 + g < m; m--) {
            str[i + middle + m] = '|';
        }
        for (; str[i] != '\n'; i++)
        m = temp + 1;
        i++;
        g--;
    }
    my_putstr(str);
    my_putchar('\n');
    return (str);
}

void print_sentence(int line, int nb_matches, char *str, int nbr)
{
    if (nbr == 2)
        my_putstr("AI removed ");
    else
        my_putstr("Player removed ");
    my_put_nbr(nb_matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    my_putstr(str);
    my_putchar('\n');
}

int help_up_board(int *j, char *str, int *line)
{
    for (int i = 0; i < (*line + 1); i++) {
        while (str[*j] != '\n') {
            *j = *j + 1;
        }
        *j = *j + 1;
    }
    *j = *j - 2;
}

int print_board_up(int nb_matches, int mmax)
{
    if (nb_matches > mmax) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(mmax);
        my_putstr(" matches per turn\n");
        return (1);
    }
    return (0);
}