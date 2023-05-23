#include <iostream>
#include <fstream>
#include <rapidjson/document.h>

using namespace rapidjson;

int main()
{
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
            SizeType size = array.Size();

            // Create a C++ array of floats with the same size
            float* carray = new float[size];

            // Iterate over the array elements and convert them to floats
            for (SizeType i = 0; i < size; i++)
            {
                // std::cout << "array element: " << carray[i] << std::endl;
                // Check if the element is a number
                if (array[i].IsNumber())
                {
                    // Convert the element to a float and store it in the C++ array
                    carray[i] = array[i].GetFloat();
                }
                else
                {
                    // Handle invalid element type
                    std::cerr << "Invalid element type at index " << i << std::endl;
                }
            }

            // Print the C++ array elements
            for (SizeType i = 0; i < size; i++)
            {
                std::cout << carray[i] << std::endl;
            }

            // Delete the C++ array
            delete[] carray;
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

    return 0;
}
