#include <stdio.h>
#include <string.h>

int isBelongsToLanguage(char *str);

int S(char *str);
int A(char *str);

int S(char *str) {
    if (str[0] == '0') {
        int len = strlen(str);
        if (str[len - 1] == '0') {
            if (len == 2) {
                return 1;
            } else {
                return S(str + 1);
            }
        }
    }
    return 0;
}

int A(char *str) {
    if (str[0] == '1') {
        int len = strlen(str);
        if (len == 1) {
            return 1;
        } else {
            return A(str + 1);
        }
    } else {
        return 1;
    }
}

int isBelongsToLanguage(char *str) {
    return S(str) && A(str);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isBelongsToLanguage(str)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }

    return 0;
}
