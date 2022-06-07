#include <stdio.h>
#include <string.h>

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};

    int len = (int) sizeof(arr);
    printf("%d\n", len);

    int len3 =  sizeof(arr) / sizeof(int);
    printf("%d\n", len3);

    int len4 =  sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", len4);

    char name[] = "victor";

    int len2 = strlen(name);
    printf("%d\n", len2);
}
