#ifndef MYALG_H_INCLUDED
#define MYALG_H_INCLUDED

/*
    LANGUAGE: C
    *************************************************************************************************************************************
    INFO: ZAGOLOVOCHNII FILE, PREDSTAVL9ET IZ SEB9 SHPARGALKY IZ POLEZNIH, CHASTO NEOBHODIMIH ALGORITMOV NA C.
    SOSTAVLENO VO VREM9 OBUCHENI9 NA KURSE PROF.PEREPODGOTOVKI V NGTU, ALGORITMI BILI SOBRANI NE TOLKO S KURSA, A SO VSEH INTERNETOV };-)
    *************************************************************************************************************************************
    YEAR:2022
    SOZDAL: ALEKSANDR KUZNETSOV
*/

//VVOD CHISLA, VIVESTI VSE EGO SOSTAVL9UWIE CHISLA OTDELNO, primmer: vvod_9876, vivod 6 7 8 9
int vivod_otd_chisel(){
    int n;
    scanf("%d", &n);
    while (n!=0) {
        int t = n % 10;
        n = n / 10;
        printf("%d ", t);
    }
}
// FACTORIAL PROSTA9 FORMULA !n, POLUCHAEM EGO RESULT
int factorial( int n )
{
    int r = 1;
    for (int i = n; i > 0;i--){
        r *= i;
    }
    return r;
}

//FACTORIAL CHEREZ REKYRSIU
int factorial_rek( int n )
{
    return n==0 ? 1 : n*factorial_rek(n-1);
}

//OPREDEL9EM KOL-VO SIMVOLOV V UKAZANNOM MASIVE
int LEN(char text[]) {
    int size = 0;
    for (; text[size] != '\0'; size++);
    return size;
}

//OPREDELENIE PERVOI BUKVI V MASIVE I ZAMENA NA VERHNII REGISTR
//unsigned dl9 raboti s polozhitelnimi ciframi 0-255
//peremennie a,A,x neobhodimmo vinesti otdelno iz za tipa unsigned, rgo ne mozhem podat v sravnenie ili v formyly,
int FCN(char text[]) {
    unsigned char a = 'а';
    unsigned char A = 'А';
    unsigned char x = text[0];
    if ((int)x >= (int)a) {
        x = (int)x - ((int)a-(int)A); //perevod nizhn registr v verhnii
    }
    int res = (int)x - (int)A + 1; // opredelenie alfavitnogo por9dka bukvi
    return res;
}
// PROVERKA NA VERNII VVOD - dovesti do uma
//int prov_vvoda(){
//      do {
//        printf("%s", "Введите порядковый номер лабораторной работы (2,3,4,5): ");
//        scanf("%d", &i);
//        if (i<2 || i>5) {
//            printf("%s\n", "Ошибка!");
//        }
//        else { break; }
//    } while (1);
//}

//GENERACI9 SLUCHAINOGO CHISLA min-max, NEED: #include <time.h> (main)srand(time(0));
int random(int min, int max) {
	return rand() % (max - min+1) + min;
}

//SOZDANIE DVUMERNOGO DIN. MASSIVA
//ne poluchaetsa s klavi v main poluchit argymenti, nado gugglit, vozmono nado kak ykazateli, ili ewe drygim tipom
// dl9 vivoda specsimvolov, men9em tip massiva na char
int din_massiv(int stroki, int stolbci){

	int **mas = (int *)malloc(sizeof(int) * stroki); // vse int na char tam gde tip masiva(mas,malloc,sizeof,), esli nuzhen vivod specsimvoli
	for (int i = 0; i < stroki; i++) {// cikl kotorii v kazhduu stroku generiruet din. massiv. Tak zadautsa stolbci
		mas[i] = (int*)malloc(sizeof(int) * stolbci);
	}
	//zapolnenie dvumernogo din. massiva
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbci; j++) {
			mas[i][j] = rand()%9+1;//to chto mi bydem vnosit v kazhdii stolbec po por9dky
		}
	}
//  ZAPOLNENIE MASIVA PO DIAGONALI NULEM, OSTALNOE RANDOMNO
//	for(int=0; i<size; i++){
//            for(int j=0; j<size; j++){
//            matrix[i][j] = (i==j || i==size-j-1) ? 0 : random(-9,10);
//            }
//	}

	//vivod dvumernogo massiva
	// transponirovanie matrici stavim j=x-1; j=>0; j --
	//v cikle vivoda nuzhno zadavat uslovie <= ,a ne kak v cikle zapolnenii < , inache vivedet liwnee znachenie - chislo strok, est kaka9 to osobennost, NADO PPOISKAT
	for (int i = 0; i <= stroki; i++) {
		for (int j = 0; j < stolbci; j++) {
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}
	//free(mas); obichno nado ochiwat videlennuu pam9t, poka ne izychil nado li tyt
}
 // POISK SOVPADENII V MASIVE C++
 int vivod_rezultata_poiska(){
 char iwem = 'T';
 for (int i=0; i<5; i++){
    //arr[i][0] - perva9 bykva stroki i
    if (arr[i][0] == vivod_rezultata_poiska){
        cout << arr[i] << endl;
    }
 }
 }
 //SOZDANIE, NAPOLNENIE, VIVOD MASSIVA
//#define SIZEm 100
//char str[SIZEm] = "";
//printf("Введите строку: ");
//scanf("%30s",str);
//printf("Вы ввели: %s",str);

// OCHISTKA EKRANA, NEED stdlib.h, obiavit funkciu, vizvat.
void clrscr()
{
	system("@cls||clear");
}

// ZAWITA OT DURAKA - VVOD TEXTA zaprewen
//if (!(scanf("%d", &vibor)))

// ZAWITA OT DURAKA - VVOD TEXTA zaprewen
//if (scanf("%d", &str[i]) != 1){
//printf("Its not a number");
//return -1;
//}
//если ввести в scanf("%d") не число, то он вернет 0
//Вот и всё решение))

// REGUL9RKA RAZDEL9ET TEKST I CIFRI
//scanf("%[^0-9]%d",str,&num);// рег все кроме цифр ввод abc123
  //  printf("%s\n",str);                                abc
    //printf("%d",num);                                  123

// OCHISTKA BUFERA POSLE SCANF
//rewind(stdin);
#endif // MYALG_H_INCLUDED
