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

bool isValid(int x, int y, const vector<vector<char>>& g) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && g[x][y] != BLOCK;
}

int countEmpty(const vector<vector<char>>& g) {
    int count = 0;
    for (auto& row : g)
        for (char c : row)
            if (c != BLOCK) count++;
    return count;
}

bool dfs(int x, int y, vector<vector<bool>>& visited, int visitedCount, int totalEmpty) {
    if (make_pair(x, y) == finish && visitedCount == totalEmpty)
        return true;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        if (isValid(nx, ny, grid) && !visited[nx][ny]) {
            visited[nx][ny] = true;
            if (dfs(nx, ny, visited, visitedCount + 1, totalEmpty))
                return true;
            visited[nx][ny] = false;
        }
    }
    return false;
}