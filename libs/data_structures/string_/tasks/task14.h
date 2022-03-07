#ifndef LAB5E_TASK14_H
#define LAB5E_TASK14_H

#include "../string_.h"

int cmp(const void *a, const void *b) {
    return *(const char *) a - *(const char *) b;
}

bool areWordsFromSameLetters(char *string) {
    *copy(string, getEndOfString(string), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);

    for (int i = 0; i < _bag.size; ++i)
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words[i].begin, sizeof(char), cmp);

    return wordsInStringAreEqual(stringBuffer);
}

void test_areWordsFromSameLetters_StringIsEmpty() {
    char s[MAX_STRING_SIZE] = "";
    assert(areWordsFromSameLetters(s) == false);
}

void test_areWordsFromSameLetters_oneWordInString() {
    char s[MAX_STRING_SIZE] = "abc";
    assert(areWordsFromSameLetters(s) == false);
}

void test_areWordsFromSameLetters_IsSameLettersInWords() {
    char s[MAX_STRING_SIZE] = "abc cab";
    assert(areWordsFromSameLetters(s) == true);
}

void test_areWordsFromSameLetters_NotSameLettersInWord() {
    char s[MAX_STRING_SIZE] = "abc cad";
    assert(areWordsFromSameLetters(s) == false);
}

void test_areWordsFromSameLetters_MoreIsSameLettersInWords() {
    char s[MAX_STRING_SIZE] = "abc cad bac cab dac";
    assert(areWordsFromSameLetters(s) == true);
}

void test_areWordsFromSameLetters_task14() {
    test_areWordsFromSameLetters_StringIsEmpty();
    test_areWordsFromSameLetters_oneWordInString();
    test_areWordsFromSameLetters_IsSameLettersInWords();
    test_areWordsFromSameLetters_NotSameLettersInWord();
    test_areWordsFromSameLetters_MoreIsSameLettersInWords();
}

#endif
