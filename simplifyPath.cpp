#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<char *> stackPath;
        char *str = new char[path.size() + 1];
        strcpy(str, path.c_str());
        char *substr = strtok(str, "/");
        while(substr != NULL) {
            if(strcmp(substr,"..") == 0) {
                if(!stackPath.empty())
                    stackPath.pop();
            }
            else if(strcmp(substr, ".") != 0) {
                stackPath.push(substr);
            }
            substr = strtok(NULL, "/");
        }
        string ret;
        char *retStr;
        if(stackPath.empty()) return "/";
        while(!stackPath.empty()) {
            retStr = stackPath.top();
            ret = retStr + ret;
            ret = "/" + ret;
            stackPath.pop();
        }
        delete [] str;
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.simplifyPath("/home/foo/./.././bar") << endl;
    return 0;
}
