#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define debug 0

#define N 201
#define M 151

void naiveSMatcher(char text[],char ptrn[])
{
    int i, j, ck = 0, f = 1;
    int n = strlen(text), m = strlen(ptrn);
    // Pattern length is 'm'
    // Text length is 'n'

    for(i = 0; i <= n-m; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(text[i+j] == ptrn[j])
            {
                ck = 1;
                continue;
            }
            else
            {
                ck = 0;
                break;
            }
        }
// "ck" is checking pattern was found or not
// 'f' is checking pattern found was the first time or not
        if(ck)
            f? f=0, printf("\'%s\' is found. Shift: %d",ptrn,i+1):printf(", %d",i+1);

    }
    if(f)
        printf("\'%s\' is not found.",ptrn);
    printf("\n");
}

int main()
{
    char text[N], ptrn[M];

    scanf("%s %s",text, ptrn);

    naiveSMatcher(text,ptrn);


    return 0;
}


