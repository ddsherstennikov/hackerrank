#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Player
{
	string name;
	int score;
};

template<typename T>
class Comparator
{
public:
	static int compare(T o1, T o2);
};

class Checker : public Comparator<int>
{
public:
	static int compare(Player a, Player b)
	{
		if (a.score > b.score)
			return 1;
		else if (a.score < b.score)
			return 0;
		else if (a.name < b.name)
			return 1;
		else
			return 0;
	}
};

vector<Player> comparator(vector<Player> players)
{
	std::sort(players.begin(), players.end(), Checker::compare);
	return players;
}


int main()
{

	int n;
	cin >> n;
	vector<Player> players;
	string name;
	int score;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> score;
		Player p1;
		p1.name = name, p1.score = score;
		players.push_back(p1);
	}

	vector<Player> answer = comparator(players);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i].name << " " << answer[i].score << endl;
	}
	return 0;
}
