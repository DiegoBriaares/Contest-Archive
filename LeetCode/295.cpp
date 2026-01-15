#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;
class MedianFinder {
/* 
   MedianFinder inicializa un ordered set y a n. addNum inserta a un ordered set y 
   crece a n, y findMedian consulta el elemento en la posicion floor((n - 1) / 2), 
   si n es impar devuelve su valor como la mediana, si n es par tambien consulta a 
   su siguiente elemento y devuelve el promedio de sus dos valores como la mediana.
*/
ordered_set<pair<double, int>> S;
int n;
public:
    MedianFinder() {
        S.clear();
        n = 0;
    }
    
    void addNum(int num) {
        n++;
        S.insert(make_pair((double)num, n));
    }
    
    double findMedian() {
       int p = (n - 1) / 2;
       if (n & 1) {
        return (*(S.find_by_order(p))).first;
       }
       else {
        auto it = S.find_by_order(p);
        return ((*it).first + (*(++it)).first) / (double)2;
       }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
