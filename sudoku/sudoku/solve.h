//
//  backtrack.h
//  sudoku
//
//  Created by 郭子奇 on 2020/1/10.
//  Copyright © 2020 郭子奇. All rights reserved.
//

#ifndef solve_h
#define solve_h

class solve
{
private:
    char map[9][9];         //数独盘
    bool check_list[9][9];  //每个宫数字的出现情况
    int current_map;//当前的宫
    int current_num;//当前搜索的数字
    int target_num; //
    FILE* fp;
public:
    void backtrack(int);
    bool check();
    bool bound();
    solve(FILE*);
    void output();
    void clean();
    void read();
};

#endif /* solve_h */
