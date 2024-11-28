//
// Created by houwe on 28/11/2024.
//

#include <iostream>
#include "CLI.h"

void greet(unordered_map<string, string> params, unordered_set<string> flags) {
    if (params.find("-name") != params.end()) {
        string name = params["-name"];
        cout << "Welcome, " << name << "\n";
    } else {
        cout << "Welcome, Guest!\n";
    }
}

void flagExample(unordered_map<string, string> params, unordered_set<string> flags){
    if (params.find("-name") != params.end()) {
        if(flags.find("--scream") != flags.end()){
            cout << params["-name"] << "!\n";
            return;
        }
        cout << params["-name"] << "\n";
    }
}

int main() {
    CLI cli( {"-name", "-guest", "-p3"}, {"--f1", "--scream", "--f3"});
    cli.registerCommand("greet", &greet, {"-name", "-guest"}, {});
    cli.registerCommand("flag", &flagExample, {{"-name", "-guest"}}, {"--scream"});
    cli.getInput();
}