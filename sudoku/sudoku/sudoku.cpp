//
//  sudoku.cpp
//  sudoku
//
//  Created by 郭子奇 on 2020/1/5.
//  Copyright © 2020 郭子奇. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "sudoku.h"
#include "changelist.h"

sudoku:: sudoku(int n)
{
    int temp_arr[9] = {'0','1','2','3','4','5','6','7','8'};
    memcpy(first_line,temp_arr,sizeof(temp_arr));
}

void sudoku::generator()//生成
{
    int current_num=0;
    changelist l;
    while(1)
    {
        output(l);
        current_num++;
        if(current_num==num)
        {
            return;
        }
        for(int i=0;i<71;++i)//list 可以有72种变化
        {
            l.change_list();
            output(l);
            current_num++;
            if(current_num==num)
            {
                return;
            }
        }
        l.change_list();
        std::next_permutation(first_line[1],first_line[9]);
    }
}

void sudoku::output(changelist l)
{
    //生成
    //list 样例 {0,3,6,1,4,7,2,5,8}
    //打开文件
    for(int i=0;i<9;++i)
    {
        for(int j=l.get(i);j<9;++j)
        {
            
            //加入一个字符
        }
        for(int j=0;j<l.get(i);++j)
        {
            //加入字符
        }
        //回车
    }
    
    //关闭文件
}
