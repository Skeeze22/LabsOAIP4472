#include <stdio.h>
#include <stdlib.h>
int main()
{
//============================================================
int **a;// указатель на массив, размерность массива A
int **b;
int nb,mb,n,m;
int i = 0, j = 0;// индексы элементов матрицы
int number;
FILE *fp;

printf ("Сканирование размеров матрицы:\n");
scanf("%d",&n);
m=n;
nb=n;
mb=m;
n=n*3;
m=m*3;
fp = fopen("f1.bin","wb");
//=============================================================
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
		number = rand()%10;
		fwrite(&number,sizeof(int),1,fp);
	}
}
fclose(fp);
printf("Бинарный файл с вашей матрицей создан\n");
fp = fopen("f1.bin","rb");
//=============================================================
// выделяем память под массив
a = (int**)malloc(n * sizeof(int*));
 // Ввод элементов массива
  for (i = 0; i<n; i++)  // цикл по строкам
  {
    // Выделение памяти под хранение строк
    a[i] = (int*)malloc(m * sizeof(int));
    for (j=0;j<m;j++){
	fread(&a[i][j], sizeof(int), 1, fp); 
		}
  }
//======================================================
printf("Начальная матрица берется из файла f1.bin:\n");
 for (i = 0; i < n; i++)  // цикл по строкам
  {
    for (j = 0; j < m; j++)  // цикл по столбцам
    {
      printf("%5d ", a[i][j]); // 5 знакомест под элемент массива
    }
    printf("\n");
  }
  fclose(fp);
//=======================================================
//Из матрицы a размером 3n×3m сформировать матрицу b размером n×m. Каждый элемент bij 
//вычислит как определитель матрицы третьего порядка, составленный из элементов матрицы a, 
//лежащих на пересечении строк (3(i+1)-2), (3(i+1)-1), 3(i+1) и столбцов (3(j+1)-2), (3(j+1)-1), 3(j+1)
//=======================================================
// выделяем память под массив
b = (int**)malloc(nb * sizeof(int*));
 // Ввод элементов массива
  for (i = 0; i<nb; i++)  // цикл по строкам
  {
    // Выделение памяти под хранение строк
    b[i] = (int*)malloc(mb * sizeof(int));
    for (j = 0; j<mb; j++)  // цикл по столбцам
    {
    b[i][j] =a[(3*(i+1)-2)][(3*(j+1)-2)]*a[(3*(i+1)-1)][(3*(i+1)-1)]*a[(3*i)][(3*j)]
    +a[(3*i)][(3*(j+1)-2)]*a[(3*(i+1)-2)][(3*(i+1)-1)]*a[(3*(i+1)-1)][(3*(j+1))]
    +a[(3*(i+1)-1)][(3*(j+1)-2)]*a[(3*i)][(3*(i+1)-1)]*a[(3*(i+1)-2)][(3*(j+1))]
    -(a[(3*i)][(3*(j+1)-2)]*a[(3*(i+1)-1)][(3*(i+1)-1)]*a[(3*(i+1)-2)][(3*(j+1))])
    -(a[(3*(i+1)-2)][(3*(j+1)-2)]*a[(3*i)][(3*(i+1)-1)]*a[(3*(i+1)-1)][(3*(j+1))])
    -(a[(3*(i+1)-1)][(3*(j+1)-2)]*a[(3*(i+1)-2)][(3*(i+1)-1)]*a[(3*i)][(3*(j+1))]); 
    // это все формула для определителя 3 порядка, по заданию не робит, так более менее
    }
  }
//============================================================
FILE *fp2 = fopen("f2.txt","w");
printf("Матрица после решения: \n");
 for (i = 0; i < nb; i++)  // цикл по строкам
  {
    for (j = 0; j < mb; j++)  // цикл по столбцам
    {
      printf("%5d ", b[i][j]); // 5 знакомест под элемент массива
    }
    printf("\n");//переход на следующую строчку
  }
printf("Матрица после решения находится в файле f2.txt \n");
for (i = 0; i < nb; i++)  // цикл по строкам
  {
    for (j = 0; j < mb; j++)  // цикл по столбцам
    {
     fprintf(fp2,"%5d ", b[i][j]); 
     //fflush(fp2);
    }
    fprintf(fp2,"\n");
  }
  fclose(fp2);
//===============================================================
// Очистка памяти
  for (i = 0; i < n; i++){  // цикл по строкам
  free(a[i]); // освобождение памяти под строку в a
  free(b[i]);} // освобождение памяти под строку в b
  free(a);
  free(b);
  getchar();   getchar();
  return 0;
}
/*
Создать f1.bin
Создать f2.txt
*/