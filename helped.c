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

int check_char_error(char *str)
{
    int i = 0;

    while (str[i] <= '9' && str[i] >= '0')
        i++;
    if (i + 1 == my_strlen(str))
        return (0);
    my_putstr("Error: invalid input (positive number expected)\n");
    return (1);
}

int help_game(char *str, game_t *game)
{
    if (game->i == 0)
        my_putstr("\nYour turn:\n");
    my_putstr("Line: ");
    if (getline(&game->line_char, &game->len, stdin) == -1)
        return (0);
    if (check_char_error(game->line_char) == 1) {
        game->m = 1;
        game->i = 1;
        game->k = 1;
    }
    game->line = my_getnbr(game->line_char);
    if (game->k == 0) {
        if (check_line_error(game->line, str, game->line_char) == 1) {
            game->m = 1;
            game->i = 1;
        }
    }
    return (1);
}

int print_updated_board_game(game_t *game, char *str, int mmax, int nbr)
{
    int j = 0;
    int i = 0;

    help_up_board(&j, str, &game->line);
    if (print_board_up(game->nb_matches, mmax) == 1)
        return (1);
    if (read_player(str, game->line, game->nb_matches, j) == 1)
        return (1);
    i = 0;
    for (; str[j] != '|'; j--) {
    }
    for (; i < game->nb_matches; i++) {
        str[j] = ' ';
        j--;
    }
    print_sentence(game->line, game->nb_matches, str, nbr);
    return (0);
}