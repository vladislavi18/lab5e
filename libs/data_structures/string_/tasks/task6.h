#ifndef LAB5E_TASK6_H
#define LAB5E_TASK6_H

#include "../string_.h"

bool areWordsOrdered(char *string) {
    WordDescriptor word1;
    WordDescriptor word2;
    if (getWord(string, &word1)) {
        word2 = word1;
        while (getWord(string, &word1)) {
            if (areWordsEqual(word1, word2) < 0)
                return false;
            word2 = word1;
            string = word1.end;
        }
        return true;
    } else
        return true;
}

void test_areWordsOrdered_stringIsEmpty() {
    char s[] = "";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_oneWordInString() {
    char s[] = "dream";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_NotorderedString() {
    char s[] = "pass op";
    assert(areWordsOrdered(s) == false);
}

void test_areWordsOrdered_TwoWordsEqual() {
    char s[] = "pass pass";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_orderedString() {
    char s[] = "a ab baaa ca cd";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_task6() {
    test_areWordsOrdered_stringIsEmpty();
    test_areWordsOrdered_oneWordInString();
    test_areWordsOrdered_NotorderedString();
    test_areWordsOrdered_TwoWordsEqual();
    test_areWordsOrdered_orderedString();
}

#endif
