 /*************************************************************************
    > Author: yiyunyao
    > Mail: yiyunyao@sina.cn
    > Created Time: 2014年04月09日 星期三 20时16分38秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode( int x ) : val( x ), next( NULL ) {}
};

void printList( ListNode * );

class Solution {
    public:
        ListNode *partition( ListNode *head, int x ) {
            ListNode *virtualNode = new ListNode( x );
            ListNode *current  = head;
            ListNode *tempBefore = NULL;
            ListNode *tempAfter = NULL;
            ListNode *currentNext = NULL; 
            while( current != NULL ) {
                currentNext = current->next;
                if( current->val < x ) {
                    current->next = virtualNode;
                    if( tempBefore != NULL ) {
                        tempBefore->next = current;
                        tempBefore = current;
                    }
                    else {
                        tempBefore = current;
                        head = current;
                    }
                }
                else {
                    if( tempAfter != NULL ) {
                        tempAfter->next = current;
                        tempAfter = current;
                    }
                    else {
                        tempAfter = current;
                        virtualNode->next = tempAfter;
                    }
                }
                current = currentNext;
            }
            if( tempBefore )
                tempBefore->next = virtualNode->next;
            if( tempAfter )
                tempAfter->next = NULL;
            delete virtualNode;
            return head;
        }
};

//test main
int main() {
    Solution sol;
    int test[] = { 2,1 };
    ListNode *before = NULL;
    ListNode *head = before = new ListNode( test[ 0 ] );
    for( int i = 1; i < 2; ++i ) {
        before->next = new ListNode( test[ i ] );
        before = before->next;
    }
    printList( head );

    head = sol.partition( head, 2 );
    printList( head );
    

    return 0;
}

void printList( ListNode * head ) {
    ListNode *current = head;
    while( current != NULL ) {
        cout << current->val << ' ';
        current = current->next;
    }
    cout << endl;
}
