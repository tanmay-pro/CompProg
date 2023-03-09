#include <stdio.h>
#include <string.h>
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(char str2[], int k, int n, char res_str[][n+1])
{
    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = 0; j < k / 2; i++)
        {
            swap(&str2[i], &str2[k - i - 1]);
        }
    }
    strcpy(res_str[k - 2], str2);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        char str[n + 1];
        scanf("%s", str);
        char str2[n + 1];
        int k;
        strcpy(str2, str);
        char res_str[n - 1][n + 1];
        for (k = 2; k < n + 1; k++)
        {
            reverse(str2, k, n, res_str[k - 2]);
            strcpy(str2, str);
        }
    }
}