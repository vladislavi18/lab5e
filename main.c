#include <stdio.h>
#include "libs/data_structures/string_/string_.h"
#include "libs/data_structures/string_/tasks/task1.h"
#include "libs/data_structures/string_/tasks/task2.h"
#include "libs/data_structures/string_/tasks/task3.h"
#include "libs/data_structures/string_/tasks/task4.h"
#include "libs/data_structures/string_/tasks/task6.h"

void test_strlen_() {
    char s[11] = "fatalerror";
    assert(strlen(s) == 10);
}

void test_strlen_zeroElements() {
    char s[] = "";
    assert(strlen(s) == 0);
}

void test_strlen() {
    test_strlen_();
    test_strlen_zeroElements();
}

void test_find_notRepeatingElements() {
    char s[11] = "ilovepizza";
    char ch = 118;
    char *symbol = find(&s[0], &s[10], ch);
    assert(*symbol == s[3]);
}

void test_find_withRepeatingElementsNotNormal() {
    char s[12] = "ilovepvizza";
    char ch = 118;
    char *symbol = find(&s[0], &s[5], ch);
    assert(*symbol == s[6]);
}

void test_find() {
    test_find_notRepeatingElements();
    test_find_withRepeatingElementsNotNormal();
}

void test_findNonSpace_firstSymbolNotSpace() {
    char s[7] = "Pic Up";
    char *symbol = findNonSpace(&s[0]);
    assert(symbol == &s[0]);
}

void test_findNonSpace_thirdElementNotSpace() {
    char s[13] = "   the phone";
    char *symbol = findNonSpace(&s[0]);
    assert(symbol == &s[3]);
}

void test_findNonSpace_allElementsIsSpace() {
    char s[8] = "       ";
    char *symbol = findNonSpace(&s[0]);
    assert(symbol == &s[7]);
}

void test_findNonSpace() {
    test_findNonSpace_firstSymbolNotSpace();
    test_findNonSpace_thirdElementNotSpace();
    test_findNonSpace_allElementsIsSpace();
}

void test_findSpace_firstSpace() {
    char s[13] = " let me know";
    char *symbol = findSpace(&s[0]);
    assert(symbol == &s[0]);
}

void test_findSpace_SecondElementSpace() {
    char s[27] = "i dont wanna lose you girl";
    char *symbol = findSpace(&s[0]);
    assert(symbol == &s[1]);
}

void test_findSpace_allElementsIsntSpace() {
    char s[8] = "abcdefg";
    char *symbol = findSpace(&s[0]);
    assert(symbol == &s[7]);
}

void test_findSpace() {
    test_findSpace_firstSpace();
    test_findSpace_SecondElementSpace();
    test_findSpace_allElementsIsntSpace();
}

void test_test_findNonSpaceReverse_firstSymbolRightNotSpace() {
    char s[7] = "Pic Up";
    char *symbol = findNonSpaceReverse(&s[5], &s[-1]);
    assert(symbol == &s[5]);
}

void test_test_findNonSpaceReverse_thirdElementRightNotSpace() {
    char s[13] = "the phone   ";
    char *symbol = findNonSpaceReverse(&s[11], &s[-1]);
    assert(symbol == &s[8]);
}

void test_test_findNonSpaceReverse_allElementsIsSpace() {
    char s[8] = "       ";
    char *symbol = findNonSpaceReverse(&s[6], &s[-1]);
    assert(symbol == &s[-1]);
}

void test_findNonSpaceReverse() {
    test_test_findNonSpaceReverse_firstSymbolRightNotSpace();
    test_test_findNonSpaceReverse_thirdElementRightNotSpace();
    test_test_findNonSpaceReverse_allElementsIsSpace();
}

void test_findSpaceReverse_firstSpace() {
    char s[13] = "let me know ";
    char *symbol = findSpaceReverse(&s[11], &s[-1]);
    assert(symbol == &s[11]);
}

void test_findSpaceReverse_fifthElementSpace() {
    char s[27] = "i dont wanna lose you girl";
    char *symbol = findSpaceReverse(&s[25], &s[-1]);
    assert(symbol == &s[21]);
}

void test_findSpaceReverse_allElementsIsntSpace() {
    char s[8] = "abcdefg";
    char *symbol = findSpaceReverse(&s[6], &s[-1]);
    assert(symbol == &s[-1]);
}

