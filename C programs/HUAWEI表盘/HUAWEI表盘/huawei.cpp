#include<stdio.h>
#include<graphics.h>//easyx ͼ�ο�ͷ�ļ�
#include<time.h>
/*
	1�������ı�����ʽ
	2������Ч��
	3��

*/
IMAGE spaceman[48];	//̫����ͼƬ����
void loadImage() {
	//����ͼƬ	[0-47]
	char fileName[50] = { 0 };//����һ���ַ����齫 "./image/%d.jpg" ��仰��Ϊһ������ ����������ֽ��иı� �ﵽ����ͼƬ��Ŀ��
	for (int i = 0; i < 48; i++)
	{
		sprintf_s(fileName,"./image/%d.jpg",i);
		printf("\n");
		loadimage(spaceman + i, fileName, 140, 130);
	}
	
	
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
	//��ͼƬ�������������
	for (int i = 0; i < 48; i++)//���������̫���˶����������ǲ�������Ч��
	{
		Sleep(20);//�ӳ�20����	�������Sleep�������ó������ߣ��������������ӳ٣�����ʹ�ö�ʱ�����
		putimage(150, 150, spaceman + i);
	}
}
int main() {
	//����һ��ͼ�ν���
	initgraph(500, 500);

	//���ñ�����ɫ
	setbkcolor(RGB(255,255,255));//�����ɫ�޷�ֱ����ʾ�������ϣ���Ϊ������ԭ����һ���ɫ����Ҫ�������������14�У�
	cleardevice();	//��ջ�ͼ�豸

	//����������ʽ
	settextcolor(BLACK);//�����ı���ɫ
	setTextStyle(55, 23, "Arial");
	outtextxy(50, 50, "90%");//�ڿͻ������ָ��λ����ʾ"" 
	loadImage();
	while (true)
	{
		animation();
	}
	getchar();
	return 0;
}