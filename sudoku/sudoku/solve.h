﻿//
//  backtrack.h
//  sudoku
//
//  Created by 郭子奇 on 2020/1/10.
//  Copyright © 2020 郭子奇. All rights reserved.
//

#ifndef solve_h
#define solve_h


using namespace std;

class solve
{
private:
	int map[9][9];         //数独盘
	bool check_list[9][10];  //每个宫数字的出现情况
	int current_box;//当前的宫
	int current_num;//当前搜索的数字
	int target_num;//空缺数量
	int flag;
	FILE* fp;
	FILE* fout;
	string superc;
public:
	int backtrack(int);
	bool check(int, int);
	solve();
	void output();
	void clean();
	int read();
	void set_file(const char*);
	void superoutput();
};

#endif /* solve_h */
