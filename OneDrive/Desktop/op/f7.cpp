/*
 FILE : F7.CPP
 PROJECT : Focused assignment- 7
 PROGRAMMER : Rushi Ghelani
 FIRST VERSION : 2023-11-17
 DESCRIPTION : Write a program to give you practice at creating text and binary files.
*/

#include <stdio.h>

// Function    : createTextFile
// Description : This function creates a "myTextFile.txt" and inserts predefined content into it.
//               The text file will contain the lines "This is line 1" and "This is line 2".
// Parameters  : None
// Returns     : void
void createTextFile() {
  
    FILE* myTextFile;

    // Disable warning related to fopen (may vary based on the compiler)
#pragma warning(disable : 4996)

// Open the file with the specified mode
    if ((myTextFile = fopen("myTextFile.txt", "w")) == NULL) {
        // Print an error message if opening the file fails
        perror("Error opening file");
        return;
    }

    // Write predefined content to the file
    if (fprintf(myTextFile, "This is line 1.\nThis is line 2.\n") < 0) {
        // Print an error message if writing to the file fails
        perror("Error writing to file");
    }

    // Close the file
    fclose(myTextFile);
}

int main() {
    // Call the function to create and write to a text file
    createTextFile();

    // Binary file variables
    const char* binaryFilename = "myBinaryFile.data";
    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

    // File pointer for binary file
    FILE* binaryFile;

    // Disable warning related to fopen (may vary based on the compiler)
#pragma warning(disable : 4996)

// Open the binary file with write binary mode
    if ((binaryFile = fopen(binaryFilename, "wb")) == NULL) {
        // Print an error message if opening the binary file fails
        perror("Error opening binaryFile.data");
        return 1;
    }

    // Write the binary data to the binary file
    if (fwrite(kBinaryData, sizeof(unsigned short), sizeof(kBinaryData) / sizeof(unsigned short), binaryFile) != sizeof(kBinaryData) / sizeof(unsigned short)) {
        // Print an error message if writing to the binary file fails
        perror("Error writing to binaryFile.data");
    }

    // Close the binary file
    fclose(binaryFile);

    // Return 0 to indicate successful execution
    return 0;
}
