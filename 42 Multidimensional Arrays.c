/*
You are designing a new cookie recipe and are experimenting with different amounts of wet (water, oil) and dry (flour, sugar, cocoa powder)
ingredients in order to get the proportions just right. All of these amounts are initially read from the user input, and the code to do so,
along with all variable declarations, had already been completed. You are interested in the total amount of wet and dry ingredients used in the recipe as well
as the ratio of these two quantities.

Take a look at the code that is already given to you. Your job is to add four lines of code, precisely where indicated by a comment such as

//Add one line here

Beneath each such line you will find an explanation of what precisely your line of code is supposed to do as well as what type of array addressing you are to use.
Please read and follow these directions carefully.
Do not change anything else in the code that is provided as our grading system will detect such changes and mark your solution as incorrect.

Example

Input
10.5 20.2                                                                                                                               
30.3 40.4 50.5

Output
Total amount of wet ingredients: 30.70 grams.                                                                                           
Total amount of dry ingredients: 121.20 grams.                                                                                          
Ratio of wet to dry ingredients: 3.95                                                                                              
New water amount: 15.35 grams, new oil amount: 15.35 grams. 


Provided code

#include <stdio.h>

int main(void) {

    double totalWet, totalDry, ratio;

    double wet[2];
    double dry[3];
    double * cookie[2] = {wet,dry};
    
    scanf("%lf%lf", &wet[0], &wet[1]);
    scanf("%lf%lf%lf", &dry[0], &dry[1], &dry[2]);

    Add one line here! 
    The line you add should use the array cookie (and not the array wet) to 
       find the sum of the wet ingredients of the cookie recipe and store that sum
       in the variable totalWet. Use only indexed notation to address the cookie
       array (that is, you need to use two pairs of brackets [..]). 
    

    printf("Total amount of wet ingredients: %.2lf grams.\n", totalWet);
    
    Add one line here! 
    The line you add should use the array cookie (and not the array dry) to 
       find the sum of the dry ingredients of the cookie recipe and store that sum
       in the variable totalDry. This time, use only one pair of brackets [..] each 
       time you address the cookie array. 
    

    printf("Total amount of dry ingredients: %.2lf grams.\n", totalDry);
    ratio = totalDry/totalWet;
    printf("Ratio of wet to dry ingredients: %.2lf.\n", ratio);

    Add two lines here.
    The lines you add should use the array cookie (and not the array wet) to
       update the amounts of water and oil in your recipe. 
       You believe that any cookie recipe should use equal amounts of water and oil.
       Without changing the total amount of wet ingredients, update the values for
       water and oil, using only the array cookie (and not the array wet) so that 
       these amounts will be equal. The easiest way to do so is to assign the value
       totalWet/2 to both the water and the oil entry. When addressing the array cookie,
       do not use any brackets at all this time.
    
    
    printf("New water amount: %.2lf grams, new oil amount: %.2lf grams.\n", wet[0], wet[1]);
    
    return 0;
}
*/


#include <stdio.h>

int main(void)
{
   double totalWet, totalDry, ratio;
   double wet[2];
   double dry[3];
   double * cookie[2] = {wet, dry};

   scanf("%lf%lf", &wet[0], &wet[1]);
   scanf("%lf%lf%lf", &dry[0], &dry[1], &dry[2]);

   totalWet = cookie[0][0] + cookie[0][1];

   printf("Total amount of wet ingredients: %.2lf grams.\n", totalWet);

   totalDry = (*cookie[1]) + (*(cookie[1] + 1)) + (*(cookie[1] + 2));

   printf("Total amount of dry ingredients: %.2lf grams.\n", totalDry);
   ratio = totalDry/totalWet;
   printf("Ratio of wet to dry ingredients: %.2lf.\n", ratio);

   *(*cookie) = totalWet / 2;
   *((*cookie) + 1) = totalWet / 2;

   printf("New water amount: %.2lf grams, new oil amount: %.2lf grams.\n", wet[0], wet[1]);

   return 0;
}

/*
Solution

#include <stdio.h>

int main(void) {

   double totalWet, totalDry, ratio;

   double wet[2];
   double dry[3];
   double * cookie[2] = {wet,dry};
    
   scanf("%lf%lf", &wet[0], &wet[1]);
   scanf("%lf%lf%lf", &dry[0], &dry[1], &dry[2]);

   Add one line here! 
   totalWet = cookie[0][0] + cookie[0][1];
   The line you add should use the array cookie (and not the array wet) to 
   find the sum of the wet ingredients of the cookie recipe and store that sum
   in the variable totalWet. Use only indexed notation to address the cookie
   array (that is, you need to use two pairs of brackets [..]). 
   
    printf("Total amount of wet ingredients: %.2lf grams.\n", totalWet);
    
   Add one line here! 
   totalDry = *cookie[1] + *(cookie[1]+1) + *(cookie[1]+2);
   The line you add should use the array cookie (and not the array dry) to 
   find the sum of the dry ingredients of the cookie recipe and store that sum
   in the variable totalDry. This time, use only one pair of brackets [..] each 
   time you address the cookie array. 
   
    printf("Total amount of dry ingredients: %.2lf grams.\n", totalDry);
    ratio = totalDry/totalWet;
    printf("Ratio of wet to dry ingredients: %.2lf.\n", ratio);

   Add two lines here.
   **cookie = totalWet/2;
   *(*cookie + 1) = totalWet/2;
   The lines you add should use the array cookie (and not the array wet) to
   update the amounts of water and oil in your recipe. 
   You believe that any cookie recipe should use equal amounts of water and oil.
   Without changing the total amount of wet ingredients, update the values for
   water and oil, using only the array cookie (and not the array wet) so that 
   these amounts will be equal. The easiest way to do so is to assign the value
   totalWet/2 to both the water and the oil entry. When addressing the array cookie,
   do not use any brackets at all this time.
       
    printf("New water amount: %.2lf grams, new oil amount: %.2lf grams.\n", wet[0], wet[1]);
    
    return 0;
}
*/

/*
Activity - Print Text in Reverse Order

Your goal is to read a 68-word text from the input and then print it to the screen backwards.
Individual words do not have to be spelled backwards, but rather your program should print out
the last word first, then the second-to-last word, etc. No word has more than 40 characters.

Example

Input
Science Computer on Papers Selected Knuth, Ervin Donald ― correct."
be will results the that reader a convince to and works algorithm an way the communicate
to concepts, mathematical as well as forms literary and aesthetic traditional with works
who essayist an ideally is programmer A clearly.
them understand can beings human that so and quickly them perform can machines computing
that so written are programs best "The

Output
"The best programs are written so that computing machines can perform them quickly and so
that human beings can understand them clearly. A programmer is ideally an essayist who works
with traditional aesthetic and literary forms as well as mathematical concepts,
to communicate the way an algorithm works and to convince a reader that the results will be correct."
― Donald Ervin Knuth, Selected Papers on Computer Science
*/

#include <stdio.h>

int main()
{
   char words[68][41];
   int i;
   for (i = 0; i < 68; i++)
   {
      scanf("%s", words[i]);
   }
   for (i = 67; i >= 0; i--)
   {
      printf("%s ", words[i]);
   }
   return 0;
}

/*
Solution

#include <stdio.h>

int main(void) {
	char text[68][41];
	int i;
	for(i = 0 ; i < 68 ; i ++){
		scanf("%s", text[i]);
	}
	for(i = 0 ; i<68 ; i++){
		printf("%s ", text[67-i]);
	}
	
	return 0;
}

*/