#include <stdio.h>      // printf aur scanf use karne ke liye library

int mutex = 1;          // mutex = lock (1 matlab buffer free hai)
int full = 0;           // full = buffer me kitne items hai
int empty = 3;          // empty = buffer me kitni empty space hai (buffer size = 3)
int x = 0;              // x = item number
// Producer function
void producer()
{
    mutex--;            // buffer lock kar diya (dusra process use nahi karega)
    empty--;            // buffer ki empty space 1 kam ho gayi
    full++;             // buffer me item 1 badh gaya
    x++;                // new item produce hua
    printf("Producer produces item %d\n", x);   // producer ne item produce kiya
    mutex++;            // buffer unlock ho gaya
}
// Consumer function
void consumer()
{
    mutex--;            // buffer lock kar diya
    full--;             // buffer me item 1 kam ho gaya
    empty++;            // empty space 1 badh gayi
    printf("Consumer consumes item %d\n", x);   // consumer item consume kar raha hai
    x--;                // item remove ho gaya
    mutex++;            // buffer unlock ho gaya
}

int main()
{
    int n,i;
    printf("Enter number of processes: ");
    scanf("%d",&n);     // user se number of processes input
    for(i=1;i<=n;i++)   // loop jitni baar process run karna hai
    {
        if(mutex==1 && empty!=0)     // agar buffer free hai aur space hai
        {
            producer();              // producer item produce karega
        }
        else if(mutex==1 && full!=0) // agar buffer free hai aur item hai
        {
            consumer();              // consumer item consume karega
        }
        else
        {
            printf("Buffer Full or Empty\n"); // buffer full ya empty hai
        }
    }
    return 0;           // program end
}
