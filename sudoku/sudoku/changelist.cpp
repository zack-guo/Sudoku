//
//  list.cpp
//  sudoku
//
//  Created by 郭子奇 on 2020/1/5.
//  Copyright © 2020 郭子奇. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include "changelist.h"

changelist::changelist()
{
	int temp_arr[9] = { 0,3,6,1,4,7,2,5,8 };
	memcpy(list, temp_arr, sizeof(temp_arr));
}

void changelist::change_list()//改变变化列表
{
	if (std::next_permutation(&list[1], &list[2]))
	{
		return;
	}
	if (std::next_permutation(&list[3], &list[5]))
	{
		return;
	}
	if (std::next_permutation(&list[6], &list[8]))
	{
		return;
	}
}

int changelist::get(int index)
{
	return list[index];
}
