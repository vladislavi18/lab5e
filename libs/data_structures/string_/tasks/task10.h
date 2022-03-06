#ifndef LAB5E_TASK10_H
#define LAB5E_TASK10_H

#include "../string_.h"

void task10(char *string) {
    *copy(string, getEndOfString(string), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);
    char *copyS = string;
    for (int i = _bag.size - 1; i >= 0; --i) {
        string = copy(_bag.words[i].begin, _bag.words[i].end, string);
        *string++ = ' ';
    }
    if (string != copyS)
        --string;
    *string = '\0';
}

void test_task10_stringIsEmpty() {
    char s[MAX_STRING_SIZE] = "";
    task10(s);
    ASSERT_STRING("", s);
}

void test_task10_oneWord() {
    char s[MAX_STRING_SIZE] = "hello";
    task10(s);
    ASSERT_STRING("hello", s);
}

void test_task10_manyWords() {
    char s[MAX_STRING_SIZE] = "hello world!";
    task10(s);
    ASSERT_STRING("world! hello", s);
}

void test_task10_veryVeryVeryManyWords() {
    char s[MAX_STRING_SIZE] = "hello world! Buy word";
    task10(s);
    ASSERT_STRING("word Buy world! hello", s);
}

void test_task10() {
    test_task10_stringIsEmpty();
    test_task10_oneWord();
    test_task10_manyWords();
    test_task10_veryVeryVeryManyWords();

}

#endif
