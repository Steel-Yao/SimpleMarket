#include "first_time.h"	// 初始化（系统首次运行）

#include <iostream>
#include <cstring>

#include "struct.h"		// 自定义结构体（包含自定义参数）
#include "color.h"		// 命令行颜色代码

using namespace std;

/*************初始化：创建超级账户*************/

int firstTime()
{
	system( "cls" );
	cout << GREY << "***系统首次运行需要进行初始化***\n" << RESET;
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
	     << "      创建超级管理员      \n"
	     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n";

	char ID[51],		// 超级管理员账号
	     password[51],	// 超级管理员密码
	     temp[51];		// 确认密码

	cout << GREY << "***长度为3~10个字符，不得包含空格***\n" << RESET
	     << "设置账号：";
	cin >> ID;
	int lengthID = strlen( ID );

	// 判断账号是否符合要求
	if ( lengthID < 3 || lengthID > 10 )
	{
		cout << RED << "***账号不符合要求***\n\n" << RESET;
		system( "pause" );
		return 0;
	}
	else	// 账号通过
	{
		cout << GREY << "***长度为6~20个字符，不得包含空格***\n" << RESET
		     << "设置密码：";
		cin >> password;
		int lengthPassword = strlen( password );

		// 判断密码是否符合要求
		if ( lengthPassword < 6 || lengthPassword > 20 )
		{
			cout << RED << "***密码密码不符合要求***\n\n" << RESET;
			system( "pause" );
			return 0;
		}
		else	// 密码通过
		{
			system( "cls" );
			cout << GREY << "***系统首次运行需要进行初始化***\n\n" << RESET
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
			     << "      创建超级管理员      \n"
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
			     << "超级管理员：" << ID << endl
			     << "确认密码：";
			cin >> temp;

			if ( strcmp( temp, password ) )	// 验证确认密码
			{
				cout << RED << "密码不匹配！\n\n" << RESET;
				system( "pause" );
				return 0;
			}
			else	// 确认密码通过
			{
				strcpy( crew.superID, ID );
				strcpy( crew.superPassword, password );
				system( "cls" );
				cout << RED << "***超级管理员创建成功***\n"
				     << " ***请牢记账号与密码***\n\n" << RESET;
				system( "pause" );
			}
		}
	}
	return 1;
}
