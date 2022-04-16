#define _CRT_SECURE_NO_WARNINGS 1
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <iostream>
#define MAX_N 500
using namespace std;

//L3-019 �����Ű� ��30 ��)

//else��{} ���⴦��������for��while��if�ɹ�Ϊһ��  ����for/while/if + () + { }
//���ñߴ��������ķ�ʽ

//�ж���������
int judge_other(string dat, int i) {
    int is;
    if (dat.find("if", i) == i && (dat[i + 2] == ' ' || dat[i + 2] == '('))
        is = 2;
    else if (dat.find("while", i) == i && (dat[i + 5] == ' ' || dat[i + 5] == '('))
        is = 5;
    else if (dat.find("for", i) == i && (dat[i + 3] == ' ' || dat[i + 3] == '('))
        is = 3;
    else if (dat.find("else", i) == i && dat[i + 4] == ' ')
        is = 4;
    else if (dat.find("{", i) == i)
        is = 1;
    else
        is = 0;   //��ͨ���
    return is;
}

//print space
void print_space(int space) {
    for (int z = 0; z < space; z++) printf(" ");
}

//��������ո�
void ignore_space(string dat, int& i) {
    while (dat[i] == ' ') i++;
}

int main() {
    string dat;
    bool flag;
    getline(cin, dat);
    int i = 0, j = 0, m, idx, k, tmp, space = 0, debt = 0;  //space ��¼����

    //����main���� ���˲���
    ignore_space(dat, i);  //ȥ������ո�
    //�ӳ�ʼ�ַ���ӡ��)
    idx = dat.find(')', 0);
    for (j = i; j <= idx; j++) printf("%c", dat[j]);
    printf("\n{\n");

    //�����ַ����е�{, ��Ϊ�ϱ��Ѿ�ֱ�Ӵ�ӡ
    space += 2;
    i = idx + 1;
    ignore_space(dat, i);
    i++;

    while (i < dat.length()) {
        ignore_space(dat, i);
        if ((tmp = judge_other(dat, i))) {
            print_space(space);
            //����{} ��������  ����{{{{}}}}
            if (tmp == 1) {
                printf("{\n");
                i++;
                space += 2;
                continue;
            }
            //else���⴦��������for��while��if�ɹ�Ϊһ��  ����for/while/if + () + { }
            if (tmp == 4) {
                for (j = 0; j < 4; j++) printf("%c", dat[i + j]);
                k = i + 3;
            }
            else {
                for (j = 0; j < tmp; j++) printf("%c", dat[i + j]);
                printf(" ");
                i += tmp;
                ignore_space(dat, i);
                //���� ) ��Ϊ�����־����˿��� if(����) ������Ҳ��()�����
                k = i;
                int t = 0;
                while (true) {
                    if (dat[k] == '(') {
                        t++;
                    }
                    else if (dat[k] == ')') {
                        t--;
                        if (!t) break;
                    }
                    k++;
                }
                for (j = i; j <= k; j++) printf("%c", dat[j]);
            }
            //�� { 
            //�˴������������һ��Դ������û��{}���������һ����䣻 ����Դ�����б�����{}
            m = k + 1;
            ignore_space(dat, m);
            if (dat[m] != '{') {
                printf(" {\n");
                flag = false;    //flag ��debt ��ͬ����Ϊ�����������һ����ΪҪ���Ǻ�ʱӦ����� }(����Ե��Ҵ�����)
                debt++;
                i = m;
            }
            else {
                printf(" {\n");
                flag = true;
                i = m + 1;
            }
            space += 2;
        }
        else if (dat[i] == '}') {
            space -= 2;
            print_space(space);
            printf("}\n");
            if (space == 0) break;   //�ַ���������ϡ����˴�����Ϊ���� �����ڳ��������пո�

            i++;

            //�±߼��д��뼴Ϊ�ж��������һ���Ƿ�Ӧ����� } 
            ignore_space(dat, i);
            while (debt && judge_other(dat, i) != 4) {
                space -= 2;
                print_space(space);
                printf("}\n");
                debt--;
            }
        }
        else {
            //��ͨ���
            idx = dat.find(';', i);
            print_space(space);
            for (j = i; j <= idx; j++) printf("%c", dat[j]);
            printf("\n");
            i = idx + 1;
            if (debt && !flag) {
                space -= 2;
                print_space(space);
                printf("}\n");
                debt--;

                //�±߼��д���ͬΪ�ж��������һ���Ƿ�Ӧ����� } 
                ignore_space(dat, i);
                while (debt && judge_other(dat, i) != 4) {
                    space -= 2;
                    debt--;
                    print_space(space);
                    printf("}\n");
                }
            }
        }
    }
    return 0;
}