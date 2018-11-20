#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h" //вызов файла с прототипами
#include "sort.c" //вызов файла с функциями 
 
int main(void)
{
    char * filename = "AeroFlotRaspis.dat";//создание файла с определенным названием
    struct AeroFlot Reisu[] = { "Minsk", "С382", "Airbus 322", "Tomsk", "С383", "Airbus 322",
			"St.Petersburg", "С385", "Airbus 325",
			"Novosibirsk", "С384", "Airbus 324",
			"Kyiv", "С386", "Airbus 326",
			"Berlin", "С387", "Airbus 322",
			"Barnaul", "С381", "Airbus 322"};//массив структур неопределенного размера,создан чтобы не заполнять 10 раз одно и тоже для проверки
    int n = sizeof(Reisu) / sizeof(Reisu[0]); //размер массива структур
    save(filename, Reisu, n);//вызов функции записывающей и сортирующей массив структур
    load(filename);//вызов функции берущей записанный массив структур и вычисляющей нужные рейсы
    
    return 0;
}