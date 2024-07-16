#include "menu1.h"		// 菜单1：人员管理

#include <iostream>
#include <cstring>
#include <iomanip>

#include "struct.h"		// 自定义结构体（包含自定义参数）
#include "color.h"		// 命令行颜色代码

using namespace std;

/************搜索账号************/

int searchID( char ID[11] )
{
	if ( !strcmp( ID, crew.superID ) )	// 超级管理员账号中搜索
		return 1;
	else
	{
		for ( int i = 0; i < crew.clerkNum; i++ )	// 店员账号中搜索
		{
			if ( !strcmp( ID, crew.clerkArr[i].clerkID ) )
				return 2;
		}
	}
	return 0;
}

/***********菜单1.1：修改超级管理员***********/

int superFix()
{
	char temp[51], ID[51], password[51];
	strcpy( temp, crew.superPassword );
	strset( temp, '*' );
	system( "cls" );
	cout << GREY
	     << "    ***输入0以返回***     \n" << RESET
	     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
	     << "      修改超级管理员      \n"
	     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << YELLOW
	     << "账号：" << crew.superID << RESET << endl
	     << "密码：" << temp << endl
	     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
	     << GREY << "***长度为3~10个字符，不得包含空格***\n" << RESET
	     << "修改" << YELLOW << "账号" << RESET << "为：";
	cin >> ID;

	if ( !strcmp( ID, "0" ) )
		return 1;
	else
	{
		// 判断账号是否符合要求
		int lengthID = strlen( ID );
		if ( lengthID < 3 || lengthID > 10 )
		{
			cout << RED << "***账号不符合要求***\n\n" << RESET;
			system( "pause" );
			return 0;
		}
		else if ( searchID( ID ) == 2 )
		{
			cout << RED << "***账号已被占用***\n\n" << RESET;
			system( "pause" );
			return 0;
		}
		else	// 账号通过
		{
			system( "cls" );
			cout << GREY
			     << "    ***输入0以返回***     \n" << RESET
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
			     << "      修改超级管理员      \n"
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
			     << "账号：" << ID << RED << "（已修改）" << YELLOW << endl
			     << "密码：" << temp << RESET << endl
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
			     << GREY << "***长度为6~20个字符，不得包含空格***\n" << RESET
			     << "修改" << YELLOW << "密码" << RESET << "为：";
			cin >> password;

			// 判断密码是否符合要求
			int lengthPassword = strlen( password );
			if ( lengthPassword < 6 || lengthPassword > 20 )
			{
				cout << RED << "***密码不符合要求***\n\n" << RESET;
				system( "pause" );
				return 0;
			}

			else	// 密码通过
			{
				strcpy( temp, password );
				strset( temp, '*' );
				system( "cls" );
				cout << GREY
				     << "    ***输入0以返回***     \n" << RESET
				     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
				     << "      修改超级管理员      \n"
				     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
				     << "账号：" << ID << RED << "（已修改）" << RESET << endl
				     << "密码：" << temp << RED << "（已修改）" << RESET << endl
				     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
				     << "确认密码：";
				cin >> temp;

				if ( strcmp( temp, password ) )	// 验证确认密码
				{
					cout << RED << "两次密码不匹配！\n\n" << RESET;
					system( "pause" );
					return 0;
				}
				else	// 确认密码通过
				{
					strcpy( crew.superID, ID );
					strcpy( crew.superPassword, password );
					system( "cls" );
					cout << RED << "***超级管理员修改成功***\n"
					     << " ***请牢记账号与密码***\n\n" << RESET;
					system( "pause" );
				}
			}
		}
	}
	return 1;
}

/************显示店员列表************/

void displayClerk()
{
	cout << "┏━━━━━┳━━━━━━━━━━━━━━┓\n"
	     << "┃编 号┃    账  号    ┃\n"
	     << "┣━━━━━╋━━━━━━━━━━━━━━┫\n";
	for ( int i = 0; i < crew.clerkNum; i++ )	// 遍历输出所有店员
		cout << "┃" << setw( 5 ) << left << i + 1 << "┃" << setw( 14 ) << left << crew.clerkArr[i].clerkID << "┃\n";
	cout << "┗━━━━━┻━━━━━━━━━━━━━━┛\n";
}

/***********菜单1.2.1：添加店员***********/

