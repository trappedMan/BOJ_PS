#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _info{
    char name[21];
    int ind;
}info;

info dir[100000];
info dir_n[100000];
int compare(const void* a, const void* b) {
    int i;

    info A = *(info*)a;
    info B = *(info*)b;

    for (i = 0; i < 21; i++) {
        if (A.name[i] > B.name[i]) return 1;
        if (A.name[i] < B.name[i]) return -1;
    }

    return 0;
} //오름차 정렬

int binary_search(info dir[], int n, char find[]) {
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    while (start <= end) {
        if (strcmp(dir[mid].name, find) == 0) return dir[mid].ind;
        else if (strcmp(dir[mid].name, find) == -1) start = mid + 1;
        else end = mid - 1;

        mid = (start + end) / 2;
    }
    return 0;
}

int main() {
    int n, m;
    int i, j, num = 0;
    char qes[21];

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        scanf("%s", dir[i].name);
        dir[i].ind = i + 1;

        dir_n[i] = dir[i];
    }

    qsort(dir, n, sizeof(dir[0]), compare);

    //문제
    for (i = 0; i < m; i++) {
        scanf("%s", qes);

        if ((int)qes[0] > 58) {
            printf("answer: %d\n", binary_search(dir, n, qes));
        }//숫자 반환

        else {
            num = 0;
            for (j = 0; j < strlen(qes); j++) {
                num = num * 10;
                num += qes[j] - '0';
            }
            printf("answer: %s\n", dir_n[num - 1].name);
        }//알파벳 반환
    }

    return 0;
}