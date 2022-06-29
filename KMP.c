#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define debug 0
#define debug1 1
#define N 200
#define T 500
#define P 200

// acacabacacabacacac
// Find prefix for a pattern
int *prefix(char ptrn[])
{
    int m = strlen(ptrn),i,q;
    // Create dynamic array
    int *arr = (int*)malloc(m * sizeof(int));

    arr[0] = 0;
    q = 0;

    for(i = 1; i < m; i++)
    {
        while(q>0 && ptrn[q] != ptrn[i])
            q = arr[q-1];

        if(ptrn[q] == ptrn[i])
            q++;

        arr[i] = q;
    }

    return arr;
}
// search pattern in the text
void kmpMatcher(char text[], char ptrn[])
{
    int n,m,i,k,f=1, *arr;

    m = strlen(ptrn);// Pattern length is 'm'
    n = strlen(text);// Text length is 'n'
    arr = prefix(ptrn);// Get prefix array of the pattern
    k = 0;

    for(i = 0; i < n; i++)
    {
        while(k>0 && ptrn[k] != text[i])
            k = arr[k-1];

        if(ptrn[k] == text[i])
            k++;
//(k == m) is checking pattern was found or not
// 'f' is checking pattern was found the first time or not
        if(k == m)
        {
            f? f=0, printf("\'%s\' is found. Shift: %d",ptrn,i-m):printf(", %d",i-m);
            k = arr[k-1];
        }
    }
}

int main()
{
    char text[T],ptrn[P];

    scanf("%s %s",text,ptrn);
    kmpMatcher(text,ptrn);


    return 0;
}


