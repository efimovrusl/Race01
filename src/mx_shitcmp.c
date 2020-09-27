#include "../inc/race01.h"

int mx_has_operator(const char* str) {
    int counter = 0;
    while (*str) {
        if ((*str == '+' || *str == '-' || *str == '*' || *str == '/') && counter != 0) return counter;
        str++;
        counter++;
    }
    return 0;
}

bool mx_has_same_operator(const char* str1, const char* str2) {
    if (str1[mx_has_operator(str1)] == str2[mx_has_operator(str2)]) return true;
    return false;
}

bool mx_eq(int a, int b) {
    if (a > 0) a = 1;
    if (a < 0) a = -1;
    if (b > 0) b = 1;
    if (b < 0) b = -1;
    return a == b;
}

int mx_cmp_op(char str1, char str2) {
    if (str1 == '+' && str2 == '-') return 1;
    if (str1 == '+' && str2 == '*') return 1;
    if (str1 == '+' && str2 == '/') return 1;
    if (str1 == '-' && str2 == '+') return -1;
    if (str1 == '-' && str2 == '*') return 1;
    if (str1 == '-' && str2 == '/') return 1;
    if (str1 == '*' && str2 == '+') return -1;
    if (str1 == '*' && str2 == '-') return -1;
    if (str1 == '*' && str2 == '/') return 1;
    if (str1 == '/' && str2 == '+') return -1;
    if (str1 == '/' && str2 == '-') return -1;
    if (str1 == '/' && str2 == '*') return -1;
    return 0;
}

int mx_shitcmp(const char *str1, const char *str2) {
    if (str1 && str2 == NULL) return 1;
    if (str2 && str1 == NULL) return -1;
    if (!mx_has_same_operator(str1, str2)) {
        return -mx_cmp_op(str1[mx_has_operator(str1)], str2[mx_has_operator(str2)]);
    } else if (mx_atoi(str1) != mx_atoi(str2)) {
        return mx_atoi(str1) - mx_atoi(str2);
    } else {
        return mx_strcmp(str1, str2);
    }
    // return (mx_atoi(str1) - mx_atoi(str2));
    return 0;
}
