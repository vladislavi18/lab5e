#ifndef LAB5E_TASK5_H
#define LAB5E_TASK5_H

#include "../string_.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), stringBuffer);
        readPtr = stringBuffer;
        recPtr = source;
    }

    WordDescriptor curWord;
    while (getWord(readPtr, &curWord)) {
        recPtr = copy(readPtr, curWord.begin, recPtr);
        if (areWordsEqual(curWord, word1) == 0) {
            recPtr = copy(word2.begin, word2.end, recPtr);
        } else {
            recPtr = copy(curWord.begin, curWord.end, recPtr);
        }
        readPtr = curWord.end;
    }

    *recPtr = '\0';
}

void test_replace_stringsAreEmpty() {
    char s[MAX_STRING_SIZE] = "";
    char *word1 = "";
    char *word2 = "";
    replace(s, word1, word2);
    ASSERT_STRING("", s);
}

void test_replace_stringIsEmpty() {
    char s[MAX_STRING_SIZE] = "";
    char *word1 = "abc";
    char *word2 = "cab";
    replace(s, word1, word2);
    ASSERT_STRING("", s);
}

void test_replace_firstWordLessThenSecond() {
    char s[MAX_STRING_SIZE] = "aaa bbb ccc aaa";
    char *word1 = "aaa";
    char *word2 = "small";
    replace(s, word1, word2);
    ASSERT_STRING("small bbb ccc small", s);
}

void test_replace_firstWordIsGreaterThenSecond() {
    char s[MAX_STRING_SIZE] = "hello world hello";
    char *word1 = "hello";
    char *word2 = "bye";
    replace(s, word1, word2);
    ASSERT_STRING("bye world bye", s);
}

void test_replace_firstWordIsNotInString() {
    char s[MAX_STRING_SIZE] = "hello world hello";
    char *word1 = "aaa";
    char *word2 = "bye";
    replace(s, word1, word2);
    ASSERT_STRING("hello world hello", s);
}

void test_replace_task5() {
    test_replace_stringsAreEmpty();
    test_replace_stringIsEmpty();
    test_replace_firstWordLessThenSecond();
    test_replace_firstWordIsGreaterThenSecond();
    test_replace_firstWordIsNotInString();
}

#endif
