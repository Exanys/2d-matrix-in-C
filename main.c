/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vojta
 *
 * Created on March 4, 2021, 10:54 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGE 10


void initzialation(int matice[RANGE][RANGE]) {
    for (int i = 0; i < RANGE; i++) {
        for (int j = 0; j < RANGE; j++) {
            matice[i][j] = -1;
        }
    }
    return;
}

void fillMatice(int matice[RANGE][RANGE]) {
    for (int i = 0; i < RANGE; i++) {
        for (int j = 0; j < RANGE; j++) {
            matice[i][j] = rand() % 100;
        }
    }
    return;
}

void write(int matice[RANGE][RANGE], char *name) {
    printf("%s\n", name);
    printf("--------------------------\n");
    for (int i = 0; i < RANGE; i++) {
        for (int j = 0; j < RANGE; j++) {
            printf("%3d", matice[i][j]);
            
        }
        printf("\n");
    }
    printf("\n\n");
    return;
}

int around(int matice[RANGE][RANGE], int row, int col) {
    int sum = 0;
    for (int i = (row - 1); i <= (row + 1); i++) {
        if (i < 0) {
            i++;
        } else {
            for (int j = (col - 1); j <= (col + 1); j++) {
                if (j < 0) {
                    j++;
                } else {
                    sum += matice[i][j];
                }

            }
        }

    }
    return sum;
}

void count(int matice[RANGE][RANGE], int sums[RANGE * RANGE], int rows[RANGE * RANGE], int cols[RANGE * RANGE]) {
    int sum;
    int position = 0;
    for (int i = 0; i < RANGE; i++) {
        for (int j = 0; j < RANGE; j++) {
            sum = matice[i][j];
            sum += around(matice, i, j);
            sums[position] = sum;
            rows[position] = i;
            cols[position] = j;
            position++;
        }
    }
    return;
}

int posMax(int sums[RANGE * RANGE]) {
    int position;
    int value = 0;
    for (int i = 0; i < (RANGE * RANGE); i++) {
        if (sums[i] > value) {
            value = sums[i];
            position = i;
        }
    }
    return position;
}

int posMin(int sums[RANGE * RANGE]) {

    int position = 0;
    int value = sums[0];
    for (int i = 0; i < (RANGE * RANGE); i++) {
        if (sums[i] < value) {
            value = sums[i];
            position = i;
        }
    }
    return position;
}

void change(int matice[RANGE][RANGE], int rows[RANGE * RANGE], int cols[RANGE * RANGE], int posMax, int posMin) {
    int rowMax = rows[posMax];
    int colMax = cols[posMax];
    int rowMin = rows[posMin];
    int colMin = cols[posMin];
    int pomMax = matice[rowMax][colMax];
    int pomMin = matice[rowMin][colMin];
    matice[rowMax][colMax] = pomMin;
    matice[rowMin][colMin] = pomMax;
    return;
}

int main(int argc, char** argv) {
    srand((unsigned) time(NULL));
    int matice[RANGE][RANGE];
    int rows[RANGE * RANGE];
    int cols[RANGE * RANGE];
    int sums[RANGE * RANGE];
    initzialation(matice);
    fillMatice(matice);
    write(matice, "N A H O D N A");
    count(matice, sums, rows, cols);
    int max = posMax(sums);
    int min = posMin(sums);
    change(matice, rows, cols, max, min);
    write(matice, "V Y M E N E N A");



    return (EXIT_SUCCESS);
}

