// Question: http://www.usaco.org/index.php?page=viewproblem2&cpid=1088

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	
	int GridSize;
	// GridSize can be as big as needed, however 500+ starts taking multiple seconds
	  
	cin >> GridSize;

	if (GridSize % 2 == 1) 
	{ 
		cout << "Please make the grid size an even number."; 
		return 1; 
	}


	vector<map<int,int>> Map(GridSize); 
	// Vector[Index = Y Position] = Map[0 = X Positon, 1 = Beauty]


	for (int Y = 0; Y < GridSize; Y++) 
	{
		map<int,int> YMap;
		for (int X = 0; X < GridSize; X++) 
		{
			cin >> YMap[X];
		}
		Map[Y] = YMap;
	}

	int Total_Beauty = 0;
	for (int Y = 0; Y < GridSize; Y+=2) 
	{
		for (int X = 0; X < GridSize; X+=2)
		{
			map<int,int> Top = Map[Y];
			map<int,int> Bottom = Map[Y+1];
			Total_Beauty += max(Top[X]+Top[X+1],Bottom[X]+Bottom[X+1]);
		}
	}

	cout << "Maximum Beauty: " << Total_Beauty;


	return 0;
}


	

