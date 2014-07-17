/*************************************************************************
    > Author: yiyunyao
    > Mail: yiyunyao@sina.cn 
    > Created Time: 2014年04月01日 星期二 17时35分02秒
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool compare( pair<int, int> a, pair<int, int> b ) {
    return a.first < b.first;
}

class Solutions {

    public:
        vector<int> twoSum( vector<int>& numbers, int target ) {
            return twoSum_method2( numbers, target );
        }

        vector<int> twoSum_method1( vector<int> &numbers, int target ) {
            vector< pair<int, int> > signalVec;
            for( int i = 0; i < numbers.size(); ++i )
                signalVec.push_back( make_pair( numbers[ i ], i + 1 ) );

            sort( signalVec.begin(), signalVec.end(), compare );

            int l = 0, r = numbers.size() - 1;
            while( l < r ) {
                int t_res = signalVec[ l ].first + signalVec[ r ].first;
                if( t_res == target ) break;
                if( t_res < target ) ++l;
                else --r;
            }
            
            vector<int> res;
            res.push_back( min( signalVec[ l ].second, signalVec[ r ].second ) );
            res.push_back( max( signalVec[ l ].second, signalVec[ r ].second ) );
            return res;

        }

        typedef unordered_map<int, vector<int> > MAP;
        vector<int> twoSum_method2( vector<int>& numbers, int target ) {
            MAP map;
            for( int i = 0; i < numbers.size(); ++i )
                map[ numbers[ i ] ].push_back( i + 1 );

            for( int i = 0; i < numbers.size(); ++i ) {
                MAP :: iterator iter = map.find( target - numbers[ i ] );
                if( iter == map.end() ) continue;

                int index1 = iter->second[ 0 ], index2 = i + 1;
                if( numbers[ i ] == target - numbers[ i ] ) {
                    if( map[ numbers[ i ] ].size() == 1 ) continue;
                    index2 = iter->second[ 1 ];
                }

                vector<int> res;
                res.push_back( min( index1, index2 ) );
                res.push_back( max( index1, index2 ) );
                return res;
            }
        }

};


//test main
int main() {

    const int VEC_SIZE = 10;
    vector<int> testVec;
    int myInt = 0;
    for( int i = 0; i < VEC_SIZE; ++i ) {
        testVec.push_back( i );
    }

    const int target = 15;

    Solutions a;
    vector<int> resVec;
    resVec = a.twoSum( testVec, target );

    for( int i = 0; i < resVec.size(); ++i ) {
        cout << resVec[ i ] << ' ';
    }

}
