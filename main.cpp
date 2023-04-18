#include <iostream>
#include "meta.hpp"
#include "argparser.hpp"
#include "lexical_analyzer.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // arg parser
    if (!_arg_parse(argc, argv))
        return 1;

    string outfile1 = "out1.txt";
    string outfile2 = "out2.txt";
    // lexical analyzer
    _pre_process(outfile1);
    _lexical_analyze(path_dest_folder + outfile1, path_dest_folder + outfile2);
}
