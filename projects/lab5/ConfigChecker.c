#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Error.h"

int showExpectedConfig(int errorCode, char *msg) {
    error(errorCode, msg);
    printf("\nОжидаемый вид файла конфигурации:\nfind = \"findWord\"\nchange = \"changeWord\"");
    return errorCode;
}

int getFindWordAndChangeWord(char *configFileName, char *findWord, char *changeWord, int *sizeFindWord, int *sizeChangeWord) {
    FILE *config = fopen(configFileName, "r");

    if (config == NULL) {
        int errorCode = error(2, "Файл конфигурации не удалось прочитать. Имя введенного файла конфигурации:\n");
        printf("%s", configFileName);
        return errorCode;
    }

    char find[] = "find = \"";
    char change[] = "change = \"";

    int sizeFind = sizeof (find) / sizeof (char) - 1;
    int sizeChange = sizeof (change) / sizeof (char) - 1;

    *sizeFindWord = -1;
    *sizeChangeWord = -1;

    int i = 0;
    char ch;

    while ((ch = fgetc(config)) != EOF) {
        if (ch == find[i] || ch == change[i]) {
            bool findWordIsBeingRead = (i == sizeFind - 1 && ch == find[i]);
            bool changeWordIsBeingRead = (i == sizeChange - 1 && ch == change[i]);
            if (findWordIsBeingRead || changeWordIsBeingRead) {
                if (*sizeChangeWord != -1 && *sizeFindWord != -1) {
                    fclose(config);
                    if (findWordIsBeingRead)
                        return showExpectedConfig(3, "В файле конфигурации указано более одного слова для поиска");
                    else
                        return showExpectedConfig(4, "В файле конфигурации указано более одного слова для замены");
                }

                int j = 0;
                while ((ch = fgetc(config)) != '"') {
                    if (ch == EOF) {
                        fclose(config);
                        if (findWordIsBeingRead)
                            return showExpectedConfig(5, "В файле конфигурации слово для поиска не оканчивается на \"");
                        else
                            return showExpectedConfig(6, "В файле конфигурации слово для замены не оканчивается на \"");
                    }
                    if (findWordIsBeingRead) {
                        findWord = realloc(findWord, (j + 1) * sizeof(char));

                        if (findWord == NULL) {
                            fclose(config);
                            return error(14, "Ошибка перераспределения памяти под findWord");
                        }

                        findWord[j] = ch;
                    }
                    else {
                        changeWord = realloc(changeWord, (j + 1) * sizeof(char));

                        if (changeWord == NULL) {
                            fclose(config);
                            return error(15, "Ошибка перераспределения памяти под changeWord");
                        }

                        changeWord[j] = ch;
                    }
                    j++;
                }
                if (findWordIsBeingRead) *sizeFindWord = j;
                else *sizeChangeWord = j;
            } else i++;
        } else i = 0;
    }

    fclose(config);

    bool changeWordNotFound = *sizeChangeWord == -1;
    bool findWordNotFound = *sizeFindWord == -1;
    if (changeWordNotFound || findWordNotFound) {
        if (changeWordNotFound && findWordNotFound)
            return showExpectedConfig(7, "В файле конфигурации не найдено команды ни для замены, ни для поиска");
        else if (changeWordNotFound)
            return showExpectedConfig(8, "В файле конфигурации не найдено команды для замены");
        else
            return showExpectedConfig(9, "В файле конфигурации не найдено команды для поиска");
    }

    return 0;
}