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
	printf("Вы попали в учебный проект игры, где нужно угадать рандомное число в заданном интервале.\
				  \nКоэффициент выигрыша меняется в зависимости от заданного числа попыток.\nПоехали!\n");
	ANYKEY();
	printf("Здорова,брат! Заходи брат!\n");
	printf("Че, как сам? При бабле сегодня?\n");
	printf("Тебе кстати фортануло.Cегодня как раз только твой игровой автомат работает.\
				  \nТут режимы новые завезли, кэфы мощные есть, но и без одежды уйти с ними можно. Тебе ведь не в первой)");
	float st1 = StartExit();
        if (st1 == 0){
            printf("Жаль что уходите, Всего хорошего");
            return 0;
        }
	COINS = MONEY * kurs;
	printf("%.0f тугриков? Окей за столько могу дать тебе %d фишек. Курс в этом месяце %.4f", MONEY, (int)COINS, kurs);
	printf("\nПолучено %d фишек.\n", (int)COINS);
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
	printf("\n...\nНажмите любую клавишу...");
	chk = getch();
	j = chk;
	for (int i = 1; i <= 256; i++)
		if (i == j) break;
	clrscr();
}
void MoneyToCoins(float MONEY)
{
	printf("Еще фишек? Ну ты капец...\nСколько у тебя еще тугриков?");
	float poslednieShtani = 0;
	MONEY = MONEY + scanf("%f", &poslednieShtani);
	printf("%f", poslednieShtani);
}

float StartExit() {
	printf("\n__________________________________________________\n*** Вам доступна только одна игра - \"Угадайка\" ***\n\
				  \nQ - Выход из игры.\n_________________________________\nВведите сумму для обмена на фишки.\n");
	while (1) {
		char MONEYtmp[100];
		if (scanf("%f", &MONEY) > 0) {
			clrscr();
			break;
		}

		else if (scanf("%[qQ]", MONEYtmp)) {
			MONEY = 0;
			printf("Скорее возвращайтесь!\n");
			rewind(stdin);
			return 0;
		}
		else if (scanf("%s", &MONEY)) {
			printf("Неверный ввод, пожалуйста повторите.\nСколько тугриков желаете обменять?\n");
			MONEY = 0;
			rewind(stdin);
		}
		else {
			printf("Неверный ввод, пожалуйста повторите.\nСколько тугриков желаете обменять?\n");
			MONEY = 0;
		}
		rewind(stdin);
	}
	return MONEY;
}

