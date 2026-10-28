#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ROLL "25BCS007"
#define STUDENT_NAME "Ahetesham Qureshi"

#define Max 1000

char str[Max];

/* This function removes the newline character from the input if it is present.
   It takes the string as a parameter and does not return anything. */
void removeNewline(char s[]){
    int len = strlen(s);

    if(len > 0 && s[len - 1] == '\n'){
        s[len - 1] = '\0';
    }
}

/* This function reads a string from the user.
   It uses fgets so that spaces between words are also accepted. */
void inputString(char s[]){
    printf("Enter a string: ");
    fgets(s, Max, stdin);
    removeNewline(s);
}

/* This function reverses every word separately without changing their order.
   It takes the string as a parameter and returns nothing. */
void reverseEachWord(char s[]){
    int i = 0, j, start;

    printf("Roll no: %s Name: %s\n", ROLL, STUDENT_NAME);

    while(s[i] != '\0'){
        if(s[i] == ' '){
            i++;
            continue;
        }

        start = i;

        while(s[i] != '\0' && s[i] != ' '){
            i++;
        }

        j = i - 1;

        while(start < j){
            char temp = s[start];
            s[start] = s[j];
            s[j] = temp;

            start++;
            j--;
        }
    }

    printf("String after reversing each word: %s\n", s);
}

/* This function removes duplicate words and keeps their first occurrence.
   It compares words without considering uppercase and lowercase differences. */
void removeDuplicateWords(char s[]){
    char words[Max][Max];
    char result[Max] = "";
    char temp[Max];
    int count = 0, i = 0, j, k, found;

    printf("Roll no: %s Name: %s\n", ROLL, STUDENT_NAME);

    while(s[i] != '\0'){
        while(s[i] == ' '){
            i++;
        }

        if(s[i] == '\0'){
            break;
        }

        j = 0;

        while(s[i] != '\0' && s[i] != ' '){
            temp[j++] = s[i++];
        }

        temp[j] = '\0';
        found = 0;

        for(k = 0; k < count; k++){
            if(strlen(words[k]) == strlen(temp)){
                int x, same = 1;

                for(x = 0; temp[x] != '\0'; x++){
                    if(tolower((unsigned char)words[k][x]) !=
                       tolower((unsigned char)temp[x])){
                        same = 0;
                        break;
                    }
                }

                if(same){
                    found = 1;
                    break;
                }
            }
        }

        if(!found){
            strcpy(words[count], temp);
            count++;
        }
    }

    for(i = 0; i < count; i++){
        if(i > 0){
            strcat(result, " ");
        }

        strcat(result, words[i]);
    }

    if(count == 0){
        printf("No words found in the string.\n");
    }else{
        printf("String after removing duplicate words: %s\n", result);
    }
}

/* This function finds the second most frequent character.
   Spaces are ignored, and uppercase and lowercase letters are treated equally.
   If two characters have the same frequency, the first one encountered wins. */
void secondMostFrequentCharacter(char s[]){
    int freq[256] = {0};
    int i, first = 0, second = 0;
    unsigned char ch;
    int found = 0;

    printf("Roll no: %s Name: %s\n", ROLL, STUDENT_NAME);

    for(i = 0; s[i] != '\0'; i++){
        ch = (unsigned char)s[i];

        if(!isspace(ch)){
            ch = (unsigned char)tolower(ch);
            freq[ch]++;
        }
    }

    for(i = 0; i < 256; i++){
        if(freq[i] > first){
            second = first;
            first = freq[i];
        }else if(freq[i] > second && freq[i] < first){
            second = freq[i];
        }
    }

    if(second == 0){
        printf("No second most frequent character exists.\n");
        return;
    }

    for(i = 0; s[i] != '\0'; i++){
        ch = (unsigned char)s[i];

        if(!isspace(ch)){
            ch = (unsigned char)tolower(ch);

            if(freq[ch] == second){
                printf("Second most frequent character: %c\n", ch);
                printf("Frequency: %d\n", second);
                found = 1;
                break;
            }
        }
    }

    if(!found){
        printf("No valid result exists.\n");
    }
}

/* This function checks whether two strings are anagrams.
   It ignores spaces and letter case, then compares character frequencies. */
void checkAnagramStrings(){
    char s1[Max], s2[Max];
    int freq[256] = {0};
    int i;
    unsigned char ch;

    printf("Roll no: %s Name: %s\n", ROLL, STUDENT_NAME);

    printf("Enter first string: ");
    fgets(s1, Max, stdin);
    removeNewline(s1);

    printf("Enter second string: ");
    fgets(s2, Max, stdin);
    removeNewline(s2);

    for(i = 0; s1[i] != '\0'; i++){
        ch = (unsigned char)s1[i];

        if(!isspace(ch)){
            freq[(unsigned char)tolower(ch)]++;
        }
    }

    for(i = 0; s2[i] != '\0'; i++){
        ch = (unsigned char)s2[i];

        if(!isspace(ch)){
            freq[(unsigned char)tolower(ch)]--;
        }
    }

    for(i = 0; i < 256; i++){
        if(freq[i] != 0){
            printf("The strings are not anagrams.\n");
            return;
        }
    }

    printf("The strings are anagrams.\n");
}

/* This function finds the longest palindromic substring.
   It checks substrings by expanding around their middle character or middle pair.
   If multiple substrings have the same length, the first one is kept. */
