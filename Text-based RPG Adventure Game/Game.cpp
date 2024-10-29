#include "Game.h"
#include "Character.h"
#include <iostream>
using namespace std;

class Enemy;

int Game::getCurrentLevel() {
    return currentLevel;
}

void Game::GameIntro() {
	cout << "======================================================================================\n\n"
		<< "In a distant realm, a once-glorious kingdom thrived, known for its vibrant culture and the powerful magic that flowed through its lands."
		<< " However, darkness fell upon the kingdom when the malevolent sorcerer MURLOCS sought to claim the source of its magic for himself."
		<< " With his army of twisted creatures, he plunged the kingdom into chaos, forcing its inhabitants into hiding.\n\n"
		<< "As the last remaining descendant of the ancient guardians, you awaken from a long slumber to find your homeland in ruins."
		<< " The whispers of the lost souls echo in your ears, urging you to rise and reclaim the light."
		<< " But the path ahead is fraught with peril, as MURLOCS' minions roam the land, guarding the artifacts of power that you must retrieve.\n\n"
		<< "To restore peace and harmony, you must embark on a quest to confront MURLOCS."
		<< " Along your journey, you will face formidable foes, harness ancient abilities, and gather powerful allies."
		<< " Only by mastering your skills and proving your worth can you challenge the dark sorcerer and bring back the forgotten glory of your kingdom.\n\n"
		<< "Your adventure begins now. Are you ready to face the shadows and become the hero the kingdom needs?\n\n"
		<< "=======================================================================================\n\n";


    cout << "\nTo defeat MURLOCS, you will need to improve on your skills and survive 5 waves of enemies, each stronger than the previous one.\n"
        << "ALL THE BEST. \n\n=============================================================================\n\n";
}
string Game::GetPlayerName() {
    string playerName;
    cout << "\n\nHi.\n\nThe People are happy to see you. What is your name\n\n";
    cin >> playerName;
    return playerName;
}

