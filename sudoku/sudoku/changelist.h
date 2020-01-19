//
//  list.h
//  sudoku
//
//  Created by 郭子奇 on 2020/1/5.
//  Copyright © 2020 郭子奇. All rights reserved.
//

#ifndef changelist_h
#define changelist_h

class changelist
{
private:
    int list[9];
public:
    void change_list();
    int get(int);
    changelist();
};

#endif /* changelist_h */
