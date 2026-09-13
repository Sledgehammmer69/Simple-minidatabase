#include <stdio.h>
#include <string.h>

// TESTING PURPOSES.
struct Candidate
{
    char name[20];
    int experience;
    int skill;
};

int main()
{
    FILE* file = fopen("test.bin", "wb");
    if(file == NULL)
    {
        printf("File doesnt exist\n");
        return 1;
    }
    if(fseek(file, 0, SEEK_END) != 0)
    {
        printf("File cannot be seeked\n");
        fclose(file);
        return 1;
    }
    long file_size = ftell(file);
    int cand_size = sizeof(struct Candidate);
    int no_of_candidates = file_size/cand_size;
    printf("File size: %ld\n", file_size);
    printf("Candidate size: %d\n", cand_size);
    printf("Number of Candidates: %d\n\n", no_of_candidates);
    rewind(file);

    struct Candidate candidate;
    char new_name[20];
    int new_experience;
    int new_skill;

    printf("Enter candidate name: ");
    scanf("%19s", new_name);
    printf("Enter candidate experience: ");
    scanf("%d", &new_experience);
    printf("Enter candidate skill: ");
    scanf("%d", &new_skill);

    strcpy(candidate.name, new_name);
    candidate.experience = new_experience;
    candidate.skill = new_skill;
    printf("\n\nName: %s\n", candidate.name);
    printf("Experience: %d\n", candidate.experience);
    printf("Skill: %d\n\n", candidate.skill);

    if(fwrite(&candidate, cand_size, 1, file) != 1)
    {
        printf("Candidate cannot be added into file\n");
        fclose(file);
        return 1;
    }
    else
    {
        printf("New Candidate successfully added\n");
    }


    fclose(file);
    return 0;
}

