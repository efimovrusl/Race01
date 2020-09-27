#include "../inc/race01.h"

t_values *mx_get_possible_values(char *number) {
    int sign = 1;
    if (number[0] == '-') sign = -1, number++;
    int dollars = 0;
    for (int i = 0; i < mx_strlen(number); i++)
        if (number[i] == '?') dollars++;
    // create some space for possible values
    t_values *values = (t_values *)malloc(16);
    values->size = mx_int_pow(10, dollars);
    values->arr = (int *)malloc(4 * values->size);
    for (int i = 0; i < values->size; i++)
        values->arr[i] = 0;
    
    for (int i = 0, d = 0; i < mx_strlen(number); i++) {
        if (mx_isdigit(number[i])) {
            for (int k = 0; k < values->size; k++) {
                values->arr[k] *= 10;
                values->arr[k] += number[i] - '0';
            }
        } else {
            for (int k = 0, var = 0; k < values->size; k++) {
                if (k % mx_int_pow(10, d) == 0) var++, var %= 10;
                values->arr[k] *= 10;
                values->arr[k] += var;
            }
            d++;
        }
    }
    for (int i = 0; i < values->size; i++) values->arr[i] *= sign;
    return values;
}
