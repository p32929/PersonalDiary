
#include<stdio.h>
#include<time.h>
int main()
{
    int n, i;
    char g;
    if (fopen("Sub.txt", "r") == NULL && fopen("N.txt", "r")==NULL)
    {
        FILE *s;
        char a[1000];
        s = fopen("Sub.txt", "w+");
        printf("How many subjects to check up daily?\n");
        scanf("%d", &n);
        g=getchar();
        printf("Enter the subjects:\n");
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
    }
    printf("Done subject inputting :)\nYour diary is readying for using :)\nPlease wait...\n\n\n");

    FILE *in0;
    in0 = fopen("N.txt", "r");
    fscanf(in0, "%d", &n);
    fclose(in0);

    FILE *in1;
    in1 = fopen("Sub.txt", "r");
    char sub[1000][1000], date[20];
    for(i=0; i<n; i++)
    {
        fgets(sub[i], 1000, in1);
    }
    fclose(in1);
    FILE *out;
    char act[1000];
    out = fopen("Diary.txt", "a+");
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ("Enter activities for current date & time: %s", asctime (timeinfo) );
    fprintf(out, "Date & time: %s", asctime (timeinfo));
    for(i=0; i<n ; i++)
    {
        printf("# %s", sub[i]);
        gets(act);
        fprintf(out, "# %s => %s\n", sub[i], act);
    }
    fclose(out);
    printf("\n\n...::: Done for today. Sayonara! ^_^ :::...\n...::: Made by p32929 :::...\n");
    return 0;
}
