#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>
#include <time.h>
#include <math.h>

float MONEY = 0;
float COINS = 0;
float kurs = 15.3527;
void ANYKEY();
void clrscr();
void MoneyToCoins(float MONEY);
float vichetMoney(float MONEY);
float StartExit();
int Zgame(float MONEY, float COINS);
int game();
int stavka();
int repGame();
float bye();

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	printf("�� ������ � ������� ������ ����, ��� ����� ������� ��������� ����� � �������� ���������.\
				  \n����������� �������� �������� � ����������� �� ��������� ����� �������.\n�������!\n");
	ANYKEY();
	printf("�������,����! ������ ����!\n");
	printf("��, ��� ���? ��� ����� �������?\n");
	printf("���� ������ ���������.C������ ��� ��� ������ ���� ������� ������� ��������.\
				  \n��� ������ ����� �������, ���� ������ ����, �� � ��� ������ ���� � ���� �����. ���� ���� �� � ������)");
	float st1 = StartExit();
        if (st1 == 0){
            printf("���� ��� �������, ����� ��������");
            return 0;
        }
	COINS = MONEY * kurs;
	printf("%.0f ��������? ���� �� ������� ���� ���� ���� %d �����. ���� � ���� ������ %.4f", MONEY, (int)COINS, kurs);
	printf("\n�������� %d �����.\n", (int)COINS);
	MONEY = vichetMoney(MONEY);
	if (Zgame(MONEY, COINS) == 1) {
            while(COINS != 0){
                int gam = game();
                    if (gam ==2){
                        bye();
                        return 0;
                    }
                        int rep = repGame();
                         if (rep == 0){
                            bye();
                            break;
                         }
                         if (rep == 1){
                            continue;
                        }
            }
	}
	else {
        bye();
	}
return 0;
}

float vichetMoney(float MONEY)
{
	float MONEY1 = floor(MONEY / kurs) * kurs;
	MONEY = MONEY - MONEY1;
	return MONEY;
}
void clrscr()
{
	system("@cls||clear");
}
void ANYKEY() {
	char chk; int j;
	printf("\n...\n������� ����� �������...");
	chk = getch();
	j = chk;
	for (int i = 1; i <= 256; i++)
		if (i == j) break;
	clrscr();
}
void MoneyToCoins(float MONEY)
{
	printf("��� �����? �� �� �����...\n������� � ���� ��� ��������?");
	float poslednieShtani = 0;
	MONEY = MONEY + scanf("%f", &poslednieShtani);
	printf("%f", poslednieShtani);
}

float StartExit() {
	printf("\n__________________________________________________\n*** ��� �������� ������ ���� ���� - \"��������\" ***\n\
				  \nQ - ����� �� ����.\n_________________________________\n������� ����� ��� ������ �� �����.\n");
	while (1) {
		char MONEYtmp[100];
		if (scanf("%f", &MONEY) > 0) {
			clrscr();
			break;
		}

		else if (scanf("%[qQ]", MONEYtmp)) {
			MONEY = 0;
			printf("������ �������������!\n");
			rewind(stdin);
			return 0;
		}
		else if (scanf("%s", &MONEY)) {
			printf("�������� ����, ���������� ���������.\n������� �������� ������� ��������?\n");
			MONEY = 0;
			rewind(stdin);
		}
		else {
			printf("�������� ����, ���������� ���������.\n������� �������� ������� ��������?\n");
			MONEY = 0;
		}
		rewind(stdin);
	}
	return MONEY;
}

int Zgame(float MONEY, float COINS)
{
	int vibor = -1;
	printf("������:\n\t�������:%.2f\n\t�����:%d\n������� 1 - ������ ����.\
				  \n������� 0 - �������� ���� � �������� ����� �� �������.\n", MONEY, (int)COINS);
	while (1)
	{
		if (scanf("%d", &vibor)) {
			if (vibor == 1) {
				clrscr();
				break;
			}
			else if (vibor == 0) {
				clrscr();
				break;
			}
			else if (vibor > 1) {
				printf("�������� ����, ���������� ���������.\n");

			}
			else {
                    rewind(stdin);
				printf("�������� ����, ���������� ���������.\n");
			}
		}
		else if ((scanf("%s", &vibor))) {
			printf("�������� ����, ���������� ���������.\n");
		}
		else {rewind(stdin);
			printf("�������� ����, ���������� ���������.\n");
		}
		rewind(stdin);
	}
	return vibor;
}

int stavka() {
	int stavka = -1;
	while (1)
	{
		if (scanf("%d", &stavka)) {
			if ((stavka <= COINS) &&  (stavka > 0)) {
				return stavka;
				break;
			}
			else if (stavka <= 0) {
				printf("�������� ����, ���������� ���������.\n");
			}
			else {
				printf("�������� ����, ���������� ���������.\n");
			}
		}
		else if ((scanf("%s", &stavka))) {
			printf("�������� ����, ���������� ���������.\n");
		}
		else {
            rewind(stdin);
            printf("�������� ����, ���������� ���������.\n");
		}
		rewind(stdin);
	}
	return stavka;
}

