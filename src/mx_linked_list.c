#include "../inc/race01.h"

t_list *mx_new_node(char *str) {
    t_list *new = (t_list *)malloc(32);
    new->str = mx_strdup(str);
    new->next = NULL;
    new->prev = NULL;
    return new;
}
void mx_add_node(t_list *curr, char *str) {
    if (curr == NULL) {
        curr = mx_new_node(str);
    } else {
        while (curr->next) curr = curr->next;
        curr->next = mx_new_node(str);
        curr->next->prev = curr;
    }
}
void mx_remove_node(t_list *curr) {
    if (curr->prev && curr->next) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    } else if (curr->prev) {
        curr->prev->next = NULL;
    } else if (curr->next) {
        curr->next->prev = NULL;
    }
    free(curr->str);
    free(curr);
}  
t_list *mx_first_node(t_list *any) {
    while (any->prev != NULL) any = any->prev;
    return any;
}
t_list *mx_last_node(t_list *any) {
    while (any->next != NULL) any = any->next;
    return any;
}
void mx_show_all_nodes(t_list *any_node) {
    while (any_node->prev) any_node = any_node->prev;
    while (any_node) {
        if (mx_strcmp(any_node->str, "init_string") != 0) {
            mx_printstr(any_node->str);
            mx_printchar('\n');
        }
        any_node = any_node->next;
    }
}
void mx_sort_list(t_list *left, t_list *right) {
    t_list *start;
    t_list *current;
    char *buffer;
    if (left == right) return;
    start = left;
    current = start->next;
    while (true) {
        if (mx_shitcmp(start->str, current->str) < 0) {
            buffer = current->str;
            current->str = start->str;
            start->str = buffer;
        }
        if (current == right) break;
        current = current->next;
    }
    buffer = left->str;
    left->str = current->str;
    current->str = buffer;
    t_list *prev_curr = current;
    current = current->prev;
    if (current != NULL) {
        if ((left->prev != current) && (current->next != left)) {
            mx_sort_list(left, current);
        }
    }
    current = prev_curr->next;
    if (current != NULL) {
        if ((current->prev != right) && (right->next != current)) {
            mx_sort_list(current, right);
        }
    }
}
