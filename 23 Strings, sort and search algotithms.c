/*
Activity: repeat a word read from the user input

Write a C-program that prints out a word as many times as specified.
The number of repetitions and the word should be given as input to the program.
You may assume that the word has no more than 100 characters (be sure to also reserve space for the null terminator, \0, though!).
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char word[101];
    scanf("%s", word);
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%s\n", word);
    }
    return 0;
}

// Solution

#include <stdio.h>

int main(void) {
    char word[101]; 
    int num, i;

    scanf("%d", &num);
    scanf("%s", word);

    for (i=0; i<num; i++)
        printf("%s\n", word);

    return 0;
}

/*
Activity: swap first and last name

Your local public library keeps a record of all of its patrons,
consisting of index cards that hold a person's last name followed by their first name (so that the cards can easily be sorted alphabetically by last name).
Unfortunately a computer error led to incorrectly printed forms last month,
resulting in a number of cards that list the patron's first name followed by their last name rather than the other way around.
Your job is to read these pairs of first and last names and display them in the correct order (last name followed by first name).
You may assume that each first and last name has at most 100 characters and does not contain any spaces.

Your program should first read the total number of names (an integer) in order to know how many index cards need to be processed altogether.
Next, for each index card, your program should read a patron's first name and last name and then display these names correctly, that is on one line,
the last name followed by one space, followed by the first name.
Your program should print the reversed name immediately after reading the patron's names (ie, it should not wait until it has read all of the index cards to begin printing). 

Note that, for ease of viewing, the example below shows all of the inputs in one block and all of the outputs in another block,
despite the fact that programmatically these will be interspersed.
*/

#include <stdio.h>

int main()
{
    char firstname[100];
    char lastname[100];
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s %s", firstname, lastname);
        printf("%s %s\n", lastname, firstname);
    }
    return 0;
}

// Solution

#include <stdio.h>

int main(void) 
{
    int num, i;
    char first[101], last[101];
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
       scanf("%s", first);
       scanf("%s", last);
       printf("%s %s\n", last, first);
    }

    return 0;
}

/*
Activity: even or odd number of letters in a word?

At the annual meeting of MOOC fans, participants register on the first day of the event in order to receive their name tags, brochures and banquet vouchers.
Unfortunately this often results in long lines.
In an attempt to speed things up, there are now two people working the registration desk:
one person who has the registration materials for those fans whose names contain an odd number of letters,
the other for those whose names have an even number of letters.
Your job is to write a C-program that will tell a fan which line to stand in.

To simplify the program, you may assume that student names are less than 50 characters long and contain no spaces.
Your program should output an integer value (1 or 2) depending on whether the fan should join line 1 (name has even number of letters)
or line 2 (name has odd number of letters).
*/

#include <stdio.h>

int main()
{
    char name[51];
    scanf("%s", name);
    int i;
    for (i = 0; name[i] != '\0'; i++)
    {
    }
    if (i % 2 == 0)
    {
        printf("1");
    }
    else
    {
        printf("2");
    }
    
    return 0;
}

// Solution

#include <stdio.h>

int main(void) {
    char name[51];
    int i=0;

    scanf("%s", name);
    while(name[i] != '\0')
        i++;

    if (i%2 == 0) 
        printf("1");
    else 
        printf("2");

    return 0;
}

/*
Activity: find the longest word in a text

Your job is to find the length of the longest word in a text with no punctuation or special characters of any kind -
only contains words. To do so, please write a C-program that takes as a input first the number of words in a text,
followed by all of the words in the text. The output of your program should be the length of the longest word in the text.

To simplify your program, you can assume that the longest word will not exceed 100 characters.
*/

#include <stdio.h>

int main()
{
    char word[101];
    int number;
    scanf("%d", &number);
    int i;
    int tamanho = 0;
    int j;
    for(i = 0; i < number; i++)
    {
        scanf("%s", word);
        j = 0;
        while(word[j] != '\0')
        {
            j++;
            if(j >= tamanho)
            {
                tamanho = j;
            }
        }
    }
    printf("%d", tamanho);
    return 0;
}

// Solution

#include <stdio.h>

int main(void) {

    int i, length;
    int max = 0;
    int num = 0;
    char word[101];

    scanf("%d", &num);
    for(i = 0 ; i < num ; i++){
        scanf("%s", word);
        length = 0;
        while(word[length]!='\0'){
            length++;
        }
        if (length > max)
        	max = length;
    }

    printf("%d\n", max);
    return 0;
}

