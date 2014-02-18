#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h>

using namespace std;

int findcount(char * filename);						//finds the count of elements in the file
void storingArray(char *filename, int *numArray, int count); //Stores the file data into an array
void BubbleSort(int *numArray, int count);			//Bubble sort function
void InsertionSort(int *numArray, int count);		//Insertion sort function
void QuickSort(int *numArray, int low, int high);	//Quick sort function
void ShellSort(int *numArray, int count);			//Shell sort function
void MergeSort(int *numArray, int low, int high);	//Merge sort function
void printElements(int *numArray, int count);		//print elements function to test the correctness

int main()
{
	clock_t start, finish;							//start and finish variables for clock
	char filename[200];								//user entered filename
	cout << "Enter the filename you'd like to sort: " ;
	cin >> filename;
	int count;							
	count = findcount(filename);					//findcount function returns the number of elements in the file which is stored to count variable
	
	int i;
	int * numArray;									//array of integers from the file
	numArray = new int [count];						//initialize the array with count as size

	cout << "Bubble Sort" << endl;
	storingArray(filename, numArray, count);
			start = clock();						//start is the clock variable initialized right before the sort is performed
			BubbleSort(numArray, count);			//bubble sort funtion call
			finish = clock();						//finish is the clock variable that ends right after the sort is performed
			cout << "\tNumber of clock ticks is:" << (finish - start) << endl;					//finish-start gives the number of ticks taken to perform the sort function
			cout << "\tTime in Seconds is: "  << (float(finish - start))/CLOCKS_PER_SEC << endl;	//displays the the time taken in seconds
	cout << "Insertion Sort" << endl;
	storingArray(filename, numArray, count);
			start = clock();						//start is the clock variable initialized right before the sort is performed
			InsertionSort(numArray, count);			//insertion sort funtion call
			finish = clock();						//finish is the clock variable that ends right after the sort is performed
			cout << "\tNumber of clock ticks is:" << (finish - start) << endl;					//finish-start gives the number of ticks taken to perform the sort function
			cout << "\tTime in Seconds is: "  << (float(finish - start))/CLOCKS_PER_SEC << endl;	//displays the the time taken in seconds
	cout << "Quick Sort" << endl;
	storingArray(filename, numArray, count);
			start = clock();						//start is the clock variable initialized right before the sort is performed
			QuickSort(numArray, 0, count-1);		//quick sort funtion call
			finish = clock();						//finish is the clock variable that ends right after the sort is performed
			cout << "\tNumber of clock ticks is:" << (finish - start) << endl;					//finish-start gives the number of ticks taken to perform the sort function
			cout << "\tTime in Seconds is: "  << (float(finish - start))/CLOCKS_PER_SEC << endl;	//displays the the time taken in seconds
	cout << "Shell Sort" << endl;
	storingArray(filename, numArray, count);
			start = clock();						//start is the clock variable initialized right before the sort is performed
			ShellSort(numArray, count);				//shell sort funtion call
			finish = clock();						//finish is the clock variable that ends right after the sort is performed	
			cout << "\tNumber of clock ticks is:" << (finish - start) << endl;					//finish-start gives the number of ticks taken to perform the sort function
			cout << "\tTime in Seconds is: "  << (float(finish - start))/CLOCKS_PER_SEC << endl;	//displays the the time taken in seconds
	cout << "Merge Sort" << endl;
	storingArray(filename, numArray, count);
			start = clock();						//start is the clock variable initialized right before the sort is performed
			MergeSort(numArray, 0, count-1);		//merge sort funtion call
			finish = clock();						//finish is the clock variable that ends right after the sort is performed
			cout << "\tNumber of clock ticks is:" << (finish - start) << endl;					//finish-start gives the number of ticks taken to perform the sort function
			cout << "\tTime in Seconds is: "  << (float(finish - start))/CLOCKS_PER_SEC << endl;	//displays the the time taken in seconds

	//printElements(numArray, count);				//This function prints all the sorted elements.
	
	return 1;
}

/* Function: findcount
 * parameter: user filename
 * Returns: Total count of integers contained in the file
 */
int findcount(char * filename)
{
	ifstream in;
	in.open(filename);				//open filename

	if(!in.is_open())				//returns true if the file is open
	{
		cout << "The file could not be opened. Check the location.\t"; 
		return false;
	}
    int * number = new int [5];		//create an array of numbers 
	int n = 0;						//n is the counter
    while(in.peek()!=EOF)		
	{
		in >> number[0];			//reads the file
		n++;						//for each read, the counter is updated
	}								
    in.clear(); 
	in.close();
	return n;						//returns the length of the sequence
}

/* Function: storingArray
 * parameter: user filename, initialized array, arraysize
 * reads data from the file and stores to the array
 */
void storingArray(char *filename, int *numArray, int count)
{
	int i;
	ifstream in;
	in.open(filename);								//opens provided filename
	while(in.good())		
	{
		for(i = 0; i < count; i++)
			in >> numArray[i];						//reads the elements and stores all to numArray
	}
	//cout << "\nThe file has been stored to an array.\n";
}

/* Function: BubbleSort
 * parameter: array, array size
 * Sorts the array using BubbleSort
 */
