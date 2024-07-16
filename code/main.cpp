/************************************
 *									*
 *		牛马超市收银管理系统		*
 *									*
 ************************************/

#include <iostream>
#include <cstring>
#include <iomanip>

#include "struct.h"		// 自定义结构体（包含自定义参数）
#include "color.h"		// 命令行颜色代码
#include "file.h"		// 数据、文件转换
#include "first_time.h"	// 初始化（系统首次运行）

/***************菜单***************/

#include "menu1.h"	// 菜单1：人员管理
#include "menu2.h"	// 菜单2：库存管理
#include "menu3.h"	// 菜单3：账单处理

using namespace std;

/*************结构体*************/

Accounts crew;		// 全部账号
StoreHouse store;	// 仓库
BillStore bill;		// 账单存储

/**************主菜单**************/

int mainMenu( int power )
{
	system( "cls" );
	if ( power )
	{
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		     << "┃   牛马超市收银管理系统  ┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		     << "┃       1、超市管理       ┃\n"
		     << "┃       2、库存管理       ┃\n"
		     << "┃       3、账单处理       ┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		     << "┃       0、退出登录       ┃\n"
		     << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	else
	{
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		     << "┃   牛马超市收银管理系统  ┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		     << "┃       " << GREY << "1、超市管理" << RESET << "       ┃\n"
		     << "┃       2、库存管理       ┃\n"
		     << "┃       3、账单处理       ┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		     << "┃       0、退出登录       ┃\n"
		     << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}

	char temp[51];
	cin >> temp;

	int selection;
	if ( temp[1] == 0 && temp[0] >= '0' && temp[0] <= '9' )
		selection = temp[0] - '0';
	else
		return 0;

	if ( selection == 0 )
		return 1;
	else
		switch ( selection )
		{
		case 1:
			if ( power )
			{
				while ( !superMenu() );
				return 0;
			}
			else
			{
				cout << RED << "***您没有权限***\n\n" << RESET;
				system( "pause" );
				return 0;
			}
		case 2:
			while ( !storeMenu() );
			return 0;
		case 3:
			while ( !billMenu() );
		default:
			return 0;
		}
}

/**************登陆界面***************/

int login()
{
	system( "cls" );
	cout << GREY
	     << "    ***输入0以退出***     \n" << RESET
	     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
	     << "         用户登录         \n"
	     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
	char ID[51],		// 账号
	     password[51];	// 密码
	cout << "输入账号：";
	cin >> ID;

	if ( !strcmp( ID, "0" ) )
		return 1;

	// 验证账号是否存在
	else if ( !searchID( ID ) )
	{
		cout << RED << "***账号不存在***\n\n" << RESET;
		system( "pause" );
		return 0;
	}
	else	// 账号存在
	{
		int lengthID = strlen( ID ), power;
		if ( searchID( ID ) == 1 )	// 超级管理员
		{
			power = 1;
			system( "cls" );
			cout << GREY
			     << "    ***输入0以退出***     \n" << RESET
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
			     << "         用户登录         \n"
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n"
			     << YELLOW << "          欢  迎          \n\n"
			     << "超级管理员：" << setw( ( 16 - lengthID ) / 2 + lengthID - 1 ) << ID << RESET
			     << "\n\n请输入密码：";
		}
		else	// 店员
		{
			power = 0;
			system( "cls" );
			cout << GREY
			     << "    ***输入0以退出***     \n" << RESET
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
			     << "         用户登录         \n"
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n"
			     << YELLOW << "          欢  迎\n\n"
			     << "店 员：" << setw( ( 21 - lengthID ) / 2 + lengthID - 1 ) << ID << RESET
			     << "\n\n请输入密码：";
		}

		cin >> password;

		if ( power )	// 验证超级管理员
		{
			if ( !strcmp( password, crew.superPassword ) )	// 密码正确
			{
				while ( !mainMenu( 1 ) );
				return 0;
			}
			else	// 密码错误
			{
				cout << RED << "***密码错误***\n\n" << RESET;
				system( "pause" );
				return 0;
			}
		}
		else	// 验证店员
		{
			int i;
			for ( i = 0; i < crew.clerkNum; i++ )	// 确定店员密码
			{
				if ( !strcmp( ID, crew.clerkArr[i].clerkID ) )
					break;
			}

			// 验证店员密码
			if ( !strcmp( password, crew.clerkArr[i].clerkPassword ) )	// 密码正确
			{
				while ( !mainMenu( 0 ) );
				return 0;
			}
			else	// 密码错误
			{
				cout << RED << "***密码错误***\n\n" << RESET;
				system( "pause" );
				return 0;
			}
		}
	}
	return 1;
}

/**************主函数**************/

int main()
{
	fileToData();

	while ( !login() );

	dataToFile();

	return 0;
}
