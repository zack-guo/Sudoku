//
//  sudoku.h
//  sudoku
//
//  Created by 郭子奇 on 2020/1/2.
//  Copyright © 2020 郭子奇. All rights reserved.
//

#ifndef sudoku_h
#define sudoku_h

#include "changelist.h"

class sudoku
{
private:
    char first_line[9];//数独y第一行的信息保存
    int num;           //生成数量
    //int move_list[9][9];
public:
    sudoku(int n);
    void generator();//生成第一行的数独，并保存在first_line中
    void output(changelist);//生成数独终局并输出
};


#endif /* sudoku_h */