int game() {
	int chisloPopitok = 0, vihod = 0, MZ=0, ZagChislo=0, zag=0, vveliChislo = 0;
	unsigned int Dmin = 0, Dmax = 0;
	float koeff = 0, STtmp;

	do {
		clrscr();

		printf("������� ����:\n ����� ������ ���������� ������� � �������� ����� � ������� ����� ��������� �����.\
				  \n ���� ���� ���������, ����� ������ ��� ������ ����������.\
				  \n ��� ������ ����� �������, ��� ���� ����������� � �������������� ���� �������!\n");
		printf("\n �������� ��������� ������������:\n");
		printf("\n 0,9 - ����� ������� = ��������� ���������.\
				  \n 1,2 - ����� ������� = 51%%-99%% ���������.\
				  \n       ������: �������� - 100 �����, ������� ������� - 51-99.\
				  \n 1,3 - ����� ������� = 20%%-50%% �� ��������� ���������.\
				  \n       ������: �������� - 100 �����, ������� ������� - 20-50.\
				  \n 1,5 - ����� ������� = 1%%-19%% �� ��������� ���������.\
				  \n       ������: �������� - 100 �����, ������� ������� - 1-19.");
		if ((Dmin == 0) && (Dmax == 0)) {
			printf("\n\n ������:\n\t�������:%.2f\n\t�����:%d\n", MONEY, (int)COINS);
		}
		else {
			printf("\n\n ������:\n\t�������:%.2f\n\t�����:%d\n\t����� �������:%d\n\t���������� ����� � ���������:%d-%d\n", MONEY, (int)COINS, chisloPopitok, Dmin, Dmax);
		}

        if (COINS < 1){
            printf("������������ �����");
            ANYKEY();
            return 2;
            break;
        } else {

            printf("\n_______________\n������� ������:\n");
            STtmp = stavka();
        }

        COINS = COINS - STtmp;
		while(MZ== 0){

                printf("\n_______________\n����� ������ �������� ������� ������������ ��������:\n");
                Dmax = 0;
                scanf("%d", &Dmax);
                if (Dmax > 0){

                MZ = 1;
                } else {
                    printf("�������� ����, ���������� ���������.\n");
                }
                rewind(stdin);
		}
		clrscr();
        printf("\n_____________________\n������� ����� �������:\n");
		while(koeff== 0){
                scanf("%d", &chisloPopitok);
			if ((chisloPopitok != 0) && ((chisloPopitok*100/Dmax) <= 19)){
				koeff = 1.5;

			}
			else if (((chisloPopitok*100/Dmax) >= 20) && ((chisloPopitok*100/Dmax) <= 50)){
				koeff = 1.3;

			}
			else if (((chisloPopitok*100/Dmax) >= 51) && ((chisloPopitok*100/Dmax) <= 99)) {
				koeff = 1.2;

			}
			else if ((chisloPopitok) == (Dmax )) {
				koeff = 0.9;
			}
			else {
				printf("�������� ����, ���������� ���������.\n");
			}
			rewind(stdin);
		}
        clrscr();
		ZagChislo = 1+rand()%Dmax;
        while (chisloPopitok != 0){
            printf("��������:%d\n����� �������:%d\n����� �����:%d\n\n���������� ������� �����\n",Dmax,chisloPopitok,(int)COINS);
            scanf("%d", &vveliChislo);
            rewind(stdin);
            if(vveliChislo==ZagChislo){
                clrscr();
                rewind(stdin);
                COINS = COINS + (STtmp * koeff);
                printf("��������:%d\n����� �������:%d\n����� �����:%d\n\n�����������! �� �������! ��� ��������:%d\n",Dmax,chisloPopitok,(int)COINS,(int)(STtmp * koeff));
                chisloPopitok =0;
            }
            else if ((vveliChislo < ZagChislo)&& (vveliChislo > 0) ){
            rewind(stdin);
               clrscr();
               printf("\n************\n����� ������\n************\n\n");
               chisloPopitok--;
               if (chisloPopitok == 0){
                printf("� ��������� ��� ��� �������!\n������� ���������\n���������� ����� = %d\n",ZagChislo);
               }
            }
            else if ((vveliChislo > ZagChislo)&& (vveliChislo > 0) ){
            rewind(stdin);
               clrscr();
               printf("\n************\n����� ������\n************\n\n");
               chisloPopitok--;
               if (chisloPopitok == 0){
                printf("� ��������� ��� ��� �������!\n������� ���������\n���������� ����� = %d\n",ZagChislo);
               }
            }
            else {
                rewind(stdin);
                clrscr();
                printf("�������� ����, ���������� ���������.\n");
            }
        }
		} while (vihod == 1);
	return vihod;
}

int repGame(){
    int tmpW =0,tmp =-1;
    while(tmpW != 1){
    printf("������� ���?\n\
           1 - ��\n\
           0 - ���\n");
    scanf("%d", &tmp);
        if (tmp == 1){
            tmpW = 1;
            return 1;
        }
        else if (tmp == 0){
            tmpW = 1;
            return 0;
        }
        else {
            printf("�������� ����, ���������� ���������.\n");
        }
    }
}

float bye() {
    MONEY = COINS / kurs;
    int COINS1 = floor(COINS/ kurs) * kurs;
    COINS = COINS - COINS1;
    clrscr();
    printf("\���� ��� ��� �������\n������:\n�������: %.2f\n�����: %.2f\n", MONEY,COINS);
    return MONEY;
}
