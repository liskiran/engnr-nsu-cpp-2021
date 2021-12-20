#pragma once

#include "Calculator.h"
#include "libs/SafeInt/SafeInt.hpp"

#include <cstdint>
#include <iostream>
#include <vector>
#include <sstream>
#include <istream>
#include <fstream>

void command_processing(std::stringstream& in_s, std::ifstream& in, int args) {
    CommandCreator creator;
    calculator_data data;
    std::vector<std::string> words;
    std::string word;
    Command *c;
    std::stack<SafeInt<int64_t>> values;
    std::map<std::string, SafeInt<int64_t>> names_and_values;
    int64_t result = 0;
    std::string command;
    std::string cmd_s;
    if(args == 2) {
        while (getline(in, cmd_s, '\n')) {
            if(cmd_s.empty())
                continue;
            std::stringstream ss(cmd_s);
            while (getline(ss, word, ' ')) {
                words.push_back(word);
            }
            c = creator.factoryMethod(words);
            c->exec(words, data, result, args);
            words.clear();
            delete c;
        }
    } else if(args == 1) {
        while (getline(std::cin, cmd_s, '\n')) {
            if(cmd_s.empty())
                continue;
            std::stringstream ss(cmd_s);
            while (getline(ss, word, ' ')) {
                words.push_back(word);
            }
            c = creator.factoryMethod(words);
            c->exec(words, data, result, args);
            words.clear();
            delete c;
        }
    } else if(args == 3) {
        while (getline(in_s, cmd_s, '\n')) {
            if(cmd_s.empty())
                continue;
            std::stringstream ss(cmd_s);
            while (getline(ss, word, ' ')) {
                words.push_back(word);
            }
            c = creator.factoryMethod(words);
            c->exec(words, data, result, args);
            words.clear();
            delete c;
        }
    }
}