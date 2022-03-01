#ifndef LAB5E_TASK2_H
#define LAB5E_TASK2_H

#include "../string_.h"

void removeExtraSpaces(char *s) {
    char *begin = s;
    char *dst = begin;
    char last = *begin;

    while (*begin != '\0') {
        if (*begin != last || last != ' ')
            *dst++ = *begin;

        last = *begin++;
    }
    if (last == ' ')
        dst--;

    *dst = '\0';
}
void test_removeExtraSpaces_() {
    char s[100] = " ab   c  d e ";
    removeExtraSpaces(s);
    ASSERT_STRING("ab c d e", s);
}

void test_removeExtraSpaces_allSpaces() {
    char s[100] = "    ";
    removeExtraSpaces(s);
    ASSERT_STRING("    ", s);
}

void test_removeExtraSpaces_stringIsEmpty() {
    char s[100] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_();
    test_removeExtraSpaces_allSpaces();
    test_removeExtraSpaces_stringIsEmpty();
}
#endif