int addClerk()
{
	system( "cls" );
	cout << GREY
	     << "  ***输入0以返回***\n" << RESET;
	if ( crew.clerkNum )
		displayClerk();
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
	     << "         添加店员         \n"
	     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
	     << "当前店员数量：" << crew.clerkNum << endl
	     << "新增店员编号：" << YELLOW << crew.clerkNum + 1 << RESET << endl
	     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
	char ID[51],		// 店员账号
	     password[51],	// 店员密码
	     temp[51];		// 确认密码

	cout << GREY << "***长度为3~10个字符，不得包含空格***\n" << RESET
	     << "设置账号：";
	cin >> ID;
	int lengthID = strlen( ID );

	if ( !strcmp( ID, "0" ) )	// 返回
		return 1;

	// 判断账号是否符合要求
	else if ( lengthID < 3 || lengthID > 10 )
	{
		cout << RED << "***账号不符合要求***\n\n" << RESET;
		system( "pause" );
		return 0;
	}
	else if ( searchID( ID ) )
	{
		cout << RED << "***账号已被占用***\n\n" << RESET;
		system( "pause" );
		return 0;
	}
	else	// 账号通过
	{
		system( "cls" );
		cout << GREY
		     << "  ***输入0以返回***\n" << RESET;
		if ( crew.clerkNum )
			displayClerk();
		cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
		     << "         添加店员         \n"
		     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
		     << "新增店员编号：" << YELLOW << crew.clerkNum << RESET << endl
		     << "新增店员账号：" << YELLOW << ID << RESET << endl
		     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n"
		     << GREY << "***长度为6~20个字符，不得包含空格***\n" << RESET
		     << "设置密码：";
	}
	cin >> password;

	if ( !strcmp( password, "0" ) )
		return 1;
	else
	{
		// 判断密码是否符合要求
		int lengthPassword = strlen( password );
		if ( lengthPassword < 6 || lengthPassword > 20 )
		{
			cout << RED << "***密码密码不符合要求***\n\n" << RESET;
			system( "pause" );
			return 0;
		}
		else	// 密码通过
		{
			system( "cls" );
			strcpy( temp, password );
			strset( temp, '*' );
			cout << GREY
			     << "  ***输入0以返回***\n" << RESET;
			if ( crew.clerkNum )
				displayClerk();
			cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
			     << "         添加店员         \n"
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
			     << "新增店员编号：" << YELLOW << crew.clerkNum << RESET << endl
			     << "新增店员账号：" << YELLOW << ID << RESET << endl
			     << "新增店员密码：" << YELLOW << temp << RESET << endl
			     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n"
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
				strcpy( crew.clerkArr[crew.clerkNum].clerkID, ID );
				strcpy( crew.clerkArr[crew.clerkNum++].clerkPassword, password );
				system( "cls" );
				cout << RED << "  ***店员创建成功***\n"
				     << "***请牢记账号与密码***\n\n" << RESET;
				system( "pause" );
			}
		}
	}
	return 1;
}

/***********菜单1.2.2：删除店员***********/

int deletClerk()
{
	system( "cls" );

	if ( crew.clerkNum == 0 )	// 没店员
	{
		cout << RED << "***当前还没有店员***\n\n" << RESET;
		system( "pause" );
		return 1;
	}
	else	// 有店员
	{
		cout << GREY << "  ***输入0以返回***\n" << RESET
		     << "***当前店员数量：" << YELLOW << crew.clerkNum << RESET << " ***\n";
		displayClerk();
		cout << "请输入要" << RED << "删除" << RESET << "店员的" << YELLOW << "编号" << RESET << "：";

		char temp[51];
		cin >> temp;

		int selection;
		if ( temp[1] == 0 && temp[0] >= '0' && temp[0] <= '9' )
			selection = temp[0] - '0';
		else
			return 0;

		if ( !selection )
			return 1;

		// 判断店员是否存在
		if ( selection < 1 || selection > crew.clerkNum )	// 店员不存在
		{
			cout << RED << "***编号对应的员工不存在***\n\n" << RESET;
			system( "pause" );
			return 0;
		}

		else	// 店员存在
		{
			while ( 1 )
			{
				system( "cls" );
				cout << GREY << "  ***输入0以返回***\n" << RESET
				     << "***当前店员数量：" << YELLOW << crew.clerkNum << RESET << " ***\n"
				     << "┏━━━━━┳━━━━━━━━━━━━━━┓\n"
				     << "┃编 号┃    账  号    ┃\n"
				     << "┣━━━━━╋━━━━━━━━━━━━━━┫\n";
				for ( int i = 0; i < crew.clerkNum; i++ )	// 遍历输出所有店员
				{
					if ( i + 1 == selection )
						cout << "┃" << RED << setw( 5 ) << left << i + 1 << RESET << "┃" << RED << setw( 14 ) << left << crew.clerkArr[i].clerkID << RESET << "┃\n";
					else
						cout << "┃" << setw( 5 ) << left << i + 1 << "┃" << setw( 14 ) << left << crew.clerkArr[i].clerkID << "┃\n";
				}
				cout << "┗━━━━━┻━━━━━━━━━━━━━━┛\n\n"
				     << "确定要" << RED << "删除" << RESET << crew.clerkArr[selection - 1].clerkID << "店员吗(Y/n)：";

				cin >> temp;

				if ( !strcmp( temp, "N" ) || !strcmp( temp, "n" ) )	// 否认删除
					return 0;

				else if ( !strcmp( temp, "Y" ) || !strcmp( temp, "y" ) )	// 确认删除
				{
					for ( int i = selection; i < crew.clerkNum; i++ )
						crew.clerkArr[i - 1] = crew.clerkArr[i];
					crew.clerkNum--;
					return 1;
				}
			}
		}
	}

	return 1;
}

