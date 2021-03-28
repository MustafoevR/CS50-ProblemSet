#include <stdio.h>
#include <cs50.h>

int main(void)
{
  long credit, credit_copy;
  int totalSum = 0, pos = 0, totalLength = 0;
  do
  {
    credit = get_long("Number: ");
    credit_copy = credit;
  }
  while(credit < 0);

  while(credit != 0)
  {
    if(pos % 2 != 0) // every other digit
    {
      int temp = 2 * (credit % 10);
      if(temp > 9)
      {
        totalSum += temp / 10 + temp % 10;
      }
      else
      {
        totalSum += temp;
      }
    }
    else
    {
      totalSum += credit % 10;
    }
    credit = credit / 10;
    pos++; // key to success
    totalLength++;
  }

  if(totalSum % 10 == 0)
    {

      //All American Express numbers start with 34 or 37 && American Express uses 15-digit numbers
      int amex_start = credit_copy / 10000000000000;
      if((amex_start == 34 || amex_start == 37) && totalLength == 15)
      {
        printf("AMEX\n");
        return 0;
      }


      //Master Card numbers start with 51, 52, 53, 54, or 55 && MasterCard uses 16-digit numbers
      int ms_start = credit_copy / 100000000000000;
      if((ms_start >= 51 && ms_start <= 55) && totalLength == 16)
      {
        printf("MASTERCARD\n");
        return 0;
      }


      //Visa numbers start with 4 && Visa uses 13- and 16-digit numbers
      int visa_start = credit_copy / 1000000000000;
      if((totalLength == 13 || totalLength == 16) && (visa_start == 4 || ms_start / 10 == 4))
      {
        printf("VISA\n");
        return 0;
      }
      printf("INVALID\n"); // if one of the above written if statement is true and there I have return then my program won't print ("INVALID")
    }
  else
    {
      printf("INVALID\n");
    }

}
