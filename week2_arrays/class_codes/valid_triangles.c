#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int a, int b, int c);

int main (void)
{
    int a = get_int("Size: ");
    int b = get_int("Size: ");
    int c = get_int("Size: ");

    if (valid_triangle(a, b, c) == true)
    {
        printf("Este é um triângula válido.\n");
    }
    else
    {
        printf("Este não é um triângulo válido.\n");
    }
}

bool valid_triangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0 )
    {
        return false;
    }
    
    if (a + b <= c || a + c <= b || b + c <= a )
    {
        return false;
    }
    else
    {
        return true;
    }
}