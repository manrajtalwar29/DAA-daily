#include <stdio.h>
#include <string.h>

int isAnagram(char str[], char pattern[]) {
    int n = strlen(str);
    int m = strlen(pattern);

    if (m > n)
        return 0;

    for (int i = 0; i <= n - m; i++) {
        int count[256] = {0};

        // Count characters of pattern
        for (int j = 0; j < m; j++) {
            count[(unsigned char)pattern[j]]++;
        }

        // Remove characters of current substring
        for (int j = 0; j < m; j++) {
            count[(unsigned char)str[i + j]]--;
        }

        int flag = 1;

        for (int j = 0; j < 256; j++) {
            if (count[j] != 0) {
                flag = 0;
                break;
            }
        }

        if (flag)
            return 1;
    }

    return 0;
}

int main() {
    char str[100], pattern[100];

    printf("Enter main string: ");
    scanf("%99s", str);

    printf("Enter substring: ");
    scanf("%99s", pattern);

    if (isAnagram(str, pattern))
        printf("Anagram substring found\n");
    else
        printf("Anagram substring not found\n");

    return 0;
}
