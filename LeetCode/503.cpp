class Solution {
public:
    /* Monotonic stack. Duplicamos el arreglo, y ponemos la copia a la derecha del
       arreglo original. Luego, insertamos el primer elemento de este nuevo arreglo 
       a una pila. Luego procesamos el resto de elementos del segundo al ultimo 
       (2*n)-esimo. Por cada uno, mientras la pila no este vacia y el elemento 
       actual sea mayor al tope de la pila, hacemos pop, y marcamos al elemento 
       actual como la respuesta para el elemento del tope de la pila, despues 
       insertamos el elemento actual a la pila. Luego devolvemos las respuestas.

    */
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n = nums.size();
      stack<int> P;
      P.push(0);
      vector<int> arr(2 * n);
      for (int i = 0; i < 2 * n; i++) {
        arr[i] = nums[i % n];
      }
      vector<int> nxtgr(2 * n, -1);
      for (int i = 1; i < 2 * n; i++) {
        while (!P.empty() && arr[i] > arr[P.top()]) {
            nxtgr[P.top()] = arr[i];
            P.pop();
        }
        P.push(i);
      }
      vector<int> new_nxtgr(n);
      for (int i = 0; i < n; i++) {
        new_nxtgr[i] = nxtgr[i];
      }
      return new_nxtgr;
    }
};
