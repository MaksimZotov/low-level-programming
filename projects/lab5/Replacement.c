#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int error(int number, char *msg) {
    printf("Ошибка %d: %s", number, msg);
    return number;
}

int argcIsCorrect(int argc) {
    if (argc != 4)
        return error(1, "Неверное количество аргументов командной строки");
}

int replaceWords(char *configFileName, char *inputFileName, char *outputFileName) {
    FILE *config, *input, *output;

    config = fopen(configFileName, "r");

    if (config == NULL)
        return error(2, "Файл конфигурации не удалось прочитать");

    char find[] = "find = \"";
    char change[] = "change = \"";

    int sizeFind = sizeof (find) / sizeof (char) - 1;
    int sizeChange = sizeof (change) / sizeof (char) - 1;

    char *findWord = (char *)malloc(0);

    if (findWord == NULL)
        return error(12, "Ошибка выделения памяти под findWord");

    char *changeWord = (char *)malloc(0);

    if (changeWord == NULL)
        return error(13, "Ошибка выделения памяти под changeWord");

    int sizeFindWord = -1;
    int sizeChangeWord = -1;

    int i = 0;
    char ch;

    while ((ch = fgetc(config)) != EOF) {
        if (ch == find[i] || ch == change[i]) {
            bool findWordIsBeingRead = (i == sizeFind - 1 && ch == find[i]);
            bool changeWordIsBeingRead = (i == sizeChange - 1 && ch == change[i]);
            if (findWordIsBeingRead || changeWordIsBeingRead) {
                if (sizeChangeWord != -1 && sizeFindWord != -1)
                    if (findWordIsBeingRead)
                        return error(3, "В файле конфигурации указано более одного слова для поиска");
                    else
                        return error(4, "В файле конфигурации указано более одного слова для замены");

                int j = 0;
                while ((ch = fgetc(config)) != '"') {
                    if (ch == EOF) {
                        fclose(config);
                        free(findWord);
                        free(changeWord);
                        if (findWordIsBeingRead)
                            return error(5, "В файле конфигурации слово для поиска не оканчивается на \"");
                        else
                            return error(6, "В файле конфигурации слово для замены не оканчивается на \"");
                    }
                    if (findWordIsBeingRead) {
                        findWord = realloc(findWord, (j + 1) * sizeof(char));

                        if (findWord == NULL)
                            return error(14, "Ошибка перераспределения памяти под findWord");

                        findWord[j] = ch;
                    }
                    else {
                        changeWord = realloc(changeWord, (j + 1) * sizeof(char));

                        if (changeWord == NULL)
                            return error(15, "Ошибка перераспределения памяти под changeWord");

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

    bool changeWordNotFound = sizeChangeWord == -1;
    bool findWordNotFound = sizeFindWord == -1;
    if (changeWordNotFound || findWordNotFound) {
        if (changeWordNotFound && findWordNotFound)
            return error(7, "В файле конфигурации не найдено команды ни для замены, ни для поиска");
        else if (changeWordNotFound)
            return error(8, "В файле конфигурации не найдено команды для замены");
        else
            return error(9, "В файле конфигурации не найдено команды для поиска");
    }

    input = fopen(inputFileName, "r");

    if (input == NULL)
        return error(10, "Файл с исходным текстом не удалось прочитать");

    output = fopen(outputFileName, "w");

    if (output == NULL) {
        fclose(input);
        return error(11, "Произошла ошибка при попытке работы с файлом, содержащим результат");
    }

    i = 0;
    char *curWord = (char *)malloc(0);

    if (curWord == NULL)
        return error(16, "Ошибка выделения памяти под curWord");

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