#include "generate.h"
#include <filesystem>

namespace fs = std::filesystem;

void clear_folder(const fs::path& path) 
{
    // Try finding and deleting
    try 
    {
        // Check if the directory exists
        if (fs::exists(path) && fs::is_directory(path)) 
            // Iterate and remove each item in the directory
            for (const auto& entry : fs::directory_iterator(path)) 
                // Delete deletelteltelte 
                fs::remove_all(entry);  
    }
    // Path is not found
    catch (const fs::filesystem_error& e) 
    {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } 
    // File (or nothing) is not found
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main(int argc, char* argv[]) 
{
    // Clear the '../tests/', Prevent memory leaks
    clear_folder("../tests/");

    // Generate tokens
    Generate gen;

    // Checks for entered in args after ./main
    if (argc != 2) 
    {
        // Congrats, you used it wrong
        std::cerr << "Usage: " << argv[0] << " <number of tests>\n";
        return 1;
    }

    // Takes arg input, convert to int
    std::string arg = argv[1];
    int numOfTests = std::stoi(arg);

    //std::cout << "Want to see what you entered?: " << arg << "\n";

    // Make the arg the number of test cases
    for (size_t i = 0; i < numOfTests; i++)
        gen.generateRandomTokens("../tests/test-" + std::to_string(i) + ".txt");

    return 0;
}