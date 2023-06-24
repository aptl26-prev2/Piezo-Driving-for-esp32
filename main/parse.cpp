#include <iostream>
#include <stdlib.h>
#include <stdio.h>
// #include <unistd.h>
#include <dirent.h>
#include <fstream>
#include "../components/rapidjson/include/rapidjson/document.h"

using namespace rapidjson;

SizeType waveArrSize;
float* waveArr;

void parse()
{

    DIR *d; // directory stream
    struct dirent *dir; // directory entry
    d = opendir ("."); // open current directory
    if (d) {
        while ((dir = readdir (d)) != NULL) { // read each entry
        if (dir->d_type == DT_REG) { // regular file
            printf ("%s (file)\n", dir->d_name);
        }
        else if (dir->d_type == DT_DIR) { // directory
            printf ("%s (directory)\n", dir->d_name);
        }
        else { // other type
            printf ("%s (other)\n", dir->d_name);
        }
        }
        closedir (d); // close directory stream
    }
    else {
        perror ("opendir");
        exit (EXIT_FAILURE);
    }
    // char path [200];
    // if (getcwd (path, 200) != NULL) {
    //     printf ("Current directory: %s\n", path);
    // }
    // else {
    //     perror ("getcwd");
    //     exit (EXIT_FAILURE);
    // }

    // Create a JSON document object
    Document document;

    // Open the JSON file
    std::ifstream file("wave.json");

    // Check if the file is opened successfully
    if (file.is_open())
    {
        // Read the file contents into a string
        std::string json((std::istreambuf_iterator<char>(file)),
                         (std::istreambuf_iterator<char>()));

        // Parse the JSON string into the document object
        document.Parse(json.c_str());

        // Check if the document is an array
        if (document.IsArray())
        {
            // Get the array as a GenericArray object
            auto array = document.GetArray();

            // Get the size of the array
            SizeType waveArrSize = array.Size();

            // Create a C++ array of floats with the same size
            float* waveArr = new float[waveArrSize];

            // Iterate over the array elements and convert them to floats
            for (SizeType i = 0; i < waveArrSize; i++)
            {
                // std::cout << "array element: " << carray[i] << std::endl;
                // Check if the element is a number
                if (array[i].IsNumber())
                {
                    // Convert the element to a float and store it in the C++ array
                    waveArr[i] = array[i].GetFloat();
                }
                else
                {
                    // Handle invalid element type
                    std::cerr << "Invalid element type at index " << i << std::endl;
                }
            }

            // // Print the C++ array elements
            // for (SizeType i = 0; i < waveArrSize; i++)
            // {
            //     std::cout << waveArr[i] << std::endl;
            // }

        }
        else
        {
            // Handle invalid document type
            std::cerr << "Invalid document type" << std::endl;
        }

        // Close the file
        file.close();
    }
    else
    {
        // Handle file opening error
        std::cerr << "Unable to open file" << std::endl;
    }
}

int main() {
    parse();
    return 0;
}