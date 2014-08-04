#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define DEBUG
using namespace std;

void printSol(vector<vector<string> > sols) {
    for(auto sol : sols) {
        for(auto row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }
}

void printBMap(vector<vector<bool>> &bMap) {
#ifdef DEBUG
    for(auto row : bMap) {
        for(auto item : row)
            cout << item;
        cout << endl;
    }
    cout << endl;
#endif
}

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<bool> bRow(n, false);
        vector<vector<bool>> bMap(n, bRow);
        vector<vector<string>> ret;
        vector<int> oprStack;
        stack<vector<pair<int, int>>> influStack;
        oprStack.push_back(0);
        int nRow = 0;
        influStack.push(getInfluPos(make_pair(nRow, 0), bMap));
        if(n == 1) {
            vector<string> t = {"Q"};
            ret.push_back(t);
            return ret; 
        }
        nRow++;
        int nCol = 0;
        while(!oprStack.empty() || nCol < n) {
            while(nCol < n && bMap[nRow][nCol] == true) nCol++;
            if(nCol == n) {
                nCol = *(oprStack.end() - 1) + 1;
                oprStack.pop_back();
                removeInfluPos(influStack.top(), bMap);
                influStack.pop();
                nRow--;
                continue;
            }
            oprStack.push_back(nCol);
            influStack.push(getInfluPos(make_pair(nRow, nCol), bMap));
            nRow++;
            nCol = 0;
            if(nRow == n) {
                vector<string> sol;
                for(auto opr : oprStack) {
                    string temp(n, '.');
                    temp[opr] = 'Q';
                    sol.push_back(temp);
                }
                ret.push_back(sol);
                nCol = *(oprStack.end() - 1) + 1;
                oprStack.pop_back();
                removeInfluPos(influStack.top(), bMap);
                influStack.pop();
                nRow--;
            }
        }
        return ret;
    }

    void removeInfluPos(vector<pair<int, int> > & poss, vector<vector<bool> > & bMap) {
        for(auto pos : poss) {
            bMap[pos.first][pos.second] = false;
        }
    }

    vector<pair<int, int>> getInfluPos(pair<int, int> pos, vector<vector<bool>>& bMap) {
        vector<pair<int, int>> ret;
        int &row = pos.first;
        int &col = pos.second;
        for(int i = 0; i < bMap.size(); ++i) {
            if(!bMap[row][i]) {
                bMap[row][i] = true;
                ret.push_back(make_pair(row, i));
            }
            if(!bMap[i][col]) {
                bMap[i][col] = true;
                ret.push_back(make_pair(i, col));
            }
        }
        for(int i = row, j = col; i < bMap.size() && j < bMap.size(); ++i, ++j) {
            if(!bMap[i][j]) {
                bMap[i][j] = true;
                ret.push_back(make_pair(i, j));
            }
        }
        for(int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if(!bMap[i][j]) {
                bMap[i][j] = true;
                ret.push_back(make_pair(i, j));
            }
        }
        for(int i = row, j = col; i < bMap.size() && j >= 0; ++i, --j) {
            if(!bMap[i][j]) {
                bMap[i][j] = true;
                ret.push_back(make_pair(i, j));
            }
        }
        for(int i = row, j = col; i >= 0 && j < bMap.size(); --i, ++j) {
            if(!bMap[i][j]) {
                bMap[i][j] = true;
                ret.push_back(make_pair(i, j));
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    printSol(sol.solveNQueens(4));
 
    return 0;
}
