#include <stdio.h>
#include <stdlib.h>

#include "candidate.h"

int read()
{
    FILE* file = fopen("test.bin", "rb");
    if(file == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    struct Candidate* candidates = NULL;
    int count = 0;
    struct Candidate temp;

    while(fread(&temp, sizeof(struct Candidate), 1, file) == 1)
    {
        count++;

        struct Candidate* temp_ptr = (struct Candidate*)realloc(candidates, count * sizeof(struct Candidate));
        if(temp_ptr == NULL)
        {
            printf("Memory allocation failed\n");
            free(candidates);
            fclose(file);
            return 1;
        }
        candidates = temp_ptr;
        candidates[count - 1] = temp;
    }

    for(int i = 0; i < count; i++)
    {
        printf("Name: %s\n", candidates[i].name);
        printf("Experience: %d\n", candidates[i].experience);
        printf("Skill: %d\n\n", candidates[i].skill);
    }


    free(candidates);
    fclose(file);
    return 0;
}