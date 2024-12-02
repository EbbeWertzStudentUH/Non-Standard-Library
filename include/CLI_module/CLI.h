#ifndef CLI_MODULE_CLI_H
#define CLI_MODULE_CLI_H


#include <unordered_set>
#include <functional>
#include <set>
#include "CommandParser.h"

using namespace std;

// A function might look like this
//void greet(map<string, string> params, set<string> flags) {
//    cout << "hello " << params["naam"];
//    if (flags.contains("roepend")) {
//        cout << "!!!";
//    }
//    cout << "\n";
//}

class CLI {
public:
    bool getInput();

    void registerCommand(const string& name,
                         function<void(unordered_map<string, string> params, unordered_set<string> flags)> cmd,
                         const unordered_set<string> &params,
                         const unordered_set<string>& flags);

    CLI(const unordered_set<string> &allowedParams, const unordered_set<string> &allowedFlags);

private:
    CommandParser parser;

    // General CLI
    string prompt = "";
    unordered_set<string> allowedParams;
    unordered_set<string> allowedFlags;

    // Command specifick
    unordered_map<string, function<void(unordered_map<string, string> params, unordered_set<string> flags)> > commands;

    void logic(CommandParser::Command cmd);
};


#endif //CLI_MODULE_CLI_H
