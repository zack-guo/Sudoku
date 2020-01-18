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


solve:: solve()
{
    current_box=0;
    current_num=1;
    memset(map,0,sizeof(map));     //数独盘
    memset(check_list, 1, sizeof(check_list));
}

void solve::clean()
{
    current_box=0;
    current_num=1;
    memset(map,0,sizeof(map));     //数独盘
    memset(check_list, 1, sizeof(check_list));
}

int solve:: read()
{
    char linep[30];
    int ir=0;
    int il=0;
    printf("hello?\n");
    while(fgets(linep, sizeof(linep), fp))
    {
        if(linep[0]=='\n')
        {
            ir=0;
            il=0;
            clean();
        }
        else
        {
            il=0;
            for(int j=0;j<strlen(linep);j++)
            {
                if(linep[j]<='9'&&linep[j]>='0')
                {
                    map[ir][il]=linep[j]-'0';
                    check_list[(ir/3)*3+(il/3)][linep[j]-'0']=false;
                    il++;
                }
            }
            ir++;
            if(ir==9)
                return 1;
        }
    }
    //到达文件末尾
    fclose(fp);
    fclose(fout);
    return 0;
}

bool solve:: check(int r,int c)
{
    for(int i=0;i<9;i++)
    {
        if(i!=c)
        {
            if(map[r][i]==current_num)
                return false;
        }
        if(i!=r)
        {
            if(map[i][c]==current_num)
                return false;
        }
    }
    return true;
}

int solve:: backtrack(int n)
{
    if(current_box==9&&current_num==9&&n>36)
    {
        output();
        return 1;
    }
    //如果当前还没有填完
    while(1)
    {
        //正常循环
        if(current_box==9)
        {
            current_box=0;
            current_num++;
            if(current_num>=10)
                return 0;
        }
        //当前的宫可以填数字
        if(check_list[current_box][current_num])
        {
            //对当前的宫进行循环
            for(int i=0;i<9;i++)
            {
                //if(current_box>9)
                //    printf("shit");
                int row=(current_box/3)*3+i/3;
                int column=(current_box%3)*3+i%3;
                if(map[row][column]==0&&check(row,column)&&check_list[current_box][current_num])
                {
                    map[row][column]=current_num;
                    check_list[current_box][current_num]=false;
                    current_box++;
                    //output();
                    if(backtrack(n+1))
                        return 1;
                    current_num=map[row][column];
                    map[row][column]=0;
                    current_box=(row/3)*3+(column/3);
                    check_list[current_box][current_num]=true;
                    
                }
            }
            return 0;
        }
        else
        {
            current_box++;
            continue;
        }

    }
    return 0;
}

void solve::output()
{
    if(fout==NULL)
        fout=fopen("sudoku.txt","w");
    else
        fwrite("\r\n",2,1,fp);
    for(int i=0;i<9;++i)
    {
        for(int j=0;j<9;++j)
        {
            fwrite(&map[i][j],sizeof(int),1,fout);
            //加入一个字符
        }
        //回车
        fwrite("\r\n",2,1,fout);
    }
    fwrite("\r\n",2,1,fp);
}

void solve:: setfile(char path[])
{
    fp=fopen(path, "r");
}
