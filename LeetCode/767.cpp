class Solution {
public:
/* 
   Por cada una de las 26 letras posibles, tomamos las existentes en la cadena,
   e insertamos el par (letra, freq[letra]) a un conjunto ordenado. Mientras el 
   tamaño del conjunto ordenado sea mayor a 1, tomamos el caracter con la menor 
   frecuencia y el caracter con la mayor frecuencia, agregamos a la respuesta el 
   de la mayor frecuencia y el de la menor frecuencia respectivamente, los sacamos 
   del conjunto, modificamos la frecuencia i.e -1 a cada caracter, y reinsertamos. 
   Si al final queda un caracter y la frecuencia del caracter que queda es mayor 
   a 1, devolvemos "". En caso contrario lo agregamos a la respuesta y devolvemos 
   la respuesta.
*/
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        set<pair<int, int>, greater<>> S;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                S.insert(make_pair(freq[i], i));
            }
        }
        string ans = "";
        while (S.size() > 1) {
            auto f = *S.begin();
            auto it = S.end();
            it--;
            auto s = *it;
            S.erase(S.find(f));
            S.erase(S.find(s));
            ans += (char)(f.second + 'a');
            ans += (char)(s.second + 'a');
            f.first--;
            s.first--;
            if (f.first) {
                S.insert(f);
            }
            if (s.first) {
                S.insert(s);
            }
        }
        if (!S.empty()) {
            auto last = *S.begin();
            if (last.first > 1) {
                return "";
            }
            else {
                ans += (char)(last.second + 'a');
            }
        }
        return ans;
    }
};
