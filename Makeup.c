//Hasibul Hassan Siam
//ID: 1921905043
//Section 9
//Makeup Quiz(Set A)


#include <stdio.h>
#include <string.h>

void main(char *str1, char *str2)
{
    int m = strlen(str1);
    int n = strlen(str2);

    int dp[m + 1][n + 1];
    int max_length = 0;
    int end_index = 0;


    for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
    if (i == 0 || j == 0)
    dp[i][j] = 0;
    else if (str1[i - 1] == str2[j - 1]) {
    dp[i][j] = dp[i - 1][j - 1] + 1;
    if (dp[i][j] > max_length) {

    max_length = dp[i][j];
    end_index = i - 1;
    }
    }
    else {
                dp[i][j] = 0;
        }
    }
    }

    if (max_length > 0) {
        printf("The longest common substring is: ");
        for (int i = end_index - max_length + 1; i <= end_index; i++) {
        printf("%c", str1[i]);
        }
        printf("\n");
    } else {
        printf("No common substring found.\n");
    }
}

int main()
{
    char str1[100], str2[100];

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    printLongest_Common_Substring(str1, str2);

    return 0;
}
