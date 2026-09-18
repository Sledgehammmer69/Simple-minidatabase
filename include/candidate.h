#ifndef CANDIDATE_H
#define CANDIDATE_H

struct Candidate
{
    char name[20];
    int experience;
    int skill;
};

int read(void);
int search_candidate(void);
int add_candidate(void);

#endif