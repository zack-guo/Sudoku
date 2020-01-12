//
//  backtrack.cpp
//  sudoku
//
//  Created by 郭子奇 on 2020/1/10.
//  Copyright © 2020 郭子奇. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "solve.h"


solve:: solve(FILE* f)
{
    current_map=0;
    current_num=0;
    fp=f;
}

void solve::clean()
{
    current_map=0;
    current_num=0;
    target_num=0;
    memset(map,0,sizeof(map));     //数独盘
    memset(check_list, 0, sizeof(check_list));
}

void solve:: read()
{
    char linep[20];
    int i=0;
    while(fgets(linep, sizeof(linep), fp))
    {
        if(*linep=='\n')
        {
            i=0;
            clean();
        }
        else
        {
            for(int j=0;j<9;j++)
            {
                map[i][j]=linep[j];
                check_list[(i/3)*3+(j/3)][linep[j]-'0']=true;
            }
            i++;
        }
    }
}

void solve:: backtrack(int n)
{
    if(n>target_num)
    {
        output();
        exit(1);
    }
    
    
        
}

