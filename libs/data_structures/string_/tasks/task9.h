#ifndef LAB5E_TASK9_H
#define LAB5E_TASK9_H
#include "../string_.h"

char *alternatingWords(char *string1, char *string2, char *s) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *sCopy = s;
    char *beginSearch1 = string1, *beginSearch2 = string2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if(isW1Found) {
            s = copy(word1.begin, word1.end, s);
            *s++ = ' ';
            beginSearch1 = word1.end;
        }
        if(isW2Found) {
            s = copy(word2.begin, word2.end, s);
            *s++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    if(s != sCopy)
        --s;
    *s = '\0';
    return sCopy;
}

void test_alternatingWords_stringsIsEmpty() {
    char s1[] = "";
    char s2[] = "";
    char s3[MAX_STRING_SIZE];
    ASSERT_STRING("", alternatingWords(s1,s2,s3));
}

void test_alternatingWords_oneStringIsEmty() {
    char s1[] = "word";
    char s2[] = "";
    char s3[MAX_STRING_SIZE];
    ASSERT_STRING("", alternatingWords(s1,s2,s3));
}

void test_alternatingWords_twoStringsNotEmpty() {
    char s1[] = "bara bara";
    char s2[] = "bere bere";
    char s3[MAX_STRING_SIZE];
    ASSERT_STRING("bara bere bara bere", alternatingWords(s1,s2,s3));
}

void test_alternatingWords_thereAreSpacesInStrings() {
    char s1[] = "   ";
    char s2[] = "   ";
    char s3[MAX_STRING_SIZE];
    ASSERT_STRING("", alternatingWords(s1,s2,s3));
}

void test_alternatingWords_task9() {
    test_alternatingWords_stringsIsEmpty();
    test_alternatingWords_oneStringIsEmty();
    test_alternatingWords_twoStringsNotEmpty();
    test_alternatingWords_thereAreSpacesInStrings();
}

#endif //LAB5E_TASK9_H
