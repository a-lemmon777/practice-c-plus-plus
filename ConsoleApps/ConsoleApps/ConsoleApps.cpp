// Calorie Counter Program
#include <iostream>

int main()
{
	int carb_grams = 10;
	int fat_grams = 20;
	int protein_grams = 15;

	int total_calories = carb_grams * 4 + fat_grams * 9 + protein_grams * 4;
	std::cout << "Yay, I'm learning C++!" << std::endl;
	std::cout << "There are " << total_calories << " total calories." << std::endl;
	return 0;
}