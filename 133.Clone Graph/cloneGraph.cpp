#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
    void visit() {
        cout << label << "is visited!" << endl;
    }
};

class Solution {
public:
    map<UndirectedGraphNode *, UndirectedGraphNode *> isAlreadyCloned;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        vector<UndirectedGraphNode *> nodeList;
        nodeList.push_back(node);
        isAlreadyCloned[node] = new UndirectedGraphNode(node->label);
        
        //copy all nodes
        int start = 0;
        while(start < nodeList.size()) {
            UndirectedGraphNode *tNode = nodeList.at(start++);
            for(vector<UndirectedGraphNode *> :: iterator it = tNode->neighbors.begin(); it != tNode->neighbors.end(); ++it) {
                if(isAlreadyCloned.count(*it) == 0) {
                    isAlreadyCloned[*it] = new UndirectedGraphNode((*it)->label);
                    nodeList.push_back(*it);
                }
            }
        }

        //copy all their neighbors
        for(vector<UndirectedGraphNode *> :: iterator it = nodeList.begin(); it != nodeList.end(); ++it) {
            vector<UndirectedGraphNode *> & nbrs = (*it)->neighbors;
            for(vector<UndirectedGraphNode *> :: iterator nbr = nbrs.begin(); nbr != nbrs.end(); ++nbr) {
                isAlreadyCloned[*it]->neighbors.push_back(isAlreadyCloned[*nbr]);
            }
        }
        return isAlreadyCloned[node];
    }
};


int main() {
    return 0;
}
