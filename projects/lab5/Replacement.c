#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int argcIsCorrect(int argc) {
    if (argc != 4) {
        printf("Ошибка 1: Неверное количество аргументов командной строки");
        return 1;
    }
}

int replaceWords(char *configFileName, char *inputFileName, char *outputFileName) {
    FILE *config, *input, *output;

    config = fopen(configFileName, "r");
    if (config == NULL) {
        printf("Ошибка 2: Файл конфигурации не удалось прочитать");
        return 2;
    }

    char find[] = "find = \"";
    char change[] = "change = \"";
    int sizeFind = sizeof (find) / sizeof (char) - 1;
    int sizeChange = sizeof (change) / sizeof (char) - 1;
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int sizeFindWord;
    int sizeChangeWord;

    int i = 0;
    char ch;

    while ((ch = fgetc(config)) != EOF) {
        if (ch == find[i] || ch == change[i]) {
            bool findWordIsBeingRead = (i == sizeFind - 1 && ch == find[i]);
            bool changeWordIsBeingRead = (i == sizeChange - 1 && ch == change[i]);
            if (findWordIsBeingRead || changeWordIsBeingRead) {
                int j = 0;
                while ((ch = fgetc(config)) != '"') {
                    if (ch == EOF) {
                        fclose(config);
                        free(findWord);
                        free(changeWord);
                        printf("Ошибка 3: Файл конфигурации не является корректным");
                        return 3;
                    }
                    if (findWordIsBeingRead) {
                        findWord = realloc(findWord, (j + 1) * sizeof(char));
                        findWord[j] = ch;
                    }
                    else {
                        changeWord = realloc(changeWord, (j + 1) * sizeof(char));
                        changeWord[j] = ch;
                    }
                    j++;
                }
                if (findWordIsBeingRead) sizeFindWord = j;
                else sizeChangeWord = j;
            } else i++;
        } else i = 0;
    }

    fclose(config);

    input = fopen(inputFileName, "r");
    if (input == NULL) {
        printf("Ошибка 4: Файл с исходным текстом не удалось прочитать");
        return 4;
    }

    output = fopen(outputFileName, "w");
    if (output == NULL) {
        fclose(input);
        printf("Ошибка 5: Произошла ошибка при попытке работы с файлом, содержащим результат");
        return 5;
    }

    i = 0;
    char *curWord = (char *)malloc(0);
    while ((ch = fgetc(input)) != EOF) {
        if (ch == findWord[i]) {
            curWord = realloc(curWord, (i + 1) * sizeof(char));
            curWord[i] = ch;
            if (i == sizeFindWord - 1) {
                for (int j = 0; j < sizeChangeWord; j++)
                    fputc(changeWord[j], output);
                i = 0;
            } else i++;
        } else if (i != 0) {
            for (int j = 0; j < i; j++)
                fputc(curWord[j], output);
            fputc(ch, output);
            i = 0;
        } else {
            fputc(ch, output);
            i = 0;
        }
    }

    fclose(input);
    fclose(output);

    free(curWord);
    free(findWord);
    free(changeWord);

    printf("Слова были успешно заменены");

    return 0;
}