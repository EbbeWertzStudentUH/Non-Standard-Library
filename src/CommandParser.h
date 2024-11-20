#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
#include <set>
#include <map>

using namespace std;

class CommandParser {
public:
    struct Command{
        string commandName;
        map<string, string> params;
        set<string> flags;
    };

    Command getInput(const string &prompt);
    bool validate(Command cmd, set<string> allowedParams, set<string> allowedFlags);

private:
    void parseToken(istringstream& iss, CommandParser::Command& cmd);

};


#endif //COMMANDPARSER_H