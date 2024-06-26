/*
Tracking a fire using arrays

You have been hired to assist firefighters locate wildfires in a large geographic area.
The area is divided into smaller zones. Each zone is scanned via satellite for its average temperature.
If a zone has an average temperature strictly greater than 1000°F,
we assume there is a fire in that zone. 
If the temperature is between 100 degrees (included) and 1000 degrees (included),
we have to further investigate, so it becomes a "zone to watch."

The large geographic area you are watching is a rectangle with a certain length and width,
each given in terms of zones.
For example, if the area to be scanned  has a length of 6 and width of 9 then it will be divided
into 6*9 zones:

----length = 6----
[ ][ ][ ][ ][ ][ ]   |
[ ][ ][ ][ ][ ][ ]   w
[ ][ ][ ][ ][ ][ ]   i
[ ][ ][ ][ ][ ][ ]   d
[ ][ ][ ][ ][ ][ ]   t
[ ][ ][ ][ ][ ][ ]   h
[ ][ ][ ][ ][ ][ ]   =
[ ][ ][ ][ ][ ][ ]   9
[ ][ ][ ][ ][ ][ ]   |

Because your program will be used for a variety of geographic areas
(each with its own length and width) your program needs to dynamically
allocate the memory for the number of zones it is to handle (vertically and horizontally).

To do so, you must use the two following functions without changing the code in them:

int ** allocateIntStarArray(int num){
    int ** ptr = (int **) malloc(num * sizeof(int *));
    return ptr;
}

int * allocateIntArray(int num){
    int * ptr = (int *) malloc(num * sizeof(int));
    return ptr;
}

The function allocateIntArray() will be used to allocate the space required to store
the average temperatures in one row of zones,
that is, an array of integers.
The function therefore returns a pointer to such an array of integers.

The function allocateIntStarArray() will be used to allocate an array of pointers,
each of which will store a pointer to a row of integers (temperatures of zones).
That is, the function returns a pointer to an array of pointers.
Each cell of this array will point to an array of integers containing the temperature values
for the zones.

The inputs of the program are first the length, then the width of an area, then the average
temperatures of all zones, row by row.

Please remember to free the memory you have allocated.

The output should pinpoint the possible zones with fires with [X] and the watch zone with a [*],
the other zone are displayed with [ ].

Look at the example at the bottom and make sure to format your output in the exact same way.

Input:

6
9
70   71   70   72   70   69
71   73   68   71   73   72
70   71   70   76   1900 78
69   71   100  800  75   71
70   70   71   79   70   69
70   71   112  1005 75   72
70   71   70   900  70   70
72   70   70   72   70   69
73   74   73   72   70   70

Output:

[ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][X][ ]
[ ][ ][*][*][ ][ ]
[ ][ ][ ][ ][ ][ ]
[ ][ ][*][X][ ][ ]
[ ][ ][ ][*][ ][ ]
[ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ][ ]


*/

#include <stdio.h>

int main()
{
    int a, b;
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &a);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &b);
    int mat[a][b];
    int i, j;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (mat[i][j] > 1000)
            {
                printf("[X] ");
            }
            else if (mat[i][j] < 100)
            {
                printf("[ ] ");
            }
            else
            printf("[*] ");
        }
        printf("\n");
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int * allocateIntArray(int num);
int ** allocateIntStarArray(int num);

int main()
{
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    int ** vetortemp = allocateIntStarArray(b);

    int i, j;
    for (int i = 0; i < b; i++)
    {
        vetortemp[i] = allocateIntArray(a);
    }
    
    for (i = 0; i < b; i++)
    {
        for (j = 0; j < a; j++)
        {
            scanf("%d", &vetortemp[i][j]);
        }
    }

    for (i = 0; i < b; i++)
    {
        for (j = 0; j < a; j++)
        {
            if (vetortemp[i][j] > 1000)
            {
                printf("[X]");
            }
            else if (vetortemp[i][j] < 100)
            {
                printf("[ ]");
            }
            else
            printf("[*]");
        }
        printf("\n");
    }
    for (i = 0; i < b; i++)
    {
        free(vetortemp[i]);
    }
    free(vetortemp);
    return 0;
}

int * allocateIntArray(int num)
{
    int * ptr = (int *) malloc(num * sizeof(int));
    return ptr;
}

int ** allocateIntStarArray(int num)
{
    int ** ptr = (int **) malloc(num * sizeof(int *));
    return ptr;
}


/*
Solution

#include <stdio.h>
#include <stdlib.h>

int ** allocateIntStarArray(int num){
	int ** ptr = (int **) malloc(num * sizeof(int *));
	return ptr;
}

int * allocateIntArray(int num){
	int * ptr = (int *) malloc(num * sizeof(int));
	return ptr;
}

int main(void)
{
    int line, col,i,j;
    scanf("%d",&col);
    scanf("%d",&line);
    int ** matrix = allocateIntStarArray(line);
    for(i = 0; i < line; i++){
     matrix[i] = allocateIntArray(col);
    }


    for(i = 0; i < line; i++){
        for(j = 0; j < col; j++){
            scanf("%d",&matrix[i][j]);
        }
    }

     for(i = 0; i < line; i++){
        for(j = 0; j < col; j++){
            if(matrix[i][j]>1000){
                printf("[X]");
            }else{
                if(matrix[i][j]>=100){
                printf("[*]");
                }else{
                printf("[ ]");
                }
            }
           
        }
        printf("\n");
    }
   

    return 0;
}


*/