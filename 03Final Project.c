/*
Check if string is reversed

Write a function isReverse() that checks whether a given word is the reverse of another given word.
More precisely, the function should take as inputs two words (null-terminated arrays of characters)
and return an integer.
If indeed the second word is the reverse of the first then the function should return the integer 1,
otherwise it should return a 0.

Your main() function should read two words from the user input
(you can assume that neither word has more than 99 characters) and then call the function isReverse,
passing both words to this function.
The function should return an integer as described above and your main program needs to print out a
sentence, indicating whether indeed, the first word is the reverse of the second word
(see below examples).

Note: The name of the function needs to be isReverse.

Here are two sample runs:

Input:

stressed
desserts

Output:

stressed is the reverse of desserts


Input:

apple
banana

Output:

apple is not the reverse of banana
*/

#include <stdio.h>

int isReverse(char palavra1[], char palavra2[]);

int main()
{
    char palavra1[100];
    char palavra2[100];
    scanf("%s", palavra1);
    scanf("%s", palavra2);
    int result;
    result = isReverse(palavra1, palavra2);
    if (result == 1)
    {
        printf("%s is the reverse of %s\n", palavra1, palavra2);
    }
    else
    {
        printf("%s is not the reverse of %s\n", palavra1, palavra2);
    }
    return 0; 
}

int isReverse(char palavra1[], char palavra2[])
{
    int tam1 = 0;
    int tam2 = 0;
    while (palavra1[tam1] != '\0')
    {
        tam1++;
    }
    while (palavra2[tam2] != '\0')
    {
        tam2++;
    }
    if (tam1 != tam2)
    {
        return 0;
    }

    int i = 0;
    int j = tam1 - 1;

    while (i < tam1)
    {
        if (palavra1[i] != palavra2[j])
        {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

// Solution

#include <stdio.h>

int isReverse(char *w1, char *w2);
int strlength(char *w);

int main(void) 
{
    char w1[100];
    char w2[100];
    
    //printf("Please enter first word: ");
    scanf("%s", w1);
    //printf("Please enter second word: ");
    scanf("%s", w2);
    
    if (isReverse(w1, w2)) 
    {
        printf("%s is the reverse of %s\n", w1, w2);
    }
    else
    {
        printf("%s is not the reverse of %s\n", w1, w2);
    }
    
    return 0;
}

int isReverse(char *w1, char *w2)
{
    int i, l1, l2;
    int rev = 1;
    
    l1 = strlength(w1);
    l2 = strlength(w2);
    if (l1!=l2) 
    {
        rev=0;
    }
    else
    {
        for (i=0; i<l1; i++)
        {
            if (w1[i] != w2[l1-i-1])
            {
                rev = 0;
            }
        }
    }
    return rev;
}

int strlength(char *w)
{
    int i = 0;
    while (w[i]!='\0')
    {
        i++;
    }
    return i;
}