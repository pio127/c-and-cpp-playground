#include<stdio.h>
#include<string.h>

int main() {
    // Array of char string literal initialization allows read and write
    char first_word[] = "first word";
    char second_word[] = "second word";

    // Pointer to string literal initialization allows ONLY READ 
    char *third_word = "read only!!!";
    
    char fourth_word[] = "desrewer";

    printf("%p: %s\n",&first_word, first_word);
    printf("%p: %s\n",&second_word, second_word);
    printf("%p: %s\n",&third_word, third_word);

    // Removing null character from first string
    first_word[10] = ' ';

    // Adding null instead of space(' ') for second string
    second_word[6] = '\0';

    printf("After string value manipulations:\n");
    printf("%p: %s\n",&first_word, first_word);
    printf("%p: %s\n",&second_word, second_word);
    printf("%p: %s\n",&third_word, third_word);

    // Printing reversly the fifth word
    char *last_character=fourth_word+strlen(fourth_word)-1;
    for(int x=0; x < strlen(fourth_word); ++x) {
        printf("%c", *(last_character-x));    
    }
}
