#include "menu2.h"		// 菜单2：库存管理

#include <iostream>
#include <cstring>
#include <thread>
#include <iomanip>

#include "struct.h"		// 自定义结构体（包含自定义参数）
#include "color.h"		// 命令行颜色代码

using namespace std;

void goodsMenu() // 商品菜单
{
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
	     << "┃         库存管理        ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃     1、新增商品         ┃\n"
	     << "┃     2、修改商品信息     ┃\n"
	     << "┃     3、增加库存         ┃\n"
	     << "┃     4、删除商品         ┃\n"
	     << "┃     5、查看商品信息     ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃     0、返回             ┃\n"
	     << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}
void addGoodsMenu() // 食品添加菜单
{
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
	     << "┃         新增商品        ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃      1、食品            ┃\n"
	     << "┃      2、饮品            ┃\n"
	     << "┃      3、日用品          ┃\n"
	     << "┃      4、烟酒            ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃      0、返回            ┃\n"
	     << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}
void viewGoodsMenu()// 查看商品菜单
{
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
	     << "┃       查看商品信息      ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃       1、所有商品       ┃\n"
	     << "┃       2、特定商品       ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃       0、返回           ┃\n"
	     << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}
void modifyGoodsMenu() // 修改商品信息菜单
{
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
	     << "┃       修改商品信息      ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃       1、修改名称       ┃\n"
	     << "┃       2、修改进价       ┃\n"
	     << "┃       3、修改售价       ┃\n"
	     << "┣━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
	     << "┃       0、返回           ┃\n"
	     << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}
void displayStore()	// 显示所有库存商品
{
	if ( !store.foodNum )
		cout << RED << "\n***暂无食品***\n" << RESET;
	else
	{
		cout << "                    **食品**\n"
		     << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
		     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n";
		for ( int i = 0; i < store.foodNum; i++ )
			cout << "┃" << setw( 20 ) << left << store.foodArr[i].name
			     << "┃" << setw( 7 ) << left << store.foodArr[i].inPrice
			     << "┃" << setw( 7 ) << left << store.foodArr[i].outPrice
			     << "┃" << setw( 4 ) << left << store.foodArr[i].count
			     << "┃" << setw( 4 ) << left << i + 1 << "┃\n";
		cout << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
	}

	if ( !store.drinkNum )
		cout << RED << "\n***暂无饮品***\n" << RESET;
	else
	{
		cout << "                    **饮品**\n"
		     << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
		     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n";
		for ( int i = 0; i < store.drinkNum; i++ )
		{
			cout << "┃" << setw( 20 ) << left << store.drinkArr[i].name
			     << "┃" << setw( 7 ) << left << store.drinkArr[i].inPrice
			     << "┃" << setw( 7 ) << left << store.drinkArr[i].outPrice
			     << "┃" << setw( 4 ) << left << store.drinkArr[i].count
			     << "┃" << setw( 4 ) << left << i + 1 << "┃\n";
		}
		cout << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
	}

	if ( !store.dailyNum )
		cout << RED << "\n***暂无日用品***\n" << RESET;
	else
	{
		cout << "                  **日用品**" << endl;
		cout << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
		     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n";
		for ( int i = 0; i < store.dailyNum; i++ )
		{
			cout << "┃" << setw( 20 ) << left << store.dailyArr[i].name
			     << "┃" << setw( 7 ) << left << store.dailyArr[i].inPrice
			     << "┃" << setw( 7 ) << left << store.dailyArr[i].outPrice
			     << "┃" << setw( 4 ) << left << store.dailyArr[i].count
			     << "┃" << setw( 4 ) << left << i + 1 << "┃\n";
		}
		cout << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
	}

	if ( !store.beerNum )
		cout << RED << "\n***暂无烟酒***\n" << RESET;
	else
	{
		cout << "                    **烟酒**" << endl;
		cout << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
		     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n";
		for ( int i = 0; i < store.beerNum; i++ )
		{
			cout << "┃" << setw( 20 ) << left << store.beerArr[i].name
			     << "┃" << setw( 7 ) << left << store.beerArr[i].inPrice
			     << "┃" << setw( 7 ) << left << store.beerArr[i].outPrice
			     << "┃" << setw( 4 ) << left << store.beerArr[i].count
			     << "┃" << setw( 4 ) << left << i + 1 << "┃\n";
		}
		cout << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
	}
}


