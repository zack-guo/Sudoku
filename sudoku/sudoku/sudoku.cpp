//
//  sudoku.cpp
//  sudoku
//
//  Created by 郭子奇 on 2020/1/5.
//  Copyright © 2020 郭子奇. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include "sudoku.h"
#include "changelist.h"

sudoku::sudoku(int n)
{
	char temp_arr[9] = { '1','2','3','4','5','6','7','8','9' };
	memcpy(first_line, temp_arr, sizeof(temp_arr));
	num = n;
	//strcpy(file_name, "sudoku_generate.txt");
	//fp = fopen(file_name, "wb");
}

void sudoku::generator()//生成
{
	int current_num = 0;
	changelist l;
	//if (fp == NULL)
	/*{
		printf("!!!\n");
		return;
	}*/
	while (1)
	{
		output(l);
		current_num++;
		if (current_num == num)
		{
			return;
		}
		else
		{
			//fwrite("\n", 1, 1, fp);
			superc += "\n";
		}
		for (int i = 0; i < 71; ++i)//list 可以有72种变化
		{
			l.change_list();
			output(l);
			current_num++;
			if (current_num == num)
			{
				return;
			}
			else
			{
				//fwrite("\n", 1, 1, fp);
				//strcat(superchar, "\n");
				superc += "\n";
			}
		}
		l.change_list();
		std::next_permutation(&first_line[1], &first_line[8]);
	}

}

void sudoku::output(changelist l)
{
	//生成
	//list 样例 {0,3,6,1,4,7,2,5,8}
	//打开文件
	for (int i = 0; i < 9; ++i)
	{
		for (int j = l.get(i); j < 9; ++j)
		{
			if (j != l.get(i))
			{
				//fwrite(" ", sizeof(char), 1, fp);
				//strcat(superchar, " ");
				superc += " ";
			}
				
			//fwrite((first_line + j), sizeof(char), 1, fp);
			//strcat(superchar, (first_line + j));
			superc += first_line[j];
			//加入一个字符
		}
		for (int j = 0; j < l.get(i); ++j)
		{
			//fwrite(" ", sizeof(char), 1, fp);
			//strcat(superchar, " ");
			superc += " ";
			//fwrite((first_line + j), sizeof(char), 1, fp);
			//strcat(superchar, (first_line + j));
			superc += first_line[j];
			//加入字符
		}
		//回车
		//fwrite("\r\n", 2, 1, fp);
		//strcat(superchar, "\n");
		superc += "\n";

	}
	//关闭文件
}

void sudoku::superoutput()
{
	ofstream fs;
	fs.open("sudoku.txt");
	fs << superc;
	fs.close();
	//fwrite(superchar, sizeof(superchar), strlen(superchar), fp);
	//fclose(fp);

}