void Game::LevelSpeech(string pName) {
	switch (currentLevel) {
	case level0:
		cout << "\n" << pName << " steps into the shadowed realm of Murlocs...\n";
		cout << "\nVillagers: Thank you for coming to our aid, " << pName << ". We believe in you. \n\n"
			<< "With every wave you conquer, you will gain a new weapon or skill to empower yourself. "
			<< "Keep an eye on both your and your enemies' stats; we will keep track of them for you after every turn. \n\n"
			<< "Prepare yourself! THE FIRST WAVE APPROACHES ......\n\n"
			<< "As per our reports, there is only ONE ENEMY in this wave.\n\n";
		break;
	case level1:
		cout << "\n========================================================================================\n\n";
		cout << "\n" << pName << " has triumphed in the First Wave ...\n";
		cout << "\n" << pName << ": That was easy! Come on, MURLOCS, show me what you've got! :) \n\n";
		cout << "Villagers: We have discovered a Map that will reveal some secrets about MURLOCS' domain. "
			<< "Use it wisely! It appears that MURLOCS is aware of your presence and is sending the SECOND WAVE with 2 enemies now!! ... \n\n";
		cout << pName << ": LET'S DO THIS!! \n\n\n"
			<< "===========================================================================================\n\n";
		break;
	case level2:
		cout << "\n========================================================================================\n\n";
		cout << "\n" << pName << " continues to shine with remarkable skill ....\n";
		cout << "\n" << pName << ": That took some effort, but I can handle this! Time to unleash more power!! \n";
		cout << "\nCongratulations!! You have unlocked the sword & special Ability: Critical Hit!\n";
		cout << "\nUnlocked: \n\n - Successful Critical Hit Probability: 10%\n\n";
		cout << "\nPrepare yourself! 3 enemies await you in the next wave... \n\n\n"
			<< "========================================================================================\n\n";
		break;
	case level3:
		cout << "\n========================================================================================\n\n";
		cout << "\n" << pName << " claims victory once AGAIN ....\n";
		cout << "\n" << pName << ": The challenge is rising, but I will not back down! Time to defend myself!\n";
		cout << "\nCongratulations!! You have unlocked the Shield and the special Ability: One Turn Blocker!\n";
		cout << "\nUnlocked: \n\n - Successful Blocking of Enemy Hit Probability: 10%\n\n";
		cout << "\nThe 4th wave has arrived! 4 enemies have come to challenge you... \n\n\n"
			<< "========================================================================================\n\n";
		break;
	case level4:
		cout << "\n========================================================================================\n\n";
		cout << "\n" << pName << " stands firm amidst the chaos!! ....\n";
		cout << "\n" << pName << ": My strength may be waning, but I will fight to the end!\n";
		cout << "\nCongratulations!! You have unlocked the Armour and special Ability: Life Steal!\n";
		cout << "\nUnlocked: \n\n - Successful Life Steal after dealing damage Probability: 10%\n\n";
		cout << "\nIt seems that MURLOCS is sending his strongest minions. 5 of his soldiers have emerged ... \n\n\n"
			<< "========================================================================================\n\n";
		break;
	case level5:
		cout << "\n========================================================================================\n\n";
		cout << "\n" << pName << " fights with unwavering spirit!! ..... \n";
		cout << "\n" << pName << ": I need to defeat these foes before I confront MURLOCS!\n";
		cout << "\nVillagers: Be cautious! MURLOCS is no ordinary foe! He has the ability to regenerate health!\n";
		cout << "\nCongratulations!! You have unlocked the Bow and are now fully equipped to take down MURLOCS!! \n";
		cout << "\nUnlocked: \n\n - No Special Abilities (MURLOCS has nullified them!)\n - MURLOCS' Health Regeneration Probability: 25%\n\n";
		cout << "\nMURLOCS approaches, furious that you have defeated his army. GIVE IT YOUR ALL!! .... \n\n\n"
			<< "========================================================================================\n\n";
		break;
	case level6:
		cout << "\n========================================================================================\n\n";
		cout << "\n" << pName << " delivers a final, victorious blow to MURLOCS!! .... IT'S FINALLY OVER!!! \n";
		cout << "\n" << pName << ": I did it! I am the hero this kingdom needs!! \n\n\n"
			<< "========================================================================================\n\n";
		break;
	default:
		break;
	}
	currentLevel += 1;
}

void Game::DisplayHealthStats(Character* player, Character* enemies) {

	cout << "Health Stats : \n\n";
	cout << player->getName() << "'s Health : " << player->getHealth() << "\n\n";

	for (int i = 0; i < currentLevel; i++) {

		if (enemies[i].getHealth() > 0) {
			cout << enemies[i].getName() << "'s Health : " << enemies[i].getHealth() << "\n";
		}

	}

}

