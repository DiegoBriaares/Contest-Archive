class Solution {
public:
    /* Mantener una monotonic-stack de minimos, i.e el tope de la pila es el elemento
       con el valor menor. Inicializamos la pila insertando el primer elemento. 
       procesamos los demas elementos de izquierda a derecha, comenzando con el 
       segundo elemento. Por cada uno, mientras sea mayor que el tope de la pila y 
       la pila no este vacia, hacemos pop a la pila y asignamos la distancia entre 
       el elemento que actualmente estamos procesando y el elemento que hicimos pop 
       como la respuesta del elemento que hicimos pop. Recuerda inicializar el 
       arreglo de respuestas con 0's. */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> P;
        vector<int> days(n, 0);
        P.push(0);
        for (int i = 1; i < n; i++) {
            while (!P.empty() && temperatures[i] > temperatures[P.top()]) {
                days[P.top()] = i - P.top();
                P.pop();
            }
            P.push(i);
        }
        return days;
    }
};
