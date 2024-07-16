简单的命令行超市收银系统
====
简介
----
这是一个简单的命令行超市收银系统，由我和另外两位同学合作完成。

这个项目其实是学校某门课程的期末作业，当时还没有学习面向对象的程序设计方法，所以虽然使用的是 `C++` 语言，但采用的仍然是面向过程的编程思想。

> - 此项目已经通过课程的期末答辩，并获得了 **“优”** 的成绩
> - 程序的图标来自 [iconfont-阿里巴巴矢量图标库](https://www.iconfont.cn/)

- **注意：只有程序被正常退出时（即输入退出指令“0”时），才会将数据保存到文件！直接点击❌无法保存数据！**

截图
----
![主菜单](<screenshots/main menu.png>)
![超市管理菜单](<screenshots/market manage.png>)
![库存管理菜单](<screenshots/storehouse manage.png>)
![货物清单](<screenshots/storehouse list.png>)
![账单处理菜单](<screenshots/bill manage.png>)

安装
----
直接下载 `Market.exe` ，双击运行即可。

>程序首次运行会在运行目录创建三个二进制文件 `market_accounts` 、`market_store` 和 `market_bill` ，分别用来存储账户、库存和账单信息。*（示例数据可以在文件夹 `data` 中找到。）*

卸载
----
直接删除 `exe` 文件即可，注意删除与其在同一目录的三个二进制文件。
