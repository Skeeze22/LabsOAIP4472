#include <stdio.h>
#include <stdlib.h>
int main()
{
//============================================================
int **a;// указатель на массив, размерность массива A
int **b;
int nb,mb,n,m;
int i = 0, j = 0;// индексы элементов матрицы
FILE *fp = fopen("f1.txt","r");
FILE *fp2 = fopen("f2.txt","w");
printf ("Сканирование размеров матрицы из файла. \n");
if(fp != NULL) 
{ 
fscanf(fp,"%d",&n);
printf("n = %d\n",n);
} 
else {printf("Невозможно открыть файл на чтение.\n "); 
fclose(fp); 
return 0; 
}
m=n;
nb=n;
mb=m;
n=n*3;
m=m*3;
//=============================================================
// выделяем память под массив
a = (int**)malloc(n * sizeof(int*));
 // Ввод элементов массива
  for (i = 0; i<n; i++)  // цикл по строкам
  {
    // Выделение памяти под хранение строк
    a[i] = (int*)malloc(m * sizeof(int));
    for (j=0;j<m;j++){
		fscanf(fp,"%d",&a[i][j]);
	}
    }
//======================================================
printf("Начальная матрица берется из файла f1.txt:\n");
 for (i = 0; i < n; i++)  // цикл по строкам
  {
    for (j = 0; j < m; j++)  // цикл по столбцам
    {
      printf("%5d ", a[i][j]); // 5 знакомест под элемент массива
    }
    printf("\n");
  }
//===========================================================
//Из матрицы a размером 3n×3m сформировать матрицу b размером n×m. Каждый элемент bij 
//вычислит как определитель матрицы третьего порядка, составленный из элементов матрицы a, 
//лежащих на пересечении строк (3(i+1)-2), (3(i+1)-1), 3(i+1) и столбцов (3(j+1)-2), (3(j+1)-1), 3(j+1)
//===============================================================
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
     fprintf(fp2,"%5d ", b[i][j]); // 5 знакомест под элемент массива
     fflush(fp2);
    }
    fprintf(fp2,"\n");
  }
//===============================================================
// Очистка памяти
    fclose(fp);
    fclose(fp2);
  for (i = 0; i < n; i++){  // цикл по строкам
  free(a[i]); // освобождение памяти под строку в a
  free(b[i]);} // освобождение памяти под строку в b
  free(a);
  free(b);
  getchar();   getchar();
  return 0;
}
/*
f1.txt
3
7 2 3 4 6 6 7 8 8
2 3 4 5 6 7 8 9 1
5 4 2 6 7 8 1 2 6
4 5 6 5 5 9 3 2 5
8 6 6 4 4 5 1 5 2
6 7 8 9 1 2 3 4 5
7 8 9 1 4 3 4 5 6
3 9 1 2 4 4 5 6 8
9 1 6 3 7 5 6 7 8 
*/