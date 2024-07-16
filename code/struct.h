#ifndef STRUCT_H
#define STRUCT_H

// 自定义参数
#define CLERK 5			// 店员容量
#define BILL 50			// 账单容量
#define BILLGOODS 50	// 单账单商品容量
#define FOOD 10			// 食品最大种数
#define DRINK 10		// 饮品最大种数
#define DAILY 10		// 日用品最大种数
#define BEER 10			// 烟酒最大种数

/*************时间*************/

struct Time
{
	int year;
	int month;
	int day;
};

/***********店员账号***********/

struct Clerks
{
	char clerkID[11];		// 店员账号
	char clerkPassword[21];	// 登陆密码
};

/**********全部账号**********/

struct Accounts
{
	char superID[11];		// 超级管理员账号
	char superPassword[21];	// 超级管理员密码
	Clerks clerkArr[CLERK];	// 店员信息
	int clerkNum = 0;		// 已有店员数量
};

/************商品************/

struct Goods
{
	char name[21];		// 名称
	int sort;			// 分类：食品（1）、饮品（2）、日用品（3）、烟酒（4）
	float inPrice;		// 进价
	float outPrice;		// 售价
	int count = 0;		// 数量
	float income = 0;	// 该商品取得的总利润
	float allprice;		// 小计
	float superout;		// 总价
};

/************仓库************/

struct StoreHouse
{
	Goods foodArr[FOOD];	// 食品
	int foodNum = 0;		// 已有食品种数

	Goods drinkArr[DRINK];	// 饮品
	int drinkNum = 0;		// 已有饮品种数

	Goods dailyArr[DAILY];	// 日用品
	int dailyNum = 0;		// 已有日用品种数

	Goods beerArr[BEER];	// 烟酒
	int beerNum = 0;		// 已有烟酒种数
};

/**************账单**************/

struct Bill
{
	Goods outGoods[BILLGOODS];	// 购买的商品信息
	int goodsNum;				// 购买商品数量
	Time billTime;				// 账单时间
};

/**************账单存储**************/

struct BillStore
{
	Bill billArr[BILL];		// 账单
	int billNum;			// 已有帐单数量
	float totalPay = 0;		// 总支出
	float totalIncome = 0;	// 总收入
};

extern Accounts crew;
extern StoreHouse store;
extern BillStore bill;

#endif
