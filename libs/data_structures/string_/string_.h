#ifndef LAB5E_STRING__H
#define LAB5E_STRING__H

#include "../../algorithms/algorithms.h"
#include <ctype.h>
#include <assert.h>
#include <memory.h>
#include <malloc.h>

// возвращает количество символов в строке
// (не считая ноль-символ)
size_t strlen(char *begin);

// возвращает указатель
// на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end не включая end
char *find(char *begin, char *end, int ch);

//  возвращает указатель на первый
// символ, отличный от пробельных, расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом
// если символ не найден, возвращается адрес первого ноль-символа
char *findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ
char *findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend.
// если символ не найден, возвращается адрес rend
char *findNonSpaceReverse(char *rbegin, const char *rend);

//  возвращает указатель на первый пробельный символ справа,
//  расположенный на ленте памяти, начиная с rbegin и заканчивая rend. Если символ не найден,
//  возвращается адрес rend
char *findSpaceReverse(char *rbegin, const char *rend);

// Функция возвращает отрицательное значение, если lhs
// располагается до rhs, значение 0, если lhs и rhs
// равны, иначе – положительное значение.
int strcmp_(const char *lhs, const char *rhs);

// записывает по адресу beginDestination
// фрагмент памяти, начиная с адреса beginSource до endSource.
// возвращает указатель на следующий свободный фрагмент памяти в
// destination
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

// записывает по адресу
// beginDestination элементы из фрагмента памяти начиная с beginSource
// заканчивая endSource, удовлетворяющие функции-предикату f. Функция
// возвращает указатель на следующий свободный для записи фрагмент в памяти.
char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

// записывает по адресу
// beginDestination элементы из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончанию работы функции.
char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

#define MAX_STRING_SIZE 100
char stringBuffer[MAX_STRING_SIZE + 1];

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

// функция getWord вернёт значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова:
int getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

#endif //LAB5E_STRING__H