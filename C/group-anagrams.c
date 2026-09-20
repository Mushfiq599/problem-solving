#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpChar(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    char words[1000][101];
    char sortedKeys[1000][101];
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
        strcpy(sortedKeys[i], words[i]);
        qsort(sortedKeys[i], strlen(sortedKeys[i]), sizeof(char), cmpChar);
    }

    int used[1000] = {0};
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        printf("[%s", words[i]);
        used[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (!used[j] && strcmp(sortedKeys[i], sortedKeys[j]) == 0) {
                printf(", %s", words[j]);
                used[j] = 1;
            }
        }
        printf("] ");
    }
    printf("\n");
    return 0;
}