bool Game::PlayLevel(Character* player) {

    int level = this->getCurrentLevel();

	player->setHealth(75 + level * 25);
	player->setHealingPower(25 + level * 5);
	player->setMeleeDamage(20 + level * 5);
	player->setRangedDamage(10 + level * 5);

	cout << "=======================================================================================\n\n Level " << level << "\n\n";
	Character* enemies = new Enemy[level];

	for (int index = 0; index < level; index++) {

		enemies[index] = Enemy(70 + currentLevel * 5, 5 + currentLevel * 5, currentLevel * 5, 5 + currentLevel * 5);
		string enemyName = "Enemy " + to_string(index + 1);
		enemies[index].setName(enemyName);

		if (level == level6) {
			enemies[0].setName("MURLOCS");
			enemies[0].setHealingPower(60);
			enemies[0].setMeleeDamage(65);
			enemies[0].setRangedDamage(45);
			enemies[0].setHealth(300);
		}
		enemies[index].GetCharacterDetails();
	}

	DisplayHealthStats(player, enemies);
	int totalEnemyHealth = enemies[0].getHealth() * level;

	while (player->getHealth() > 0 && totalEnemyHealth > 0) {

		char playerInput;
		cout << "\n=======================================================================================\n\n";
		cout << player->getName() << ", Your Turn ..... Attack (A/a) or Heal (H/h) : ";
		cin >> playerInput;
		cout << "\n=======================================================================================\n\n";

		if (playerInput == 'A' || playerInput == 'a') {
			cout << "\n" << player->getName() << " has decided to Attack. \nCheck the Enemy details. Which Enemy do you want to attack ? .... \n\n";
			cout << "Enemies not dead yet and their health is: \n";

			for (int i = 0; i < level; i++) {

				if (enemies[i].getHealth() > 0) {
					cout << enemies[i].getName() << " : " << enemies[i].getHealth() << "\n";
				}
			}

			int enemyIndex;
			cout << "\nEnter Enemy No. to Attack : ";
			cin >> enemyIndex;

			if (enemyIndex > 0 && enemyIndex <= level && enemies[enemyIndex - 1].getHealth() > 0) {

				int attackDamage = player->Attack(level);
				int enemyHealth = enemies[enemyIndex - 1].getHealth();
				enemies[enemyIndex - 1].setHealth(max(0, enemyHealth - attackDamage));
				cout << "\n" << enemies[enemyIndex - 1].getName() << "'s updated Health : " << enemies[enemyIndex - 1].getHealth() << "\n";
				bool isEnemyDead = enemies[enemyIndex - 1].getHealth() == 0;

				if (isEnemyDead) {
					cout << "Good Attack. " << enemies[enemyIndex - 1].getName() << " has died. Keep it up. \n";
				}
				totalEnemyHealth -= min(attackDamage, enemyHealth);
			}
			else {
				cout << "\nYour mistake costs you!. You lost your chance\n\n";
			}
		}
		else if (playerInput == 'H' || playerInput == 'h') {
			cout << "\n" << player->getName() << " has decided to Heal. Cleaning wounds and applying bandages .... \n\n";
			player->Heal(level);
		}
		else {
			cout << "\nYou pressed wrong key!. You lose your chance. \n\n";
		}

		if (totalEnemyHealth > 0) {
			cout << "\n=======================================================================================\n\n";
			for (int j = 0; j < level; j++) {
				enum EnemyChoice {
					EnemyAttack, EnemyHeal
				};
				if (enemies[j].getHealth() > 0) {

					int enemyChoice = rand() % 2;

					if (enemyChoice == EnemyAttack) {

						int attackDamage = enemies[j].Attack(level);
						int heroHealth = player->getHealth();
						player->setHealth(max(0, heroHealth - attackDamage));
						cout << "\n" << player->getName() << "'s Updated Health : " << player->getHealth() << "\n\n";

					}
					else {

						int previousHealth = enemies[j].getHealth();
						enemies[j].Heal(level);
						int currentHealth = enemies[j].getHealth();
						totalEnemyHealth += (currentHealth - previousHealth);

					}
				}
			}
		}
		DisplayHealthStats(player, enemies);
	}
	delete[] enemies;
	return player->getHealth() > 0;
}

void Game::PlayGame() {

	string playerName = GetPlayerName();

	Character* player = new Player(100, 25, 15, 30, playerName);

	player->GetCharacterDetails();
	LevelSpeech(player->getName());

	while (PlayLevel(player)) {

		cout << "\nWohoo, You win this level " << getCurrentLevel() << "\n\n";
		LevelSpeech(player->getName());
		if (getCurrentLevel() == level7)
			break;

	}
	if (player->getHealth() > 0) {

		cout << "\n" << player->getName() << ", You Win. The villagers thank you for defeating MURDOCS.\n";
	}
	else {

		cout << "\nYou Lost. It was a great battle. " << player->getName() << ", you will be remembered. \n";
	}
	delete player;
}