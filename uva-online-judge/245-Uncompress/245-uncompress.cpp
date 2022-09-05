#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
#include <list>

int getWordLength(char* str)
{
    int length = 0;
    if(isdigit(*str))
    {
        do
        {
            ++length;
            ++str;
        }while(isdigit(*str));
    }
    else if(isalpha(*str))
    {
        do
        {
            ++length;
            ++str;
        }while(isalpha(*str));
    }
    return length;
}

std::string uncompress(std::string& compressed)
{

    std::string res;
    std::unordered_map<std::string, std::list<std::string>::iterator> myMap;
    std::list<std::string> myList;
    for(int i = 0; i < compressed.length(); ++i)
    {
        if(isdigit(compressed[i]))
        {
            int length = getWordLength(&compressed[i]);
            int currentNum = std::stoi(compressed.substr(i, length));
            for(auto it = myList.begin(); it != myList.end(); ++it)
            {
                if(--currentNum == 0)
                {
                    res += *it;
                    myList.splice(myList.begin(), myList, it);
                }
            }

            i = i + length - 1;
        }
        else if(isalpha(compressed[i]))
        {
            int length = getWordLength(&compressed[i]);
            std::string currentWord = compressed.substr(i, length);
            auto mapPtr = myMap.find(currentWord);
            if(mapPtr == myMap.end())
            {
                myList.push_front(currentWord);
                auto it = myList.begin();
                myMap.insert(std::make_pair(currentWord, it));
            }
            else
            {
                auto listPtr = mapPtr->second;
                myList.splice(myList.begin(), myList, listPtr);
            }
            res = res + currentWord;
            i = i + length - 1;
        }
        else
            res.push_back(compressed[i]);
    }

    return res;
}

int main(int argc, char** argv)
{
    std::string line;
    std::string paragraph;
    while(std::getline(std::cin, line))
    {
        if(line == "0")
            break;
        paragraph = paragraph + line + "\n";
    }
    std::string res = uncompress(paragraph);
    std::cout << res.substr(0,res.length()-1) << std::endl;
    return 0;
}
