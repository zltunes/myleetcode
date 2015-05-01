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
        ListNode *current  = head;
        ListNode *listBefore = NULL;
        ListNode *listBeforeHead = NULL;
        ListNode *listAfter = NULL;
        ListNode *listAfterHead = NULL;
        while( current != NULL ) {
            if( current->val < x ) {
                if( listBefore != NULL ) {
                    listBefore->next = current;
                    listBefore = current;
                }
                else {
                    listBefore = current;
                    listBeforeHead = current;
                }
            }
            else {
                if( listAfter != NULL ) {
                    listAfter->next = current;
                    listAfter = current;
                }
                else {
                    listAfter = current;
                    listAfterHead = current;
                }
            }
            current = current->next;
        }
        if(listBeforeHead) {
            listBefore->next = listAfterHead;
        }
        else {
            listBeforeHead = listAfterHead;
        }
        if(listAfter)
            listAfter->next = NULL;
        return listBeforeHead;
    }
};

//test main
int main() {
    Solution sol;
    int test[] = { 1 };
    ListNode *before = NULL;
    ListNode *head = before = new ListNode( test[ 0 ] );
    for( int i = 1; i < 1; ++i ) {
        before->next = new ListNode( test[ i ] );
        before = before->next;
    }
    printList( head );

    head = sol.partition( head, 0 );
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