/***********菜单1.2.3：修改店员信息***********/

int clerkFix()
{
	system( "cls" );

	if ( crew.clerkNum == 0 )	// 没店员
	{
		cout << RED << "***当前还没有店员***\n\n" << RESET;
		system( "pause" );
		return 1;
	}
	else	// 有店员
	{
		cout << GREY << "  ***输入0以返回***\n" << RESET;
		displayClerk();
		cout << "请输入要" << YELLOW << "编辑" << RESET << "店员的" << YELLOW << "编号" << RESET << "：";

		char temp[51];
		cin >> temp;

		int selection;
		if ( temp[1] == 0 && temp[0] >= '0' && temp[0] <= '9' )
			selection = temp[0] - '0';
		else
			return 0;

		if ( !selection )
			return 1;

		// 判断店员是否存在
		if ( selection < 1 || selection > crew.clerkNum )	// 店员不存在
		{
			cout << RED << "***编号对应的员工不存在***\n\n" << RESET;
			system( "pause" );
			return 0;
		}

		else	// 店员存在
		{
			while ( 1 )
			{
				system( "cls" );
				cout << GREY << "  ***输入0以返回***\n" << RESET
				     << "┏━━━━━┳━━━━━━━━━━━━━━┓\n"
				     << "┃编 号┃    账  号    ┃\n"
				     << "┣━━━━━╋━━━━━━━━━━━━━━┫\n";
				for ( int i = 0; i < crew.clerkNum; i++ )	// 遍历输出所有店员
				{
					if ( i + 1 == selection )
						cout << "┃" << YELLOW << setw( 5 ) << left << i + 1 << RESET << "┃" << YELLOW << setw( 14 ) << left << crew.clerkArr[i].clerkID << RESET << "┃\n";
					else
						cout << "┃" << setw( 5 ) << left << i + 1 << "┃" << setw( 14 ) << left << crew.clerkArr[i].clerkID << "┃\n";
				}
				cout << "┗━━━━━┻━━━━━━━━━━━━━━┛\n";

				char temp[51], ID[51], password[51];
				strcpy( temp, crew.clerkArr[selection - 1].clerkPassword );
				strset( temp, '*' );

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
				     << "       修改店员信息       \n"
				     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << YELLOW
				     << "账号：" << crew.clerkArr[selection - 1].clerkID << RESET << endl
				     << "密码：" << temp << endl
				     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
				     << GREY << "***长度为3~10个字符，不得包含空格***\n" << RESET
				     << "修改" << YELLOW << "账号" << RESET << "为：";

				cin >> ID;

				if ( !strcmp( ID, "0" ) )
					return 0;
				else
				{
					// 判断账号是否符合要求
					int lengthID = strlen( ID );
					if ( lengthID < 3 || lengthID > 10 )
					{
						cout << RED << "***账号不符合要求***\n\n" << RESET;
						system( "pause" );
					}
					else if ( searchID( ID ) == 1 || searchID( ID ) == 2 )
					{
						cout << RED << "***账号已被占用***\n\n" << RESET;
						system( "pause" );
					}
					else	// 账号通过
					{
						system( "cls" );
						cout << GREY << "  ***输入0以返回***\n" << RESET
						     << "┏━━━━━┳━━━━━━━━━━━━━━┓\n"
						     << "┃编 号┃    账  号    ┃\n"
						     << "┣━━━━━╋━━━━━━━━━━━━━━┫\n";
						for ( int i = 0; i < crew.clerkNum; i++ )	// 遍历输出所有店员
						{
							if ( i + 1 == selection )
								cout << "┃" << YELLOW << setw( 5 ) << left << i + 1 << RESET << "┃" << YELLOW << setw( 14 ) << left << crew.clerkArr[i].clerkID << RESET << "┃\n";
							else
								cout << "┃" << setw( 5 ) << left << i + 1 << "┃" << setw( 14 ) << left << crew.clerkArr[i].clerkID << "┃\n";
						}
						cout << "┗━━━━━┻━━━━━━━━━━━━━━┛\n"
						     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
						     << "       修改店员信息       \n"
						     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
						     << "账号：" << ID << RED << "（已修改）" << YELLOW << endl
						     << "密码：" << temp << RESET << endl
						     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
						     << GREY << "***长度为6~20个字符，不得包含空格***\n" << RESET
						     << "修改" << YELLOW << "密码" << RESET << "为：";

						cin >> password;

						// 判断密码是否符合要求
						int lengthPassword = strlen( password );
						if ( lengthPassword < 6 || lengthPassword > 20 )
						{
							cout << RED << "***密码不符合要求***\n\n" << RESET;
							system( "pause" );
						}

						else	// 密码通过
						{
							strcpy( temp, password );
							strset( temp, '*' );

							system( "cls" );
							cout << GREY << "  ***输入0以返回***\n" << RESET
							     << "┏━━━━━┳━━━━━━━━━━━━━━┓\n"
							     << "┃编 号┃    账  号    ┃\n"
							     << "┣━━━━━╋━━━━━━━━━━━━━━┫\n";
							for ( int i = 0; i < crew.clerkNum; i++ )	// 遍历输出所有店员
							{
								if ( i + 1 == selection )
									cout << "┃" << YELLOW << setw( 5 ) << left << i + 1 << RESET << "┃" << YELLOW << setw( 14 ) << left << crew.clerkArr[i].clerkID << RESET << "┃\n";
								else
									cout << "┃" << setw( 5 ) << left << i + 1 << "┃" << setw( 14 ) << left << crew.clerkArr[i].clerkID << "┃\n";
							}
							cout << "┗━━━━━┻━━━━━━━━━━━━━━┛\n"
							     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
							     << "       修改店员信息       \n"
							     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
							     << "账号：" << ID << RED << "（已修改）" << RESET << endl
							     << "密码：" << temp << RED << "（已修改）" << RESET << endl
							     << "━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
							     << "确认密码：";
							cin >> temp;

							if ( strcmp( temp, password ) )	// 验证确认密码
							{
								cout << RED << "两次密码不匹配！\n\n" << RESET;
								system( "pause" );
							}
							else	// 确认密码通过
							{
								strcpy( crew.clerkArr[selection - 1].clerkID, ID );
								strcpy( crew.clerkArr[selection - 1].clerkPassword, password );

								system( "cls" );
								cout << RED
								     << "***店员信息修改成功***\n"
								     << "***请牢记账号与密码***\n\n" << RESET;
								system( "pause" );
								return 1;
							}
						}
					}
				}
			}
		}
	}
}

