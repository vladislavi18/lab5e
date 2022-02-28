#ifndef LAB5E_TASK1_H
#define LAB5E_TASK1_H

#include "../string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_digitToStartTransform_oneWord() {
    char s[] = " H i 1 2 3 ";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}


#endif
