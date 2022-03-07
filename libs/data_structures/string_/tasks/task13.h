#ifndef LAB5E_TASK13_H
#define LAB5E_TASK13_H

#include "../string_.h"

bool wordsInStringAreEqual(char *string1) {
    getBagOfWords(&_bag, string1);
    for (int i = 0; i < _bag.size; ++i)
        for (int j = i + 1; j < _bag.size; ++j)
            if (areWordsEqual(_bag.words[i], _bag.words[j]) == 0)
                return true;

    return false;
}

void test_wordsInStringAreEqual_StringIsEmpty() {
    char s[MAX_STRING_SIZE] = "";
    assert(wordsInStringAreEqual(s) == false);
}

void test_wordsInStringAreEqual_IsWordsEqual() {
    char s[MAX_STRING_SIZE] = "together Forever and never to part together forever we two";
    assert(wordsInStringAreEqual(s) == true);
}

void test_wordsInStringAreEqual_NotWordsEqual() {
    char s[MAX_STRING_SIZE] = "Together Forever and never to part together forever we two";
    assert(wordsInStringAreEqual(s) == true);
}

void test_wordsInStringAreEqual_TwoWordsEqual() {
    char s[MAX_STRING_SIZE] = "together forever and never to part together forever we two";
    assert(wordsInStringAreEqual(s) == true);
}

void test_wordsInStringAreEqual_task13() {
    test_wordsInStringAreEqual_StringIsEmpty();
    test_wordsInStringAreEqual_IsWordsEqual();
    test_wordsInStringAreEqual_NotWordsEqual();
    test_wordsInStringAreEqual_TwoWordsEqual();
}

#endif
