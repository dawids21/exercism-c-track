#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>



bool is_isogram(const char phrase[])
{
    if (phrase == NULL)
        return false;
    bool alphabet[26] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,false, false, false,false, false, false,false, false, false, false};
    for (int i=0; phrase[i] != '\0'; i++)
    {
		if (isalpha(phrase[i]))
        {
			if (alphabet[tolower(phrase[i])-'a'])
                return false;
            else
                alphabet[tolower(phrase[i])-'a'] = true;
		}
    }
    return true;
}
