#ifndef LAB5E_TASK8_H
#define LAB5E_TASK8_H

#include "../string_.h"

bool isWordPalindrome(WordDescriptor word) {
    word.end--;
    while (word.end - word.begin > 0) {
        if (word.begin != word.end) {
            printf("%s %s \n", word.begin, word.end);
            return false;
        }
        word.begin++;
        word.end--;
    }
    return true;
}

int howManyWordsPalindromes(char *string) {
    WordDescriptor word = {string, string};
    int countPalindromes = 0;
    while (*string != '\0') {
        if (*string == ',') {
            if (isWordPalindrome(word))
                countPalindromes++;
            word.begin = word.end + 1;
        }
        word.end++;
        string++;
    }
    return countPalindromes;
}

void test_howManyWordsPalindromes() {
    char s[] = "abcba";
    assert(howManyWordsPalindromes(s) == 1);
}

#endif