/***********菜单1.2：店员管理***********/

int clerkMenu()
{
	system( "cls" );
	cout << "***当前店员数量：" << YELLOW << crew.clerkNum << RESET << " ***\n" << RESET;
	if ( crew.clerkNum )
		displayClerk();
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
	     << "┃         店员管理        ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃       1、添加店员       ┃\n"
	     << "┃       2、删除店员       ┃\n"
	     << "┃     3、修改店员信息     ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃         0、返回         ┃\n"
	     << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

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
	{
		switch ( selection )
		{
		case 1:
			while ( !addClerk() );
			return 0;
		case 2:
			while ( !deletClerk() );
			return 0;
		case 3:
			while ( !clerkFix() );
			return 0;
		default:
			return 0;
		}
	}
}

/***********菜单1.3：经营状态***********/

int status()
{
	system( "cls" );
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
	     << "┃         经营状态        ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃                         ┃\n";

	float income = bill.totalIncome - bill.totalPay;
	if ( income > 0 )
		cout << "┃          " << GREEN << "盈  利" << RESET << "         ┃\n";
	else if ( income < 0 )
		cout << "┃          " << RED << "亏  损" << RESET << "         ┃\n";
	else
		cout << "┃         " << YELLOW << "收支相抵" << RESET << "        ┃\n";

	cout << "┃                         ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃" << RED << "总支出：" << fixed << setprecision( 2 ) << setw( 17 ) << left << bill.totalPay << RESET << "┃\n"
	     << "┃" << YELLOW << "总收入：" << setw( 17 ) << left << bill.totalIncome << RESET << "┃\n";

	if ( income > 0 )
		cout << "┃" << GREEN << "总利润：" << setw( 17 ) << left << income << RESET << "┃\n";
	else if ( income < 0 )
		cout << "┃" << RED << "总利润：" << setw( 17 ) << left << income << RESET << "┃\n";
	else
		cout << "┃" << "总利润：" << setw( 17 ) << left << income << "┃\n";

	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n";

	system( "pause" );
	return 1;
}

/***********菜单1：超市管理***********/

int superMenu()
{
	system( "cls" );
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
	     << "┃         超市管理        ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃    1、修改超级管理员    ┃\n"
	     << "┃    2、店员管理          ┃\n"
	     << "┃    3、经营状态          ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃    0、返回              ┃\n"
	     << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

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
			while ( !superFix() );
			return 0;
		case 2:
			while ( !clerkMenu() );
			return 0;
		case 3:
			while ( !status() );
		default:
			return 0;
		}
}
