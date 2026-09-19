#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    if (fgets(s, sizeof(s), stdin) == NULL) return 0;
    int len = (int)strlen(s);
    if (len > 0 && s[len - 1] == '\n') s[--len] = '\0';

    int lastSeen[256];
    for (int i = 0; i < 256; i++) lastSeen[i] = -1;

    int maxLen = 0, start = 0;
    for (int i = 0; i < len; i++) {
        unsigned char ch = s[i];
        if (lastSeen[ch] >= start) {
            start = lastSeen[ch] + 1;
        }
        lastSeen[ch] = i;
        if (i - start + 1 > maxLen) maxLen = i - start + 1;
    }

    printf("%d\n", maxLen);
    return 0;
}