#include <stdio.h>
#include <string.h>

int isPalindromeRange(const char *s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return 0;
        left++;
        right--;
    }
    return 1;
}

int almostPalindrome(const char *s, int len)
{
    int left = 0, right = len - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return isPalindromeRange(s, left + 1, right) ||
                   isPalindromeRange(s, left, right - 1);
        }
        left++;
        right--;
    }

    return 1;
}

int main()
{
    char s[1000000];
    if (fgets(s, sizeof(s), stdin) == NULL)
        return 0;

    int len = (int)strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[--len] = '\0';

    printf("%s\n", almostPalindrome(s, len) ? "YES" : "NO");
    return 0;
}