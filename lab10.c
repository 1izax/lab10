#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

float area_triangle(float a);
void print_definition();
void draw_triangle(int a, char s);
void print_parameters(float a);
float compare_triangle(float a1, float a2);

int main()
{
    setlocale(LC_ALL, "RUS");

    int choice;
    int size_for_draw;
    float a, a2;
    char s;
    float diff;
    do
    {
        printf("\n=============================================================\n");
        printf("                            МЕНЮ \n");
        printf("=============================================================\n");
        printf("1) Рассчитать площадь треугольника\n");
        printf("2) Вывести определение фигуры\n");
        printf("3) Нарисовать фигуру\n");
        printf("4) Вывести параметры фигуры\n");
        printf("5) Сравнить по площади с другим треугольником\n");
        printf("0) Выход\n");
        printf("-------------------------------------------------------------\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Введите длину стороны: ");
            scanf("%f", &a);
            printf("-------------------------------------------------------------\n");
            printf("Площадь треугольника: %.2f\n", area_triangle(a));
            break;

        case 2:
            printf("-------------------------------------------------------------\n");
            print_definition();
            break;

        case 3:
            printf("Введите сторону треугольника: ");
            scanf("%d", &size_for_draw);
            printf("Введите символ: ");
            scanf(" %c", &s);
            printf("-------------------------------------------------------------\n");
            draw_triangle(size_for_draw, s);
            break;

        case 4:
            printf("Введите длину стороны: ");
            scanf("%f", &a);
            printf("-------------------------------------------------------------\n");
            print_parameters(a);
            break;

        case 5:
            printf("Введите сторону первого треугольника: ");
            scanf("%f", &a);
            printf("Введите сторону второго треугольника: ");
            scanf("%f", &a2);
            printf("-------------------------------------------------------------\n");

            diff = compare_triangle(a, a2);
            if (diff > 0.0001) {
                printf("Первый треугольник больше второго на %.2f\n", diff);
            }
            else if (diff < -0.0001) {
                printf("Второй треугольник больше первого на %.2f\n", fabs(diff));
            }
            else {
                printf("Площади треугольников равны.\n");
            }
            break;

        case 0:
            printf("Программа завершена.\n");
            break;

        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}

float area_triangle(float a)
{
    return (sqrt(3.0) / 4.0) * a * a;
}

void print_definition()
{
    printf("Равносторонний треугольник — это треугольник, у которого все три стороны равны, а все углы равны 60 градусам.\n");
}

void draw_triangle(int a, char s)
{
    for (int i = 1; i <= a; i++)
    {
        for (int j = 0; j < i - 1; j++)
            printf(" ");
        for (int j = 1; j <= 2 * (a - i + 1) - 1; j++)
        {
            if (i == 1 || j == 1 || j == 2 * (a - i + 1) - 1)
                printf("%c", s);
            else
                printf(" ");
        }
        printf("\n");
    }
}

void print_parameters(float a)
{
    printf("Параметры фигуры:\n");
    printf("Сторона A = %.2f\n", a);
    printf("Периметр  = %.2f\n", 3 * a);
    printf("Высота    = %.2f\n", (sqrt(3.0) / 2.0) * a);
}

float compare_triangle(float a1, float a2)
{
    float s1 = area_triangle(a1);
    float s2 = area_triangle(a2);
    return s1 - s2;
}