//$ Need to remove
// Students: complete and submit this file
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define WORDMAXSIZE 50


// Determines if specified substring is a palindrome
int isPalindrome(char* word, int start, int end) {

	// base case: we reach a recursive step where end <= start
	if ( end <= start )
		return 1;

	else
		// compares the first and last character of the word and recurses
		//$ Want to explain logically that you are checking if substring is a
		//$ palindrome.  We can tell from code that the call is recursive.
		return word[start] == word[end] && isPalindrome( word, start + 1, end - 1 );

}

// reads in a words and checks whether it's a palindrome by calling isPalindrome
int main(int argc, char *argv[]) {

	// reads in the word
	char theWord[WORDMAXSIZE];
	printf("%s\n", "Enter a string: ");
	// handles the case for no input
	if (scanf("%s", theWord) != 1) {
		printf("format: is_palindrome + string\n");
		break;
	}

	if ( isPalindrome( theWord, 0, strlen(theWord) - 1 ) )
		printf("%s is a palindrome\n", theWord);
	else
		printf("%s is not a palindrome\n", theWord);

	return 0;
}