int addFood()
{
	while ( true )
	{
		char m_name[51];
		system( "cls" );
		cout << GREY << "输入0以退出" << RESET << endl;
		cout << "请输入商品名称：(长度不得超过10个字)" << endl;
		cin >> m_name;
		if ( !strcmp( m_name, "0" ) )
			return 1;
		int len = strlen( m_name );
		if ( len > 20 )
		{
			cout << "名称过长" << endl;
			system( "pause" );
			return 0;
		}

		for ( int i = 0; i < store.foodNum; i++ )
		{
			if ( strcmp( store.foodArr[i].name, m_name ) == 0 )
			{
				cout << "商品名称重复！请重新输入" << endl;
				system( "pause" );
				return 0;
			}
		}
		strcpy( store.foodArr[store.foodNum].name, m_name );
		float m_inPrice = 0;
		float m_outPrice = 0;
		cout << "请输入商品进价(进价<=售价)：" << endl;
		cin >> m_inPrice;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		cout << "请输入商品售价：" << endl;
		cin >> m_outPrice;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		if ( m_outPrice < m_inPrice )
		{
			cout << "进价需小于等于售价！！！" << endl;
			system( "pause" );
			return 0;
		}
		store.foodArr[store.foodNum].inPrice = m_inPrice;
		store.foodArr[store.foodNum].outPrice = m_outPrice;
		int m_count = 0;
		cout << "请输入商品数量(数量需>=于50)：" << endl;
		cin >> m_count;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		if ( m_count < 50 )
			return 0;
		cout << "请确认添加是否无误(换行即添加无误)" << endl;
		char m;
		cin.get( m );
		if ( cin.get() != '\n' )
		{
			return 0;
			system( "cls" );
		}
		store.foodArr[store.foodNum].count = m_count;
		store.foodArr[store.foodNum].sort = 1;
		bill.totalPay += m_inPrice * m_count;
		cout << "添加成功，此商品的编号为：" << store.foodNum++ + 1 << endl;
		system( "pause" );
	}
}
int addDrink()
{
	while ( true )
	{
		char m_name[51];
		system( "cls" );
		cout << GREY << "输入0以退出" << RESET << endl;

		cout << "请输入商品名称：(长度不得超过10个字)" << endl;
		cin >> m_name;
		int len = strlen( m_name );
		if ( !strcmp( m_name, "0" ) )
			return 1;

		else if ( len > 20 )
		{
			cout << "名称过长" << endl;
			system( "pause" );
			return 0;
		}
		for ( int i = 0; i < store.drinkNum; i++ )
		{
			if ( strcmp( store.drinkArr[i].name, m_name ) == 0 )
			{
				cout << "商品名称重复！请重新输入" << endl;
				system( "pause" );
				return 0;
			}
		}
		strcpy( store.drinkArr[store.drinkNum].name, m_name );
		float m_inPrice = 0;
		cout << "请输入商品进价(进价<=售价)：" << endl;
		cin >> m_inPrice;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}

		float m_outPrice = 0;
		cout << "请输入商品售价：" << endl;
		cin >> m_outPrice;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		if ( m_outPrice < m_inPrice )
		{
			cout << "进价需小于等于售价！！！" << endl;
			system( "pause" );
			return 0;
		}
		store.drinkArr[store.drinkNum].inPrice = m_inPrice;
		store.drinkArr[store.drinkNum].outPrice = m_outPrice;
		int m_count = 0;
		cout << "请输入商品数量(数量需>=50)：" << endl;
		cin >> m_count;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		if ( m_count < 50 )
			return 0;
		cout << "请确认添加是否无误(换行即添加无误)" << endl;
		char m;
		cin.get( m );
		if ( cin.get() != '\n' )
			return 0;
		store.drinkArr[store.drinkNum].count = m_count;
		store.drinkArr[store.drinkNum].sort = 2;
		bill.totalPay += m_inPrice * m_count;
		cout << "添加成功，此商品的编号为： " << store.drinkNum++ + 1 << endl;
		system( "pause" );
	}
}
int addDaily()
{
	while ( true )
	{
		char m_name[51];
		system( "cls" );
		cout << GREY << "输入0以退出" << RESET << endl;
		cout << "请输入商品名称：(长度不得超过10个字)" << endl;
		cin >> m_name;
		int len = strlen( m_name );
		if ( !strcmp( m_name, "0" ) )
			return 1;

		else if ( len > 20 )
		{
			cout << "名称过长" << endl;
			system( "pause" );
			return 0;
		}
		for ( int i = 0; i < store.dailyNum; i++ )
		{
			if ( strcmp( store.dailyArr[i].name, m_name ) == 0 )
			{
				cout << "商品名称重复！请重新输入" << endl;
				system( "pause" );
				return 0;
			}
		}
		strcpy( store.dailyArr[store.dailyNum].name, m_name );
		float m_inPrice = 0;
		cout << "请输入商品进价(进价<=售价)：" << endl;
		cin >> m_inPrice;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}

		float m_outPrice = 0;
		cout << "请输入商品售价：" << endl;
		cin >> m_outPrice;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		if ( m_outPrice < m_inPrice )
		{
			cout << "进价需小于等于售价！！！" << endl;
			system( "pause" );
			return 0;
		}
		store.dailyArr[store.dailyNum].inPrice = m_inPrice;
		store.dailyArr[store.dailyNum].outPrice = m_outPrice;
		int m_count = 0;
		cout << "请输入商品数量(数量需>=50)：" << endl;
		cin >> m_count;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		if ( m_count < 50 )
			return 0;
		cout << "请确认添加是否无误(换行即添加无误)" << endl;
		char m;
		cin.get( m );
		if ( cin.get() != '\n' )
			return 0;
		store.dailyArr[store.dailyNum].count = m_count;
		store.dailyArr[store.dailyNum].sort = 3;
		bill.totalPay += m_inPrice * m_count;
		cout << "添加成功，此商品的编号为： " << store.dailyNum++ + 1 << endl;
		system( "pause" );
	}
}
int addBeer()
{
	while ( true )
	{
		char m_name[51];
		system( "cls" );
		cout << GREY << "输入0以退出" << RESET << endl;
		cout << "请输入商品名称：(长度不得超过10个字)" << endl;
		cin >> m_name;
		int len = strlen( m_name );
		if ( !strcmp( m_name, "0" ) )
			return 1;

		else if ( len > 20 )
		{
			cout << "名称过长" << endl;
			system( "pause" );
			return 0;
		}
		for ( int i = 0; i < store.beerNum; i++ )
		{
			if ( strcmp( store.beerArr[i].name, m_name ) == 0 )
			{
				cout << "商品名称重复！请重新输入" << endl;
				system( "pause" );
				return 0;
			}
		}
		strcpy( store.beerArr[store.beerNum].name, m_name );
		float m_inPrice = 0;
		cout << "请输入商品进价(进价<=售价)：" << endl;
		cin >> m_inPrice;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}

		float m_outPrice = 0;
		cout << "请输入商品售价：" << endl;
		cin >> m_outPrice;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		if ( m_outPrice < m_inPrice )
		{
			cout << "进价需小于等于售价！！！" << endl;
			system( "pause" );
			return 0;
		}
		store.beerArr[store.beerNum].inPrice = m_inPrice;
		store.beerArr[store.beerNum].outPrice = m_outPrice;
		int m_count = 0;
		cout << "请输入商品数量(数量需>=50)：" << endl;
		cin >> m_count;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		if ( m_count < 50 )
			return 0;
		cout << "请确认添加是否无误(换行即添加无误)" << endl;
		char m;
		cin.get( m );
		if ( cin.get() != '\n' )
			return 0;
		store.beerArr[store.beerNum].count = m_count;
		store.beerArr[store.beerNum].sort = 4;
		bill.totalPay += m_inPrice * m_count;
		cout << "添加成功，此商品的编号为： " << store.beerNum++ + 1 << endl;
		system( "pause" );
	}
}
int addGoods() // 添加商品选择
{
	int select = 0;
	while ( true )
	{
		system( "cls" );
		addGoodsMenu();
		cin >> select;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		switch ( select )
		{
		case 1:
			system( "cls" );
			while ( !addFood() );
			system( "cls" );
			break;
		case 2:
			system( "cls" );
			while ( !addDrink() );
			system( "cls" );
			break;
		case 3:
			system( "cls" );
			while ( !addDaily() );
			system( "cls" );
			break;
		case 4:
			system( "cls" );
			while ( !addBeer() );
			system( "cls" );
			break;
		case 0:
			system( "cls" );
			return 1;
		default:
			// 提示用户输入错误
			cout << "输入错误，请重新输入！" << endl;
			system( "pause" );
			break;
		}
	}
}


