#include <stdio.h>

/*print Fahrenheit-Celsisu table
	for fahr = 0, 20, ..., 300 */

main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;				// lower limit of temperature table
	upper = 300;			// upper limit
	step = 20;				//  step size 

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		//printf("%3d  %6d\n", fahr, celsius);
		//printf("%3d  %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	/*
	// for loop notation for while loop
	for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%3d  %6.1f\n", fahr, celsius);
	}
	*/

}
