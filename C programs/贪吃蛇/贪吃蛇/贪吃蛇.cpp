#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#pragma comment(lib, "Winmm.lib")
void start(); //��ʼ����
void chose(); //ѡ��ģʽ;0:��ͨģʽ 1:��ǽģʽ 2:�޵�ģʽ 3:�Զ�ģʽ
void init(); //��ʼ����Ϸ����
void DrawMap(); //���Ƶ�ͼ
void ChangeDir(); //��������,�ı䷽��
void move(); //�ߵ��ƶ�
void addfood(int order); //���ʳ��
void autoseek(); //�Զ�Ѱ��ʳ��ģʽ

enum game //ö������
{
    SPACE, WALL, SNAKE, FOOD //SPACE = 0, WALL = 1, SMAKE = 2, FOOD = 3
};
int mode; //��Ϸģʽ
int score; //����

const int ROW = 50; //��ͼ����
const int COL = 50; //��ͼ����
const int number = 3; //ʳ������
const int width = 500; //ͼ�ο��(x)
const int high = 520; //ͼ�θ߶�(y)
int map[ROW][COL]; //��ͼ��С
COORD food[number]; //ʳ���λ��
COORD snake[ROW * COL]; //�ߵ�λ��
int SnakeSize; //�ߵĳߴ�
char SnakeDir; //�ߵ��ƶ�����
char path[ROW - 2][COL - 2] = { 0 }; //·��
bool path_mark[ROW - 2][COL - 2]; //·����־

int time1 = 50; //�趨��ʱʱ��

