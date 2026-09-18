#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "candidate.h"

int read(void)
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

int search_candidate(void)
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
        struct Candidate* temp_ptr = (struct Candidate*)realloc(candidates, count * (sizeof(struct Candidate)));
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

    char search_name[20];
    int found = 0;
    printf("Enter candidate name: ");
    scanf("%19s", search_name);
    for(int i = 0; i < count; i++)
    {
        if(strcmp(candidates[i].name, search_name) == 0)
        {
            found = 1;
            printf("Candidate Found !!\n\n");
            printf("Name: %s\n", candidates[i].name);
            printf("Experience: %d\n", candidates[i].experience);
            printf("Skill: %d\n", candidates[i].skill);
            break;
        }
    }
    if(!found)
    {
        printf("Candidate does not exist\n");
    }

    free(candidates);
    fclose(file);
    return 0;
}

int add_candidate(void)
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

    struct Candidate new_candidate;
    printf("Enter name of the new candidate\n");
    scanf("%19s", new_candidate.name);
    printf("Enter name of the new experience\n");
    scanf("%d", &new_candidate.experience);
    printf("Enter name of the new skill\n");
    scanf("%d", &new_candidate.skill);

    count++;
    struct Candidate* new_temp_ptr = (struct Candidate*)realloc(candidates, count * sizeof(struct Candidate));
    if(new_temp_ptr == NULL)
    {
        printf("Memory allocation failed\n");
        free(candidates);
        fclose(file);
        return 1;
    }
    candidates = new_temp_ptr;
    candidates[count - 1] = new_candidate;

    printf("\nUpdated candidates:\n\n");
    for(int i = 0; i < count; i++)
    {
        printf("Name: %s\n", candidates[i].name);
        printf("Experience: %d\n", candidates[i].experience);
        printf("Skill: %d\n\n", candidates[i].skill);
    }
    fclose(file);

    file = fopen("test.bin", "wb");
    if(file == NULL)
    {
        printf("File cannot be opened\n");
        free(candidates);
        return 1;
    }
    size_t written = fwrite(candidates, sizeof(struct Candidate), count, file);
    if(written != (size_t)count)
    {
        printf("Error writing candidates!\n");
        free(candidates);
        fclose(file);
        return 1;
    }

    free(candidates);
    fclose(file);
    return 0;
}

int update_candidate()
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
        struct Candidate* temp_ptr = (struct Candidate*)realloc(candidates, count * (sizeof(struct Candidate)));
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

    char search_name[20];
    int found = 0;
    printf("Enter candidate name: ");
    scanf("%19s", search_name);
    for(int i = 0; i < count; i++)
    {
        if(strcmp(candidates[i].name, search_name) == 0)
        {
            found = 1;
            printf("Candidate Found !!\n");
            printf("Name: %s\n", candidates[i].name);
            printf("Experience: %d\n", candidates[i].experience);
            printf("Skill: %d\n", candidates[i].skill);

            int type;
            int update_type;
            printf("Enter what needs to be updated: 1. Experience    2. Skill\n");
            scanf("%d", &type);
            if(type == 1)
            {
                printf("Enter updated experience: ");
                scanf("%d", &update_type);
                candidates[i].experience = update_type;
                printf("Candidate updated\n\n");
                printf("Name: %s\n", candidates[i].name);
                printf("Experience: %d\n", candidates[i].experience);
                printf("Skill: %d\n", candidates[i].skill);

            }
            else if(type == 2)
            {
                printf("Enter updated skill: ");
                scanf("%d", &update_type);
                candidates[i].skill = update_type;
                printf("Candidate updated\n\n");
                printf("Name: %s\n", candidates[i].name);
                printf("Experience: %d\n", candidates[i].experience);
                printf("Skill: %d\n", candidates[i].skill);
            }
            else
            {
                printf("Error\n");
                return 1;
            }
            break;
        }
    }
    if(!found)
    {
        printf("Candidate does not exist\n");
        free(candidates);
        fclose(file);
        return 1;
    }
    fclose(file);

    file = fopen("test.bin", "wb");
    if(file == NULL)
    {
        printf("File cannot be opened\n");
        free(candidates);
        return 1;
    }
    size_t written = fwrite(candidates, sizeof(struct Candidate), count, file);
    if(written != (size_t)count)
    {
        printf("Error writing candidates!\n");
        free(candidates);
        fclose(file);
        return 1;
    }

    free(candidates);
    fclose(file);
    return 0;
    
}

int delete_candidate(void)
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
        struct Candidate* temp_ptr = (struct Candidate*)realloc(candidates, count * (sizeof(struct Candidate)));
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

    char delete_name[20];
    int found = 0;
    printf("Enter name of the candidate to be deleted\n");
    scanf("%19s", delete_name);
    for(int i = 0; i < count; i++)
    {
        if(strcmp(candidates[i].name, delete_name) == 0)
        {
            found = 1;
            printf("Candidate Found !!!\n");
            for(int j = i; j < count - 1; j++)
            {
                candidates[j] = candidates[j + 1];
            }
            count--;

            if(count == 0)
            {
                free(candidates);
                candidates = NULL;
            }
            else
            {
                struct Candidate* ptr = (struct Candidate*)realloc(candidates, count * sizeof(struct Candidate));
                if(ptr == NULL)
                {
                    printf("Memory reallocation failed!\n");
                    free(candidates);
                    return 1;
                }
                candidates = ptr;
            }

            printf("Candidate succesfully deleted !!!\n");
            break;
        }
    }
    if(!found)
    {
        printf("Candidate not found!\n");
        free(candidates);
        return 1;
    }

    printf("New list of candidates\n");
    for(int k = 0; k < count; k++)
    {
        printf("\nName: %s\n", candidates[k].name);
        printf("Experience: %d\n", candidates[k].experience);
        printf("Skill: %d\n\n", candidates[k].skill);
    }
    fclose(file);

    // write to file
    file = fopen("test.bin", "wb");
    if(file == NULL)
    {
        printf("File cannot be opened for writing!\n");
        free(candidates);
        return 1;
    }
    size_t written = fwrite(candidates, sizeof(struct Candidate), count, file);
    if(written != (size_t)count)
    {
        printf("Error writing candidates!\n");
        fclose(file);
        free(candidates);
        return 1;
    }

    free(candidates);
    fclose(file);

    return 0;
}