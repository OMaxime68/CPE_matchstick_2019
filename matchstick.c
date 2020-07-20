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

int on_helped_game(char *str, game_t *game, int mmax)
{
    my_putstr("Matches: ");
    if (getline(&game->nb_matches_char, &game->len2, stdin) == -1)
        return (0);
    game->nb_matches = my_getnbr(game->nb_matches_char);
    if (print_updated_board_game(game, str, mmax, 1) != 1)
        game->a = 1;
    else
        game->i = 1;
    return (1);
}

int in_helped_game(char *str, game_t *game, int mmax)
{
    if (help_game(str, game) == 0)
        return (0);
    if (game->m == 0) {
        if (on_helped_game(str, game, mmax) == 0)
            return (0);
    }
    return (1);
}

int helped_game(char *str, game_t *game, int mmax)
{
    game->m = 0;
    game->k = 0;
    if (game->a == 0) {
        if (in_helped_game(str, game, mmax) == 0)
            return (0);
    } else {
            my_putstr("\nAI's turn...\n");
            game->line = ia_line(str);
            game->nb_matches = 1;
            print_updated_board_game(game, str, mmax, 2);
            game->a = 0;
            game->i = 0;
        }
    return (1);
}

int game(int argc, char **argv, char *str, int mmax)
{
    game_t game;

    game.a = 0;
    game.i = 0;
    game.m = 0;
    game.k = 0;
    game.len = 0;
    game.len2 = 0;
    while (check_c(str, '|') != 0) {
        if (helped_game(str, &game, mmax) == 0)
            return (0);
    }
    if (game.a == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    } else {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
}

int main(int argc, char **argv)
{
    int line;
    int matches_max;
    char *str;

    if (argc != 3)
        return (84);
    else if (my_getnbr(argv[1]) > 100)
        return (84);
    line = my_getnbr(argv[1]);
    matches_max = my_getnbr(argv[2]);
    str = malloc(sizeof(char*) * (line * (line - 1) + 2));
    str = print_game_board(my_getnbr(argv[1]), str);
    return (game(argc, argv, str, matches_max));
}