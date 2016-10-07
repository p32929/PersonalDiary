//Created by p32929
//Add me in facebook: https://www.facebook.com/p32929

#include<stdio.h>
#include<time.h>

int main()
{
    int n, i, c1;
    if (fopen("Sub.txt", "r") == NULL && fopen("N.txt", "r")==NULL)
    {

        char a[1000], g;
        printf("... First time running :::...\n");
        printf("How many activities to check daily:\n");
        scanf("%d", &n);
        g=getchar();
        printf("Enter the activity names:\n");
        FILE *s;
        s = fopen("Sub.txt", "w+");
        for (i = 0; i < n; i++)
        {
            gets(a);
            fprintf(s, "%s\n", a);
        }
        fclose(s);

        FILE *N;
        N = fopen("N.txt", "w+");
        fprintf(N, "%d", n);
        fclose(N);
        printf("Done activity names inputting\nPlease wait...\n");
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("...::: Current date: %d-%d-%d :::...\n", tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);

    FILE *out;
    out = fopen("Diary.txt", "a+");
    printf("\nEnter your choice:\n1. Use current date\n2. Enter custom date\n");
    scanf("%d", &c1);
    if(c1==1)
    {
        printf("...::: Using date: %d-%d-%d :::...\n", tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900 );
        fprintf(out, "...::: Date: %d-%d-%d :::...\n", tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900 );
    }
    else
    {
        printf("Enter date[dd-mm-yyyy]:\n");
        char date[15];
        scanf("%s", &date);
        fprintf(out, "...::: Date: %s :::...\n", date);
    }
    fclose(out);

    char g;
    g=getchar();

    FILE *in0;
    in0 = fopen("N.txt", "r");
    fscanf(in0, "%d", &n);
    printf("Total activities = %d\n", n);
    fclose(in0);

    FILE *in1;
    in1 = fopen("Sub.txt", "r");

    char sub[1000][1000], date[20];
    for(i=0; i<n; i++)
    {
        fgets(sub[i], 1000, in1);
    }
    fclose(in1);

    out = fopen("Diary.txt", "a+");
    char act[1000];
    printf("\n");
    for(i=0; i<n ; i++)
    {
        printf("%d: %s", i+1, sub[i]);
        gets(act);
        fprintf(out, "# %s%s\n\n", sub[i], act);
    }

    fclose(out);
    printf("\n...::: Done for today. Sayonara!\n^_^ :::...\n...::: Made by p32929 :::...\n");
    return 0;
}
