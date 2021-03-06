/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/1574

#######################################

Exemplo de entrada:
2
3
LEFT
RIGHT
SAME AS 2
5
LEFT
SAME AS 1
SAME AS 2
SAME AS 1
SAME AS 4

######################################

Exemplo de saída:
1
- 5

*/

#include "pch.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

enum Command
{
	Left = -1,
	Right = 1
};

Command getCommand(string commandString, vector<Command> commandHistory)
{
	Command command;

	if (commandString == "LEFT")
		command = Left;
	else if (commandString == "RIGHT")
		command = Right;
	else
	{
		const int offset = 8; // start position of index
		int count = commandString.size() - offset;
		string indexStr = commandString.substr(offset, count);
		int index = stoi(indexStr);
		command = commandHistory[index - 1];
	}

	return command;
}

int main()
{
	int T, N, actualPosition;
	string commandString;
	Command command;
	vector<Command> commandHistory;

	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		cin >> N;
		cin.ignore(1);

		commandHistory.clear();
		actualPosition = 0;

		for (int n = 0; n < N; ++n)
		{
			getline(cin, commandString);
			command = getCommand(commandString, commandHistory);
			commandHistory.emplace_back(command);
			actualPosition += command;
		}

		cout << actualPosition << endl;
	}
}