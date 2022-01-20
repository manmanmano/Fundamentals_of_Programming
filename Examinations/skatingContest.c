#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct skater {
    const char* pName;
    double points;
} SKATER;

typedef struct judge {
    const char* pName;
    SKATER Skaters[10];
} JUDGE;

typedef struct thebest_skater {
    const char* theskater;
    double score;
} BEST;

SKATER* Exam(JUDGE* pJudges, int nJudges);

int main()
{
    JUDGE Competition[] =
    {
        {"John Smith", {{"Mary Cook", 5.9}, {"Nancy Gardener", 5.7}, {"Lindsay Weaver", 5.2}, {"Jane Clerk", 5.4}, {"Joan Singer", 5.3}}},
        {"Richard Farmhand", {{"Nancy Gardener", 5.9}, {"Mary Cook", 5.2}, {"Joan Singer", 5.3}, {"Lindsay Weaver", 4.9}, {"Jane Clerk", 5.1}}},
        {"Elizabeth Sailor", {{"Jane Clerk", 4.8}, {"Joan Singer", 5.3}, {"Nancy Gardener", 5.1}, {"Lindsay Weaver", 5.0}, {"Mary Cook", 5.7}}},
        {"Agatha Lawyer", {{"Joan Singer", 5.5}, {"Mary Cook", 5.5}, {"Nancy Gardener", 5.4}, {"Lindsay Weaver", 5.3}, {"Jane Clerk", 4.7}}},
        {"Clara Baker", {{"Lindsay Weaver", 5.5}, {"Jane Clerk", 5.6}, {"Mary Cook", 5.3}, {"Joan Singer", 5.3}, {"Nancy Gardener", 5.6}}}
    };
    SKATER* skate = Exam(Competition, 5);
    printf("The best skater is: %s\n\nFinal score: %lg\n", skate->pName, skate->points);
    return 0;
}

SKATER* Exam(JUDGE* pJudges, int nJudges)
{
    if (!pJudges || !nJudges)
    {
        return 0;
    }
    char** ppSkater = (char**)malloc(nJudges * sizeof(char*));
    for (int i = 0; i < nJudges; i++)
    {
        *(ppSkater + i) = (char*)malloc(strlen(pJudges->Skaters[i].pName) + 1);
        strcpy(*(ppSkater + i), pJudges->Skaters[i].pName);
    }
    double* totScores = (double*)calloc(nJudges, sizeof(double));
    BEST* pro = (BEST*)malloc(sizeof(BEST));
    pro->score = 0;
    for (int i = 0; i < nJudges; i++)
    {
        for (int j = 0; j < nJudges; j++)
        {
            for (int k = 0; k < nJudges; k++)
            {
                if (!strcmp((pJudges + i)->Skaters[j].pName, *(ppSkater + k)))
                {
                    *(totScores + k) += (pJudges + i)->Skaters[j].points;
                    if (*(totScores + k) > pro->score)
                    {
                        pro->score = *(totScores + k);
                        pro->theskater = (pJudges + i)->Skaters[j].pName;
                    }
                }
            }
        }
    }
    SKATER* skate = (SKATER*)malloc(sizeof(SKATER));
    skate->pName = pro->theskater;
    skate->points = pro->score;
    memset(totScores, 0, nJudges * sizeof(double));
    double max = 0, min = 6;
    for (int i = 0; i < nJudges; i++)
    {
        for (int j = 0; j < nJudges; j++)
        {
            if (!strcmp(skate->pName, (pJudges + i)->Skaters[j].pName))
            {
                *(totScores + i) = (pJudges + i)->Skaters[j].points;

            }
        }
    }
    for (int i = 0; i < nJudges; i++)//remove the highest and lowest scores
    {
        if (*(totScores + i) > max)
        {
            max = *(totScores + i);
        }
        if (*(totScores + i) < min)
        {
            min = *(totScores + i);
        }
    }
    skate->points -= max + min;
    return skate;
} 
