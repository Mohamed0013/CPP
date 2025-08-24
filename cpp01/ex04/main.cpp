#include "nosed.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Please enter three parametters" << std::endl;
        return (0);
    }
    
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty\n";
        return 1;
    }

    std::ifstream infile(av[1]);
    if (!infile.is_open()) {
        std::cerr << "Cannot open file to read from\n";
        return (1);
    }

    std::ofstream outfile("outfile");
    if (!outfile.is_open()) {
        std::cerr << "Cannot open file to write in\n";
        return (1);
    }

    std::string line;
    while (getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << "\n";
    }

    infile.close();
    outfile.close();
    return (0);
}