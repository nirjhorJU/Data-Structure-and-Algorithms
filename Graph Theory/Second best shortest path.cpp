#include<bits/stdc++.h>
using namespace std ;
typedef long long LL ;
#define Rep( i , n , m ) for( i = n ; i <= m ; i ++ )
#define InpOut freopen( "in.txt" , "r" , stdin ) , freopen( "out.txt" , "w" , stdout )

LL n , m , caseno ;
LL dis[3][5003] ;
vector< LL > V[5003] , cost[5003] ;

struct node{
    LL u , cost ;
    node(){}
    node( LL u , LL cost ): u(u) , cost(cost) {}
    bool operator < ( const node &p ) const{
        return cost > p.cost ;
    }
};

void Dyaxtra2ndSP( LL u ){
    LL i , w , d ;
    Rep( i , 1 , n ) dis[1][i] = dis[2][i] = LLONG_MAX ;
    dis[1][u] = 0LL ;
    priority_queue< node > pq ;
    pq.push( node( u , dis[1][u] ) ) ;
    while( !pq.empty() ){
        u = pq.top().u ;
        w = pq.top().cost ;
        d = V[u].size() ;
        pq.pop() ;
        Rep( i , 0 , d - 1 ){
            LL v = V[u][i] ;
            if( w + cost[u][i] < dis[1][v] ){
                LL tmp = dis[1][v] ;
                dis[1][v] = w + cost[u][i] ;
                dis[2][v] = tmp ;
                pq.push( node( v , dis[1][v] ) ) ;
            }
            else if( w + cost[u][i] != dis[1][v] && w + cost[u][i] < dis[2][v] ){
                dis[2][v] = w + cost[u][i] ;
                pq.push( node( v , dis[2][v] ) ) ;
            }
        }
    }
}

int main(){
    //InpOut ;
    LL i , j , t , s , d ;
    scanf("%lld",&t) ;
    Rep( caseno , 1 , t ){
        scanf("%lld%lld",&n,&m) ;
        Rep( i , 1 , m ){
            LL u , v , w ;
            scanf("%lld%lld%lld",&u,&v,&w) ;
            V[u].push_back( v ) ;
            V[v].push_back( u ) ;
            cost[u].push_back( w ) ;
            cost[v].push_back( w ) ;
        }
        Dyaxtra2ndSP( 1 ) ;
        printf("Case %lld: %lld\n",caseno,dis[2][n]) ;
        Rep( i , 1 , n ) V[i].clear() , cost[i].clear() ;
    }
    return 0 ;
}
