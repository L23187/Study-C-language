#include<stdio.h>
#include<graphics.h>//easyx 图形库头文件
#include<time.h>
/*
	1、调好文本的样式
	2、动画效果
	3、

*/
IMAGE spaceman[48];	//太空人图片数组
void loadImage() {
	//加载图片	[0-47]
	char fileName[50] = { 0 };//定义一个字符数组将 "./image/%d.jpg" 这句话变为一个数组 把里面的数字进行改变 达到更换图片的目的
	for (int i = 0; i < 48; i++)
	{
		sprintf_s(fileName,"./image/%d.jpg",i);
		printf("\n");
		loadimage(spaceman + i, fileName, 140, 130);
	}
	
	
}
//设置文字样式
void setTextStyle(int h,int w,const char *faceName) {
	LOGFONT f = { 0 };		//如果没有设置初始值的话，默认会设置一个乱值	结构体相当于一个数组，只是里面成员类型不一样
	f.lfHeight = h;
	f.lfWidth = w;
	strcpy(f.lfFaceName, faceName);
	settextstyle(&f);//设置文本样式		该函数需要一个设置好的LOGFONT的地址
}

//太空人动画效果
void animation() {
	//把图片输出到窗口上面
	for (int i = 0; i < 48; i++)//这个可以让太空人动起来，但是不是理想效果
	{
		Sleep(20);//延迟20毫秒	但是这个Sleep函数会让程序休眠，它会整个程序都延迟，可以使用定时器解决
		putimage(150, 150, spaceman + i);
	}
}
int main() {
	//创建一个图形界面
	initgraph(500, 500);

	//设置背景颜色
	setbkcolor(RGB(255,255,255));//这个颜色无法直接显示到界面上，因为界面上原来有一层黑色，需要把它清除掉（第14行）
	cleardevice();	//清空绘图设备

	//设置文字样式
	settextcolor(BLACK);//设置文本颜色
	setTextStyle(55, 23, "Arial");
	outtextxy(50, 50, "90%");//在客户界面的指定位置显示"" 
	loadImage();
	while (true)
	{
		animation();
	}
	getchar();
	return 0;
}