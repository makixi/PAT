#include <stdio.h>
#include <string.h>

#define MAX_LEN        (1024)

int main(void)
{
    char str[MAX_LEN];
    int table[10] = {0};
    int i, len;
        
    scanf("%s", str);
    len = strlen(str);
    for(i = 0; i < len; i++)
    {
        table[str[i]-'0']++;
    }
    for(i = 0; i < sizeof(table)/sizeof(table[0]); i++)
    {
        if(table[i] != 0)
            printf("%d:%d\n", i, table[i]);
    }
    return 0;    
}
