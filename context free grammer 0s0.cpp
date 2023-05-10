#include <stdio.h>
#include <string.h>

// Function to check whether a given string belongs to the language defined by the CFG
int belongs_to_grammar(char str[]) {
    int len = strlen(str);
    int i = 0;

    // Check if the string is empty or contains only 0s or only 1s
    if (len == 0 || (len == 1 && (str[0] == '0' || str[0] == '1'))) {
        return 1;
    }

    // Check if the string starts with a 0 or a 1
    if (str[0] == '0' || str[0] == '1') {
        // Check if the string ends with a 0 or a 1
        if (str[len-1] == '0' || str[len-1] == '1') {
            // Remove the starting and ending symbols from the string
            str[len-1] = '\0';
            str++;

            // Check if the remaining string belongs to the language defined by S ? 0S0 | 1S1 | 0 | 1 | e
            if (strlen(str) == 0) {
                return 1; // Empty string belongs to the language
            } else if (str[0] == '0') {
                i = 1;
                while (str[i] != '\0' && str[i] == '0') {
                    i++;
                }
                if (str[i] == '0') {
                    return belongs_to_grammar(str+i); // Remove the leading 0s and continue checking
                }
            } else if (str[0] == '1') {
                i = 1;
                while (str[i] != '\0' && str[i] == '1') {
                    i++;
                }
                if (str[i] == '1') {
                    return belongs_to_grammar(str+i); // Remove the leading 1s and continue checking
                }
            }
        }
    }

    return 0; // String does not belong to the language
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (belongs_to_grammar(str)) {
        printf("%s belongs to the language defined by the CFG.\n", str);
    } else {
        printf("%s does not belong to the language defined by the CFG.\n", str);
    }

    return 0;
}