int viewGoods2( char m_name[] ) // 查看特定商品
{

	system( "cls" );
	cout << GREY << "输入0以退出" << RESET << endl;
	cout << "请输入商品名称进行查找" << endl;
	cin >> m_name;
	int len = strlen( m_name );
	if ( !strcmp( m_name, "0" ) )
		return 1;

	else if ( len > 20 )
	{
		cout << "名称过长" << endl;
		system( "pause" );
		return 0;
	}
	for ( int i = 0; i < store.foodNum; i++ )
	{
		if ( !strcmp( store.foodArr[i].name, m_name ) )
		{
			cout << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
			     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
			     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n"
			     << "┃" << setw( 20 ) << left << store.foodArr[i].name
			     << "┃" << setw( 7 ) << left << store.foodArr[i].inPrice
			     << "┃" << setw( 7 ) << left << store.foodArr[i].outPrice
			     << "┃" << setw( 4 ) << left << store.foodArr[i].count
			     << "┃" << setw( 4 ) << left << i + 1 << "┃\n"
			     << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
			system( "pause" );
			return 0;
		}
	}
	for ( int i = 0; i < store.drinkNum; i++ )
	{
		if ( !strcmp( store.drinkArr[i].name, m_name ) )
		{
			cout << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
			     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
			     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n"
			     << "┃" << setw( 20 ) << left << store.drinkArr[i].name
			     << "┃" << setw( 7 ) << left << store.drinkArr[i].inPrice
			     << "┃" << setw( 7 ) << left << store.drinkArr[i].outPrice
			     << "┃" << setw( 4 ) << left << store.drinkArr[i].count
			     << "┃" << setw( 4 ) << left << i + 1 << "┃\n"
			     << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
			system( "pause" );
			return 0;
		}
	}
	for ( int i = 0; i < store.dailyNum; i++ )
	{
		if ( !strcmp( store.dailyArr[i].name, m_name ) )
		{
			cout << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
			     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
			     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n"
			     << "┃" << setw( 20 ) << left << store.dailyArr[i].name
			     << "┃" << setw( 7 ) << left << store.dailyArr[i].inPrice
			     << "┃" << setw( 7 ) << left << store.dailyArr[i].outPrice
			     << "┃" << setw( 4 ) << left << store.dailyArr[i].count
			     << "┃" << setw( 4 ) << left << i + 1 << "┃\n"
			     << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
			system( "pause" );
			return 0;
		}
	}
	for ( int i = 0; i < store.beerNum; i++ )
	{
		if ( !strcmp( store.beerArr[i].name, m_name ) )
		{
			cout << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
			     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
			     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n"
			     << "┃" << setw( 20 ) << left << store.beerArr[i].name
			     << "┃" << setw( 7 ) << left << store.beerArr[i].inPrice
			     << "┃" << setw( 7 ) << left << store.beerArr[i].outPrice
			     << "┃" << setw( 4 ) << left << store.beerArr[i].count
			     << "┃" << setw( 4 ) << left << i + 1 << "┃\n"
			     << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
			system( "pause" );
			return 0;
		}
	}
	cout << "暂无此商品信息" << endl;
	system( "pause" );

	return 1;
}
void viewGoods1() // 查看所有商品信息
{
	system( "cls" );
	displayStore();

	cout << GREY << "输入0以退出" << RESET << endl;
	int m;
	cin >> m;
	if ( m == 0 )
		return;
	system( "pause" );
	system( "cls" );
}
int viewGoods( ) // 查看商品菜单
{
	int select;
	while ( true )
	{
		system( "cls" );
		viewGoodsMenu();
		cin >> select;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		system( "cls" );
		switch ( select )
		{
		case 1:
			viewGoods1();
			break;
		case 2:
			char m_name[51];
			viewGoods2( m_name );
			break;
		case 0:
			return 1;
		default:
			break;
		}
	}
}


