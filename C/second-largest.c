#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    long long first = LLONG_MIN, second = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        long long num;
        scanf("%lld", &num);
        if (num > first) {
            second = first;
            first = num;
        } else if (num < first && num > second) {
            second = num;
        }
    }

    if (second == LLONG_MIN) printf("-1\n");
    else printf("%lld\n", second);

    return 0;
}