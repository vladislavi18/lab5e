#ifndef LAB5E_TASK8_H
#define LAB5E_TASK8_H

#include "../string_.h"

bool isWordPalindrome(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            return false;
        begin++;
        end--;
    }
    return true;
}

size_t howManyWordsPalindromes(char *s) {
    char *endS = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPalindromes = 0;

    char *commaPos = find(beginSearch, endS, ',');
    bool lastComma = *commaPos == '\0' && endS - beginSearch != 0;
    while (*commaPos != '\0' || lastComma) {
        beginSearch = findNonSpace(beginSearch);

        countPalindromes += isWordPalindrome(beginSearch, commaPos);

        beginSearch = commaPos + 1;

        if (lastComma)
            break;

        commaPos = find(beginSearch, endS, ',');
        lastComma = *commaPos == '\0';
    }
    return countPalindromes;
}

void test_howManyWordsPalindromes_stringIsEmpty() {
    char s[] = "";
    assert(howManyWordsPalindromes(s) == 0);
}

void test_howManyWordsPalindromes_oneWOrdIsPalindrome() {
    char s[] = "abcba";
    assert(howManyWordsPalindromes(s) == 1);
}

void test_howManyWordsPalindromes_twoWordsIsPalindrome() {
    char s[] = "abcba,bacab";
    assert(howManyWordsPalindromes(s) == 2);
}

void test_howManyWordsPalindromes_onePallAndOneNot() {
    char s[] = "abcba,abcd";
    assert(howManyWordsPalindromes(s) == 1);
}

void test_howManyWordsPalindromes_OneSymbol() {
    char s[] = "a";
    assert(howManyWordsPalindromes(s) == 1);
}

void test_howManyWordsPalindromes() {
    test_howManyWordsPalindromes_stringIsEmpty();
    test_howManyWordsPalindromes_oneWOrdIsPalindrome();
    test_howManyWordsPalindromes_twoWordsIsPalindrome();
    test_howManyWordsPalindromes_onePallAndOneNot();
    test_howManyWordsPalindromes_OneSymbol();
}
#endif
