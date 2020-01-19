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

int main(int argc, const char* argv[]) {
	//对命令行参数的处理
	char c[5];
	strcpy(c, "-c");
	//if (!strcmp(argv[1], "-c"))//生成数独
	//{
	//	int n = atoi(argv[2]);
	//	for (int i = 0; i < strlen(argv[2]); i++)
	//	{
	//		if (argv[2][i] > '9' || argv[2][i] < '0')
	//		{
	//			printf("please input the right parameter!");
	//			return 0;
	//		}
	//	}

	//	sudoku sudoku_(n);
	//	sudoku_.generator();
	//	sudoku_.superoutput();
	//	printf("生成数独成功！\n");
	//}
	//else if (!strcmp(argv[1], "-s"))//求解数独
	{
		solve s;
		s.set_file("E:\\sudokuproblem\\problem_easy.txt");
		while (s.read())
			s.backtrack(0);
		s.superoutput();
		cout << "解数独完成！" << endl;
	}
	return 0;
}

