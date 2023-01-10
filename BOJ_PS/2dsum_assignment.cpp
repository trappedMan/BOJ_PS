#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>


int A[1001][1001];
int cum[1001][1001];

int main() {

    FILE* in = fopen("input_assignment2.txt", "r");
    //FILE* in = fopen("input2.txt", "r");
    int n, m;
    fscanf(in, "%d %d", &m, &n);

    // 배열에 0값 삽입
    for (int i = 0; i < n; i++)
        A[i + 1][0] = 0;
    for (int i = 0; i < m; i++)
        A[0][i + 1] = 0;
    A[0][0] = 0;

    //
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            fscanf(in, "%d ", &tmp);
            A[i + 1][j + 1] = tmp;
        }
    }

    //start code
    for (int j = 0; j < m; j++)
        cum[1][j + 1] = cum[1][j] + A[1][j + 1];
    for (int i = 0; i < n; i++) 
        cum[i+1][1] = cum[i][1] + A[i+1][1];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            cum[i + 1][j + 1] = cum[i + 1][j] + cum[i][j + 1] - cum[i][j] + A[i + 1][j + 1];
        }
    }

    
    //end code
    
    /*
    //누적합 배열 확인용 코드
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", cum[i][j]);
        }
        printf("\n");
    }*/
    
    
    //Q queries
    fscanf(in, "%d", &m);

    for (int i = 0; i < m; i++) {

        // left up, right down (x, y)
        int lux, luy, rdx, rdy;
        fscanf(in, "%d %d %d %d", &lux, &luy, &rdx, &rdy);

        lux++;
        luy++;
        rdx++;
        rdy++;


        int value = cum[rdy][rdx] - cum[rdy][lux-1] - cum[luy-1][rdx] + cum[luy-1][lux-1];
        printf("%d\n", value);

    }



    return 0;

}
