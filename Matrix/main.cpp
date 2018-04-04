#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	/*{
		Matrix M(3, 3);
		Matrix M2(3, 3);
		M.fill();
		M2.fill();
		cout << '\n';

		M.multiplyBy(M2);
		M.print();
	}*/

	{
		Matrix M(2, 2);
		M.fill();

		M.pow(3);
		cout << "\n";
		M.print();
	}

	system("pause");
	return 0;
}
/*
0 9 1
1 3 7
2 7 0

0 9 8 
0 9 9
1 9 6

-----
1 90 87 
7 99 77
0 81 79

-----------
1 2 
3 4

-----
37 54
81 118
*/