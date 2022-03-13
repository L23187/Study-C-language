#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#pragma comment(lib, "Winmm.lib")
void start(); //开始界面
void chose(); //选择模式;0:普通模式 1:穿墙模式 2:无敌模式 3:自动模式
void init(); //初始化游戏数据
void DrawMap(); //绘制地图
void ChangeDir(); //接收命令,改变方向
void move(); //蛇的移动
void addfood(int order); //添加食物
void autoseek(); //自动寻找食物模式

enum game //枚举类型
{
    SPACE, WALL, SNAKE, FOOD //SPACE = 0, WALL = 1, SMAKE = 2, FOOD = 3
};
int mode; //游戏模式
int score; //分数

const int ROW = 50; //地图行数
const int COL = 50; //地图列数
const int number = 3; //食物数量
const int width = 500; //图形宽度(x)
const int high = 520; //图形高度(y)
int map[ROW][COL]; //地图大小
COORD food[number]; //食物的位置
COORD snake[ROW * COL]; //蛇的位置
int SnakeSize; //蛇的尺寸
char SnakeDir; //蛇的移动方向
char path[ROW - 2][COL - 2] = { 0 }; //路径
bool path_mark[ROW - 2][COL - 2]; //路径标志

int time1 = 50; //设定延时时间

int main()
{
    DWORD t1 = 0, t2 = 0; //延时时间(32位无符号整型)

    mciSendString(L"open D:\\22-音效\\ACG经典爆裂双吉他串烧.wav alias bgm", 0, 0, 0); //打开背景音乐
    mciSendString(L"play bgm", 0, 0, 0); //播放背景音乐

    initgraph(500, 520); //初始化图形界面: x=500, y=520
    start(); //开始界面
    outtextxy(170, 100, L"->"); //初始默认模式一

    chose(); //选择游戏模式;Enter键进入游戏

    init();  //初始化游戏参数

    while (1)
    {
        t2 = GetTickCount();

        DrawMap(); //绘制地图
        if (_kbhit()) //等待键盘输入命令
        {
            ChangeDir(); //接收命令
            move(); //移动

            t2 = GetTickCount();
            t1 = t2;
        }
        if (t2 - t1 > time1)
        {
            move(); //移动
            if (mode == 3)
            {
                autoseek();
            }
            t1 = t2; //更新时间
        }
    }
    return 0;
}
void start()
{
    setbkcolor(YELLOW); //设置窗口背景色;
    cleardevice(); //清除屏幕
    setbkmode(TRANSPARENT); //设置字体背景色为透明
    settextcolor(RED); //设置字体颜色为红色
    settextstyle(20, 0, _T("黑体")); //字体大小:20;字体类型:黑体
    outtextxy(200, 40, L"进入模式");
    outtextxy(190, 100, L"1.普通模式");
    outtextxy(190, 150, L"2.穿墙模式");
    outtextxy(190, 200, L"3.无敌模式");
    outtextxy(190, 250, L"4.自动模式");
    outtextxy(65, 300, L"数字键 1,2,3,4选择模式，Enter键进入游戏");
    outtextxy(65, 350, L"字母键 W,S,A,D 控制方向: 上 下 左 右 ");
    outtextxy(65, 400, L"空格键 暂停, Esc键 结束游戏");
}
void chose()
{
    while (1)
    {
        switch (_getch()) //接收字符
        {
        case '1':
            start();
            outtextxy(170, 100, L"->");
            mode = 0;
            break;
        case '2':
            start();
            outtextxy(170, 150, L"->");
            mode = 1;
            break;
        case '3':
            start();
            outtextxy(170, 200, L"->");
            mode = 2;
            break;
        case '4':
            start();
            outtextxy(170, 250, L"->");
            mode = 3;
            break;
        case 13: //回车键
            return; //返回
            break;
        }
    }
}
void init()
{
    srand((unsigned)time(NULL)); //随机数种子
    setbkcolor(BLACK); //设置背景颜色
    //初始化分数
    score = 0;
    //初始化map数组
    memset(map, SPACE, sizeof(map));
    // 每一行的 第一个 和 最后一个 是墙
    for (int i = 0; i < ROW; i++)
    {
        map[i][0] = map[i][COL - 1] = WALL;
    }
    //每一列的 第二个 和 倒数第二个是墙
    for (int j = 1; j < COL - 1; j++)
    {
        map[0][j] = map[ROW - 1][j] = WALL;
    }

    SnakeSize = 2; //蛇初始长度
    SnakeDir = 'D';
    //初始化蛇的位置
    map[1][2] = SNAKE; //头部
    map[1][1] = SNAKE; //身体
    snake[0].X = 1; snake[0].Y = 2; //头部位置
    snake[1].X = 1; snake[1].Y = 1; //身体位置
    path_mark[0][0] = path_mark[0][1] = path_mark[1][0] = path_mark[1][1] = true;
    //初始化食物位置
    for (int i = 0; i < number; i++)
    {
        addfood(i);
    }
    //初始化路径(ROW-2,COL-2)
    for (int i = 0; i < ROW - 2; i += 2)
    {
        for (int j = 0; j < COL - 2; j += 2)
        {
            path[i][j] = 'D';
            path[i][j + 1] = 'S';
            path[i + 1][j + 1] = 'A';
            path[i + 1][j] = 'W';
        }
    }
    //初始化路径标志(ROW-2,COL-2)
    for (int i = 0; i < ROW - 2; i++)
    {
        for (int j = 0; j < COL - 2; j++)
        {
            path_mark[i][j] = false;
        }
    }
    if (mode == 3)
    {
        autoseek();
    }
}
void DrawMap()
{
    BeginBatchDraw(); //开始绘图
    setbkcolor(BLACK); //设置背景颜色
    settextcolor(YELLOW); //设置文本颜色
    cleardevice(); //清屏

    WCHAR arr[10]; //保存成绩
    wsprintf(arr, L"总分：%d", score); //将成绩格式化输出到字符串arr中 
    outtextxy(0, 0, arr); //显示成绩

    for (int y = 0; y < ROW; y++) //y轴方向向下(行)
    {
        for (int x = 0; x < COL; x++) //x轴方向向右(列)
        {
            switch (map[y][x])
            {
            case SPACE:
                break;
            case WALL: //墙
                setlinecolor(BLACK); //设置线条颜色为黑色
                setfillcolor(WHITE); //设置填充颜色为白色
                fillrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30); //画方块,边长10,左右对角的坐标
                break;
            case SNAKE: //蛇
                if (y == snake[0].X && x == snake[0].Y)
                {
                    setfillcolor(LIGHTBLUE);
                    solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
                }
                else
                {
                    setfillcolor(RGB(255, 255, 0)); //黄  255 255 0
                    solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
                }
                break;
            case FOOD:
                setfillcolor(LIGHTRED); //食物颜色
                solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
                break;
            default:
                break;
            }
        }
    }
    EndBatchDraw(); //结束绘制
}
void autoseek()
{
    int temp = 0; //最短距离的食物序号
    int d = pow((snake[0].X - food[0].X), 2) + pow((snake[0].Y - food[0].Y), 2);
    //寻找最短距离的食物
    if (number > 1)
    {
        for (int i = 1; i < number; i++)
        {
            if (d > pow((snake[0].X - food[i].X), 2) + pow((snake[0].Y - food[i].Y), 2))
            {
                d = pow((snake[0].X - food[i].X), 2) + pow((snake[0].Y - food[i].Y), 2);
                temp = i; //存储最短距离的食物序号
            }
        }
    }
    //遍历整个路径,删除无效路径
    for (int i = 0; i <= COL - 4; i += 2)
    {
        for (int j = 1; j <= ROW - 5; j += 2)
        {
            //纵向
            if ((map[j][i + 1] != SNAKE && map[j][i + 2] != SNAKE && map[j + 1][i + 1] != SNAKE && map[j + 1][i + 2] != SNAKE)
                || (map[j + 2][i + 1] != SNAKE && map[j + 2][i + 2] != SNAKE && map[j + 3][i + 1] != SNAKE && map[j + 3][i + 2] != SNAKE))
            {
                //设置独立环路
                path[j + 1][i] = 'D';
                path[j][i + 1] = 'A';
                //标记为0
                if (map[j][i + 1] != SNAKE && map[j][i + 2] != SNAKE && map[j + 1][i + 1] != SNAKE && map[j + 1][i + 2] != SNAKE)
                {
                    path_mark[j - 1][i] = false;
                    path_mark[j - 1][i + 1] = false;
                    path_mark[j][i] = false;
                    path_mark[j][i + 1] = false;
                }
                if (map[j + 2][i + 1] != SNAKE && map[j + 2][i + 2] != SNAKE && map[j + 3][i + 1] != SNAKE && map[j + 3][i + 2] != SNAKE)
                {
                    path_mark[j + 1][i] = false;
                    path_mark[j + 2][i] = false;
                    path_mark[j + 1][i + 1] = false;
                    path_mark[j + 2][i + 1] = false;
                }
            }
        }
    }
    for (int i = 0; i <= ROW - 4; i += 2)
    {
        for (int j = 1; j <= COL - 5; j += 2)
        {
            //横向
            if ((map[i + 1][j] != SNAKE && map[i + 1][j + 1] != SNAKE && map[i + 2][j] != SNAKE && map[i + 2][j + 1] != SNAKE)
                || (map[i + 1][j + 2] != SNAKE && map[i + 1][j + 3] != SNAKE && map[i + 2][j + 2] != SNAKE && map[i + 2][j + 3] != SNAKE))
            {
                //设置独立环路
                path[i][j] = 'S';
                path[i + 1][j + 1] = 'W';
                //标记为0
                if (map[i + 1][j] != SNAKE && map[i + 1][j + 1] != SNAKE && map[i + 2][j] != SNAKE && map[i + 2][j + 1] != SNAKE)
                {
                    path_mark[i][j - 1] = false;
                    path_mark[i + 1][j - 1] = false;
                    path_mark[i][j] = false;
                    path_mark[i + 1][j] = false;
                }
                if (map[i + 1][j + 2] != SNAKE && map[i + 1][j + 3] != SNAKE && map[i + 2][j + 2] != SNAKE && map[i + 2][j + 3] != SNAKE)
                {
                    path_mark[i][j + 1] = false;
                    path_mark[i][j + 2] = false;
                    path_mark[i + 1][j + 1] = false;
                    path_mark[i + 1][j + 2] = false;
                }
            }
        }
    }
    //生成路径
    COORD head; //头部位置
    head.X = snake[0].X - 1; head.Y = snake[0].Y - 1;
    head.X = head.X % 2 == 1 ? head.X - 1 : head.X; //头部位置回到左上角(奇数,-1;偶数,不变)
    head.Y = head.Y % 2 == 1 ? head.Y - 1 : head.Y;
    COORD end; //食物位置
    end.X = food[temp].X - 1; end.Y = food[temp].Y - 1;
    end.X = end.X % 2 == 1 ? end.X - 1 : end.X; //食物位置左上角(奇数,-1;偶数,不变)
    end.Y = end.Y % 2 == 1 ? end.Y - 1 : end.Y;

    int dx, dy; //头部与食物位置之间的相对关系
    dx = head.X > end.X ? -1 : head.X < end.X ? 1 : 0; //食物在下边,1;在上边,-1
    dy = head.Y > end.Y ? -1 : head.Y < end.Y ? 1 : 0; //食物在右边,1;在左边,-1

    while (head.Y != end.Y)
    {
        //横向
        head.Y += dy;
        if (head.Y % 2 == 1) //只在奇数时判断
        {
            if (!(path_mark[head.X][head.Y] && path_mark[head.X + 1][head.Y + 1]))
            {
                path[head.X][head.Y] = 'D';
                path[head.X + 1][head.Y + 1] = 'A';
                path_mark[head.X][head.Y - 1] = true; path_mark[head.X][head.Y] = true; path_mark[head.X + 1][head.Y - 1] = true; path_mark[head.X + 1][head.Y] = true;
                path_mark[head.X][head.Y + 1] = true; path_mark[head.X][head.Y + 2] = true; path_mark[head.X + 1][head.Y + 1] = true; path_mark[head.X + 1][head.Y + 2] = true;
            }
        }
    }
    while (head.X != end.X)
    {
        //纵向
        head.X += dx;
        if (head.X % 2 == 1) //只在奇数时判断
        {
            if (!(path_mark[head.X][head.Y] && path_mark[head.X + 1][head.Y + 1]))
            {
                path[head.X + 1][head.Y] = 'W';
                path[head.X][head.Y + 1] = 'S';
                path_mark[head.X - 1][head.Y] = path_mark[head.X - 1][head.Y + 1] = path_mark[head.X][head.Y] = path_mark[head.X][head.Y + 1] = true;
                path_mark[head.X + 1][head.Y] = path_mark[head.X + 1][head.Y + 1] = path_mark[head.X + 2][head.Y] = path_mark[head.X + 2][head.Y + 1] = true;
            }
        }
    }
    SnakeDir = path[snake[0].X - 1][snake[0].Y - 1];
}
void ChangeDir()
{
    switch (_getch())
    {
    case'A':
    case'a':
    case 75:
        if (SnakeDir != 'D') SnakeDir = 'A';
        break;
    case'D':
    case'd':
    case 77:
        if (SnakeDir != 'A') SnakeDir = 'D';
        break;
    case'W':
    case'w':
    case 72:
        if (SnakeDir != 'S') SnakeDir = 'W';
        break;
    case'S':
    case's':
    case 80:
        if (SnakeDir != 'W') SnakeDir = 'S';
        break;
    case 32:
        _getch();
        break;
    case 27:
        MessageBox(GetHWnd(), L"游戏结束", L"SORRY", MB_OK);
        start(); //开始界面
        outtextxy(200, 100, L"->"); //初始默认模式一

        chose(); //选择模式;Enter键进入游戏

        init();  //初始化游戏界面
    default:
        break;
    }
}
void move()
{
    COORD next; //蛇头的下一个位置
    static int times = 1; //游戏难度
    //选择移动方向
    switch (SnakeDir)
    {
    case'A':
        next.X = snake[0].X;
        next.Y = snake[0].Y - 1;
        break;
    case'W':
        next.X = snake[0].X - 1;
        next.Y = snake[0].Y;
        break;
    case'D':
        next.X = snake[0].X;
        next.Y = snake[0].Y + 1;
        break;
    case'S':
        next.X = snake[0].X + 1;
        next.Y = snake[0].Y;
        break;
    default:
        break;
    }
    //判断下一个位置是什么
    switch (map[next.X][next.Y])
    {
    case SPACE:
        map[snake[SnakeSize - 1].X][snake[SnakeSize - 1].Y] = SPACE; //地图蛇尾所在地置空
        for (int i = SnakeSize - 1; i > 0; i--) //蛇尾到蛇头整体移动一位
        {
            snake[i] = snake[i - 1];
            map[snake[i].X][snake[i].Y] = SNAKE; //蛇身位置必须赋予SNAKE
        }
        snake[0] = next; //将下一个位置赋予给头部
        map[snake[0].X][snake[0].Y] = SNAKE; //设置头部
        break;
    case WALL:
        if (mode == 1 || mode == 2) //模式一模式二可穿墙
        {
            map[snake[SnakeSize - 1].X][snake[SnakeSize - 1].Y] = SPACE; //蛇尾置空
            for (int i = SnakeSize - 1; i > 0; i--) //蛇尾到蛇头整体移动一位
            {
                snake[i] = snake[i - 1];
                map[snake[i].X][snake[i].Y] = SNAKE;
            }
            switch (SnakeDir) //穿墙
            {
            case 'A':next.Y = COL - 2; break;
            case 'D':next.Y = 1; break;
            case 'W':next.X = ROW - 2; break;
            case 'S':next.X = 1; break;
            default:
                break;
            }
            snake[0] = next; //蛇头移动到新位置
            map[snake[0].X][snake[0].Y] = SNAKE; //新的蛇头所在的位置
        }
        else {
            MessageBox(GetHWnd(), L"游戏结束", L"SORRY", MB_OK);
            start(); //开始界面
            outtextxy(200, 100, L"->"); //初始默认模式一
            chose(); //选择模式;Enter键进入游戏
            init();  //初始化游戏界面
        }
        break;
    case SNAKE:
        map[snake[SnakeSize - 1].X][snake[SnakeSize - 1].Y] = SPACE; //地图蛇尾所在地置空
        for (int i = SnakeSize - 1; i > 0; i--) //蛇尾到蛇头整体移动一位
        {
            snake[i] = snake[i - 1];
            map[snake[i].X][snake[i].Y] = SNAKE;
        }
        snake[0] = next; //将下一个位置赋予给头部
        map[snake[0].X][snake[0].Y] = SNAKE; //设置头部
        break;
    case FOOD: //食物
        for (int i = SnakeSize; i > 0; i--) //蛇尾到蛇头整体移动一位
        {
            snake[i] = snake[i - 1];
        }
        snake[0] = next; //设置蛇头位置
        map[next.X][next.Y] = SNAKE; //设置头部
        SnakeSize++; //蛇尺度加一
        PlaySound(TEXT("D:\\22-音效\\1枪声.wav"), NULL, SND_FILENAME | SND_ASYNC); //播放音效//SND_ASYNC:播放音乐的同时结束程序;SND_SYNC:播放完音乐后才结束程序;
        score++; //分数加一
        //加快移动速度
        if (score == 3 * times)
        {
            time1 -= 10;
            times++;
            if (time1 == 0)
            {
                time1 = 10;
            }
        }
        int yu;//添加新的食物
            for (int order = 0; order < number; order++)
            {
                if ((snake[0].X == food[order].X) && (snake[0].Y == food[order].Y))
                {
                    addfood(order);
                }
            }
        break;
    default:
        break;
    }
}
void addfood(int order)
{
    int row, col;
    int flag = 0;
    //判断是否有空位
    for (int i = 1; i <= ROW - 2; i++)
    {
        for (int j = 1; j <= COL - 2; j++)
        {
            if (map[i][j] == SPACE)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    //如果有空位,设置食物位置范围
    if (flag == 1)
    {
        do
        {
            row = rand() % (ROW - 2) + 1;
            col = rand() % (COL - 2) + 1;
        } while (map[row][col] != SPACE);
        map[row][col] = FOOD;
        food[order].X = row;
        food[order].Y = col;
    }
}