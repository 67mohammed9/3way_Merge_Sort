//Algorithms Assignment 1 
//Mohammed Bhuiyan
//Date: 02/17/19
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*Mergesort with Three recursive calls*/
void mergesort3(int * a, int * aux, int length){
	if (length < 2)//Base case for 1 element. Already sorted so return
		return;
	else if (length == 2)//Base case for 2 elements.Swap elements if not sorted. Then return both elements. 
	{
		if (a[1] < a[0]) {
			int temp = a[1];
			a[1] = a[0];
			a[0] = temp;
		}
		return;
	}
	else {
		int lengthFirst = length / 3;//Length of first subpart of a[]
		int lengthSecond = length / 3;//Length of middle subpart of a[]
		int lengthThird = length - 2 * (length / 3);//Length of the last subpart of a[]
		mergesort3(a, aux, lengthFirst);//Recursion through first subpart
		mergesort3(a + lengthFirst, aux, lengthSecond);//Recursion Through middle subpart
		mergesort3(a + lengthFirst + lengthSecond, aux, lengthThird);//recursion through last subpart
		int i = 0; int j = lengthSecond; int k = lengthFirst + lengthSecond; int l = 0;
		while (l < length)//loop until auxillary array is filled
		{
			//If an element is smallest in the first n/3 length of a[], add to auxillarry array
			if ((a[i] <= a[j] && a[i] <= a[k] && j < lengthFirst + lengthSecond && k < length && i < lengthFirst)//all indexes are good
				|| (j >= lengthFirst + lengthSecond && a[i] <= a[k] && k < length && i < lengthFirst)//j index is finished
				|| (k >= length && a[i] <= a[j] && j < lengthFirst + lengthSecond && i < lengthFirst)//k index is finished
				|| j >= lengthFirst + lengthSecond && k >= length)//j & k are finished
			{
				aux[l++] = a[i++];
			}
			//If an element is smallest in the middle n/3 length of a[], add to auxillarry array
			else if ((a[j] <= a[i] && a[j] <= a[k] && i < lengthFirst && k < length && j < lengthFirst + lengthSecond)//all indexes are good
				|| (i >= lengthFirst && a[j] <= a[k] && k < length && j < lengthFirst + lengthSecond) //i index is finished
				|| (a[j] <= a[i] && i < lengthFirst && k >= length && j < lengthFirst + lengthSecond) //k index is finished
				|| i >= lengthFirst && k >= length)//i & k index are finished
			{
				aux[l++] = a[j++];
			}
			//If an element is smallest in the last n/3 length of a[] (add from k if above two arent satisfied)
			else
				aux[l++] = a[k++];
		}
		//copy elements back to a from aux[]
		for (int s = 0; s < length; s++)
			a[s] = aux[s];
	}
}
