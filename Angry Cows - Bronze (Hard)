// Question: http://www.usaco.org/index.php?page=viewproblem2&cpid=592

#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
using vint = vector<int>::iterator;

vint Begin, End;
int Explosion(vint Position,  int Range, int Direction)
{

	int Explosions = 0;
	vint Next = next(Position,1);
	vint Last = next(Position,-1);

	if (*Position+Range >= *Next && Next < End && Direction >= 0)
	{
		Explosions += 1 + Explosion(Next, Range + 1, 1);
	}

	if (*Position-Range <= *Last && Last >= Begin && Direction <= 0) 
	{
		Explosions += 1 + Explosion(Last, Range + 1, -1);
	}

	return Explosions;
}

int main() 
{
	int NumberOfHay;
	cin >> NumberOfHay;

	vector<int> HayPositions(NumberOfHay);
	Begin = HayPositions.begin();
	End = HayPositions.end();

	for (int Position = 0; Position < NumberOfHay; Position++) 
	{
		cin >> HayPositions[Position];
	}

	sort(Begin, End);

	int Max_Explosions = 0;
	int ResultPosition = 0;
	for (vint Position = Begin; Position != End; ++Position)
	{
		int Explosions = Explosion(Position,1,0);
		if (Explosions > Max_Explosions) {
			ResultPosition = *Position;
			Max_Explosions = Explosions;
			if (Max_Explosions == NumberOfHay-1) { break; }
		}
	} 

	cout << ResultPosition << " with " << Max_Explosions << " explosions";

	return 0;
}
