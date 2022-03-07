#ifndef LAB5E_TASK19_H
#define LAB5E_TASK19_H

#include "../string_.h"

bool allLettersOfWordAreIncludedInString(char *string, char *word) {
    static char stringArray[255];

    if (*word == '\0' || *string == '\0')
        return false;
    while (*string != '\0') {
        stringArray[*string]++;
        string++;
    }
    while (*word != '\0') {
        if (!stringArray[*word])
            return false;
        word++;
    }
    return true;
}

void test_allLettersOfWordAreIncludedInString_hasEqualLetters() {
    char s[MAX_STRING_SIZE] = "abcde";
    char word[MAX_STRING_SIZE] = "de";

    assert(allLettersOfWordAreIncludedInString(s, word) == true);
}

void test_allLettersOfWordAreIncludedInString_hasNoEqualLetters() {
    char s[MAX_STRING_SIZE] = "abcde";
    char word[MAX_STRING_SIZE] = "def";

    assert(allLettersOfWordAreIncludedInString(s, word) == false);
}

void test_allLettersOfWordAreIncludedInString_spacesInString() {
    char s[MAX_STRING_SIZE] = "a b c d e f g t y u";
    char word[MAX_STRING_SIZE] = "abc";

    assert(allLettersOfWordAreIncludedInString(s, word) == true);
}

void test_allLettersOfWordAreIncludedInString_wordIsEmpty() {
    char s[MAX_STRING_SIZE] = "abc";
    char word[MAX_STRING_SIZE] = "";

    assert(allLettersOfWordAreIncludedInString(s, word) == false);
}

void test_allLettersOfWordAreIncludedInString_spaces() {
    char s[MAX_STRING_SIZE] = "abc";
    char word[MAX_STRING_SIZE] = "ab c";

    assert(allLettersOfWordAreIncludedInString(s, word) == true);
}

void test_allLettersOfWordAreIncludedInString() {
    test_allLettersOfWordAreIncludedInString_hasEqualLetters();
    test_allLettersOfWordAreIncludedInString_hasNoEqualLetters();
    test_allLettersOfWordAreIncludedInString_wordIsEmpty();
    test_allLettersOfWordAreIncludedInString_spacesInString();
    test_allLettersOfWordAreIncludedInString_spaces();
}

#endif
