#include <stdio.h>
#include <stdlib.h>
#include "Error.h"

int argcIsCorrect(int argc) {
    if (argc != 4)
        return error(1, "Неверное количество аргументов командной строки. Ожидается 3 аргемента вида:\n"
                        "путь\\к\\конфигурации путь\\к\\входному\\тексту путь\\к\\выходному\\тексту");
    else
        return 0;
}

int replaceWords(char *inputFileName, char *outputFileName, char *findWord, char *changeWord, int sizeFindWord, int sizeChangeWord) {
    FILE *input, *output;

    input = fopen(inputFileName, "r");

    if (input == NULL) {
        int errorCode = error(10, "Файл с исходным текстом не удалось прочитать. Имя введенного входного файла:\n");
        printf("%s", inputFileName);
        return errorCode;
    }

    output = fopen(outputFileName, "w");

    if (output == NULL) {
        fclose(input);
        int errorCode = error(11, "Произошла ошибка при попытке работы с файлом, содержащим результат. Имя введенного выходного файла:\n");
        printf("%s", outputFileName);
        return errorCode;
    }

    char *curWord = (char *)malloc(0);

    if (curWord == NULL) {
        return error(16, "Ошибка выделения памяти под curWord");
    }

    int i = 0;
    char ch;
    while ((ch = fgetc(input)) != EOF) {
        if (ch == findWord[i]) {
            curWord = realloc(curWord, (i + 1) * sizeof(char));

            if (curWord == NULL)
                return error(17, "Ошибка перераспределения памяти под curWord");

            curWord[i] = ch;
            if (i == sizeFindWord - 1) {
                for (int j = 0; j < sizeChangeWord; j++)
                    fputc(changeWord[j], output);
                i = 0;
            } else i++;
        } else if (i != 0) {
            for (int j = 0; j < i; j++)
                fputc(curWord[j], output);
            if (ch != findWord[0]) {
                fputc(ch, output);
                i = 0;
            } else {
                curWord = realloc(curWord, sizeof(char));

                if (curWord == NULL)
                    return error(17, "Ошибка перераспределения памяти под curWord");

                curWord[0] = ch;
                i = 1;
            }
        } else {
            fputc(ch, output);
            i = 0;
        }
    }

    fclose(input);
    fclose(output);

    free(curWord);

    printf("Слова были успешно заменены");

    return 0;
}