void longestPalindromicSubstring(char s[]){
    int n = strlen(s);
    int start = 0, maxLen = 0;
    int i, left, right, len;

    printf("Roll no: %s Name: %s\n", ROLL, STUDENT_NAME);

    for(i = 0; i < n; i++){

        left = i;
        right = i;

        while(left >= 0 && right < n &&
              tolower((unsigned char)s[left]) ==
              tolower((unsigned char)s[right])){

            len = right - left + 1;

            if(len > maxLen){
                maxLen = len;
                start = left;
            }

            left--;
            right++;
        }

        left = i;
        right = i + 1;

        while(left >= 0 && right < n &&
              tolower((unsigned char)s[left]) ==
              tolower((unsigned char)s[right])){

            len = right - left + 1;

            if(len > maxLen){
                maxLen = len;
                start = left;
            }

            left--;
            right++;
        }
    }

    if(maxLen == 0){
        printf("No valid palindrome exists.\n");
    }else{
        printf("Longest palindromic substring: ");

        for(i = start; i < start + maxLen; i++){
            printf("%c", s[i]);
        }

        printf("\nLength: %d\n", maxLen);
    }
}

/* This function finds the word that occurs most frequently.
   Words are compared without considering letter case, and the first word
   with the maximum frequency is displayed. */
void mostFrequentWord(char s[]){
    char words[Max][Max];
    int freq[Max] = {0};
    char temp[Max];
    int count = 0, i = 0, j, k;
    int best = 0, bestIndex = -1;

    printf("Roll no: %s Name: %s\n", ROLL, STUDENT_NAME);

    while(s[i] != '\0'){
        while(s[i] == ' '){
            i++;
        }

        if(s[i] == '\0'){
            break;
        }

        j = 0;

        while(s[i] != '\0' && s[i] != ' '){
            temp[j++] = s[i++];
        }

        temp[j] = '\0';

        for(j = 0; temp[j] != '\0'; j++){
            temp[j] = tolower((unsigned char)temp[j]);
        }

        for(k = 0; k < count; k++){
            if(strcmp(words[k], temp) == 0){
                break;
            }
        }

        if(k == count){
            strcpy(words[count], temp);
            freq[count] = 1;
            count++;
        }else{
            freq[k]++;
        }
    }

    for(i = 0; i < count; i++){
        if(freq[i] > best){
            best = freq[i];
            bestIndex = i;
        }
    }

    if(bestIndex == -1){
        printf("No words found in the string.\n");
    }else{
        printf("Most frequent word: %s\n", words[bestIndex]);
        printf("Frequency: %d\n", best);
    }
}

/* This function finds the longest substring without repeating characters.
   It checks every possible starting position and keeps the first longest result. */
void longestSubstringWithoutRepeating(char s[]){
    int n = strlen(s);
    int start = 0, maxLen = 0;
    int i, j, k, repeated;

    printf("Roll no: %s Name: %s\n", ROLL, STUDENT_NAME);

    for(i = 0; i < n; i++){
        int seen[256] = {0};

        for(j = i; j < n; j++){
            unsigned char ch = (unsigned char)s[j];
            repeated = 0;

            if(seen[ch]){
                repeated = 1;
            }

            if(repeated){
                break;
            }

            seen[ch] = 1;

            if(j - i + 1 > maxLen){
                maxLen = j - i + 1;
                start = i;
            }
        }
    }

    if(maxLen == 0){
        printf("No valid substring exists.\n");
    }else{
        printf("Longest substring without repeating characters: ");

        for(k = start; k < start + maxLen; k++){
            printf("%c", s[k]);
        }

        printf("\nLength: %d\n", maxLen);
    }
}

int main(){

    /* No parameters are required here. The menu keeps running until the user
       selects Exit, and each choice calls the required string operation. */

    int choice;

    printf("Roll no: %s Name: %s\n", ROLL, STUDENT_NAME);

    inputString(str);

    while(1){

        printf("\n");
        printf("Roll no: %s Name: %s\n", ROLL, STUDENT_NAME);

        printf("\nSelect an option below:-\n");
        printf("1. Reverse Each Word\n");
        printf("2. Remove Duplicate Words\n");
        printf("3. Find the Second Most Frequent Character\n");
        printf("4. Check Anagram Strings\n");
        printf("5. Find the Longest Palindromic Substring\n");
        printf("6. Find the Most Frequent Word\n");
        printf("7. Find the Longest Substring Without Repeating Characters\n");
        printf("8. Exit The Program\n");

        printf("\nEnter Your choice: ");
        if(scanf("%d", &choice) != 1){
            printf("Invalid input. Please enter a number.\n");
            break;
        }

        getchar();

        switch(choice){

            case 1:
                reverseEachWord(str);
                break;

            case 2:
                removeDuplicateWords(str);
                break;

            case 3:
                secondMostFrequentCharacter(str);
                break;

            case 4:
                checkAnagramStrings();
                break;

            case 5:
                longestPalindromicSubstring(str);
                break;

            case 6:
                mostFrequentWord(str);
                break;

            case 7:
                longestSubstringWithoutRepeating(str);
                break;

            case 8:
                printf("Exiting the program. Thank you!\n");
                return 0;

            default:
                printf("Invalid choice!!! Please select from 1 to 8.\n");
        }
    }

    return 0;
}