int modifyFood( int i ) // 修改食品选择
{
	int select;
	while ( true )
	{
		system( "cls" );
		cout << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
		     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n"
		     << "┃" << setw( 20 ) << left << store.foodArr[i].name
		     << "┃" << setw( 7 ) << left << store.foodArr[i].inPrice
		     << "┃" << setw( 7 ) << left << store.foodArr[i].outPrice
		     << "┃" << setw( 4 ) << left << store.foodArr[i].count
		     << "┃" << setw( 4 ) << left << i + 1 << "┃\n"
		     << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
		modifyGoodsMenu();
		cin >> select;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		system( "cls" );
		switch ( select )
		{
		case 1:// 修改食品名称
			char m_name[51];
			cout << "请修改食品名称：" << endl;
			cin >> m_name;
			strcpy( store.foodArr[i].name, m_name );
			break;
		case 2:// 修改食品进价
			float m_inPrice;
			cout << "请修改食品进价：" << endl;
			cin >> m_inPrice;
			store.foodArr[i].inPrice = m_inPrice;
			break;
		case 3:// 修改食品售价
			float m_outPrice;
			cout << "请修改食品售价" << endl;
			cin >> m_outPrice;
			store.foodArr[i].outPrice = m_outPrice;
			break;
		case 0:// 退出食品修改
			return 1;
		default:
			break;
		}
	}
}
int modifyDrink( int i ) // 修改饮品选择
{
	int select;
	while ( true )
	{
		system( "cls" );
		cout << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
		     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n"
		     << "┃" << setw( 20 ) << left << store.drinkArr[i].name
		     << "┃" << setw( 7 ) << left << store.drinkArr[i].inPrice
		     << "┃" << setw( 7 ) << left << store.drinkArr[i].outPrice
		     << "┃" << setw( 4 ) << left << store.drinkArr[i].count
		     << "┃" << setw( 4 ) << left << i + 1 << "┃\n"
		     << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
		modifyGoodsMenu();
		cin >> select;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		system( "cls" );
		switch ( select )
		{
		case 1:// 修改食品名称
			char m_name[51];
			cout << "请修改饮品名称" << endl;
			cin >> m_name;
			strcpy( store.drinkArr[i].name, m_name );
			break;
		case 2:// 修改饮品进价
			float m_inPrice;
			cout << "请修改饮品进价" << endl;
			cin >> m_inPrice;
			store.drinkArr[i].inPrice = m_inPrice;
			break;
		case 3:// 修改饮品售价
			float m_outPrice;
			cout << "请修改饮品售价" << endl;
			cin >> m_outPrice;
			store.drinkArr[i].outPrice = m_outPrice;
			break;
		case 0:// 退出食品修改
			return 1;
		default:
			break;
		}
	}
}
int modifyDaily( int i ) // 修改日用品选择
{
	int select;
	while ( true )
	{
		system( "cls" );
		cout << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
		     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n"
		     << "┃" << setw( 20 ) << left << store.dailyArr[i].name
		     << "┃" << setw( 7 ) << left << store.dailyArr[i].inPrice
		     << "┃" << setw( 7 ) << left << store.dailyArr[i].outPrice
		     << "┃" << setw( 4 ) << left << store.dailyArr[i].count
		     << "┃" << setw( 4 ) << left << i + 1 << "┃\n"
		     << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
		modifyGoodsMenu();
		cin >> select;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		system( "cls" );
		switch ( select )
		{
		case 1:// 修改日用品名称
			char m_name[51];
			cout << "请修改日用品名称" << endl;
			cin >> m_name;
			strcpy( store.dailyArr[i].name, m_name );
			break;
		case 2:// 修改日用品进价
			float m_inPrice;
			cout << "请修改日用品进价" << endl;
			cin >> m_inPrice;
			store.dailyArr[i].inPrice = m_inPrice;
			break;
		case 3:// 修改日用品售价
			float m_outPrice;
			cout << "请修改日用品售价" << endl;
			cin >> m_outPrice;
			store.dailyArr[i].outPrice = m_outPrice;
			break;
		case 0:// 退出食品修改
			return 1;
		default:
			break;
		}
	}
}
int modifyBeer( int i ) // 修改烟酒选择
{
	int select;
	while ( true )
	{
		system( "cls" );
		cout << "┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━┳━━━━┓\n"
		     << "┃     商 品 名 称    ┃ 进 价 ┃ 售 价 ┃数量┃编号┃\n"
		     << "┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━╋━━━━┫\n"
		     << "┃" << setw( 20 ) << left << store.beerArr[i].name
		     << "┃" << setw( 7 ) << left << store.beerArr[i].inPrice
		     << "┃" << setw( 7 ) << left << store.beerArr[i].outPrice
		     << "┃" << setw( 4 ) << left << store.beerArr[i].count
		     << "┃" << setw( 4 ) << left << i + 1 << "┃\n"
		     << "┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━┻━━━━┛\n";
		modifyGoodsMenu();
		cin >> select;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		system( "cls" );
		switch ( select )
		{
		case 1:// 修改烟酒名称
			char m_name[51];
			cout << "请修改烟酒名称" << endl;
			cin >> m_name;
			strcpy( store.beerArr[i].name, m_name );
			break;
		case 2:// 修改烟酒进价
			float m_inPrice;
			cout << "请修改烟酒进价" << endl;
			cin >> m_inPrice;
			store.beerArr[i].inPrice = m_inPrice;
			break;
		case 3:// 修改烟酒售价
			float m_outPrice;
			cout << "请修改烟酒售价" << endl;
			cin >> m_outPrice;
			store.beerArr[i].outPrice = m_outPrice;
			break;
		case 0:// 退出食品修改
			return 1;
		default:
			break;
		}
	}
}
int modifyGoods( char m_name[] ) // 修改商品信息
{
	while ( true )
	{
		system( "cls" );
		displayStore();
		cout << GREY << "输入0以退出" << RESET << endl;
		cout << "请输入要修改的商品名称: " << endl;
		cin >> m_name;
		if ( !strcmp( m_name, "0" ) )
		{
			system( "cls" );
			return 1;
		}

		int len = strlen( m_name );
		if ( len > 20 )
		{
			cout << "名称过长,名称错误" << endl;
			system( "pause" );
			return 0;
		}
		for ( int i = 0; i < store.foodNum; i++ )
		{
			if ( strcmp( store.foodArr[i].name, m_name ) == 0 )
				modifyFood( i );
		}
		for ( int i = 0; i < store.drinkNum; i++ )
		{
			if ( strcmp( store.drinkArr[i].name, m_name ) == 0 )
				modifyDrink( i );
		}
		for ( int i = 0; i < store.drinkNum; i++ )
		{
			if ( strcmp( store.dailyArr[i].name, m_name ) == 0 )
				modifyDaily( i );
		}
		for ( int i = 0; i < store.beerNum; i++ )
		{
			if ( strcmp( store.beerArr[i].name, m_name ) == 0 )
				modifyBeer( i );
		}
	}
}


