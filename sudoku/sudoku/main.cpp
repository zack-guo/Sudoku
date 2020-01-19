//
//  main.cpp
//  sudoku
//
//  Created by 郭子奇 on 2019/12/31.
//  Copyright © 2019 郭子奇. All rights reserved.
//

#include <iostream>
#include <string>
#include "sudoku.h"
#include "changelist.h"
#include "solve.h"

int main(int argc, const char * argv[]) {
	//对命令行参数的处理
	char c[5];
	strcpy(c, "-c");
	//if(!strcmp(argv[1], "-c"))//生成数独
	{
		//int n = atoi(argv[2]);
		int n = 1000000;
		sudoku sudoku_(n);
		sudoku_.generator();
		sudoku_.superoutput();
		printf("生成数独终局完成！\n");
	}
	//else if (!strcmp(argv[1], "-s"))//求解数独
	//{
	//	solve s;
	//	s.set_file("E:\\sudokuproblem\\problem_easy.txt");
	//	while (s.read())
	//		s.backtrack(0);
	//	printf("解数独完成！\n");
	//}
    return 0;
}

