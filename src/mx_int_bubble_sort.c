void mx_int_bubble_sort(int *arr, int size) {
    int buffer;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                buffer = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buffer;
            }
        }
    }
}
