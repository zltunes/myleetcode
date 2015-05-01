#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
    public:
        vector<string> fullJustify(vector<string> &words, int L) {
            int tLength = 0;
            vector<string> classification; 
            vector<string> group;
            for(vector<string> :: iterator it = words.begin(); it != words.end(); ++it) {
                if(tLength + it->length() + group.size() <= L) {
                    group.push_back(*it);
                    tLength += it->length();
                    //cout << *it << endl;
                    //cout << tLength << endl;
                }
                else {
                    int space = L;
                    string classifyString = "";
                    for(vector<string> :: iterator groupIt = group.begin(); groupIt != group.end(); ++groupIt) {
                        space -= groupIt->length();
                        //cout << *groupIt << endl;
                        //cout << "space :" << space << endl;
                    }
                    int groupCnt = 0;
                    if(group.size() == 1) {
                        classifyString += group[0];
                        classifyString += string(space, ' ');
                    }
                    else {
                        int remainingSize = group.size() - 1;
                        while(space != 0) {
                            classifyString  += group[groupCnt];
                            groupCnt++;
                            //cout << space << " " << remainingSize << endl;
                            int cSpace = ceil(static_cast<double>(space) / remainingSize);
                            remainingSize--;
                            space -= cSpace;
                            classifyString += string(cSpace, ' ');
                        }
                        classifyString += group[groupCnt];
                    }
                    classification.push_back(classifyString);
                    //cout << classifyString << endl;
                    group.clear();
                    tLength = 0;
                    it--;
                }
            }
            //last line
            ////cout << "all is well" << endl;
            string lastLine = "";
            for(vector<string> :: iterator it = group.begin(); it != group.end(); ++it) {
                lastLine += *it + " ";
            }
            int space = L - lastLine.length();
            if(space < 0) {
                lastLine = lastLine.substr(0, L);
                space = 0;
            }
            lastLine += string(space, ' ');
            classification.push_back(lastLine);
            return classification;
        }
};

int main() {
    vector<string> src = {"Imagination","is","more","important","than","knowledge."};
    Solution sol;
    vector<string> dst = sol.fullJustify(src, 11);
    for(vector<string> :: iterator it = dst.begin(); it != dst.end(); ++it) {
        cout << *it << endl;
    }
    return 0; 
}
