void cleanArray(void *ar,int length)
{
    int i;
    for(i = 0; i<length;i++)
    {
        ar[i] = 0;
    }
}
