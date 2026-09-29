#include <stdio.h>
#include <string.h>

int longestSubstring(char s[]) {
    int last[256];
    int start = 0, maxLength = 0;

    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }

    for (int i = 0; i < strlen(s); i++) {
        if (last[(unsigned char)s[i]] >= start) {
            start = last[(unsigned char)s[i]] + 1;
        }

        last[(unsigned char)s[i]] = i;

        int length = i - start + 1;

        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}

int main() {
    char s[1000];

    printf("Enter string: ");
    scanf("%999s", s);

    printf("Length of longest substring: %d\n", longestSubstring(s));

    return 0;
}
