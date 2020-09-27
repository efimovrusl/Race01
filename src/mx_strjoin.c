#include "../inc/race01.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (!s1 && !s2)
        return 0;
    if (!s1 && s2)
        return mx_strdup(s2);
    if (s1 && !s2)
        return mx_strdup(s1);
    char *new_str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    return mx_strcat(mx_strcpy(new_str, s1), s2);
}