int Zgame(float MONEY, float COINS)
{
	int vibor = -1;
	printf("Баланс:\n\tТугрики:%.2f\n\tФишки:%d\nВведите 1 - Начать игру.\
				  \nВведите 0 - Покинуть игру и обменять фишки на тугрики.\n", MONEY, (int)COINS);
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
				printf("Неверный ввод, пожалуйста повторите.\n");

			}
			else {
                    rewind(stdin);
				printf("Неверный ввод, пожалуйста повторите.\n");
			}
		}
		else if ((scanf("%s", &vibor))) {
			printf("Неверный ввод, пожалуйста повторите.\n");
		}
		else {rewind(stdin);
			printf("Неверный ввод, пожалуйста повторите.\n");
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
				printf("Неверный ввод, пожалуйста повторите.\n");
			}
			else {
				printf("Неверный ввод, пожалуйста повторите.\n");
			}
		}
		else if ((scanf("%s", &stavka))) {
			printf("Неверный ввод, пожалуйста повторите.\n");
		}
		else {
            rewind(stdin);
            printf("Неверный ввод, пожалуйста повторите.\n");
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

		printf("Правила игры:\n Игрок задает количество попыток и диапазон чисел в котором будет угадывать число.\
				  \n Игра дает подсказку, число больше или меньше введенного.\
				  \n Чем меньше число попыток, тем выше коэффициент и соответственно выше выйгрыш!\n");
		printf("\n Доступны следующие коэффициенты:\n");
		printf("\n 0,9 - Число попыток = заданному диапазону.\
				  \n 1,2 - Число попыток = 51%%-99%% диапазона.\
				  \n       Пример: Интервал - 100 чисел, попыток угадать - 51-99.\
				  \n 1,3 - Число попыток = 20%%-50%% от заданного диапазона.\
				  \n       Пример: Интервал - 100 чисел, попыток угадать - 20-50.\
				  \n 1,5 - Число попыток = 1%%-19%% от заданного диапазона.\
				  \n       Пример: Интервал - 100 чисел, попыток угадать - 1-19.");
		if ((Dmin == 0) && (Dmax == 0)) {
			printf("\n\n Баланс:\n\tТугрики:%.2f\n\tФишки:%d\n", MONEY, (int)COINS);
		}
		else {
			printf("\n\n Баланс:\n\tТугрики:%.2f\n\tФишки:%d\n\tЧисло попыток:%d\n\tЗагаданное число в диапазоне:%d-%d\n", MONEY, (int)COINS, chisloPopitok, Dmin, Dmax);
		}

        if (COINS < 1){
            printf("Недостаточно фишек");
            ANYKEY();
            return 2;
            break;
        } else {

            printf("\n_______________\nВведите ставку:\n");
            STtmp = stavka();
        }

        COINS = COINS - STtmp;
		while(MZ== 0){

                printf("\n_______________\nЧтобы задать интервал введите максимальное значение:\n");
                Dmax = 0;
                scanf("%d", &Dmax);
                if (Dmax > 0){

                MZ = 1;
                } else {
                    printf("Неверный ввод, пожалуйста повторите.\n");
                }
                rewind(stdin);
		}
		clrscr();
        printf("\n_____________________\nВведите число попыток:\n");
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
				printf("Неверный ввод, пожалуйста повторите.\n");
			}
			rewind(stdin);
		}
        clrscr();
		ZagChislo = 1+rand()%Dmax;
        while (chisloPopitok != 0){
            printf("Интервал:%d\nЧисло попыток:%d\nЧисло фишек:%d\n\nПопробуйте угадать число\n",Dmax,chisloPopitok,(int)COINS);
            scanf("%d", &vveliChislo);
            rewind(stdin);
            if(vveliChislo==ZagChislo){
                clrscr();
                rewind(stdin);
                COINS = COINS + (STtmp * koeff);
                printf("Интервал:%d\nЧисло попыток:%d\nЧисло фишек:%d\n\nПоздравляем! Вы угадали! Ваш выйгрышь:%d\n",Dmax,chisloPopitok,(int)COINS,(int)(STtmp * koeff));
                chisloPopitok =0;
            }
            else if ((vveliChislo < ZagChislo)&& (vveliChislo > 0) ){
            rewind(stdin);
               clrscr();
               printf("\n************\nЧисло больше\n************\n\n");
               chisloPopitok--;
               if (chisloPopitok == 0){
                printf("В следующий раз вам повезет!\nПопытки исчерпаны\nЗагаданное число = %d\n",ZagChislo);
               }
            }
            else if ((vveliChislo > ZagChislo)&& (vveliChislo > 0) ){
            rewind(stdin);
               clrscr();
               printf("\n************\nЧисло меньше\n************\n\n");
               chisloPopitok--;
               if (chisloPopitok == 0){
                printf("В следующий раз вам повезет!\nПопытки исчерпаны\nЗагаданное число = %d\n",ZagChislo);
               }
            }
            else {
                rewind(stdin);
                clrscr();
                printf("Неверный ввод, пожалуйста повторите.\n");
            }
        }
		} while (vihod == 1);
	return vihod;
}

int repGame(){
    int tmpW =0,tmp =-1;
    while(tmpW != 1){
    printf("Сыграть еще?\n\
           1 - да\n\
           0 - Нет\n");
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
            printf("Неверный ввод, пожалуйста повторите.\n");
        }
    }
}

float bye() {
    MONEY = COINS / kurs;
    int COINS1 = floor(COINS/ kurs) * kurs;
    COINS = COINS - COINS1;
    clrscr();
    printf("\nЖаль что уже уходите\nБаланс:\nТугрики: %.2f\nФишки: %.2f\n", MONEY,COINS);
    return MONEY;
}
