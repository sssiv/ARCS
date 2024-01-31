#include "generate.h"
#include <filesystem>

namespace fs = std::filesystem;

void clear_folder(const fs::path& path) 
{
    try 
    {
        // Check if the directory exists
        if (fs::exists(path) && fs::is_directory(path)) 
        {
            // Iterate and remove each item in the directory
            for (const auto& entry : fs::directory_iterator(path)) 
            {
                fs::remove_all(entry);
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


int main(int argc, char* argv[]) 
{
    // Clear the '../tests/', Prevent memory leaks
    clear_folder("../tests/");
    Generate gen;
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number of tests>\n";
        return 1;
    }

    // Convert arguments to strings (or use as char* if suitable for your program)
    std::string input1 = argv[1];
    int numOfTests = std::stoi(input1);

    //std::cout << "Input 1: " << input1 << "\n";

    for (size_t i = 0; i < numOfTests; i++)
        gen.generateRandomTokens("../tests/test-" + std::to_string(i) + ".txt");

    return 0;
}