#include<stdio.h>
#include<graphics.h>//easyx ͼ�ο�ͷ�ļ�
#include<time.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
/*
	1�������ı�����ʽ
	2������Ч��
	3����ʾ��̬ʱ��
	4����װ��������
*/
#define WIN_SIZE 500			//���ڴ�С
#define WIN_HALF (WIN_SIZE/2)    //���ڵ�һ��

IMAGE spaceman[48];	//̫����ͼƬ����
IMAGE heartbeat[1];
void loadImage() {
	//����ͼƬ	[0-47]
	char fileName[50] = { 0 };//����һ���ַ����齫 "./image/%d.jpg" ��仰��Ϊһ������ ����������ֽ��иı� �ﵽ����ͼƬ��Ŀ��
	for (int i = 0; i < 48; i++)
	{
		sprintf_s(fileName,"./image/%d.jpg",i);
		printf("\n");
		loadimage(spaceman + i, fileName, 140, 130);
	}
	
	//��ʾ����

	
}
//����������ʽ
void setTextStyle(int h,int w,const char *faceName) {
	LOGFONT f = { 0 };		//���û�����ó�ʼֵ�Ļ���Ĭ�ϻ�����һ����ֵ	�ṹ���൱��һ�����飬ֻ�������Ա���Ͳ�һ��
	f.lfHeight = h;
	f.lfWidth = w;
	strcpy(f.lfFaceName, faceName);
	settextstyle(&f);//�����ı���ʽ		�ú�����Ҫһ�����úõ�LOGFONT�ĵ�ַ
}

//̫���˶���Ч��
void animation() {
	static DWORD t1 = clock(); //DWord��Ϊ�˼���Windows��������������һ�����ͣ���MFC��һ���ġ���ʾDouble Word����˼���̶�4byte.
	//static ֻ��ʼ��һ�Σ����������������ڼ�ֻ����һ��

	/*����DWORDʹ������Ҫ��һ�㡣DWORD ���ڱ�ʾ 32bit �޷�����������ʹ�Ժ� Windows
����������64λ��DWORD ��Ȼ�� 32bit �޷���������Ҳ���Ժ�� long ��
������32bit�ˣ�ֻ��Ҫ���¶���һ�� DWORD �Ϳ����ˣ���������Щֱ��
������λ���йص���������ò��� int, long, short ֮�ڵ����ͣ���Ϊ
������Щ���͵�λ�����ܲ�ȷ�������磬��16λ�����int ��16λ�ģ���
����32λ�����int ��32λ�ģ�˭֪�����Ժ��64λ�����int �Ƕ���
����λ��long ���Ƕ���λ���������¶�������;�û���ⷽ��������ˣ�
������ൽʱ���޸�һ�¶���Ϳ����ˣ�������Ҫ�ڳ�����һ��һ�еĲ���*/

	DWORD t2 = clock();//��ȡ�������е����øú����������ĺ�����
	//printf("ʱ��%d\n",t2-t1);
	//��ͼƬ�������������
	static int i = 0;
	if (t2 - t1 > 20) {

		i = (i + 1) % 48;//ÿ48��ͼƬѭ��һ�Σ�������һ��ѭ��
		t1 = t2;
	}
	putimage(WIN_HALF - 60, WIN_HALF -70, spaceman + i);

	/*//���������̫���˶����������ǲ�������Ч������������ṩ��Ч�������ǲ���ʹ��
	for (int i = 0; i < 48; i++)
	{
		Sleep(20);//�ӳ�20����	�������Sleep�������ó������ߣ��������������ӳ٣�����ʹ�ö�ʱ�����
		putimage(150, 150, spaceman + i);
		
	}*/
	
}
//�����������
void gameDraw() {

	//���ñ�����ɫ
	setbkcolor(RGB(255, 255, 255));//�����ɫ�޷�ֱ����ʾ�������ϣ���Ϊ������ԭ����һ���ɫ����Ҫ�������������һ�У�
	cleardevice();	//��ջ�ͼ�豸
	setbkmode(TRANSPARENT);//����������Ϊ͸��

	//���Ʊ���
	setlinecolor(RGB(68,68,68));
	setlinestyle(PS_SOLID, 40);
	setfillcolor(RGB(255, 255, 255));
	fillellipse(0, 0, WIN_SIZE, WIN_SIZE);

	//��������
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 4);

	//����
	line(WIN_HALF - 30, 20, WIN_HALF - 30, 130);
	//����
	line(WIN_HALF - 195, WIN_HALF-120, WIN_HALF + 195, WIN_HALF - 120);
	line(WIN_HALF - 195, WIN_HALF + 120, WIN_HALF + 195, WIN_HALF + 120);

	//��ʾ��̬ʱ��
	//��ȡ��ǰ��ϵͳʱ�� time.h
	time_t curTime = time(NULL);
	//printf("%lld\n", curTime);//1643084614 ����������ʱ��,��Ҫ�������з���
	struct tm * humanTime = localtime(&curTime);
	char buf[40] = { 0 };
	sprintf_s(buf, "%d:%d", humanTime->tm_hour, humanTime->tm_min);
	outtextxy(WIN_HALF-145, WIN_HALF-115, buf);//����ʱ���λ��
	sprintf_s(buf, "%d", humanTime->tm_sec);
	outtextxy(335,160, buf);//����ʱ���λ��
}

//��ӱ�������
void getMusic() {
	mciSendString("open ./image/Σ���ɶ�.mp3 alias bkmusic", NULL, 0, NULL);
	/*
	openָ�����Ҫ���ŵ����֣�alias�����ƶ���ǰ���ļ�·���ı������Ժ���Ҫ��������ļ�ֱ��ʹ�������������
	��������ļ������ǵ�debug�ļ�����ͬһĿ¼�£��Ϳ���ֱ��д������

	*/
	mciSendString("play bkmusic repeat", NULL, 0, NULL);//ѭ����������
	system("pause");
}
int main() {
	//����һ��ͼ�ν���
	initgraph(500, 500,EW_SHOWCONSOLE);

	//���ñ�����ɫ
	setbkcolor(RGB(255,255,255));//�����ɫ�޷�ֱ����ʾ�������ϣ���Ϊ������ԭ����һ���ɫ����Ҫ�������������һ�У�
	cleardevice();	//��ջ�ͼ�豸

	//����������ʽ
	settextcolor(BLACK);//�����ı���ɫ
	setTextStyle(55, 23, "Arial");
	outtextxy(50, 50, "90%");//�ڿͻ������ָ��λ����ʾ"" 
	loadImage();

	BeginBatchDraw();//˫�����ͼ ����������ֹ����
	
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