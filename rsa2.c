/*Authors:Rohit kumar Nayak,Vineet kumar pilania
Topic:Rsa algorithm in c
Date:9-FEB-2022*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// declaration of variables
int x = 71, y = 293, n, t, i, flag;
long int e[500000], d[500000], temp[500000], j;
char en[100000], m[100000];
char msg[100000];
int isprime(long int);
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();
// main function
int main()
{
   int ch;
   printf("Enter 1 for Encryption\n");
   printf("Enter 2 for Decryption\n");
   scanf("%d", &ch);
   if (ch == 1)
   {
      fflush(stdin);
      printf("Enter the Message to Encrypt\n");
      gets(msg);
      for (i = 0; msg[i] != '\0'; i++)
         m[i] = msg[i];
      n = x * y;
      t = (x - 1) * (y - 1);
      encryption_key();
      encrypt();
   }
   if (ch == 2)
   {
      msg[0] = 'h';
      m[0] = 'h';
      n = x * y;
      t = (x - 1) * (y - 1);
      encryption_key();
      decrypt();
   }
   return 0;
}
// checking for the prime no
int isprime(long int pr)
{
   int i;
   j = sqrt(pr);
   for (i = 2; i <= j; i++)
   {
      if (pr % i == 0)
         return 0;
   }
   return 1;
}
// generating public(e[]) and private encryption key(d[])
void encryption_key()
{
   int k;
   k = 0;
   for (i = 2; i < t; i++)
   {
      if (t % i == 0)
         continue;
      flag = isprime(i);
      if (flag == 1 && i != x && i != y)
      {
         e[k] = i;
         flag = cd(e[k]);
         if (flag > 0)
         {
            d[k] = flag;
            k++;
         }
         if (k == 100000)
            break;
      }
   }
}

long int cd(long int a)
{
   long int k = 1;
   while (1)
   {
      k = k + t;
      if (k % a == 0)
         return (k / a);
   }
}
// encrypt fuction
void encrypt()
{
   long int pt, ct, key = e[0], k, len;
   i = 0;
   len = strlen(msg);

   while (i != len)
   {
      pt = m[i];
      pt = pt - 96;
      k = 1;
      for (j = 0; j < key; j++)
      {
         k = k * pt;
         k = k % n;
      }
      temp[i] = k;
      ct = k + 96;
      en[i] = ct;
      i++;
   }
   en[i] = '\0';
   printf("\n\n DECRYPTION KEY is:\n");
   for (i = 0; en[i] != '\0'; i++)
      printf("%ld ", temp[i]);
   printf("\n\nTHE ENCRYPTED MESSAGE is:\n");
   for (i = 0; en[i] != '\0'; i++)
      printf("%c", en[i]);
}
// decryption function
void decrypt()
{
   fflush(stdin);
   printf("\n\nENTER ENCRYPTED MESSAGE \n");
   gets(en);
   printf("\n\n ENTER DECRYPTION KEY\n");
   for (i = 0; i != strlen(en); i++)
   {
      scanf("%ld", &temp[i]);
   }
   d[0] = 13627; // private key code

   long int pt, ct, key = d[0], k;
   i = 0;
   while (en[i] != '\0')
   {
      ct = temp[i];
      k = 1;
      for (j = 0; j < key; j++)
      {
         k = k * ct;
         k = k % n;
      }
      pt = k + 96;
      m[i] = pt;
      i++;
   }
   m[i] = '\0';
   printf("\n\nTHE DECRYPTED MESSAGE is:\n");
   for (i = 0; m[i] != '\0'; i++)
      printf("%c", m[i]);

   printf("\n");
}