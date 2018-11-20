#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Raspis{ //структура с самолетами
	char NAZN[50];//место назначения
	char NUMR[30];//номер рейса
	char TIP[50];//модель самолета
}AeroFlot;

int main(){
	AeroFlot b1 = {"Barnaul", "С381" ,"Airbus 322"};
	AeroFlot b2 = {"Minsk", "С382" ,"Airbus 322"};
	AeroFlot b3 = {"Tomsk", "С383" ,"Airbus 322"};
	AeroFlot b4 = {"Novosibirsk", "С384" ,"Airbus 324"};
	AeroFlot b5 = {"St.Petersburg", "С385" ,"Airbus 325"};
	AeroFlot b6 = {"Kyiv", "С386" ,"Airbus 326"};
	AeroFlot b7 = {"Berlin", "С387" ,"Airbus 322"};

	AeroFlot Reisu[] = {b1, b2, b3, b4, b5, b6, b7};//тут чтоб 10 раз не вводить я сразу оформил массив структур
//========================================================== 
  int j,k;
 struct Raspis p;//переменная для сортировки пузырьком
 for(j=0; j<7; j++)
  {
   for(k=j+1; k<7; k++)
    {
     if(strcmp(Reisu[k-1].NAZN, Reisu[k].NAZN)<0) //сравниваем места назначения предыдущее с следующим
      {
       p=Reisu[k-1]; //выстраиваем по порядку пузырьком
       Reisu[k-1]=Reisu[k];
       Reisu[k]=p;
      }
    }
  }
	FILE *f; //указатель на файл

	f = fopen("Informatsiya.txt", "w");
	for(int i = 0; i<7; i++){
		fprintf(f,"%s %s %s\n",Reisu[i].NAZN, Reisu[i].NUMR, Reisu[i].TIP); //записываем отсортированные рейсы в файл чисто по приколу
	}
	fclose(f);//закрываем файл
//==========================================================
printf ("Справка:\n");
printf("В авиапарке имеются самолеты Airbus:321,322,323,324,325,326,327\n");
	printf("Введите модель самолета:\n");
	char model[100];//это короче компания 
	char number[6];//это номер модели
	char probel[1];//а это пробел между ними, люблю кастыли 
	probel[0]=' ';//объявил пробел
	scanf("%s %s",&model, &number); //записываем модель и номер
	strncat (model, probel,1);//соединяем компанию и пробел
	strncat (model, number,6);//соединяем компанию с пробелом и номером
	printf("Список самолетов для вас находится в файле Spisok.txt\n");
  
	f = fopen("Spisok.txt", "w");//файл для записи
	fprintf(f, "||      CITY      ||     Plane and Number           ||\r\n");
	for (int i = 0; i < 7; ++i){
		if (strcmp (model, Reisu[i].TIP)==0){//если наша костыльная модель совпала с той что в массиве структур
				fprintf(f, "======================================================\r\n");
		fprintf(f, "||%15s || %15s %15s ||\r\n",Reisu[i].NAZN,Reisu[i].TIP,Reisu[i].NUMR);}//записываем в файл
		if (strcmp (model, Reisu[i].TIP)!=0 && i==6){//если дошли до конца и не одно не попало
			fprintf(f, "Этого самолета нет в авиапарке\n");//записывем это
		}
	}
    fprintf(f, "======================================================");
	fclose(f);
return 0;
}
