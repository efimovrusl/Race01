#include "../inc/race01.h"

int mx_static_calculate(int a, int b, char *op) {
    if (mx_strcmp(op, "+") == 0) {
        return a + b;
    } else if (mx_strcmp(op, "-") == 0) {
        return a - b;
    } else if (mx_strcmp(op, "*") == 0) {
        return a * b;
    } else if (mx_strcmp(op, "/") == 0) {
        return (int)((float)a / (float)b);
    }
    return -2147483648;
}

t_list *mx_get_results(t_values *arg1, t_values *arg2, t_values *arg3, char op) {
    t_list *res_list = mx_new_node("init_string");
    t_list *opers = mx_new_node("init_operator");
    if (op == '?') {
        mx_add_node(opers, "+");
        mx_add_node(opers, "-");
        mx_add_node(opers, "*");
        mx_add_node(opers, "/");

    } else if (op == '+') {
        mx_add_node(opers, "+");
    } else if (op == '-') {
        mx_add_node(opers, "-");
    } else if (op == '*') {
        mx_add_node(opers, "*");
    } else if (op == '/') {
        mx_add_node(opers, "/");
    }
    opers = mx_first_node(opers);
    while (opers != NULL) {
        if (mx_strcmp(opers->str, "root") == 0) {
            opers = opers->next;
            continue;
        }
        for (int i = 0; i < arg1->size; i++) {

            for (int j = 0; j < arg2->size; j++) {

                for (int k = 0; k < arg3->size; k++) {
                    if (mx_static_calculate(arg1->arr[i], arg2->arr[j], opers->str) == arg3->arr[k]) {
                        mx_add_node(res_list, 
                            mx_strjoin(
                                mx_strjoin(
                                    mx_strjoin(mx_itoa(arg1->arr[i]), " "),
                                    mx_strjoin(opers->str, " ")
                                ),
                                mx_strjoin(
                                    mx_strjoin(mx_itoa(arg2->arr[j]), " = "),
                                    mx_itoa(arg3->arr[k])
                                )
                        ));
                    }
                }
            }
        }
        opers = opers->next;
    }
    mx_sort_list(mx_first_node(res_list), mx_last_node(res_list));
    return res_list;
}
