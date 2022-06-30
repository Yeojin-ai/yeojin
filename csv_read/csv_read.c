/*csv읽어오는 함수(미완)*/
#include <stdio.h>
#include <string.h>
#include "csv_practice.h"

int csv_read() {
    char str_tmp[1024];
    FILE* pFile = NULL;

    pFile = fopen("apt_realprice.csv", "r");
    if (pFile != NULL)
    {
        while (!feof(pFile)) {
            fgets(str_tmp, 1024, pFile);
            printf("%s", str_tmp);
        }
    }
    fclose(pFile);

    return 0;
}
