#include "menu3.h"	// 菜单3：账单处理

#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>

#include "struct.h"		// 自定义结构体（包含自定义参数）
#include "color.h"		// 命令行颜色代码

using namespace std;

void time( int &year, int &month, int &day )
{
	time_t nowtime;
	time( &nowtime );
	tm *Year = localtime( &nowtime );
	tm *Month = localtime( &nowtime );
	tm *Day = localtime( &nowtime );
	printf( "%04d-%02d-%02d", Year->tm_year + 1900, Month->tm_mon + 1, Day->tm_mday );
	year = Year->tm_year + 1900;
	month = Month->tm_mon + 1;
	day = Day->tm_mday;
}

int findgoods( int a, int num[], int number[] )
{
	if ( bill.billArr[bill.billNum].outGoods[a].sort == 1 )
	{
		for ( int j = 0; j < store.foodNum; j++ )
			cout << setw( 3 ) << right << j + 1 << "." << setw( 21 ) << left << store.foodArr[j].name << "数量：" << store.foodArr[j].count << "\n";
		if ( store.foodNum == 0 )
		{
			cout << RED << "商品短缺" << RESET << endl;
			return 0;
		}
	}
	else if ( bill.billArr[bill.billNum].outGoods[a].sort == 2 )
	{
		for ( int i = 0; i < store.drinkNum; i++ )
			cout << setw( 3 ) << right << i + 1 << "." << setw( 21 ) << left << store.drinkArr[i].name << "数量：" << store.drinkArr[i].count << "\n";
		if ( store.drinkNum == 0 )
		{
			cout << RED << "商品短缺" << RESET << endl;
			return 0;
		}
	}
	else if ( bill.billArr[bill.billNum].outGoods[a].sort == 3 )
	{
		for ( int i = 0; i < store.dailyNum; i++ )
			cout << setw( 3 )  << right << i + 1 << "." << setw( 21 ) << left << store.dailyArr[i].name << "数量：" << store.dailyArr[i].count << "\n";
		if ( store.dailyNum == 0 )
		{
			cout << RED << "商品短缺" << RESET << endl;
			return 0;
		}
	}
	else if ( bill.billArr[bill.billNum].outGoods[a].sort == 4 )
	{
		for ( int i = 0; i < store.beerNum; i++ )
			cout << setw( 3 ) << right << i + 1 << "." << setw( 21 ) << left << store.beerArr[i].name << "数量：" << store.beerArr[i].count << "\n";
		if ( store.beerNum == 0 )
		{
			cout << RED << "商品短缺" << RESET << endl;
			return 0;
		}
	}

	return 1;
}