void test_findSpaceReverse() {
    test_findSpaceReverse_firstSpace();
    test_findSpaceReverse_fifthElementSpace();
    test_findSpaceReverse_allElementsIsntSpace();
}

void test_strcmp_lhsMoreThenRhs() {
    char s1[5] = "abcd";
    char s2[3] = "ab";
    assert(strcmp_(s1, s2) > 0);
}

void test_strcmp_rhsMoreThenlhs() {
    char s1[3] = "ab";
    char s2[5] = "abcd";
    assert(strcmp_(s1, s2) < 0);
}

void test_strcmp_lhsEqualRhs() {
    char s1[5] = "abcd";
    char s2[5] = "abcd";
    assert(strcmp_(s1, s2) == 0);
}

void test_strcmp() {
    test_strcmp_lhsMoreThenRhs();
    test_strcmp_rhsMoreThenlhs();
    test_strcmp_lhsEqualRhs();
}

void test_copy() {
    char s1[8] = "history";
    char s2[10];
    char *a = copy(&s1[0], &s1[6], s2);
    assert(s2[0] == 'h');
    assert(s2[1] == 'i');
    assert(s2[2] == 's');
    assert(s2[3] == 't');
    assert(s2[4] == 'o');
    assert(s2[5] == 'r');
    assert(&s2[6] == a);
}

void test_copyIf_allElementsMatchCondition() {
    char s1[4] = "246";
    char s2[4];
    char *a = copyIf(&s1[0], &s1[2], s2, isEvenSymbol);
    assert(s2[0] == '2');
    assert(s2[1] == '4');
    assert(&s2[2] == a);
}

void test_copyIf_allElementsNotSatisfyCondition() {
    char s1[4] = "135";
    char s2[4];
    char s3[4];
    char *a = copy(&s2[0], &s2[2], s3);
    char *b = copyIf(&s1[0], &s1[2], s2, isEvenSymbol);
    assert(s2[0] == s3[0]);
    assert(s2[1] == s3[1]);
    assert(&s2[0] == b);
}

void test_copyIf_mixedElements() {
    char s1[7] = "123456";
    char s2[4];
    char *a = copyIf(&s1[0], &s1[5], s2, isEvenSymbol);
    assert(s2[0] == '2');
    assert(s2[1] == '4');
    assert(&s2[2] == a);
}

void test_copyIf() {
    test_copyIf_allElementsMatchCondition();
    test_copyIf_allElementsNotSatisfyCondition();
    test_copyIf_mixedElements();
}

void test_copyIfReverse_allElementsMatchCondition() {
    char s1[4] = "246";
    char s2[4];
    char *a = copyIfReverse(&s1[2], &s1[0], s2, isEvenSymbol);
    assert(s2[0] == '6');
    assert(s2[1] == '4');
    assert(&s2[2] == a);
}

void test_copyIfReverse_allElementsNotSatisfyCondition() {
    char s1[4] = "135";
    char s2[4];
    char s3[4];
    char *a = copy(&s2[0], &s2[2], s3);
    char *b = copyIfReverse(&s1[2], &s1[0], s2, isEvenSymbol);
    assert(s2[0] == s3[0]);
    assert(s2[1] == s3[1]);
    assert(&s2[0] == b);
}

void test_copyIfReverse_mixedElements() {
    char s1[7] = "123456";
    char s2[4];
    char *a = copyIfReverse(&s1[5], &s1[0], s2, isEvenSymbol);
    assert(s2[0] == '6');
    assert(s2[1] == '4');
    assert(s2[2] == '2');
    assert(&s2[3] == a);
}

void test_copyIfReverse() {
    test_copyIfReverse_allElementsMatchCondition();
    test_copyIfReverse_allElementsNotSatisfyCondition();
    test_copyIfReverse_mixedElements();
}

void test_functions() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}

void test_tasks() {
    test_removeNonLetters_task1();
    test_removeExtraSpaces_task2();
    test_digitToStartString_task3();
    test_replacesNumbersWithSpaces_task4();
    test_areWordsOrdered_task6();
}

void test() {
    test_functions();
    test_tasks();
}

int main() {
    test();

    return 0;
}
