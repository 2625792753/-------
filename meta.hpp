#pragma once
#include <string>
#include <unordered_map>

#include <iostream>

std::string path_sour;
std::string path_dest_folder;

const std::unordered_map<std::string, int> keywords = {
    {"void", 1},
    {"main", 2},
    {"int", 3},
    {"cout", 4},
    {"return", 5},
};

const std::unordered_map<char, int> separaters = {
    {'(', 6},
    {')', 7},
    {'{', 8},
    {'}', 9},
    {';', 10},
    {',', 11},
    {'=', 12},
    {'*', 13},
    {'/', 14}};