void BubbleSort(int *numArray, int count)
{
	int i,j,temp;
	for(i = 1; i < count; i++)
	{
		for(j = 0; j < count-1; j++)				//multiple pass loop
		{
			if(numArray[j] > numArray[j+1])			//if the element at j is greater than the next element, the perform a swap
			{
				temp = numArray[j];					//store the element at j to temp
				numArray[j] = numArray[j+1];		//store the next element to index j
				numArray[j+1] = temp;				//store the temp back to index j+1
			}
		}
	}												//the loop continues as long as a swap occurs in a pass
}

/* Function: InsertionSort
 * parameter: array, array size
 * Sorts the array using insertion method
 */
void InsertionSort(int *numArray, int count)
{												//uses inplace sort- moves the current item past the already sorted items 
	int i, j, element;							
	for(i = 1; i < count; i++)
	{
		element = numArray[i];
        j = i-1;
        while((j >= 0) && (numArray[j] > element))
        {
            numArray[j+1] = numArray[j];		//inplace sort, repeatedly swapping it with preceeding item until it is in correct place
            j -= 1;
        }
        numArray[j+1] = element;
	}
}

/* Function: merge
 * parameter: array, low, mid and high values from MergeSort function
 * Sorts the array using merging 
 */
void merge(int *numArray, int low, int high, int mid)
{
	int * C;										//temp array C
	C = new int[high+1];							//high = count - 1, hence, temp array C is sized high + 1
	int i, j, k;
	i = low;      									//index for first part
    j = mid+1;    									//index for second part
    k = 0;        									//index for array C
    while((i <= mid) && (j <= high))				
    {
        if(numArray[i] < numArray[j]) 
			C[k] = numArray[i++];
        else 
			C[k] = numArray[j++];
        k++;
    }
    while(i <= mid) 
		C[k++] = numArray[i++];
    while(j <= high) 
		C[k++] = numArray[j++];
    for(i = low, j = 0; i <= high; i++, j++) 
		numArray[i] = C[j];
}
/* Function: MergeSort
 * Parameters: Array, 0 as low, size as high
 * Sorts data by Divide and conquer method
 */
void MergeSort(int *numArray, int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high)/2;						//divides the array size
        MergeSort(numArray, low, mid);				//recursive function sort first half
        MergeSort(numArray, mid+1, high);			//recursive function sort second half
        merge(numArray, low, high, mid);			//merge function call 
    }
}

/* Function: ShellSort
 * Parameters: Array, count
 * Sorts data by repititive use of insertion sort
 */
void ShellSort(int *numArray, int count)
{
	int temp, gap, i;
	int swapped;
	gap = count/2;									//initial gap count/2
	do
	{
		do{
			swapped = 0;
			for(i = 0; i < count-gap; i++)
			{
				if(numArray[i] > numArray[i+gap])
				{
					temp = numArray[i];
					numArray[i] = numArray[i+gap];
					numArray[i+gap] = temp;
					swapped = 1;
				}
			}
		}while(swapped == 1);
	}while((gap = gap/2) >= 1);						//loop until gap is 1
}
int partition(int* numArray, int pivot, int low, int high)
{

    int left = low;
    int right = high;
    while(left < right)             //shuttle pivot until the boundaries meet
    {
         while( pivot < numArray[right]       //keep moving until a lesser element is found
                && right > left)   //or until the left is reached
         {
              right--;                      //move left
         }
         swap(numArray[left], numArray[right]);
         //PrintArray(numArray, ARRAY_SIZE);            //Uncomment this line for study
          
         while( pivot >= numArray[left]       //keep moving until a greater or equal element is found
                && left < right)   //or until the right is reached
         {
              left++;                        //move right
         }
         swap(numArray[right], numArray[left]);
         //PrintArray(numArray, ARRAY_SIZE);            //Uncomment this line for study
    }
    return left;                              //left is the split point because
                                                     //the above while loop exits only when
                                                      //left and right are equal
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
//void QuickSort(int* numArray, int low, int high)
//{
//    int pivot = numArray[low];                  //pivot element is the leftmost element
//    int splitPoint;
//    if(high > low)                         //if they are equal, it means there is
//                                                      //only one element and QuickSort's job
//                                                      //here is finished
//    {
//        splitPoint = partition(numArray, pivot, low, high);	//partition() returns the position where
//															//pivot belongs to
//        numArray[splitPoint] = pivot;
//        QuickSort(numArray, low, splitPoint-1);   //Quick sort first half
//        QuickSort(numArray, splitPoint+1, high);    //Quick sort second half
//    }
//
//}

void QuickSort(int* numArray, int low, int high)
{
	int i = low;
    int j = high;
	int element;
	int piv = numArray[(low + high) / 2];		// partition
	while (i <= j)
    {
		while (numArray[i] < piv)
			i++;
		while (numArray[j] > piv)
			j--;
		if (i <= j) {
			element = numArray[i];
			numArray[i] = numArray[j];
			numArray[j] = element;
			i++;
			j--;
		}
	}
    
	if (low < j)
    {
		QuickSort(numArray, low, j);
    }
	if (i < high)
    {
		QuickSort(numArray, i, high);
    }
}


void printElements(int *numArray, int count)
{
	int i = 0;
    for(i = 0; i < count; i++)
        cout << numArray[i] << "\t";
}

