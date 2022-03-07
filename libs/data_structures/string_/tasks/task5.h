#ifndef LAB5E_TASK5_H
#define LAB5E_TASK5_H

#include "../string_.h"

bool comparisonWords(char *string, char *word) {
    char *copyString = string;
    char *copyWord = word;
    while (*copyString != ' ' && *copyString != '\0') {
        if (*copyString != *copyWord)
            return false;
        copyString++;
        copyWord++;
    }
    return true;
}

void replacesWord(char *source, WordDescriptor word1, WordDescriptor word2, size_t w2Size) {
    while (*w2Size != 0) {
        *source = *word2.begin;
        w2Size--;
    }
    while (word1.end - 1 - word2.begin != 0) {
        *source = ' ';
        word2.begin++;
    }
}

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
    char *copySource = source;
    size_t copyW2Size = w2Size;
    if (comparisonWords(copySource, w1)) {
        replacesWord(copySource, word1, word2, copyW2Size);
    }
}

#endif
