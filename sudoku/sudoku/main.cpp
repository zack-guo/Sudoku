//
//  main.cpp
//  sudoku
//
//  Created by 郭子奇 on 2019/12/31.
//  Copyright © 2019 郭子奇. All rights reserved.
//

#include <iostream>
#include "sudoku.h"
#include "changelist.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    scanf("%d",&n);
    sudoku sudoku_(n);
    sudoku_.generator();
    return 0;
}

