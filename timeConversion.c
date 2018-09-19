#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getNumberInWords(int num)
{
    switch (num)
    {
    case 0:
        return "o'clock";
    case 1:
        return "One";
    case 2:
        return "Two";
    case 3:
        return "Three";
    case 4:
        return "Four";
    case 5:
        return "Five";
    case 6:
        return "Six";
    case 7:
        return "Seven";
    case 8:
        return "Eight";
    case 9:
        return "Nine";
    case 10:
        return "Ten";
    case 11:
        return "Eleven";
    case 12:
        return "Twelve";
    case 15:
    case 45:
        return "Quater";
    case 20:
        return "Twenty";
    case 30:
        return "half";
    default:
        return "";
    }
}
char *getElevenOnwards(int num)
{
    switch (num)
    {
    case 1:
        return "Eleven";
    case 2:
        return "Twelve";
    case 3:
        return "Thirteen";
    case 5:
        return getNumberInWords(10 + num);
    }
    return strcat(getNumberInWords(num), "teen");
}

void partition(int num)
{
    int firstPart, secondPart;
    firstPart = (num / 10) * 10;
    if (firstPart == 0)
        firstPart = -1;
    secondPart = num % 10;
    if ((firstPart + secondPart) > 10 && (firstPart + secondPart) < 20)
    {
        if (firstPart + secondPart == 15)
        {
            printf("%s ", getElevenOnwards(secondPart));
        }
        else
        {
            printf("%s minutes", getElevenOnwards(secondPart));
        }
    }
    else
    {
        printf("%s %s minutes ", getNumberInWords(firstPart), getNumberInWords(secondPart));
    }
}

void timeInWords(int hour, int minute)
{
    char *hourInWords = malloc(sizeof(char *));
    char *minuteInWords = malloc(sizeof(char *));

    if (minute == 0)
    {
        hourInWords = getNumberInWords(hour);
        minuteInWords = getNumberInWords(minute);
        printf("%s %s", hourInWords, minuteInWords);
    }
    else
    {
        if (minute <= 30)
        {
            hourInWords = getNumberInWords(hour);
            partition(minute);
            printf(" past %s", hourInWords);
        }
        else
        {
            minute = 60 - minute;
            hourInWords = getNumberInWords(hour + 1);
            if (minute != 15)
                partition(minute);
            else
            {
                printf("%s ", getNumberInWords(minute));
            }
            printf(" to %s", hourInWords);
        }
    }
}

int main()
{
    int h, m;
    do
    {
        printf("\nEnter the hour");
        scanf("%d", &h);
        if (h <= 0 || h > 12)
        {
            printf("\nInvalid hour...Please enter again!!!!");
        }
    } while (h <= 0 || h > 12);
    do
    {
        printf("\nEnter the minute");
        scanf("%d", &m);
        if (m < 0 || m > 60)
        {
            printf("\nInvalid minute...Please enter again!!!!");
        }
    } while (m < 0 || m > 60);

    printf("\nTIME IS %d:%d\n", h, m);
    timeInWords(h, m);
}