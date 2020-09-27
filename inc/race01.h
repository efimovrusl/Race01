#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_values {
    int size;
    int *arr;
} t_values;

typedef struct s_list {
    char *str;
    struct s_list *next;
    struct s_list *prev;
} t_list;

t_list *mx_new_node(char *str);
void mx_add_node(t_list *current, char *str);
void mx_remove_node(t_list *current);
void mx_show_all_nodes(t_list *any_node);
void mx_sort_list(t_list *left, t_list *right);
t_list *mx_first_node(t_list *any);
t_list *mx_last_node(t_list *any);
char *mx_strjoin(char const *s1, char const *s2);
bool mx_isspace(char);
bool mx_isdigit(char);
char *mx_strcpy(char*, const char*);
int mx_strcmp(const char *, const char *);
int mx_atoi(const char*);
int mx_strlen(const char*);
void mx_printstr(const char*);
void mx_printchar(char);
void mx_printint(int);
char *mx_strdup(const char *str);
char *mx_strnew(const int size);
bool mx_noormal_num(char *s);
char *mx_strcat(char *s1, const char *s2);
int mx_int_pow(int num, int pow);
int mx_sign_digit(int num);
t_values *mx_get_possible_values(char *number);
void mx_int_bubble_sort(int *arr, int size);
t_list *mx_get_results(t_values *arg1, t_values *arg2, t_values *arg3, char op);
char *mx_itoa(int n);
char *mx_strtrim(const char *str);
int mx_shitcmp(const char *str1, const char *str2);
