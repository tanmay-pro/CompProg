//BOY OR GIRL
#include <stdio.h>
#include <string.h>
int main()
{
    char str[128] = {0};
    int ch;
    while ((ch = getchar()) != '\n')
    {
        str[ch]++;
    }
    int c;
    for (int i = 0; i < 128; i++)
    {
        if (str[i] == 1)
            c++;
        else if (str[i] == 0)
            c = c;
        else
        {
            c++;
        }
    }
    if (c % 2 == 1)
        printf("IGNORE HIM!");
    else
    {
        printf("CHAT WITH HER!");
    }
}