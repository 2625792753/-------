#pragma once
#include <iostream>
#include "meta.hpp"

bool _arg_parse(int argc, char const* argv[])
{
    if (argc < 2)
    {
        std::cout << "2 Args are needed." << '\n'
                << "Arg[1]:: Source Path" << '\n'
                << "(Optional) Arg[2]:: Dest Folder Path" << std::endl;
        return false;
    }

    path_sour = argv[1];
    path_dest_folder = (argc < 3) ? "./" : argv[2];
    std::cout << "SOURCE PATH:: " << path_sour << std::endl;
    std::cout << "DESTINATION PATH:: " << path_dest_folder << std::endl;
    return true;
}