#include <iostream>
#include "Array.h"
#include "Vector.h"
#include <chrono>
#include "PriorityQueue.h"

enum Stats
{
    Health,
    Attack,
    Defense,
    Stamina,
    Speed,
};

class Player
{
private:
    Stats stats;
    std::string name;
    Stats statType;

public:
    Array<int, 5> PlayerStats;

    // Default constructor
    Player() : name("Default_Player") {}

    // Parameterized constructor
    Player(std::string playerName)
    {
        name = playerName;
    }

    // Initialize player stats
    void GivePlayerStats()
    {
        PlayerStats[Health] = 100;

        std::cout << "\nPlayer " << name << " initialized with stats: \n";
        std::cout << "Health: " << PlayerStats[Health] << "\n";

        for (int i = Attack; i <= Speed; ++i)
        {
            PlayerStats[i] = rand() % 4 + 1;
            std::cout << "Stat " << i + 1 << ": " << PlayerStats[i] << "\n"; // i + 1 for 1-based stat numbers
        }

        std::cout << "\n";
    }

    // Get the value of a specific stat
    void getStatValue(Stats stat)
    {
        std::cout << "Stat value for stat " << stat + 1 << " is: " << PlayerStats[stat] << "\n";
    }

    // Get the player's name
    std::string GetName() const
    {
        return name;
    }
};

// Calculate remaining health after an attack
int PlayerStatsSetup(Player& player1, Player& player2)
{
    int AtkPwr = player1.PlayerStats[Attack] * player1.PlayerStats[Stamina];
    int DefPwr = player2.PlayerStats[Defense] * player2.PlayerStats[Speed];

    int Damage = AtkPwr - (DefPwr / player2.PlayerStats[Health]);
    int remainingHealth = player2.PlayerStats[Health] - Damage;

    return remainingHealth;
}

// Simulate a duel between two players
Player& PlayerAttack(Player& attacker, Player& defender)
{
    int P1RemainingHealth = PlayerStatsSetup(defender, attacker);
    int P2RemainingHealth = PlayerStatsSetup(attacker, defender);

    if (P1RemainingHealth > P2RemainingHealth)
    {
        return defender;
    }
    else if (P1RemainingHealth == P2RemainingHealth)
    {
        int randNum = rand() % 2;

        if (randNum == 1)
        {
            std::cout << "50/50 chose defender\n";
            return defender;
        }
        else
        {
            std::cout << "50/50 chose attacker\n";
            return attacker;
        }
    }
    else
    {
        std::cout << attacker.GetName() << " wins the duel against " << defender.GetName() << "\n";
        return attacker;
    }
}

int main()
{
    int VectorSize = 10;
    int VecReomeve = 6;
    int PlyrToAdd = 5;

    Vector<Player> Vec;

    // Adding players
    for (int i = 0; i < VectorSize; i++)
    {
        std::cout << "Give a name to player " << i + 1 << ": ";
        std::string playerName;
        std::cin >> playerName;
        Vec.PushBack(Player(playerName));

        Vec[i].GivePlayerStats();
    }

    //Removing last 5 players
    for (int i = VectorSize; i >= VecReomeve; --i)
    {
        Vec.PopBack();
    }

    //Adding 5 new players
    for (int i = 0; i < PlyrToAdd; i++)
    {
        Vec.PushBack(Player("NewPlayer"));
        Vec[Vec.Size() - 1].GivePlayerStats();
    }

    //// Duel between two random players
    int FightingPlayer = rand() % Vec.Size();
    int FightingPlayer2 = rand() % Vec.Size();

    PlayerAttack(Vec[FightingPlayer], Vec[FightingPlayer2]);
}