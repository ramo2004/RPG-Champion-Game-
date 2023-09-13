#ifndef CHAMPION_H //preprocessor directive
#define CHAMPION_H
enum ChampionRole { //enumeration for champ roles
	MAGE,
	FIGHTER,
	SUPPORT,
	TANK,
};
//struct for champion
typedef struct Champion {
	enum ChampionRole role;
	int level;
	struct Champion* next;
} Champion;
//function prototypes
Champion* createChampion();

Champion* addChampion(Champion *head, Champion *c);

Champion* buildChampionList(int n);

void printChampionList(Champion *head);

Champion* removeChampion(Champion *head);

Champion* destroyChampionList(Champion *head);

#endif
//end of preprocessor directive
