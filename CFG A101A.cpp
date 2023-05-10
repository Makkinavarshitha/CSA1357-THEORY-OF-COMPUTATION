#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool belongsToCFG(char *str, int start, int end);

bool isNonTerminal(char symbol);
bool isTerminal(char symbol);
bool processNonTerminalA(char *str, int start, int end);

bool processNonTerminalS(char *str, int start, int end);

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (belongsToCFG(str, 0, strlen(str) - 1)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }

    return 0;
}

bool belongsToCFG(char *str, int start, int end) {
    if (start > end) {
        
        return true;
    }

    return processNonTerminalS(str, start, end);
}

bool isNonTerminal(char symbol) {
    return symbol == 'S' || symbol == 'A';
}

bool isTerminal(char symbol) {
    return symbol == '0' || symbol == '1';
}

bool processNonTerminalA(char *str, int start, int end) {
    if (start > end) {
        return false;
    }

    if (isTerminal(str[start])) {
        return processNonTerminalA(str, start + 1, end);
    }

    if (str[start] == 'e') {
        return true;
    }

    return false;
}

bool processNonTerminalS(char *str, int start, int end) {
    if (start > end) {
        return false;
    }

    if (isTerminal(str[start]) && str[start] == '1') {
        return processNonTerminalA(str, start + 1, end);
    }

    if (isNonTerminal(str[start]) && str[start] == 'A') {
        int index = start + 1;
        if (index <= end && str[index] == '0') {
            if (index + 1 <= end && str[index + 1] == '1') {
                return processNonTerminalA(str, index + 2, end);
            }
        }
    }

    return false;
}

