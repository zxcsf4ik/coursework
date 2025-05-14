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

bool dfs(int x, int y, bool horizontal, int lastLen,
         int visitedCount, int totalEmpty,
         vector<vector<bool>>& visited) {
    if (make_pair(x, y) == finish && visitedCount == totalEmpty)
        return true;

    vector<pair<int, int>> directions = horizontal ?
        vector<pair<int, int>>{{0, 1}, {0, -1}} :
        vector<pair<int, int>>{{1, 0}, {-1, 0}};

    for (auto [dx, dy] : directions) {
        for (int len = 1; len <= SIZE; ++len) {
            if (len == lastLen) continue;

            vector<pair<int, int>> segment;
            bool ok = true;
            int nx = x, ny = y;
            for (int i = 1; i <= len; ++i) {
                nx += dx;
                ny += dy;
                if (!isValid(nx, ny, grid) || visited[nx][ny]) {
                    ok = false;
                    break;
                }
                segment.emplace_back(nx, ny);
            }

            if (!ok) continue;

            for (auto [sx, sy] : segment) visited[sx][sy] = true;

            if (dfs(nx, ny, !horizontal, len, visitedCount + segment.size(),
                   totalEmpty, visited))
                return true;

            for (auto [sx, sy] : segment) visited[sx][sy] = false;
        }
    }
    return false;
}