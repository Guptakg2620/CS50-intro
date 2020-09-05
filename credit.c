#include <stdio.h>
#include <cs50.h>

void check_validity( long v, long w);

void check_cardtype( long ct);

int length( long l);

int main(void)
{
 long Number;
 do
 {
    Number = get_long("Number:");

 } while(Number < 0);

 length(Number);

 int len = length(Number);

if( len == 13 || len == 15 || len == 16)
{

 check_validity(Number,Number);

} else
{
    printf("INVALID\n");
}
}
int length(long l)
{
    int lt = 0;

    for( lt = 0; l != 0; l /= 10)
    {
    lt++;
    }
    return lt;
}
void check_validity (long v, long w)
{
    int val;
    int tot = 0;
    int mult;
    for(val = 0; v != 0; val++, v /= 10)
    {
        if(val % 2 == 0)
        {
            tot = tot + v % 10;
        }else
        {
            mult = 2*(v % 10);
            tot = tot + mult/10 + mult%10;
        }


    }
    if((tot % 10) == 0)
    {
        check_cardtype(w);
    }else
    {
        printf("INVALID\n");
    }



}
void check_cardtype(long ct)
{

   if(((ct >= 34e13 && ct < 35e13) || (ct >= 37e13 && ct  <38e13)))
    {
        printf("AMEX\n");
    }
    else if(((ct >= 4e12 && ct < 5e12) || (ct >= 4e15 && ct < 5e15)))
    {
        printf("VISA\n");
    }
     else if(((ct >= 51e14) && (ct < 56e14)))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