/*
Activity: is there a 't' in this word?

You are conducting a linguistic study and are interested in finding words that contain the letter 't' or 'T' in the first half of the word
(including the middle letter if there is one).
Specifically, if the first half of the word does contain a 't' or a 'T', your program should output a 1.
If the first half does not contain the letter 't' or 'T', but the second half does, then your program should output a 2.
Otherwise, if there is no 't' or 'T' in the word at all, your program's output should be -1. You may assume that the word entered does not have more than 50 letters.
*/

#include <stdio.h>

int main()
{
	// Leitura da palavra
    char word[51];
    scanf("%s", word);
    // Contagem do número de caracteres
    int i = 0;
    while(word[i] != '\0')
    {
        i++;
    }
    // Busca linear
    int found = 0;
    int j = 0;
    while(!found && j < i)
    {
    	if('t' == word[j] || 'T' == word[j])
    	{
    		found = 1;
		}
		else
		{
			j++;
		}
	}
	// Imprime se não achar a letra
	if(!found)
	{
		printf("-1");
	}
	// Imprime se encontrar a letra
	else
	{
	    // Imprime se estiver na primeira metade da palavra
		if((i % 2 == 0 && j <= i / 2) || (i % 2 == 1 && j + 1 < i))
		{
			printf("1");
		}
		// Imprime se estiver na segunda metade
		else
		{
			printf("2");
		}
	}
    return 0;
}

// Solution

#include <stdio.h>
int main(void)
{
	char word[51];
	int length = 0;
	int i,found, maxindex;

	scanf("%s", word);
	
	while (word[length]!='\0')
	    length++;
	if (length%2==0)
	    maxindex = length/2-1;
	else
	    maxindex = length/2;
	
	i = 0;
	found = 0;
	while (!found && i < length) {
		if (word[i]=='t' || word[i]=='T') found++;
		else i++;
	}

	if (!found) 
	    printf("-1");
	else if (i <= maxindex) printf("1");
	else printf("2");

	return 0;
}

/*
Activity: find repeat letters in a word

You are still conducting linguistic research!
This time, you'd like to write a program to find out how many letters occur multiple times in a given word.
Your program should read a word from the input and then sort the letters of the word alphabetically (by their ASCII codes).
Next, your program should iterate through the letters of the word and compare each letter with the one following it.
If these equal each other, you increase a counter by 1, making sure to then skip ahead far enough so that letters that occur more than twice are not counted again.
You may assume that the word you read from the input has no more than 50 letters, and that the word is all lowercase.
*/

#include <stdio.h>

int main()
{
    // Leitura da palavra
    char word[51];
    scanf("%s", word);
    // Contagem dos caracteres
    int nchar = 0;
    while (word[nchar] != '\0')
    {
        nchar++;
    }
    // Ordenacao usando Bubble Sort
    int i, j, swap;
    for(j = 0; j < nchar - 1; j++)
    {
        for(i = 0; i < nchar - 1; i++)
        {
            if(word[i] > word[i + 1])
            {
                swap = word[i];
                word[i] = word[i + 1];
                word[i + 1] = swap; 
            }
        }
    }
    // Contagem de letras repetidas
    int cont = 0;

    for(i = 0; i < nchar - 1; i++)
    {
        if(word[i] == word[i + 1] && word[i] != word[i + 2])
        {
            cont++;
        }
    }
    printf("%d\n", cont);

    return 0;
}

// Solution

#include <stdio.h>
int main(void)
{
    char word[51];
    int length = 0;
    int i, j;
    char swap;
    int repeats = 0;

    scanf("%s", word);
	
    while (word[length]!='\0')
	length++;

    //Sort the word by alphabetical order    
    for(j=0;j<length-1; j++) {
        for(i=0;i<length-1;i++) { 
            if (word[i] > word[i+1]) {
                swap = word[i];
                word[i]   = word[i+1];
                word[i+1] = swap;
            }
        }
    }
    
    i = 0;
    
    //Check for repeating characters in the sorted word
    while (i<length-1) {
        if (word[i]==word[i+1]) {
            repeats++;
            j=i+2;

            //Continues through the word until it reaches a new character
            while (j<length && word[i]==word[j]) 
                j++;
            i = j;
        } else {
            i++;
        }
    }
    
    printf("%d", repeats);

    return 0;
}


