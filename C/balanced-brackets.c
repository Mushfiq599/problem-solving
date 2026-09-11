#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000000

int main() {
    static char input[MAX_LEN];
    int len = 0;
    int ch;

    while ((ch = getchar()) != EOF && len < MAX_LEN - 1) {
        input[len++] = (char)ch;
    }
    input[len] = '\0';

    char stack[MAX_LEN];
    int top = -1;
    int balanced = 1;

    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) { balanced = 0; break; }
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                balanced = 0;
                break;
            }
        }
        // ignore all other characters
    }

    if (top != -1) balanced = 0;

    printf("%s\n", balanced ? "YES" : "NO");
    return 0;
}