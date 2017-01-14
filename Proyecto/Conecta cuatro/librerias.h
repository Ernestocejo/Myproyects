/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newfile.h
 * Author: Ernesto
 *
 * Created on 15 de octubre de 2016, 13:42
 */
#include <stdio.h>
#include <stdlib.h>


int leestring(char *cad, int n) {
    int i, c;
    c = getchar();
    if (c == EOF) {
        cad[0] = '\0';
        return 0;
    }
    if (c == '\n')
        i = 0;
    else {
        cad[0] = c;
        i = 1;
    }
    for (; i < n - 1 && (c = getchar()) != EOF && c != '\n';
            i++)
        cad[i] = c;
    cad[i] = '\0';
    if (c != '\n' && c != EOF)
        while ((c = getchar()) != '\n' && c != EOF);
    return 1;
}
