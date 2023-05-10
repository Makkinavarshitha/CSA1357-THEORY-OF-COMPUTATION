#include <stdio.h>

#define STATES 3
#define ALPHABET_SIZE 2

int transitionTable[STATES][ALPHABET_SIZE] = {
    {1, -1},
    {1, 2},
    {-1, -1}
};

int isValidString(char *str) {
    int currentState = 0;
    int i = 0;

    while (str[i] != '\0') {
        int charIndex = (str[i] == 'a') ? 0 : 1;

        if (charIndex == -1) {
            return 0; 
        }

        currentState = transitionTable[currentState][charIndex];

        if (currentState == -1) {
            return 0; 
        }

        i++;
    }

    return currentState == 2; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isValidString(str)) {
        printf("Valid string\n");
    } else {
        printf("Invalid string\n");
    }

    return 0;
}

