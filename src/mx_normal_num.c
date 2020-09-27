#include <stdbool.h>
bool mx_isdigit(int c);
int mx_strlen(const char *s);

bool mx_noormal_num(char *s) {
    for (int i = 0; i < mx_strlen(s); i++) {
        if( (i == 0 && s[i] == '-') ||s[i] == '?' || mx_isdigit(s[i])) continue;
        else return false;
    }
    return true;
}
