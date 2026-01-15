class Solution {
public:
    /* Two pointers. Encuentra el ultimo elemento de izquierda a derecha, que es 
       menor que x. Pon un primer puntero alli, y otro segundo puntero en el 
       siguiente elemento. Si el elemento del primer puntero es mas cercano a x  
       y sigue dentro del arreglo, agrega su elemennto a la respuesta y mueve a ese 
       puntero a la izquierda, en caso contrario, agrega el elemento del segundo 
       puntero a la respuesta y mueve el segundo a la derecha. Considera edge-cases
       al comparar distancias i.e que un puntero ya este fuera del arreglo.
        */ 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int p1, p2;
        p1 = p2 = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= x) {
                break;
            }
            else {
                p1 = i;
                p2 = i + 1;
            }
        }
        if (p2 == -1) {
            p2 = 0;
        }
        vector<int> close;
        while (k--) {
            int d1 = -1;
            int d2 = -1;
            if (p1 >= 0) {
                d1 = abs(x - arr[p1]);
            } 
            if (p2 < n) {
                d2 = abs(x - arr[p2]);
            }
            if (d1 == -1) {
                close.push_back(arr[p2++]);
            }
            else {
                if (d2 == -1) {
                    close.push_back(arr[p1--]);
                }
                else {
                    if (d1 <= d2) {
                        close.push_back(arr[p1--]);
                    }
                    else {
                        close.push_back(arr[p2++]);
                    }
                }
            }
        }
        sort(close.begin(), close.end());
        return close;
    }
};
