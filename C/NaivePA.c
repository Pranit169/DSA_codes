#include <stdio.h>
#include <string.h>
void patternMatch(char *text, char *pattern)
{
    int M = strlen(pattern);
    int N = strlen(text);
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == M)
        {
            printf("The pattern is found at index %d", i);
        }
    }
}
int main()
{
    
}