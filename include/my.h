/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** pour include tout
*/

#ifndef MY_H_

typedef struct games
{
    int line;
    int nb_matches;
    int a;
    int i;
    char *line_char;
    char *nb_matches_char;
    int m;
    int k;
    long unsigned int len;
    long unsigned int len2;

} game_t;

#define MY_H_

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(int const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *str);
int print_updated_board_game(game_t *game, char *str, int mmax, int nbr);
int read_player(char *str, int line, int nb, int j);
char *print_final_board(char *str, int line, int i);
int strline(char *str);
int count_match_line(int j, char *str);
int check_c(char *str, char c);
char *print_game_board(int line, char *str);
int count_larg_line(char *str);
int ia_line(char *str);
int check_line_error(int line, char *str, char *line_char);
int help_game(char *str, game_t *game);
int help_up_board(int *j, char *str, int *line);
int print_board_up(int nb_matches, int mmax);
void print_sentence(int line, int nb_matches, char *str, int nbr);

#endif