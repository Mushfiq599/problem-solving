#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    int result = (n > 0) && ((n & (n - 1)) == 0);
    printf("%s\n", result ? "YES" : "NO");
    return 0;
}