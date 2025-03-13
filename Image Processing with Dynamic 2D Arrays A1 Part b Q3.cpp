/*Image Processing with Dynamic 2D Arrays
Background: You are developing a simple image processing tool. Images are represented as 2D arrays
of pixel values (0-255 for grayscale).
Task:
1. Ask the user to input the dimensions (rows and columns) of the image.
2. Dynamically allocate a 2D array to represent the image.
3. Populate the array with random pixel values (0-255).
4. Implement the following operations:
	• Flip the image horizontally (swap rows).
	• Convert the image to its negative (subtract each pixel value from 255).
	• Crop the image (ask the user for new dimensions and resize the array).

5. Display the original and processed images (print the 2D arrays).
6. Deallocate the memory after use.

Real-world connection: This scenario mimics basic image processing tasks, 
such as flipping, cropping, and applying filters, which are common in graphics software.*/


#include<iostream>
#include<iomanip>
using namespace std;

void display(int**image, int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout<<setw(3)<<image[i][j]<<" ";
		}
		cout<<"\n";
	}	
}
int main()
{
	int row, col;
	
//1. Ask the user to input the dimensions (rows and columns) of the image.
	cout<<"\nEnter Height of Image in pixels: ";
	cin>>row;
	cout<<"\nEnter Width of Image in pixels: ";
	cin>>col;

//2. Dynamically allocate a 2D array to represent the image.	 	
	int** image = new int*[row];
 	// for each row allocate memory in new array
	 for (int i = 0; i < row; i ++)
	{
	 	image[i] = new int[col];
	}
//3. Populate the array with random pixel values (0-255).
	cout<<"\nEnter the Values for Pixels [0-255] "<<endl;

	for(int i = 0; i < row; i++)
	{
		for(int j=0; j <col; j++)
		{
			cin>>image[i][j];
		}
		cout<<"\n";
	}
	// display current image
	display(image, row, col);
	
//4. Implement the following operations:
//	• Flip the image horizontally (swap rows).
// new array creation 
	int row_size = row, col_size= col;	 	
	int** new_image = new int*[row_size];
 	// for each row allocate memory in new array
	 for (int i = 0; i < row_size; i ++)
	{
	 	new_image[i] = new int[col_size];
	}
	// copy data into new image from  previous one
	  for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) 
			new_image[i][j] = image[i][j];
		
	}
	
// displaying new image after creation
//	cout<<"\nNew Image without modification"<<endl;
//	display(new_image, row, col);			

	cout<<"\nFlipping image"<<endl;
	// i tried to swap the elements in row so a mirrired image is produced;
	  for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size / 2; j++) 
            // Swap elements in the row
            swap(new_image[i][j], new_image[i][col_size-j-1]);
    }
	// display current image
	display(new_image, row_size, col_size);
	
//• Convert the image to its negative (subtract each pixel value from 255).
// we create a new image then subtracts each element
	 	
	int** imagesub = new int*[row_size];
 	// for each row allocate memory in new array
	 for (int i = 0; i < row_size; i ++)
	{
	 	imagesub[i] = new int[col_size];
	}
	// copy data into new image from  previous one
	  for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) 
			imagesub[i][j] = image[i][j];
		
	}
	// subtracting 
	for(int i = 0; i < row_size; i++)
	{
		for(int j = 0; j <col_size; j++)
		{	imagesub[i][j] = 255 - imagesub[i][j];   }
	}
	
	// display current image
	cout<<"\nSubtracted Image"<<endl;
	display(imagesub, row, col);

//• Crop the image (ask the user for new dimensions and resize the array).
	
int r_size, c_size;

bool flag = true;
while(flag==true)
{
	cout<<"\nResizing Image";
	cout<<"\nEnter new height [must be less than previous one]: ";
	cin>>r_size;
	cout<<"\nEnter new width [must be less than previous one]: ";
	cin>>c_size;
	if (r_size<=row && c_size <= col)
	{
		
	cout<<"\nImage can be resized";
	flag = false;
	}
	
	else cout<<"The new size is invalid ";
}

	// create new image
int** final_image = new int*[r_size];
for(int i = 0; i <r_size; i++)
	final_image[i] = new int[c_size];

// copying the data from image to final one ie, auto resizing 
cout<<"\ncropped Image"<<endl;
for(int i = 0; i < r_size; i++)
{
	for(int j = 0; j < c_size; j++)
	{
		final_image[i][j] = image[i][j];
	}
}

///////////////////////////////////////Display time////////////////////////////
cout<<"\nDisplaying Original image"<<endl;
display(image, row, col );
cout<<"\nDisplaying horizontally Flipped Image"<<endl;
display(new_image, row, col);

cout<<"\nDisplaying Negative Image"<<endl;
//	cout<<"\nNegative Image"<<endl;
display(imagesub, row,col);

//  display cropped image
cout<<"\nDisplaying Cropped Image"<<endl;
display(final_image, r_size, col_size);

cout<<"\n";

/////////////////////////////////6. Deallocate the memory after use.
	for(int i = 0; i <row; i++)
{
	delete[] image[i];
	delete[] new_image[i];
	delete[] imagesub[i];
}
delete[] image;
delete[] new_image;
delete[] imagesub;


// deleting the final image
for(int i = 0; i <r_size; i++)
	delete[] final_image[i];
	
delete[] final_image;
	
	return 0;			
}

