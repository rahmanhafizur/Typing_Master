void compareEasyStrings(const char *str, const char *tar)
{
    int score=0;
    char *a, *b;
    a = strtok(str, " ");
    b = strtok(tar, " ");
    if(!strcmp(a,b)) score++;
    while (a != NULL || b != NULL)
    {
        a = strtok(NULL, " ");
        b = strtok(NULL, " ");
        printf("%s %s\n",a,b);
        if(!strcmp(a,b)) score++;
    }
    printf("%d\n",score);
}
