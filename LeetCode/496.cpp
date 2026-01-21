class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        map<int, int> H;
        for (int i = 0; i < m; i++) {
               H[nums2[i]] = i;
        }
        stack<int> P;
        vector<int> nxt(m, -1);
        P.push(0);
        for (int i = 1; i < m; i++) {
            while (!P.empty() && nums2[P.top()] < nums2[i]) {
                nxt[P.top()] = nums2[i];
                P.pop();
            }
            P.push(i);
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nxt[H[nums1[i]]];
        }
        return ans;
    }
};