int main()
{
    DWORD t1 = 0, t2 = 0; //��ʱʱ��(32λ�޷�������)

    mciSendString(L"open D:\\22-��Ч\\ACG���䱬��˫��������.wav alias bgm", 0, 0, 0); //�򿪱�������
    mciSendString(L"play bgm", 0, 0, 0); //���ű�������

    initgraph(500, 520); //��ʼ��ͼ�ν���: x=500, y=520
    start(); //��ʼ����
    outtextxy(170, 100, L"->"); //��ʼĬ��ģʽһ

    chose(); //ѡ����Ϸģʽ;Enter��������Ϸ

    init();  //��ʼ����Ϸ����

    while (1)
    {
        t2 = GetTickCount();

        DrawMap(); //���Ƶ�ͼ
        if (_kbhit()) //�ȴ�������������
        {
            ChangeDir(); //��������
            move(); //�ƶ�

            t2 = GetTickCount();
            t1 = t2;
        }
        if (t2 - t1 > time1)
        {
            move(); //�ƶ�
            if (mode == 3)
            {
                autoseek();
            }
            t1 = t2; //����ʱ��
        }
    }
    return 0;
}
void start()
{
    setbkcolor(YELLOW); //���ô��ڱ���ɫ;
    cleardevice(); //�����Ļ
    setbkmode(TRANSPARENT); //�������屳��ɫΪ͸��
    settextcolor(RED); //����������ɫΪ��ɫ
    settextstyle(20, 0, _T("����")); //�����С:20;��������:����
    outtextxy(200, 40, L"����ģʽ");
    outtextxy(190, 100, L"1.��ͨģʽ");
    outtextxy(190, 150, L"2.��ǽģʽ");
    outtextxy(190, 200, L"3.�޵�ģʽ");
    outtextxy(190, 250, L"4.�Զ�ģʽ");
    outtextxy(65, 300, L"���ּ� 1,2,3,4ѡ��ģʽ��Enter��������Ϸ");
    outtextxy(65, 350, L"��ĸ�� W,S,A,D ���Ʒ���: �� �� �� �� ");
    outtextxy(65, 400, L"�ո�� ��ͣ, Esc�� ������Ϸ");
}
void chose()
{
    while (1)
    {
        switch (_getch()) //�����ַ�
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
        case 13: //�س���
            return; //����
            break;
        }
    }
}
void init()
{
    srand((unsigned)time(NULL)); //���������
    setbkcolor(BLACK); //���ñ�����ɫ
    //��ʼ������
    score = 0;
    //��ʼ��map����
    memset(map, SPACE, sizeof(map));
    // ÿһ�е� ��һ�� �� ���һ�� ��ǽ
    for (int i = 0; i < ROW; i++)
    {
        map[i][0] = map[i][COL - 1] = WALL;
    }
    //ÿһ�е� �ڶ��� �� �����ڶ�����ǽ
    for (int j = 1; j < COL - 1; j++)
    {
        map[0][j] = map[ROW - 1][j] = WALL;
    }

    SnakeSize = 2; //�߳�ʼ����
    SnakeDir = 'D';
    //��ʼ���ߵ�λ��
    map[1][2] = SNAKE; //ͷ��
    map[1][1] = SNAKE; //����
    snake[0].X = 1; snake[0].Y = 2; //ͷ��λ��
    snake[1].X = 1; snake[1].Y = 1; //����λ��
    path_mark[0][0] = path_mark[0][1] = path_mark[1][0] = path_mark[1][1] = true;
    //��ʼ��ʳ��λ��
    for (int i = 0; i < number; i++)
    {
        addfood(i);
    }
    //��ʼ��·��(ROW-2,COL-2)
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
    //��ʼ��·����־(ROW-2,COL-2)
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
    BeginBatchDraw(); //��ʼ��ͼ
    setbkcolor(BLACK); //���ñ�����ɫ
    settextcolor(YELLOW); //�����ı���ɫ
    cleardevice(); //����

    WCHAR arr[10]; //����ɼ�
    wsprintf(arr, L"�ܷ֣�%d", score); //���ɼ���ʽ��������ַ���arr�� 
    outtextxy(0, 0, arr); //��ʾ�ɼ�

    for (int y = 0; y < ROW; y++) //y�᷽������(��)
    {
        for (int x = 0; x < COL; x++) //x�᷽������(��)
        {
            switch (map[y][x])
            {
            case SPACE:
                break;
            case WALL: //ǽ
                setlinecolor(BLACK); //����������ɫΪ��ɫ
                setfillcolor(WHITE); //���������ɫΪ��ɫ
                fillrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30); //������,�߳�10,���ҶԽǵ�����
                break;
            case SNAKE: //��
                if (y == snake[0].X && x == snake[0].Y)
                {
                    setfillcolor(LIGHTBLUE);
                    solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
                }
                else
                {
                    setfillcolor(RGB(255, 255, 0)); //��  255 255 0
                    solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
                }
                break;
            case FOOD:
                setfillcolor(LIGHTRED); //ʳ����ɫ
                solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
                break;
            default:
                break;
            }
        }
    }
    EndBatchDraw(); //��������
}
void autoseek()
{
    int temp = 0; //��̾����ʳ�����
    int d = pow((snake[0].X - food[0].X), 2) + pow((snake[0].Y - food[0].Y), 2);
    //Ѱ����̾����ʳ��
    if (number > 1)
    {
        for (int i = 1; i < number; i++)
        {
            if (d > pow((snake[0].X - food[i].X), 2) + pow((snake[0].Y - food[i].Y), 2))
            {
                d = pow((snake[0].X - food[i].X), 2) + pow((snake[0].Y - food[i].Y), 2);
                temp = i; //�洢��̾����ʳ�����
            }
        }
    }
    //��������·��,ɾ����Ч·��
    for (int i = 0; i <= COL - 4; i += 2)
    {
        for (int j = 1; j <= ROW - 5; j += 2)
        {
            //����
            if ((map[j][i + 1] != SNAKE && map[j][i + 2] != SNAKE && map[j + 1][i + 1] != SNAKE && map[j + 1][i + 2] != SNAKE)
                || (map[j + 2][i + 1] != SNAKE && map[j + 2][i + 2] != SNAKE && map[j + 3][i + 1] != SNAKE && map[j + 3][i + 2] != SNAKE))
            {
                //���ö�����·
                path[j + 1][i] = 'D';
                path[j][i + 1] = 'A';
                //���Ϊ0
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
            //����
            if ((map[i + 1][j] != SNAKE && map[i + 1][j + 1] != SNAKE && map[i + 2][j] != SNAKE && map[i + 2][j + 1] != SNAKE)
                || (map[i + 1][j + 2] != SNAKE && map[i + 1][j + 3] != SNAKE && map[i + 2][j + 2] != SNAKE && map[i + 2][j + 3] != SNAKE))
            {
                //���ö�����·
                path[i][j] = 'S';
                path[i + 1][j + 1] = 'W';
                //���Ϊ0
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
    //����·��
    COORD head; //ͷ��λ��
    head.X = snake[0].X - 1; head.Y = snake[0].Y - 1;
    head.X = head.X % 2 == 1 ? head.X - 1 : head.X; //ͷ��λ�ûص����Ͻ�(����,-1;ż��,����)
    head.Y = head.Y % 2 == 1 ? head.Y - 1 : head.Y;
    COORD end; //ʳ��λ��
    end.X = food[temp].X - 1; end.Y = food[temp].Y - 1;
    end.X = end.X % 2 == 1 ? end.X - 1 : end.X; //ʳ��λ�����Ͻ�(����,-1;ż��,����)
    end.Y = end.Y % 2 == 1 ? end.Y - 1 : end.Y;

    int dx, dy; //ͷ����ʳ��λ��֮�����Թ�ϵ
    dx = head.X > end.X ? -1 : head.X < end.X ? 1 : 0; //ʳ�����±�,1;���ϱ�,-1
    dy = head.Y > end.Y ? -1 : head.Y < end.Y ? 1 : 0; //ʳ�����ұ�,1;�����,-1

    while (head.Y != end.Y)
    {
        //����
        head.Y += dy;
        if (head.Y % 2 == 1) //ֻ������ʱ�ж�
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
        //����
        head.X += dx;
        if (head.X % 2 == 1) //ֻ������ʱ�ж�
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
        MessageBox(GetHWnd(), L"��Ϸ����", L"SORRY", MB_OK);
        start(); //��ʼ����
        outtextxy(200, 100, L"->"); //��ʼĬ��ģʽһ

        chose(); //ѡ��ģʽ;Enter��������Ϸ

        init();  //��ʼ����Ϸ����
    default:
        break;
    }
}
void move()
{
    COORD next; //��ͷ����һ��λ��
    static int times = 1; //��Ϸ�Ѷ�
    //ѡ���ƶ�����
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
    //�ж���һ��λ����ʲô
    switch (map[next.X][next.Y])
    {
    case SPACE:
        map[snake[SnakeSize - 1].X][snake[SnakeSize - 1].Y] = SPACE; //��ͼ��β���ڵ��ÿ�
        for (int i = SnakeSize - 1; i > 0; i--) //��β����ͷ�����ƶ�һλ
        {
            snake[i] = snake[i - 1];
            map[snake[i].X][snake[i].Y] = SNAKE; //����λ�ñ��븳��SNAKE
        }
        snake[0] = next; //����һ��λ�ø����ͷ��
        map[snake[0].X][snake[0].Y] = SNAKE; //����ͷ��
        break;
    case WALL:
        if (mode == 1 || mode == 2) //ģʽһģʽ���ɴ�ǽ
        {
            map[snake[SnakeSize - 1].X][snake[SnakeSize - 1].Y] = SPACE; //��β�ÿ�
            for (int i = SnakeSize - 1; i > 0; i--) //��β����ͷ�����ƶ�һλ
            {
                snake[i] = snake[i - 1];
                map[snake[i].X][snake[i].Y] = SNAKE;
            }
            switch (SnakeDir) //��ǽ
            {
            case 'A':next.Y = COL - 2; break;
            case 'D':next.Y = 1; break;
            case 'W':next.X = ROW - 2; break;
            case 'S':next.X = 1; break;
            default:
                break;
            }
            snake[0] = next; //��ͷ�ƶ�����λ��
            map[snake[0].X][snake[0].Y] = SNAKE; //�µ���ͷ���ڵ�λ��
        }
        else {
            MessageBox(GetHWnd(), L"��Ϸ����", L"SORRY", MB_OK);
            start(); //��ʼ����
            outtextxy(200, 100, L"->"); //��ʼĬ��ģʽһ
            chose(); //ѡ��ģʽ;Enter��������Ϸ
            init();  //��ʼ����Ϸ����
        }
        break;
    case SNAKE:
        map[snake[SnakeSize - 1].X][snake[SnakeSize - 1].Y] = SPACE; //��ͼ��β���ڵ��ÿ�
        for (int i = SnakeSize - 1; i > 0; i--) //��β����ͷ�����ƶ�һλ
        {
            snake[i] = snake[i - 1];
            map[snake[i].X][snake[i].Y] = SNAKE;
        }
        snake[0] = next; //����һ��λ�ø����ͷ��
        map[snake[0].X][snake[0].Y] = SNAKE; //����ͷ��
        break;
    case FOOD: //ʳ��
        for (int i = SnakeSize; i > 0; i--) //��β����ͷ�����ƶ�һλ
        {
            snake[i] = snake[i - 1];
        }
        snake[0] = next; //������ͷλ��
        map[next.X][next.Y] = SNAKE; //����ͷ��
        SnakeSize++; //�߳߶ȼ�һ
        PlaySound(TEXT("D:\\22-��Ч\\1ǹ��.wav"), NULL, SND_FILENAME | SND_ASYNC); //������Ч//SND_ASYNC:�������ֵ�ͬʱ��������;SND_SYNC:���������ֺ�Ž�������;
        score++; //������һ
        //�ӿ��ƶ��ٶ�
        if (score == 3 * times)
        {
            time1 -= 10;
            times++;
            if (time1 == 0)
            {
                time1 = 10;
            }
        }
        int yu;//����µ�ʳ��
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
    //�ж��Ƿ��п�λ
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
    //����п�λ,����ʳ��λ�÷�Χ
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