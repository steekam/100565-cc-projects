#include <iostream>
#include <map>
#include <regex>
#include <fstream>

using namespace std;

class SimpleLexer
{
private:
    ifstream &programFile;

    void matchTokens(string str)
    {
        // define list of patterns
        map<string, string> patterns{
            {"[0-9]+", "Number"},
            {"[a-z]+", "Identifier"},
            {"\\*|\\+|\\-|\\/|\\>|\\<|\\=|\\!", "Operator"},
            {"\\,|\\(|\\)|\\;|\\{|\\}|\\[|\\]", "Separator"},
            {"if|void|int|return", "Keyword"}};

        // storage for results
        map<size_t, pair<string, string>> matches;

        for (auto pattern = patterns.begin(); pattern != patterns.end(); ++pattern)
        {
            regex r(pattern->first);
            auto words_begin = sregex_iterator(str.begin(), str.end(), r);
            auto words_end = sregex_iterator();

            for (auto it = words_begin; it != words_end; ++it)
                matches[it->position()] = make_pair(it->str(), pattern->second);
        }

        for (auto match = matches.begin(); match != matches.end(); ++match)
        {
            cout << match->second.first << " is a " << match->second.second << endl;
        }
    };

public:
    SimpleLexer(ifstream &program_file) : programFile(program_file){};

    void analyse()
    {
        string line;
        while (getline(programFile, line))
        {
            matchTokens(line);
        }
    };
};

// Main
int main()
{
    // Read test file
    ifstream program_file("program.txt");

    if (!program_file.is_open())
    {
        cout << "Error while opening file\n";
    }

    // Print the code being analysed
    string line;
    while (getline(program_file, line))
    {
        cout << line << endl;
    }

    // Reset file pointer position
    program_file.clear();
    program_file.seekg(0, ios::beg);

    // Call lexer, it outputs the token types
    SimpleLexer simple_lexer(program_file);
    simple_lexer.analyse();

    //Close file
    program_file.close();

    return 0;
}