void addFoodCount( char m_name[], int i ) // 增加食品库存
{
	cout << m_name << "当前的数量为" << store.foodArr[i].count << endl;
	int n;
	cout << "请输入需要该食品添加的数量" << endl;
	cin >> n;
	store.foodArr[i].count = store.foodArr[i].count + n;
	bill.totalPay += store.foodArr[i].inPrice * n;
	cout << "成功增加" << m_name << "的数量,现数量为：" << endl;
	cout << store.foodArr[i].count << endl;
	system( "pause" );
}
void addDrinkCount( char m_name[], int i ) // 增加饮品库存
{
	cout << m_name << "当前的数量为" << store.drinkArr[i].count << endl;
	int n;
	cout << "请输入需要该饮品添加的数量" << endl;
	cin >> n;
	store.drinkArr[i].count = store.drinkArr[i].count + n;
	bill.totalPay += store.drinkArr[i].inPrice * n;
	cout << "成功增加" << m_name << "的数量,现数量为：" << endl;
	cout << store.drinkArr[i].count << endl;
	system( "pause" );
}
void addDailyCount( char m_name[], int i ) // 增加日用品库存
{
	cout << m_name << "当前的数量为" << store.dailyArr[i].count << endl;
	int n;
	cout << "请输入需要该日用品添加的数量" << endl;
	cin >> n;
	store.dailyArr[i].count = store.dailyArr[i].count + n;
	bill.totalPay += store.dailyArr[i].inPrice * n;
	cout << "成功增加" << m_name << "的数量,现数量为：" << endl;
	cout << store.dailyArr[i].count << endl;
	system( "pause" );
}
void addBeerCount( char m_name[], int i ) // 增加烟酒库存
{
	cout << m_name << "当前的数量为" << store.beerArr[i].count << endl;
	int n;
	cout << "请输入需要该烟酒添加的数量" << endl;
	cin >> n;
	store.beerArr[i].count = store.beerArr[i].count + n;
	bill.totalPay += store.beerArr[i].inPrice * n;
	cout << "成功增加" << m_name << "的数量,现数量为：" << endl;
	cout << store.beerArr[i].count << endl;
	system( "pause" );
}
void countAlarm() // 商品预警
{
	system( "cls" );
	cout << RED << "以下商品库存疑似过少： " << RESET << endl;
	int i = 0;
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "         **食品**" << endl;
	for ( i = 0; i < store.foodNum; i++ )
	{
		if ( store.foodArr[i].count < 15 )
		{
			cout << YELLOW << store.foodArr[i].name << RESET << "剩余数量： ";
			cout << store.foodArr[i].count << endl;
			cout << "当前商品利润为： " << store.foodArr[i].income << endl;
		}
	}
	cout << endl;


	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "         **饮品**" << endl;
	i = 0;
	for ( ; i < store.drinkNum; i++ )
	{
		if ( store.drinkArr[i].count < 15 )
		{
			cout << YELLOW << store.drinkArr[i].name << RESET << "剩余数量： ";
			cout << store.drinkArr[i].count << endl;
			cout << "当前商品利润为： " << store.drinkArr[i].income << endl;
		}
	}
	cout << endl;


	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "        **日用品**" << endl;
	i = 0;
	for ( ; i < store.dailyNum; i++ )
	{
		if ( store.dailyArr[i].count < 15 )
		{
			cout << YELLOW << store.dailyArr[i].name << RESET << "剩余数量： ";
			cout << store.dailyArr[i].count << endl;
			cout << "当前商品利润为： " << store.dailyArr[i].income << endl;
		}
	}
	cout << endl;


	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "         **烟酒**" << endl;
	i = 0;
	for ( ; i < store.beerNum; i++ )
	{
		if ( store.beerArr[i].count < 15 )
		{
			cout << YELLOW << store.beerArr[i].name << RESET << "剩余数量： ";
			cout << store.beerArr[i].count << endl;
			cout << "当前商品利润为： " << store.beerArr[i].income << endl;
		}
	}
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
}
int addCount( char m_name[] ) // 增加商品库存
{
	countAlarm();
	while ( true )
	{
		cout << GREY << "输入0以退出" << RESET << endl;
		cout << "请输入要增加的商品名称: " << endl;
		cin >> m_name;
		if ( !strcmp( m_name, "0" ) )
		{
			system( "cls" );
			return 1;
		}

		int len = strlen( m_name );
		if ( len > 20 )
		{
			cout << "名称过长,名称错误" << endl;
			system( "pause" );
			system( "cls" );
			return 0;
		}
		for ( int i = 0; i < store.foodNum; i++ )
		{
			if ( strcmp( store.foodArr[i].name, m_name ) == 0 )
				addFoodCount( m_name, i );
		}
		for ( int i = 0; i < store.drinkNum; i++ )
		{
			if ( strcmp( store.drinkArr[i].name, m_name ) == 0 )
				addDrinkCount( m_name, i );
		}
		for ( int i = 0; i < store.drinkNum; i++ )
		{
			if ( strcmp( store.dailyArr[i].name, m_name ) == 0 )
				addDailyCount( m_name, i );
		}
		for ( int i = 0; i < store.beerNum; i++ )
		{
			if ( strcmp( store.beerArr[i].name, m_name ) == 0 )
				addBeerCount( m_name, i );
		}
	}
}


