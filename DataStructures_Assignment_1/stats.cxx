// Matthew Munoz
// mmunoz005@citymail.cuny.edu

// Preprocessor Directives
#include <cassert>
#include "stats.h"


namespace main_savitch_2C
{
	statistician::statistician()
	{
		count = 0;
		total = 0;
	}

	void statistician::next(double n)
	{
		//SUM
		total += n;

		// Define Tinyest and Largest
		if (count == 0)
		{
			tinyest = n;
			largest = n;
		}
		else if (n < tinyest)
		{
			tinyest = n;
		}
		else if (n > largest)
		{
			largest = n;
		}
		
		// Increment the count and therefore increment the length of the sequence
		count++;
	}

	// Friend function used to add two objects
	statistician operator +(const statistician& s1, const statistician& s2)
	{
		// Tmporary staticticain object for the addition operator
		statistician TempAdd;

		// Adding the total lenght of the two objects to set it to TampAdd
		TempAdd.count = s1.count + s2.count;

		// Identify the tinyest and largest values of the s1 and s2 objects to set them to TempAdd object
		if (s2.count == 0)
		{
			TempAdd.largest = s1.largest;
			TempAdd.tinyest = s1.tinyest;
		}
		else if (s1.count == 0)
		{
			TempAdd.largest = s2.largest;
			TempAdd.tinyest = s2.tinyest;
		}
		else
		{
			if (s1.largest > s2.largest)
			{
				TempAdd.largest = s1.largest;
			}
			else
			{
				TempAdd.largest = s2.largest;
			}

			if (s1.tinyest < s2.tinyest)
			{
				TempAdd.tinyest = s1.tinyest;
			}
			else
			{
				TempAdd.tinyest = s2.tinyest;
			}
		}

		// Adding the total of the s1 and s2 object to set it in the TempAdd object
		TempAdd.total = s1.total + s2.total;

		// return the TempAdd object along with the addition of the s1 and s2 values
		return TempAdd;
	}

	// Friend function to multiply the values in an object
	statistician operator *(double scale, const statistician& s2)
	{
		// Setting a tmporaty object to be used localy
		statistician TempMult;

		// Set the count value as the same since th equnatity isn't changing
		TempMult.count = s2.count;

		// Multiply the toal of the given object by the scaler value
		TempMult.total = s2.total * scale;
		
		// Multiply the tinyest and largest values in the object and set the appropriately
		if (scale < 0)
		{
			TempMult.largest = s2.tinyest * scale;
			TempMult.tinyest = s2.largest * scale;
		}
		else
		{
			TempMult.tinyest = s2.tinyest * scale;
			TempMult.largest = s2.largest * scale;
		}

		// Return the new multiplied object
		return TempMult;
	}

	// Outside member functun used to check if two objct hold the same values
	bool operator ==(const statistician& s1, const statistician& s2)
	{
		// Check if the two object have the same number of values
		if (s1.length() != s2.length())
		{
			return false;
		}

		// Check if the total of the two object are equal
		if (s1.sum() != s2.sum())
		{
			return false;
		}

		// Check if the largest and tinyest values of the two object are the same
		if (s1.length() > 0 && s2.length() > 0)
		{
			if (s1.mean() != s2.mean())
			{
				return false;
			}

			if (s1.minimum() != s2.minimum())
			{
				return false;
			}

			if (s1.maximum() != s2.maximum())
			{
				return false;
			}
		}

		// return true if all of the variables are equal
		return true;
	}
}