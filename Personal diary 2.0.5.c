
//Created by p32929
//Add me in facebook: https://www.facebook.com/p32929

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<sys/stat.h>

int reverse(char *str)
{
    char *p1, *p2;

    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    }
    while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    return;
}

int main()
{
    int n=0, i, c1;
    if (fopen("Sub.txt", "r") == NULL && fopen("N.txt", "r")==NULL)
    {
        char a[1000], g;
        printf("...::: First time running :::...\n");
        printf("...::: Are you ready? Enter YES to continue :::...\n");
        gets(a);
        printf("...::: Enter the activity names :::...\n...::: Input 0 to end inputting :::...\n");
        FILE *s;
        s = fopen("Sub.txt", "w+");
        while(1)
        {
            gets(a);
            if(strcmp(a, "0")==0)
                break;
            n++;
            fprintf(s, "%s\n", a);
        }
        fclose(s);

        FILE *N;
        N = fopen("N.txt", "w+");
        fprintf(N, "%d", n);
        fclose(N);
        printf("\n...::: Done inputting :::...\n...::: Total activities = %d :::...\n\n",n);
    }

    if(fopen("last.txt", "r")!=NULL)
    {
        FILE *last;
        last = fopen("last.txt", "r");
        char l[20];
        fgets(l, 20, last);
        printf(":::::: Last entry: %s ::::::\n", l);
        fclose(last);
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("...::: Current date: %d-%d-%d :::...\n", tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);

    int date[3];
    date[0]=tm.tm_mday;
    date[1]=tm.tm_mon + 1;
    date[2]=tm.tm_year + 1900;

    char raw[5][3], dates[15], dir[10]="Diary";
    dates[0]='\0';

    for(i=0; i<3; i++)
    {
        itoa(date[i], raw[i]);
    }

    for(i=0; i<3; i++)
    {
        strcat(dates, raw[i]);
        if(i==2)
        {
            strcat(dates, ".txt");
            break;
        }
        strcat(dates, "-");
    }

    mkdir(dir, S_IRWXU);
    strcat(dir, "/");

    FILE *out;
    FILE *last;

    printf("\nEnter your choice:\n1. Use current date\n2. Enter custom date\n");
    scanf("%d", &c1);

    if(c1==1)
    {
        printf("...::: Using date: %d-%d-%d :::...\n", tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900 );
        strcat(dir, dates);
        out= fopen(dir, "w+");
        fclose(out);

        last =  fopen("last.txt", "w+");
        fprintf(last, "%d-%d-%d", tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900 );
        fclose(last);
    }
    else
    {
        printf("Enter date[dd-mm-yyyy]:\n");
        char date2[15];
        scanf("%s", &date2);
        char last1[15];
        strcpy(last1, date2);
        strcat(date2, ".txt");
        strcat(dir, date2);

        out = fopen(dir, "w+");
        fclose(out);

        last =  fopen("last.txt", "w+");
        fprintf(last, "%s", last1);
        fclose(last);
    }

    char g;
    g=getchar();

    FILE *in0;
    in0 = fopen("N.txt", "r");
    fscanf(in0, "%d", &n);
    printf("...::: Total activities = %d :::...\n",n);
    fclose(in0);

    FILE *in1;
    in1 = fopen("Sub.txt", "r");

    char sub[1000][1000];
    for(i=0; i<n; i++)
    {
        fgets(sub[i], 1000, in1);
    }
    fclose(in1);

    out = fopen(dir, "w+");
    char act[1000];
    printf("\n");
    for(i=0; i<n ; i++)
    {
        printf("%d: %s", i+1, sub[i]);
        gets(act);
        fprintf(out, "# %s%s\n\n", sub[i], act);
    }

    fclose(out);
    printf("\n...::: Done for today!! Sayonara! ^_^ :::...\n...::: Made by p32929 :::...\n");
    return 0;
}
