// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;
    while (*str != '\0') {
        if (std::isalpha(static_cast<unsigned char>(*str))) {
            if (!inWord) {
                inWord = true;
            }
        } else if (std::isdigit(static_cast<unsigned char>(*str))) {
            hasDigit = true;
        } else {
            if (inWord && !hasDigit) {
                count++;
            }
            inWord = false;
            hasDigit = false;
        }
        str++;
    }
    if (inWord && !hasDigit) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool isWordStart = true;
    bool validWord = false;
    while (*str) {
        if (isWordStart && std::isupper(static_cast<unsigned char>(*str))) {
            validWord = true;
            isWordStart = false;
        } else if (std::islower(static_cast<unsigned char>(*str))) {
            if (!isWordStart && !validWord) {
                validWord = false;
            }
        }
        else if (std::isspace(static_cast<unsigned char>(*str))
            || *(str + 1) == '\0') {
            if (validWord) {
                count++;
            }
            isWordStart = true;
            validWord = false;
        } else {
            validWord = false;
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
    float average;
    if (wordCount > 0) {
        average = static_cast<float>(totalLength)/static_cast<float>(wordCount);
    } else {
        average = 0;
    }
    return (unsigned int)(average + 0.5);
}
