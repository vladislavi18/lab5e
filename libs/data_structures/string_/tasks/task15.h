#ifndef LAB5E_TASK15_H
#define LAB5E_TASK15_H

#include "../string_.h"

void lineWithWordsOtherThanLast(char *string) {
    char *copyS1 = string;
    char *copyS2 = string;
    WordDescriptor lastWord;
    getWordReverse(getEndOfString(string), string - 1, &lastWord);
    WordDescriptor currentWord;
    while (getWord(copyS1, &currentWord)) {
        if (areWordsEqual(currentWord, lastWord) != 0) {
            string = copy(currentWord.begin, currentWord.end, string);
            *string++ = ' ';
        }
        copyS1 = currentWord.end;
    }
    if (string != copyS2)
        --string;
    *string = '\0';
}

void test_lineWithWordsOtherThanLast_StringIsEmpty() {
    char s[MAX_STRING_SIZE] = "";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("", s);
}

void test_lineWithWordsOtherThanLast_oneWord() {
    char s[MAX_STRING_SIZE] = "word";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("", s);
}

void test_lineWithWordsOtherThanLast_twoSameWords() {
    char s[MAX_STRING_SIZE] = "word word";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("", s);
}

void test_lineWithWordsOtherThanLast_twoNotSameWords() {
    char s[MAX_STRING_SIZE] = "hello world";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("hello", s);
}

void test_lineWithWordsOtherThanLast_() {
    char s[MAX_STRING_SIZE] = "Moi Lolita je mappelle Lolita";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("Moi je mappelle", s);
}

void test_lineWithWordsOtherThanLast_task15() {
    test_lineWithWordsOtherThanLast_StringIsEmpty();
    test_lineWithWordsOtherThanLast_oneWord();
    test_lineWithWordsOtherThanLast_twoSameWords();
    test_lineWithWordsOtherThanLast_twoNotSameWords();
    test_lineWithWordsOtherThanLast_();
}

#endif
