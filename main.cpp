#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 7;
const char EMPTY = ' ';
const char BLOCK = '#';
const char START = 'S';
const char FINISH = 'F';

vector<vector<char>> grid = {
    {' ', ' ', ' ', ' ', ' ', ' ', 'F'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', '#', '#', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', '#', '#'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'S', ' ', ' ', ' ', ' ', ' ', ' '}
};

pair<int, int> start = {6, 0};
pair<int, int> finish = {0, 6};