int deleteGoods( char m_name[] ) // 删除商品信息
{
	while ( true )
	{
		system( "cls" );
		displayStore();
		cout << GREY << "输入0以退出" << RESET << endl;
		cout << "请输入要删除的商品名称: " << endl;
		cin >> m_name;
		int len = strlen( m_name ), flag = 0;

		if ( !strcmp( m_name, "0" ) )
			return 1;
		if ( len > 20 )
		{
			cout << "名称过长,名称错误" << endl;
			system( "pause" );
			return 0;
		}

		for ( int i = 0; i < store.foodNum; i++ )
		{
			if ( strcmp( store.foodArr[i].name, m_name ) == 0 )
			{
				if ( store.foodArr[i].count == 0 )
				{
					for ( int j = i; j < store.foodNum; j++ )
						store.foodArr[j] = store.foodArr[j + 1];
					store.foodNum--;
					flag = 1;
					cout << "删除成功" << endl;
					system( "pause" );
				}
				else
				{
					cout << "未销售完的商品，不得删除" << endl;
					system( "pause" );
				}
			}
		}
		for ( int i = 0; i < store.drinkNum; i++ )
		{
			if ( strcmp( store.drinkArr[i].name, m_name ) == 0 )
			{
				if ( store.drinkArr[i].count == 0 )
				{
					for ( int j = i; j < store.drinkNum; j++ )
						store.drinkArr[j] = store.drinkArr[j + 1];
				}
				store.drinkNum--;
				flag = 1;
				cout << "删除成功" << endl;
				system( "pause" );
			}
			else
			{
				cout << "未销售完的商品，不得删除" << endl;
				system( "pause" );
			}
		}
		for ( int i = 0; i < store.drinkNum; i++ )
		{
			if ( strcmp( store.dailyArr[i].name, m_name ) == 0 )
			{
				if ( store.dailyArr[i].count == 0 )
				{
					for ( int j = i; j < store.dailyNum; j++ )
						store.dailyArr[j] = store.dailyArr[j + 1];
				}
				store.dailyNum--;
				flag = 1;
				cout << "删除成功" << endl;
				system( "pause" );
			}
			else
			{
				cout << "未销售完的商品，不得删除" << endl;
				system( "pause" );
			}
		}
		for ( int i = 0; i < store.beerNum; i++ )
		{
			if ( strcmp( store.beerArr[i].name, m_name ) == 0 )
			{
				if ( store.beerArr[i].count == 0 )
				{
					for ( int j = i; j < store.beerNum; j++ )
						store.beerArr[j] = store.beerArr[j + 1];
					store.beerNum--;
					flag = 1;
					cout << "删除成功" << endl;
				}
				else
				{
					cout << "未销售完的商品不得删除" << endl;
					system( "pause" );
				}
			}
		}
		if ( !flag )
		{
			cout << "未找到要删除的商品" << endl;
			system( "pause" );
		}
		system( "cls" );
	}
}


int storeMenu() // 库存菜单选择
{
	int select = 0;
	while ( true )
	{

		goodsMenu();
		system( "cls" );
		displayStore();
		goodsMenu();
		cin >> select;
		if ( cin.fail() )
		{
			cout << "输入无效，请重新输入" << endl;
			cin.clear(); // 清除错误状态标志
			cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // 忽略缓冲区中的所有字符直到换行符
			system( "pause" );
			continue; // 返回重新输入
		}
		switch ( select )
		{
		case 1:// 添加商品
			addGoods();
			break;
		case 2:// 修改商品信息
			char m_name[51];
			modifyGoods( m_name );
			break;
		case 3:// 增加商品库存
			char m_Name[51];
			addCount( m_Name );
			break;
		case 4:// 删除商品
			char h_name[51];
			deleteGoods( h_name );
			break;
		case 5:// 查看商品信息
			viewGoods(); // 查看商品菜单
			break;
		case 0:// 返回主菜单
			system( "cls" );
			return 1;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
	}
}
