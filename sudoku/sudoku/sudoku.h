//
//  sudoku.h
//  sudoku
//
//  Created by 郭子奇 on 2020/1/2.
//  Copyright © 2020 郭子奇. All rights reserved.
//

#ifndef sudoku_h
#define sudoku_h

class sudoku
{
private:
    char first_line[9];
    int move_list[9][9];
public:
    void generator();
    void output();
};

class list
{
private:
    int list[3][3];
public:
    void change_list(int *);
};


#endif /* sudoku_h */
