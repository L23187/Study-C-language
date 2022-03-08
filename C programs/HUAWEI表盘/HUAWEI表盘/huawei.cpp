#include<stdio.h>
#include<graphics.h>//easyx 图形库头文件
#include<time.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
/*
	1、调好文本的样式
	2、动画效果
	3、显示动态时间
	4、组装整个表盘
*/
#define WIN_SIZE 500			//窗口大小
#define WIN_HALF (WIN_SIZE/2)    //窗口的一半

IMAGE spaceman[48];	//太空人图片数组
IMAGE heartbeat[1];
void loadImage() {
	//加载图片	[0-47]
	char fileName[50] = { 0 };//定义一个字符数组将 "./image/%d.jpg" 这句话变为一个数组 把里面的数字进行改变 达到更换图片的目的
	for (int i = 0; i < 48; i++)
	{
		sprintf_s(fileName,"./image/%d.jpg",i);
		printf("\n");
		loadimage(spaceman + i, fileName, 140, 130);
	}
	
	//显示心跳

	
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
	static DWORD t1 = clock(); //DWord是为了兼容Windows基础类库而重名的一个类型，与MFC是一样的。表示Double Word的意思。固定4byte.
	//static 只初始化一次，在整个程序运行期间只运行一次

	/*关于DWORD使用中重要的一点。DWORD 现在表示 32bit 无符号整数，即使以后 Windows
　　升级到64位，DWORD 仍然是 32bit 无符号整数（也许以后的 long 不
　　是32bit了，只需要重新定义一下 DWORD 就可以了）。对于那些直接
　　和位数有关的整数，最好不用 int, long, short 之内的内型，因为
　　这些类型的位数可能不确定（比如，在16位程序里，int 是16位的，在
　　32位程序里，int 是32位的，谁知道在以后的64位程序里，int 是多少
　　位，long 又是多少位）。用重新定义的内型就没有这方面的问题了，
　　最多到时候修改一下定义就可以了，而不需要在程序里一行一行的查找*/

	DWORD t2 = clock();//获取程序运行到调用该函数所经过的毫秒数
	//printf("时间差：%d\n",t2-t1);
	//把图片输出到窗口上面
	static int i = 0;
	if (t2 - t1 > 20) {

		i = (i + 1) % 48;//每48张图片循环一次，类似于一个循环
		t1 = t2;
	}
	putimage(WIN_HALF - 60, WIN_HALF -70, spaceman + i);

	/*//这个可以让太空人动起来，但是不是理想效果，这个可以提供好效果，但是不能使用
	for (int i = 0; i < 48; i++)
	{
		Sleep(20);//延迟20毫秒	但是这个Sleep函数会让程序休眠，它会整个程序都延迟，可以使用定时器解决
		putimage(150, 150, spaceman + i);
		
	}*/
	
}
//其他界面绘制
void gameDraw() {

	//设置背景颜色
	setbkcolor(RGB(255, 255, 255));//这个颜色无法直接显示到界面上，因为界面上原来有一层黑色，需要把它清除掉（下一行）
	cleardevice();	//清空绘图设备
	setbkmode(TRANSPARENT);//将背景设置为透明

	//绘制表盘
	setlinecolor(RGB(68,68,68));
	setlinestyle(PS_SOLID, 40);
	setfillcolor(RGB(255, 255, 255));
	fillellipse(0, 0, WIN_SIZE, WIN_SIZE);

	//绘制线条
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 4);

	//竖线
	line(WIN_HALF - 30, 20, WIN_HALF - 30, 130);
	//横线
	line(WIN_HALF - 195, WIN_HALF-120, WIN_HALF + 195, WIN_HALF - 120);
	line(WIN_HALF - 195, WIN_HALF + 120, WIN_HALF + 195, WIN_HALF + 120);

	//显示动态时间
	//获取当前的系统时间 time.h
	time_t curTime = time(NULL);
	//printf("%lld\n", curTime);//1643084614 包含年月日时间,需要函数进行翻译
	struct tm * humanTime = localtime(&curTime);
	char buf[40] = { 0 };
	sprintf_s(buf, "%d:%d", humanTime->tm_hour, humanTime->tm_min);
	outtextxy(WIN_HALF-145, WIN_HALF-115, buf);//表明时间的位置
	sprintf_s(buf, "%d", humanTime->tm_sec);
	outtextxy(335,160, buf);//表明时间的位置
}

//添加背景音乐
void getMusic() {
	mciSendString("open ./image/危险派对.mp3 alias bkmusic", NULL, 0, NULL);
	/*
	open指令打开需要播放的音乐，alias后面制定了前面文件路径的别名，以后想要操作这个文件直接使用这个别名即可
	如果音乐文件和我们的debug文件夹在同一目录下，就可以直接写音乐名

	*/
	mciSendString("play bkmusic repeat", NULL, 0, NULL);//循环播放音乐
	system("pause");
}
int main() {
	//创建一个图形界面
	initgraph(500, 500,EW_SHOWCONSOLE);

	//设置背景颜色
	setbkcolor(RGB(255,255,255));//这个颜色无法直接显示到界面上，因为界面上原来有一层黑色，需要把它清除掉（下一行）
	cleardevice();	//清空绘图设备

	//设置文字样式
	settextcolor(BLACK);//设置文本颜色
	setTextStyle(55, 23, "Arial");
	outtextxy(50, 50, "90%");//在客户界面的指定位置显示"" 
	loadImage();

	BeginBatchDraw();//双缓冲绘图 可以用来防止闪屏
	
	while (true)
	{
		gameDraw();
		animation();
		FlushBatchDraw();
		getMusic();
	}

	
	getchar();
	return 0;
}