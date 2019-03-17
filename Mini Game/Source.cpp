#include <iostream>
#include <cmath>
using namespace std;
class Position
{
private:
	int m_x;
	int m_y;
public:
	Position(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	bool Is_in_Range(Position other, float range)
	{
		const int deltaX = other.m_x - m_x;
		const int deltaY = other.m_y - m_y;
		const int distance = pow(deltaX, 2) + pow(deltaY, 2);

		bool isin_range = distance <= pow(range, 2);

		return isin_range;
	}

};
class Hero
{
private:
	Position cordinat_Hero;

public:
	Position getCordinat()
	{
		return cordinat_Hero;
	}
	Hero()
		: cordinat_Hero(0, 0)
	{

	}
};
class Enemy
{
private:
	Position cordinat_Enemy;
	float enemy_attacRange;
public :
	Enemy()
		: cordinat_Enemy(10, 0),
		enemy_attacRange(50)
	{

	}

	void attacEnemy(Hero &hero)
	{
		cout << "Enemy attac" << endl;

		const Position heroCordinat = hero.getCordinat();
		const bool Range = cordinat_Enemy.Is_in_Range(heroCordinat, enemy_attacRange);

		if (Range)
		{
			cout << "Game Over, Hero id dead" << endl;
		}
		else
		{
			cout << "Hero is alive" << endl;
		}
	}

	

};
int main()
{
	cout << "Game is starting" << endl;
	Hero hero;
	Enemy enemy;
	enemy.attacEnemy(hero);
	system("pause");
	return 0;
	
}