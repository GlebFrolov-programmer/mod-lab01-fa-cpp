// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    const char* wordStart = nullptr;
    bool inWord = false;
    // Проходим по всей строке
    while (*str != '\0') {
        if (std::isalpha(static_cast<unsigned char>(*str))) {
            if (!inWord) {
                wordStart = str;
                inWord = true;
            }
        } else if (std::isdigit(static_cast<unsigned char>(*str))) {
            wordStart = nullptr;
            inWord = false;
        } else if (inWord) {
            if (wordStart) {
                count++;
            }
            inWord = false;
        }
        ++str;
    }
    // Проверяем, если последнее слово не заканчивается на пробел
    if (inWord && wordStart) {
        count++; 
    }
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool isWordStart = true;
    bool validWord = true;

    while (*str) {
        if (isWordStart && std::isupper(static_cast<unsigned char>(*str))) {
            validWord = true;     // Starting with an uppercase letter
        } else if (!std::islower(static_cast<unsigned char>(*str))) {
            validWord = false;
        }
        if (std::isspace(static_cast<unsigned char>(*str)) || *(str + 1) == '\0') {
            if (validWord && !isWordStart) {
                count++;
            }
            isWordStart = true;
            validWord = true;
        } else {
            isWordStart = false;
        }
        str++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int wordCount = 0;
    unsigned int totalLength = 0;
    unsigned int wordLength = 0;
    while (*str != '\0') {
        if (std::isalpha(static_cast<unsigned char>(*str))) {
            wordLength++;
        } else {
            if (wordLength > 0) {
                // End of a word
                wordCount++;
                totalLength += wordLength;
                wordLength = 0;
            }
        }
        str++;
    }
    if (wordLength > 0) {
        wordCount++;
        totalLength += wordLength;
    }
    // Подсчитываем среднюю длину слова
    float average = wordCount > 0 ? (float)totalLength / (float)wordCount : 0;
    return (unsigned int)(average + 0.5);
}