void outbill( int b, int a, int num[], int number[] )// 商品种数 账单数 商品编号 商品单数
{
	int supernum = 0;// 数量合计
	float supermon = 0;// 总钱
	cout << "编号：" << bill.billNum + 1 << endl;
	cout << "         欢迎光临 牛马超市" << endl;
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "收银：人工\n消费时间：";
	time( bill.billArr[a].billTime.year, bill.billArr[a].billTime.month, bill.billArr[a].billTime.day );
	cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "品名                    单价|数量             小计" << endl;
	for ( int i = 0; i < b; i++ )
	{
		int c = num[i] - 1;
		if ( bill.billArr[a].outGoods[i].sort == 1 )
		{
			strcpy( bill.billArr[a].outGoods[i].name, store.foodArr[c].name );
			bill.billArr[a].outGoods[i].count = number[i];
			bill.billArr[a].outGoods[i].inPrice = store.foodArr[c].inPrice;
			bill.billArr[a].outGoods[i].allprice = store.foodArr[c].outPrice * number[i];
			bill.billArr[a].outGoods[i].outPrice = store.foodArr[c].outPrice;
			cout << setw( 20 ) << left << store.foodArr[c].name << setw( 7 ) << right << store.foodArr[c].outPrice << " × " << setw( 8 ) << left << number[i] << setw( 12 ) << right << store.foodArr[c].outPrice * number[i] << "￥" << endl;
			supermon += store.foodArr[c].outPrice * number[i];
			store.foodArr[c].income += store.foodArr[c].income + ( store.foodArr[c].outPrice * number[i] - store.foodArr[c].inPrice * number[i] );
			store.foodArr[c].count -= number[i];
		}
		else if ( bill.billArr[a].outGoods[i].sort == 2 )
		{
			strncpy( bill.billArr[a].outGoods[i].name, store.drinkArr[c].name, sizeof( bill.billArr[a].outGoods[i].name ) - 1 );
			bill.billArr[a].outGoods[i].count = number[i];
			bill.billArr[a].outGoods[i].inPrice = store.drinkArr[c].inPrice;
			bill.billArr[a].outGoods[i].allprice = store.drinkArr[c].outPrice * number[i];
			bill.billArr[a].outGoods[i].outPrice = store.drinkArr[c].outPrice;
			cout << setw( 20 ) << left << store.drinkArr[c].name << setw( 7 ) << right << store.drinkArr[c].outPrice << " × " << setw( 8 ) << left << number[i] << setw( 12 ) << right << store.drinkArr[c].outPrice * number[i] << "￥" << endl;
			supermon += store.drinkArr[c].outPrice * number[i];
			store.drinkArr[c].count -= number[i];
			store.drinkArr[c].income += store.drinkArr[c].income + ( store.drinkArr[c].outPrice * number[i] - store.drinkArr[c].inPrice * number[i] );
		}
		else if ( bill.billArr[a].outGoods[i].sort == 3 )
		{
			strncpy( bill.billArr[a].outGoods[i].name, store.dailyArr[c].name, sizeof( bill.billArr[a].outGoods[i].name ) - 1 );
			bill.billArr[a].outGoods[i].count = number[i];
			bill.billArr[a].outGoods[i].inPrice = store.dailyArr[c].inPrice;
			bill.billArr[a].outGoods[i].allprice = store.dailyArr[c].outPrice * number[i];
			bill.billArr[a].outGoods[i].outPrice = store.dailyArr[c].outPrice;
			cout << setw( 20 ) << left << store.dailyArr[c].name << setw( 7 ) << right << store.dailyArr[c].outPrice << " × " << setw( 8 ) << left << number[i] << setw( 12 ) << right << store.dailyArr[c].outPrice * number[i] << "￥" << endl;
			supermon += store.dailyArr[c].outPrice * number[i];
			store.dailyArr[c].count -= number[i];
			store.dailyArr[c].income += store.drinkArr[c].income + ( store.dailyArr[c].outPrice * number[i] - store.dailyArr[c].inPrice * number[i] );
		}
		else if ( bill.billArr[a].outGoods[i].sort == 4 )
		{
			strncpy( bill.billArr[a].outGoods[i].name, store.beerArr[c].name, sizeof( bill.billArr[a].outGoods[i].name ) - 1 );
			bill.billArr[a].outGoods[i].count = number[i];
			bill.billArr[a].outGoods[i].inPrice = store.beerArr[c].inPrice;
			bill.billArr[a].outGoods[i].allprice = store.beerArr[c].outPrice * number[i];
			bill.billArr[a].outGoods[i].outPrice = store.beerArr[c].outPrice;
			cout << setw( 20 ) << left << store.beerArr[c].name << setw( 7 ) << right << store.beerArr[c].outPrice << " × " << setw( 8 ) << left << number[i] << setw( 12 ) << right << store.beerArr[c].outPrice * number[i] << "￥" << endl;
			supermon += store.beerArr[c].outPrice * number[i];
			store.beerArr[c].count -= number[i];
			store.beerArr[c].income += store.beerArr[c].income + ( store.beerArr[c].outPrice * number[i] - store.beerArr[c].inPrice * number[i] );
		}
		supernum += number[i];
	}
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "数量合计：" << setw( 25 ) << left << supernum << "总消费：" << setw( 7 ) << right << supermon << "￥" << endl;
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "地址：重庆交通大学科学城校区牛马超市" << endl;
	cout << "              欢迎下次光临\n" << endl;
	bill.billArr[bill.billNum].outGoods[0].superout = supermon;
	bill.totalIncome += supermon;
	bill.billArr[bill.billNum].goodsNum = b;
	bill.billNum++;
	system( "pause" );
}
int goodsnum( int a, int num[], int number[] )
{
	if ( bill.billArr[bill.billNum].outGoods[a].sort == 1 )
	{
		int k = store.foodArr[num[a] - 1].count;
		for ( int i = 0; i <= a; i++ )
		{
			if ( num[a] == num[i] )
				k = k - number[i];
			if ( k < 0 )
			{
				cout << RED << "商品短缺" << RESET << endl;
				system( "pause" );
				return 0;
			}
		}
	}

	if ( bill.billArr[bill.billNum].outGoods[a].sort == 2 )
	{
		int k = store.drinkArr[num[a] - 1].count;
		for ( int i = 0; i <= a; i++ )
		{
			if ( num[a] == num[i] )
				k = k - number[i];
			if ( k < 0 )
			{
				cout << RED << "商品短缺" << RESET << endl;
				system( "pause" );
				return 0;
			}
		}
	}
	if ( bill.billArr[bill.billNum].outGoods[a].sort == 3 )
	{
		int k = store.dailyArr[num[a] - 1].count;
		for ( int i = 0; i <= a; i++ )
		{
			if ( num[a] == num[i] )
				k = k - number[i];
			if ( k < 0 )
			{
				cout << RED << "商品短缺" << RESET << endl;
				system( "pause" );
				return 0;
			}
		}
	}
	if ( bill.billArr[bill.billNum].outGoods[a].sort == 4 )
	{
		int k = store.beerArr[num[a] - 1].count;
		for ( int i = 0; i <= a; i++ )
		{
			if ( num[a] == num[i] )
				k = k - number[i];
			if ( k < 0 )
			{
				cout << RED << "商品短缺" << RESET << endl;
				system( "pause" );
				return 0;
			}
		}
	}
	return 1;
}
void mao()
{
	cout << "恭喜，触发彩蛋\n"
	     << "  /\\_/\\\n"
	     << "=( °w° )=\n"
	     << "  )   ( // \n"
	     << " (__ __)// " << endl;
	system( "pause" );
}
int maomao( int sort, int num )
{
	if ( sort == 1 )
	{
		if ( num > store.foodNum or num < 0 )
		{
			mao();
			return 0;
		}
	}

	if ( sort == 2 )
	{
		if ( num > store.drinkNum or num < 0 )
		{
			mao();
			return 0;
		}
	}
	if ( sort == 3 )
	{
		if ( num > store.dailyNum or num < 0 )
		{
			mao();
			return 0;
		}
	}
	if ( sort == 4 )
	{
		if ( num > store.beerNum or num < 0 )
		{
			mao();
			return 0;
		}
	}
	return 1;
}
int inbill()
{
	system( "cls" );
	int number[100] = {0}; // 数量
	int b = 0, num[100] = {0};// 商品种数 编号
	char c = 0;
	while ( 1 )
	{
		cout << GREY << "食品（1）、饮品（2）、日用品（3）、烟酒（4）\n         输入 0 返回 ; 输入 Y 继续\n" << RESET << endl;
		cout << GREEN << "商品类别: " << RESET;
		cin >> bill.billArr[bill.billNum].outGoods[b].sort;
		if ( bill.billArr[bill.billNum].outGoods[b].sort > 4 or bill.billArr[bill.billNum].outGoods[b].sort < 0 )
		{
			cout << RED << "不存在该类别" << RESET << endl;
			system( "pause" );
			return 0;
		}
		if ( bill.billArr[bill.billNum].outGoods[b].sort == 0 )return 1;
		cout << YELLOW << "该类商品如下：" << RESET << endl;
		int k = findgoods( b, num, number );
		if ( k == 0 )return 0;
		cout << GREEN << "商品编号：" << RESET;
		cin >> num[b];
		if ( maomao( bill.billArr[bill.billNum].outGoods[b].sort, num[b] ) == 0 )return 0;
		if ( num[b] == 0 )return 0;
		cout << GREEN << "商品数量: " << RESET;
		cin >> number[b];
		if ( number[b] == 0 )return 0;
		if ( goodsnum( b, num, number ) == 0 )
			return 0;
		cout << GREY << "是否继续" << RESET << endl;
		cin >> c;
		system( "cls" );
		b++;
		if ( c <= 'z' and c >= 'a' )
			c = c - 32;
		if ( c != 'Y' )
		{
			outbill( b, bill.billNum, &num[0], &number[0] );// 商品种数 账单数 商品编号 商品单数
			return 0;
		};
	}
}

