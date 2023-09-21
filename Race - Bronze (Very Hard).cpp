// Question: http://www.usaco.org/index.php?page=viewproblem2&cpid=989
// 440x effeciency on the official solution! (Benchmark: https://ide.usaco.guide/NeLQ4UtbHGwkCtIekEN)

#include <bits/stdc++.h>
using namespace std;

/*
long MaxToDistance(int MaxSpeed)
{
	bool e = (MaxSpeed-1) % 2;
	return ceil((1 + e/2)*MaxSpeed + MaxSpeed*((MaxSpeed-e-1)/2));
}

int DistanceToMax(long Distance)
{
	return ceil(sqrt(Distance*2+0.25)-0.5);
}
*/

int FindSolution(int MaxSpeed, long RaceLength)
{

	bool e = (MaxSpeed-1) % 2;
	long InitialDistance = (1 + e/2)*MaxSpeed + MaxSpeed*((MaxSpeed-e-1)/2);

	if (InitialDistance >= RaceLength)
	{
		return ceil(sqrt(2*RaceLength+0.25)-0.5);
	}

	int time = MaxSpeed+1;
	int RequiredSlowPeriod = time;

	for (int CurrentSpeed = time;; CurrentSpeed++) {

		InitialDistance += CurrentSpeed;
		time++;
		if (InitialDistance + RequiredSlowPeriod >= RaceLength) { return time; }

		RequiredSlowPeriod += CurrentSpeed;
		time++;
		if (InitialDistance + RequiredSlowPeriod >= RaceLength) { return time; }

	}

}



int main()
{
	long long RaceLength, MaxSpeedAmount;
	cin >> RaceLength >> MaxSpeedAmount;

	for (int Index = 1; Index <= MaxSpeedAmount; Index++)
	{

		int MaxSpeed;
		cin >> MaxSpeed;
		cout << FindSolution(MaxSpeed,RaceLength) << "\n";

	}

	return 0;
}
