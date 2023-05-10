#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_TRANSITIONS 10

typedef struct {
    int state;
    char symbol;
} Transition;

typedef struct {
    int state;
    int transitionCount;
    Transition transitions[MAX_TRANSITIONS];
} State;

void addTransition(State *state, int nextState, char symbol) {
    Transition transition;
    transition.state = nextState;
    transition.symbol = symbol;

    state->transitions[state->transitionCount] = transition;
    state->transitionCount++;
}

void findEpsilonClosure(State *states, int stateCount, int currentState, bool *visited, int *epsilonClosure) {
    visited[currentState] = true;
    epsilonClosure[currentState] = 1;

    int i;
    for (i = 0; i < states[currentState].transitionCount; i++) {
        Transition transition = states[currentState].transitions[i];
        if (transition.symbol == 'E' && !visited[transition.state]) {
            findEpsilonClosure(states, stateCount, transition.state, visited, epsilonClosure);
        }
    }
}

int main() {
    State states[MAX_STATES];
    int stateCount = 0;

    int i;
    for (i = 0; i < MAX_STATES; i++) {
        states[i].state = i;
        states[i].transitionCount = 0;
    }

    
    addTransition(&states[0], 1, 'E');
    addTransition(&states[1], 2, 'E');
    addTransition(&states[1], 4, 'E');
    addTransition(&states[2], 3, 'a');
    addTransition(&states[3], 7, 'E');
    addTransition(&states[4], 5, 'b');
    addTransition(&states[5], 6, 'E');
    addTransition(&states[6], 7, 'c');

    stateCount = 8;

    
    int epsilonClosure[MAX_STATES][MAX_STATES];

    for (i = 0; i < stateCount; i++) {
        bool visited[MAX_STATES] = {false};
        findEpsilonClosure(states, stateCount, i, visited, epsilonClosure[i]);
    }

    
    printf("e-Closure for all states:\n");
    for (i = 0; i < stateCount; i++) {
        printf("e-Closure(q%d): ", i);
        int j;
        for (j = 0; j < stateCount; j++) {
            if (epsilonClosure[i][j] == 1) {
                printf("q%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}

