int mx_sign_digit(int num) {
    while (num / 10 > 0) num /= 10;
    return num;
}