int findbillNum()
{
	system( "cls" );
	cout << "已有帐单数：" << bill.billNum << endl;
	cout << "请输入想要查看的账单编号" << endl;
	int a;
	cin >> a;
	if ( !a )
		return 1;
	if ( a > bill.billNum or a < 0 )
	{
		cout << RED << "不存在该账单" << RESET << endl;
		system( "pause" );
		return 0;
	}
	system( "cls" );
	cout << "品名                    单价|数量             小计" << endl;
	for ( int i = 0; i < bill.billArr[a - 1].goodsNum ; i++ )
	{
		int k = bill.billArr[a - 1].outGoods[i].allprice / bill.billArr[a - 1].outGoods[i].outPrice;
		cout << setw( 20 ) << left << bill.billArr[a - 1].outGoods[i].name << setw( 7 ) << right << bill.billArr[a - 1].outGoods[i].outPrice << " × " << setw( 8 ) << left << k << setw( 12 ) << right << bill.billArr[a - 1].outGoods[i].allprice << "￥" << endl;
	}
	cout << "总价：  " << bill.billArr[a - 1].outGoods[0].superout << "￥" << endl;
	cout << bill.billArr[a - 1].billTime.year << "-" << bill.billArr[a - 1].billTime.month << "-" << bill.billArr[a - 1].billTime.day << endl;
	system( "pause" );
	return 0;
}
int findbillYear()
{
	system( "cls" );
	int b = 0;
	cout << "请输入想查询的年份" << endl;
	int a;// 查询
	cin >> a;
	if ( a == 0 )
		return 1;
	system( "cls" );
	for ( int i = 0; i < bill.billNum; i++ )
	{
		if ( a == bill.billArr[i].billTime.year )
		{
			b++;
			cout << "编号：" << i + 1 << endl;
			cout << "品名                    单价|数量             小计" << endl;
			for ( int j = 0; j < bill.billArr[i].goodsNum; j++ )
			{
				int k = bill.billArr[i].outGoods[j].allprice / bill.billArr[i].outGoods[j].outPrice;
				cout << setw( 20 ) << left << bill.billArr[i].outGoods[j].name << setw( 7 ) << right << bill.billArr[i].outGoods[j].outPrice << " × " << setw( 8 ) << left << k << setw( 12 ) << right << bill.billArr[i].outGoods[j].allprice << "￥" << endl;
			}
			cout << "总价：  " << bill.billArr[i].outGoods[0].superout << "￥" << endl;
			cout << endl;
		}
	}
	cout << "共查询到" << GREEN << b << RESET << "个结果" << endl;
	system( "pause" );
	return 0;
}
int findbillMon()
{
	system( "pause" );
	int b = 0;
	cout << "请输入想查询的年份" << endl;
	int a1;// 查询
	cin >> a1;
	if ( a1 == 0 )
		return 1;
	cout << "请输入想查询的月份" << endl;
	int a;// 查询
	cin >> a;
	if ( a == 0 )
		return 0;
	system( "cls" );
	for ( int i = 0; i < bill.billNum; i++ )
	{
		if ( a1 == bill.billArr[i].billTime.year )
		{
			if ( a == bill.billArr[i].billTime.month )
			{
				b++;
				cout << "编号：" << i + 1 << endl;
				cout << "品名                    单价|数量             小计" << endl;
				for ( int j = 0; j < bill.billArr[i].goodsNum; j++ )
				{
					int k = bill.billArr[i].outGoods[j].allprice / bill.billArr[i].outGoods[j].outPrice;
					cout << setw( 20 ) << left << bill.billArr[i].outGoods[j].name << setw( 7 ) << right << bill.billArr[i].outGoods[j].outPrice << " × " << setw( 8 ) << left << k << setw( 12 ) << right << bill.billArr[i].outGoods[j].allprice << "￥" << endl;
				}
			}
			cout << "总价：  " << bill.billArr[i].outGoods[0].superout << "￥" << endl;
			cout << endl;
		}
	}
	cout << "共查询到" << GREEN << b << RESET << "个结果" << endl;
	system( "pause" );
	return 0;
}
int findbillDay()
{
	system( "pause" );
	cout << "请输入想查询的年份" << endl;
	int a;// 查询
	cin >> a;
	if ( a == 0 )
		return 1;
	cout << "请输入想查询的月份" << endl;
	int a1;// 查询
	cin >> a1;
	if ( a1 == 0 )
		return 0;
	int b = 0;
	cout << "请输入想查询的时间段" << endl;
	int q, p; // 查询
	cout << "开始日期：";
	cin >> q;
	cout << "结束日期：";
	cin >> p;
	if ( q < p )
	{
		int w = q;
		p = q;
		q = w;
	}
	system( "cls" );
	for ( int i = 0; i < bill.billNum; i++ )
	{
		if ( a == bill.billArr[i].billTime.year )
		{
			if ( a1 == bill.billArr[i].billTime.month )
			{
				if ( q >= bill.billArr[i].billTime.day and p <= bill.billArr[i].billTime.day )
				{
					b++;
					cout << "编号：" << i + 1 << endl;
					cout << "品名                    单价|数量             小计" << endl;
					for ( int j = 0; j < bill.billArr[i].goodsNum; j++ )
					{
						int k = bill.billArr[i].outGoods[j].allprice / bill.billArr[i].outGoods[j].outPrice;
						cout << setw( 20 ) << left << bill.billArr[i].outGoods[j].name << setw( 7 ) << right << bill.billArr[i].outGoods[j].outPrice << " × " << setw( 8 ) << left << k << setw( 12 ) << right << bill.billArr[i].outGoods[j].allprice << "￥" << endl;
					}
				}
			}
			cout << "总价：  " << bill.billArr[i].outGoods[0].superout << "￥" << endl;
			cout << endl;
		}
	}
	cout << "共查询到" << GREEN << b << RESET << "个结果" << endl;
	system( "pause" );
	return 0;
}
int findbillTime()
{
	system( "cls" );
	cout << "查找方式：\n";
	cout << GREY << "1.年度账单  2.月季账单  3.时间账单（时间段）" << RESET << endl;
	int a;// 选择
	cin >> a;
	if ( a > 3 or a < 0 )
	{
		cout << RED << "错误操作" << RESET << endl;
		system( "pause" );
		return 0;
	}
	switch ( a )
	{
	case 1:
		while ( !findbillYear() );
		return 0;
	case 2:
		while ( !findbillMon() );
		return 0;
	case 3:
		while ( !findbillDay() );
		return 0;
	}
	return 0;
}
int findbillAll()
{
	system( "cls" );
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
	     << "┃         查找账单        ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃      1、按编号查找      ┃\n"
	     << "┃      2、按时间查找      ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃      0、返回            ┃\n"
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
			while ( !findbillNum() );
			return 0;
		case 2:
			while ( findbillTime() );
			return 0;
		default:
			return 0;
		}
}
void Cutbill( int a )
{
	bill.totalIncome -= bill.billArr[a - 1].outGoods[0].superout;
	for ( int i = 0; i < bill.billArr[a - 1].goodsNum; i++ )
	{

		if ( bill.billArr[a - 1].outGoods[i].sort == 1 )
		{
			for ( int j = 0; j < store.foodNum; j++ )
			{
				if ( !strcmp( bill.billArr[a - 1].outGoods[i].name, store.foodArr[j].name ) )
				{
					store.foodArr[j].count = store.foodArr[j].count + bill.billArr[a - 1].outGoods[i].count;
					store.foodArr[j].income = store.foodArr[j].income - ( bill.billArr[a - 1].outGoods[i].allprice - bill.billArr[a - 1].outGoods[i].count * bill.billArr[a - 1].outGoods[i].inPrice );
				}
			}
		}
		if ( bill.billArr[a - 1].outGoods[i].sort == 2 )
		{
			for ( int j = 0; j < store.drinkNum; j++ )
			{
				if ( !strcmp( bill.billArr[a - 1].outGoods[i].name, store.drinkArr[j].name ) )
				{
					store.drinkArr[j].count = store.drinkArr[j].count + bill.billArr[a - 1].outGoods[i].count;
					store.drinkArr[j].income = store.drinkArr[j].income - ( bill.billArr[a - 1].outGoods[i].allprice - bill.billArr[a - 1].outGoods[i].count * bill.billArr[a - 1].outGoods[i].inPrice );
				}
			}
		}
		if ( bill.billArr[a - 1].outGoods[i].sort == 3 )
		{
			for ( int j = 0; j < store.dailyNum; j++ )
			{
				if ( !strcmp( bill.billArr[a - 1].outGoods[i].name, store.dailyArr[j].name ) )
				{
					store.dailyArr[j].count = store.dailyArr[j].count + bill.billArr[a - 1].outGoods[i].count;
					store.dailyArr[j].income = store.dailyArr[j].income - ( bill.billArr[a - 1].outGoods[i].allprice - bill.billArr[a - 1].outGoods[i].count * bill.billArr[a - 1].outGoods[i].inPrice );
				}

			}
		}
		if ( bill.billArr[a - 1].outGoods[i].sort == 4 )
		{
			for ( int j = 0; j < store.beerNum; j++ )
			{
				if ( !strcmp( bill.billArr[a - 1].outGoods[i].name, store.beerArr[j].name ) )
				{
					store.beerArr[j].count = store.beerArr[j].count + bill.billArr[a - 1].outGoods[i].count;
					store.beerArr[j].income = store.beerArr[j].income - ( bill.billArr[a - 1].outGoods[i].allprice - bill.billArr[a - 1].outGoods[i].count * bill.billArr[a - 1].outGoods[i].inPrice );
				}

			}
		}
	}
	bill.billNum--;
	for ( int i = a - 1; i < bill.billNum - 1; i++ )
		bill.billArr[i] = bill.billArr[i + 1];
	float secs = 1.5;
	clock_t delay = secs * CLOCKS_PER_SEC;
	cout << YELLOW << "删除中..." << RESET << endl;
	clock_t start = clock();
	while ( clock() - start < delay );
	cout << GREEN << "删除完毕" << RESET << endl;
}
int Cutbillall()// 删除账单系统
{
	system( "cls" );
	cout << GREY << "***输入0退出***" << RESET << endl;
	cout << "***当前有" << GREEN << bill.billNum << RESET << "个账单***" << endl;
	cout << "请输入想删除的账单编号：";
	int a;// 编号
	cin >> a;
	if ( a == 0 )
		return 1;
	if ( a > bill.billNum or a < 0 )
	{
		cout << RED << "不存在该账单" << RESET << endl;
		system( "pause" );
		return 0;
	}
	system( "cls" );
	cout << "品名                    单价|数量             小计" << endl;
	for ( int i = 0; i < bill.billArr[a - 1].goodsNum ; i++ )
	{
		int k = bill.billArr[a - 1].outGoods[i].allprice / bill.billArr[a - 1].outGoods[i].outPrice;
		cout << setw( 20 ) << left << bill.billArr[a - 1].outGoods[i].name << setw( 7 ) << right << bill.billArr[a - 1].outGoods[i].outPrice << " × " << setw( 8 ) << left << k << setw( 12 ) << right << bill.billArr[a - 1].outGoods[i].allprice << "￥" << endl;
	}
	cout << "总价：  " << bill.billArr[a - 1].outGoods[0].superout << "￥" << endl;
	cout << bill.billArr[a - 1].billTime.year << "-" << bill.billArr[a - 1].billTime.month << "-" << bill.billArr[a - 1].billTime.day << endl;
	cout << endl;
	cout << "确认删除：1.是 2.否" << endl;
	int choice;// 选择
	cin >> choice;
	if ( choice == 1 )
	{
		Cutbill( a );
		system( "pause" );
		return 1;
	}
	else
		return 0;
}
int billMenu()
{
	system( "cls" );
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
	     << "┃         账单处理        ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃       1、录入账单       ┃\n"
	     << "┃       2、删除账单       ┃\n"
	     << "┃       3、查找账单       ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃       0、返回           ┃\n"
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
			while ( !inbill() );
			return 0;
		case 2:
			while ( !Cutbillall() );
			return 0;
		case 3:
			while (	!findbillAll() );
			return 0;
		default:
			return 0;
		}
}
