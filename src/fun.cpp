unsigned int faStr1(const char *str)
{
    int count_w = 0;
    bool inWord = false;
    bool withNumb = false;
    int i = 0;

    while (str[i] != '\0')
    {
        if(!inWord && str[i] != ' ')
        {
            inWord = true;
            if(str[i] <= 57 && str[i] >= 48)
                withNumb = true;
        }
        else if(inWord && str[i] != ' ')
        {
            if(str[i] <= 57 && str[i] >= 48)
                withNumb = true;
        }
        else
        {
            if(!withNumb && inWord)
                count_w++;
            inWord = false;
            withNumb = false;
        }
        i++;
    }
    if(!withNumb && inWord)
        count_w++;
    
    return count_w;
}

unsigned int faStr2(const char *str)
{
    bool CheckLowerCase = true;
    bool CheckUpperCase = false;
    bool inWord = false;
    int count_w = 0;
    int i = 0;

    while(str[i] != '\0')
    {
        if(!inWord && str[i] != ' ')
        {
            inWord = true;
            if(str[i] >= 65 && str[i] <= 90)
                CheckUpperCase = true;
        }
        else if(inWord && str[i] != ' ')
        {
            if(str[i] < 97 || str[i] > 122)
                CheckLowerCase = false;
        }
        else
        {
            if(CheckUpperCase && CheckLowerCase && inWord)
                count_w++;
            inWord = false;
            CheckLowerCase = true;
            CheckUpperCase = false;
        }
        i++;
    }
    if(CheckUpperCase && CheckLowerCase && inWord) 
       count_w++;
    
    return count_w;
}

unsigned int faStr3(const char *str)
{
    double avg_sum = 0.0;
    int i = 0;
    int count_w = 0;
    int length = 0;
    bool inWord = false;

    while(str[i] != '\0')
    {
        if(!inWord && str[i] != ' ')
        {
            inWord = true;
            length++;
            count_w++;
        }
        else if (inWord && str[i] != ' ')
        {
            length++;
        }
        else
        {
            inWord = false;
            avg_sum += length;
            length = 0;
        }
        i++;
    }
    if(inWord)
        avg_sum += length;
    avg_sum /= count_w;
    int r_sum = avg_sum;
    if(avg_sum - r_sum >= 0.5)
       r_sum++;
    
    return r_sum;
}