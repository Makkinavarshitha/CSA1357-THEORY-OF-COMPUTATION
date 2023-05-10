#include <stdio.h>
#include <stdbool.h>

bool isAccepted(char *str) {
    int currentState = 0;

    while (*str != '\0') {
        switch (currentState) {
            case 0:
                if (*str == 'b')
                    currentState = 1;
                else
                    currentState = -1;
                break;
            case 1:
                if (*str == 'a')
                    currentState = 2;
                else if (*str != 'b')
                    currentState = -1;
                break;
            case 2:
                currentState = -1;
                break;
            default:
                currentState = -1;
                break;
        }

        if (currentState == -1)
            return false;

        str++;
    }

    return currentState == 2;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isAccepted(str))
        printf("String accepted!\n");
    else
        printf("String not accepted!\n");

    return 0;
}

