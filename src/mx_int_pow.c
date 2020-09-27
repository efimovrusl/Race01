int mx_int_pow(int num, int pow) {
    int res = 1;
    for (int i = 0; i < pow; i++) {
        res *= num;
    }
    return res;
}
