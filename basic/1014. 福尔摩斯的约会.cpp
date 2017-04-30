#include <stdio.h>
#include <string.h>

int main()
{
    char *week_table[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char str1[61], str2[61], str3[61], str4[61];
    int i;
    int week, hour, second;
    int len1, len2, len3, len4;

    scanf("%s%s%s%s", str1, str2, str3, str4);

    len1 = strlen(str1);
    len2 = strlen(str2);
    len3 = strlen(str3);
    len4 = strlen(str4);

    week = hour = second = 0;

    for(i = 0; i < len1 && i < len2; i++)
    {
        if(str1[i] == str2[i] && (str1[i] >= 'A' && str1[i] <= 'G'))
        {
            week = str1[i] - 'A'; 
            break;
        }
    }
    for(i++; i < len1 && i < len2; i++)
    {
        if(str1[i] == str2[i] && ((str1[i] >= 'A' && str1[i] <= 'N') || (str1[i] >= '0' && str1[i] <= '9')))
        {
            if(str1[i] >= 'A' && str1[i] <= 'N')
                hour = str1[i] - 'A' + 10;
            else
                hour = str1[i] - '0';

            break;
        }
    }

    for(i = 0; i < len3 && i < len4; i++)
    {
        if((str3[i] == str4[i]) && ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z')))
        {
            second = i;
            break;
        }
    }

    printf("%s %02d:%02d", week_table[week], hour, second);

    return 0;
}
