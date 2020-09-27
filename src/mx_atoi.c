#include "../inc/race01.h"

int mx_atoi(const char *str) {
	const char* buffer;
	while(mx_isspace(*str)) str++;
	int num = 0;
	int digit = (str[0] == '-') ? -1 : 1;
	if (!mx_isdigit(str[0]) && str[0] != '-' && str[0] != '+') return 0;
	if (str[0] == '-' || str[0] == '+') str++;
	buffer = str;
	// while(*buffer) {
	// 	if (!mx_isdigit(*buffer++ + 1))
	// 		return 0;
	// }
	buffer = str;
	while(mx_isdigit(*buffer)) {
		num *= 10;
		num += *buffer - '0';
		buffer++;
	}
	return num * digit;
}
