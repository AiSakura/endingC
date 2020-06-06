// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <string.h>
#define LONG_STR 80  /* длина вводимой строки */

void itob(int n, char s[], int b)
{
    int i, sign, c;

    sign = n; //сохраняем знак
    if (sign < 0)
        n = -n;
    i = 0;
    do //генерируем цифры в обратном порядке
    {
        c = (n % b);
        s[i++] = (c > 9) ? c + 'A' - 10 : c + '0';
        n /= b;
    } while (n >= 1);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void reverse(char s[]);


int main()
{
    int n, b;
    char s[LONG_STR];

    printf("Enter the number n: ");
    scanf_s("%d", &n);
    printf("base b: ");
    scanf_s("%d", &b);
    itob(n, s, b);
    printf("%s", s);
    printf("\n");
    return 0;
}


/*reverse*/
void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}