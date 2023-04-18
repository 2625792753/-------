#include "meta.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

bool _FileCheck(string path)
{
    ifstream tmp(path, ios::in | ios::out);
    if (!tmp.is_open())
    {
        cout << "File at Path:: " << path << " Depercated." << endl;
        return false;
    }
    return true;
}

void _pre_process(string output_filename)
{
    if (!_FileCheck(path_sour))
        return;
    ifstream in(path_sour, ios::in);

    if (!_FileCheck(path_dest_folder + output_filename))
        return;
    ofstream out(path_dest_folder + output_filename, ios::out);

    bool _exegesis = false;
    while (!in.eof())
    {
        string tmp;
        in >> tmp;

        size_t start = tmp.find("/*");
        size_t end = tmp.find("*/");
        _exegesis = start != string::npos || start != string::npos || _exegesis;

        if (_exegesis)
        {
            if (start == end)
            {
                continue;
            }

            if (start < end)
            {
                if (end != string::npos)
                {
                    tmp.erase(start, end - start + 2);
                    _exegesis = tmp.empty() ? false : _exegesis;
                    continue;
                }
                else
                    tmp.erase(start);
            }

            if (start > end)
            {
                if (start != string::npos)
                    tmp = tmp.substr(start + 2, end - start);
                else
                {
                    tmp.erase(0, end + 2);
                    _exegesis = false;
                }
            }
        }
        else
        {
            if (tmp.find("//") != string::npos)
            {
                tmp.erase(tmp.find("//"));
                out << tmp;
                while (!in.eof())
                {
                    in >> tmp;
                    if (tmp.find('\n') != string::npos)
                    {
                        in >> tmp;
                        break;
                    }
                }
            }

            if (tmp.find('\n') != string::npos)
            {
                tmp.erase(tmp.find('\n'), 1);
            }
        }

        out << tmp << ' ';
    }

    in.close();
    out.close();
}

void _lexical_analyze(string source_path, string dest_path)
{
    if (!_FileCheck(source_path))
        return;
    fstream in(source_path, ios::in);

    if (!_FileCheck(dest_path))
        return;
    fstream out(dest_path, ios::out);

    string expression;
    int index = 0;

    while (!in.eof())
    {
        in >> expression;
        cout << "Expression: " << expression << endl;

        int i = 0;
        while (i < expression.length())
        {
            char c = expression[i];
            auto s = separaters.find(c);

            // separater found
            if (s != separaters.end())
            {
                cout << "Separater: " << c << endl;
                out << index++ << '\t' << s->second << '\t' << s->first << endl;
                ++i;
                continue;
            }

            string token = "";
            while (i < expression.length() && separaters.find(expression[i]) == separaters.end())
            {
                token += expression[i];
                ++i;
            }

            // token analyze
            if (token.length() > 0)
            {
                cout << "Token: " << token << endl;

                // keyword found
                auto k = keywords.find(token);
                if (k != keywords.end())
                {
                    out << index++ << '\t' << k->second << '\t' << k->first << endl;
                }
                else
                {
                    // non_keyword found
                    bool valid = true;
                    bool startwithdigit = isdigit(token[0]);
                    for (int j = 1; j < token.length(); ++j)
                    {
                        if ((startwithdigit && isalpha(token[j])) || (!isalnum(token[j]) && token[j] != '_'))
                        {
                            valid = false;
                            break;
                        }
                    }

                    if (valid)
                    {
                        out << index++ << '\t' << 0 << '\t' << token << endl;
                    }
                }
            }
        }
    }

    in.close();
    out.close();
}