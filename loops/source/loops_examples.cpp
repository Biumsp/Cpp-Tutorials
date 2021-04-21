#include <iostream>

void body(int i)
{
	std::cout << "Iteration" << i << std::endl;
}

int main()
{
	std::cout << "Loop 1\n";
	for (int i = 0; i < 4; i++)
	{
		body(i);
	}
	
	// This would give an error: the variable declared in the for loop
	// definition is deleted after the loop
	// std::cout << i << std::endl;

	// ---------------------------------------------------------------------
	// ---------------------------------------------------------------------

	std::cout << "Loop 2\n";
	int j = 0;
	for (j; j < 4; j++)
		body(j);

	// This won't give an error: j was defined outside the loop declaration
	std::cout << j << std::endl;
	// And the value of j is 4: the loop changed it and the condition resulted false

	// ---------------------------------------------------------------------
	// ---------------------------------------------------------------------

	std::cout << "Loop 3\n";
	for (j; j < 8; j++)
	{
		body(j);
		int m = 0;
		
		// This logs successfully
		std::cout << m << std::endl;
	}

	// This would give an error: m was defined inside the loop
	// std::cout << m << std::endl;

	// ---------------------------------------------------------------------
	// ---------------------------------------------------------------------

	std::cout << "Loop 4\n";
	{
		int k = 0;
		bool condition = k < 4;
		for (; condition;)
		{
			body(k);
			if (k >= 4)
				condition = false;
		}
	}

	// These would give an error: k and condition were defined inside the loop-containing block
	// std::cout << k << std::endl;
	// std::cout << condition << std::endl;
	// This is good practice (equivalent to defining the index inside the loop 
	// definition) because, this way, the variable is not accessible from
	// outside the loop

	// ---------------------------------------------------------------------
	// ---------------------------------------------------------------------

	{
		int a = 2;
		std::cout << a << std::endl;
	}

	// this would give an error
	// std::cout << a << std::endl;
	// BLOCKS CREATE NEW VARIABLES' SCOPES

	// ---------------------------------------------------------------------
	// ---------------------------------------------------------------------

	std::cin.get();
}