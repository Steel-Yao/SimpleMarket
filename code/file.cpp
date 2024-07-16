#include "first_time.h"	// 初始化（系统首次运行）

#include <fstream>

#include "struct.h"		// 自定义结构体（包含自定义参数）
#include "first_time.h"	// 初始化（系统首次运行）

using namespace std;

ofstream ofs;
ifstream ifs;

/***************文件处理***************/

// 读入文件数据
void fileToData()
{
	// 读入账户数据
	ifs.open( "market_accounts", ios::in | ios::binary );
	if ( !( ifs.is_open() ) )
	{
		while ( !firstTime() );
	}
	else
	{
		ifs.read( ( char * )&crew, sizeof( Accounts ) );
		ifs.close();
	}

	// 读入库存数据
	ifs.open( "market_store", ios::in | ios::binary );
	if ( ifs.is_open() )
	{
		ifs.read( ( char * )&store, sizeof( StoreHouse ) );
		ifs.close();
	}

	// 读入账单数据
	ifs.open( "market_bill", ios::in | ios::binary );
	if ( ifs.is_open() )
	{
		ifs.read( ( char * )&bill, sizeof( BillStore ) );
		ifs.close();
	}

	return;
}

// 保存数据到文件
void dataToFile()
{
	// 保存账户数据
	ofs.open( "market_accounts", ios::out | ios::binary );
	ofs.write( ( const char * )&crew, sizeof( Accounts ) );
	ofs.close();

	// 保存库存数据
	ofs.open( "market_store", ios::out | ios::binary );
	ofs.write( ( const char * )&store, sizeof( StoreHouse ) );
	ofs.close();

	// 保存账单数据
	ofs.open( "market_bill", ios::out | ios::binary );
	ofs.write( ( const char * )&bill, sizeof( BillStore ) );
	ofs.close();

	return;
}
