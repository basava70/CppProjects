#include <iostream>

/*********************************************************/
// Code for printing elements of matrix in spiral order.
// Limitations: Only works for non negative integers of the matrix.
void BuildSpiralOrderString(int *Matrix, int NumRows, int NumColumns, 
    char* OutBuffer) {
  const int len = NumColumns*NumRows;
  int tracker_1 = 0, tracker_2 = 0, tracker_3 = 0, tracker_4 = 0;
  int count = 0, i, iter;
  int x = 0, y = 0;
  int *elem_iter = new int[len + 1]; 

  /*********************************************************/
  // Calculating the elem_iter vector which will give 
  // the spiral element indices. Once we have this
  // vector, we can iterate our Matrix over this vector
  // We parse through the entire matrix once. 
  // Time complexity = O(NumRows * NumColumns).
  elem_iter[0] = 0;
  while(count < (NumColumns * NumRows - 1))
  {
    while(y < NumColumns -1 - tracker_1)
    {
      y++;
      count++;
      elem_iter[count] = x*NumColumns + y;
    }
    tracker_1++;
    if (count == len - 1) break;

    while(x < NumRows -1 - tracker_2)
    {
      x++;
      count++;
      elem_iter[count] = x*NumColumns + y;
    }
    tracker_2++;
    if (count == len - 1) break;

    while(y > 0 + tracker_3)
    {
      y--;
      count++;
      elem_iter[count] = x*NumColumns + y;
    }
    tracker_3++;
    if (count == len - 1) break;

    while(x > 1 + tracker_4)
    {
      x--;
      count++;
      elem_iter[count] = x*NumColumns + y;
    }
    tracker_4++;
    if (count == len - 1) break;
  }

  // Can print the indices in Spiral order if needed.
  //std::cout << " elem_iter = ";
  //for(i = 0; i < len; i++)
  //  std::cout << elem_iter[i] << " ";
  //std::cout << std::endl;

  /*********************************************************/
  //Now we just iterate over all the indices of elem_iter.
  iter = 0;
  for(i = 0; i < len; i++)
  {
    // Initialise with elem_iter and find how many 
    // digits doest the element have and store in length.
    // Added Time complexity O(d), where d is the number of
    // digits in Matrix[i].
    int Int = Matrix[elem_iter[i]], length = 1;
    while(Int/10 != 0)
    {
      length++;
      Int /=10;
    }

    // We use basic ascii conversion digit by digit.
    // We get the digits in reverse order.
    Int = Matrix[elem_iter[i]];

    char *reverse_buffer = new char[length];
    char *buffer = new char[length];
    //std::cout << " length = " << length << std::endl;

    int j = 0, count;
    // Another O(d).
    for(j = 0; j < length; j++)
    {
      reverse_buffer[j] = (char)(Int % 10 + '0');
      Int /= 10;
    }

    // Now, we just reverse the reverse buffer to the correct order.
    // Another O(d).
    for(count = 0; count < length; count++)
      buffer[count] = reverse_buffer[length - 1 -count];

    // Copying the correct buffer into the OutBuffer.
    // Another O(d).
    for(j = 0; j < length; j++)
      OutBuffer[j + iter] = buffer[j];

    // Extend iter until the length of the buffer.
    iter += j;

    // Addend an extra "," after the buffer except for the last matrix entry.
    if(i != len-1)
      OutBuffer[iter] = ',';

    // Adjust the iter for the added ",".
    iter++;
    // freeing memory that was dynamically allocated.
    delete [] reverse_buffer;
    delete [] buffer;
  }
  // Finally the Time complexity is 
  // T = O(NumColumns * NumRows) + O(d*NumRows * NumColumns).
  //  Since d is constant, we have Time complexity = O(NumColumns * NumRows)
  /*********************************************************/
  std::cout << " OutBuffer = " << OutBuffer << std::endl;

  // freeing memory that was dynamically allocated.
  delete[] elem_iter;
}

/*********************************************************/
int main()
{
  int matrix[] = {1, 4, 2, 3, 8, 6, 9, 10, 7, 5, 0, 12};
  int NumRows = 3, NumColumns = 4;

  int matrix_len = sizeof(matrix)/sizeof(*matrix);
  if (NumRows < 0 || NumColumns < 0) 
  {
    std::cout << "Error : Invalid Row or Column entries" << std::endl;
    exit(1);
  }
  if (matrix_len < 0 || matrix_len != NumColumns * NumRows)
  {
    std::cout << "Error : invalid matrix length, matrix length either non positive" <<
      " or not equal to NumRows * NumColumns" << std::endl;
    exit(1);
  }
  if(matrix_len == 0)
  {
    std::cout << "Empty Matrix in the input " << std::endl;
    exit(1);
  }

  // Assumed that OutBuffer is long enough to hold any output.
  char *OutBuffer = new char[NumRows * NumColumns*100];
  BuildSpiralOrderString(matrix, NumRows, NumColumns, OutBuffer);
  return 0;
}
