// Question: http://www.usaco.org/index.php?page=viewproblem2&cpid=832

#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	int NumberOfCows, CowsInHierarchy, CowsWithPositions;

	cin >> NumberOfCows >> CowsInHierarchy >> CowsWithPositions;

	int CowsInOrder[NumberOfCows] = {0};
	vector<int> CowHierarchy(CowsInHierarchy);

	for (int Index = 0; Index < CowsInHierarchy; Index++) 
	{
		cin >> CowHierarchy[Index];
	}

	for (int Index = 0; Index < CowsWithPositions; Index++) 
	{
		int Cow, Position;
		cin >> Cow >> Position;

		for (vector<int>::iterator Hierarchy = CowHierarchy.begin(); Hierarchy != CowHierarchy.end(); ++Hierarchy) 
		{
			if (Cow == *Hierarchy)
			{
				CowHierarchy.erase(Hierarchy);
				CowsInHierarchy--;
			}
		}

		CowsInOrder[Position-1] = Cow;
	}


	int HierarchyIndex = 0;
	int Result = 0;

	for (int Position = 0; Position < NumberOfCows; Position++)
	{
		if (CowsInOrder[Position] == 0)
		{
			if (HierarchyIndex < CowsInHierarchy) 
			{
				CowsInOrder[Position] = CowHierarchy[HierarchyIndex];
				HierarchyIndex++;
			} else {
				Result = Position;
				break;
			}
		} 
	}

	cout << "Earliest milk order position is: {FromBase0Index= " << Result << ", FromBase1Index= " << Result+1 << "}";

	return 0;

}
