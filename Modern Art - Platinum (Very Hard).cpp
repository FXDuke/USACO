// Question: http://www.usaco.org/index.php?page=viewproblem2&cpid=744

#include <bits/stdc++.h>
using namespace std;


int GetLayer(int Start, int StartLayer, map<int,map<int,int>> Interrupt, map<int,bool> Checked = {})
{
	int Output = StartLayer;

	for (auto InterruptPoint : Interrupt[Start])
	{
		if (InterruptPoint.first > 0 && (int)Interrupt[InterruptPoint.first].size() != 0 && Checked[InterruptPoint.first] == 0)
		{
			Checked[InterruptPoint.first] = 1;
			Output = max(GetLayer(InterruptPoint.first, Output+1, Interrupt, Checked),Output);
		}
	}

	return Output;
}

int main() {

	int CanvasSize;
	cin >> CanvasSize;

	int Possible_Colors = CanvasSize*CanvasSize;
	int Possible_Start_Colors = Possible_Colors;

	// Variables for creating the map array
	int Map[CanvasSize][CanvasSize] = {{0}};
	map<int,int> Colors_Used; 

	// Variables for finding interrupted rectangles
	map<int,map<int,int>> Interrupted;
	map<int,int> YSuspended;
	map<int,int> Length;

	// Variables for sorting through the interrupted rectangles
	map<int,int> LayeredColors;
	map<int,bool> SortedColors; 

	for (int Y = 0; Y < CanvasSize; Y++)
	{
		for (int X = 0; X < CanvasSize; X++)
		{

			int Color;
			cin >> Color;

			if (Colors_Used[Color]==0 && Color != 0)
			{
				// If a color is on the board, it is removed from the
				// total possible start colors.
				// (because it could be covering a smaller square)
				Possible_Start_Colors -= 1;
				Colors_Used[Color] = 1;
				Interrupted[Color];
			}
			
			Map[Y][X]= Color;

		}
	}

	for (int Y = 0; Y < CanvasSize; Y++)
	{

		// X Suspended detects when a line is interrupted
		// by another color before it reaches its length
		// i.e; 1 1 1 1, legnth 1 = 4 --> 1 1 2 1, length 1 = 3, interruption detected

		// Y Suspended does the same as X Suspended but for the Y Axis

		// temp length stores the x value of a color when it starts
		// 0 0 1 1 0, templength[1] = 2, x(4) - templength[1] = 2, length[1] = 2;

		map<int,int> XSuspended;
		map<int,int> TempLength;
		int Last = Map[Y][0];

		for (int X = 0; X < CanvasSize; X++)
		{
			int LastY = Map[Y-1][X];
			int Color = Map[Y][X];


			if (Color != 0)
			{

				if (LastY != Color)
				{
					if (YSuspended[Color] == 1 && Interrupted[Color][LastY] == 0)
					{
						Interrupted[Color][LastY] = 1;
					}
					else 
					{
						YSuspended[Color] = 1;
					}
				}

				if (Last != Color)
				{
					if (XSuspended[Color] == 1 && Interrupted[Color][Last] == 0)
					{
						Interrupted[Color][Last] = 1;
					} else if (X < Length[Last] && Interrupted[Last][Color] == 0)
					{
						Interrupted[Last][Color] = 1;
					} 
					TempLength[Color] = X;
					XSuspended[Last] = 1;
				} 

				Last = Color;
				Length[Color] = max(Length[Color], X-TempLength[Color]+1);

			}

		}
	}

	for (auto Possible_Start : Interrupted)
	{
		LayeredColors[Possible_Start.first] = GetLayer(Possible_Start.first,0,Interrupted);
		if ((int)Possible_Start.second.size() == 0)
		{
			SortedColors[Possible_Start.first] = true;
		}
		for (auto ColorsToSort : Possible_Start.second)
		{
			if ((int)Interrupted[ColorsToSort.first].size() == 0 )
			{
				SortedColors[ColorsToSort.first] = false;
			}
			if (ColorsToSort.first != 0 && LayeredColors[ColorsToSort.first] < LayeredColors[Possible_Start.first])
			{
				SortedColors[Possible_Start.first] = true;
				SortedColors[ColorsToSort.first] = false;
			}
		}
	}

	for (auto SortedColor : SortedColors)
	{
		Possible_Start_Colors+=SortedColor.second;
	}

	cout << Possible_Start_Colors;

	return 0;
}
