class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        set<pair<int, int>> S;
        for (int i = 0; i < k; i++) {
            S.insert(make_pair(nums[i], -i));
        }
        int n = nums.size();
        int m = (k + 1) / 2;
        if (!(k & 1)) {
            m++;
        }
        auto it = S.begin();
        for (int i = 0; i < m - 1; i++) {
            it++;
        }
        int p = k - 1;
        vector<double> med;
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                med.push_back(nums[i]);
            }
            return med;
        }
        if (k == 2) {
            for (int i = 1; i < n; i++) {
                med.push_back((double)(((double)nums[i] + (double)nums[i - 1]) / (double)2));
            }
            return med;
        }
        do {
            if ((k & 1)) {
                med.push_back((*it).first);
            }
            else {
                med.push_back((double)((double)((*(it)).first) + (double)(*(--it)).first) / (double)2);
                it++;
            }
            if (-(*it).second == p - k + 1) {
                it++;
                S.erase(S.find(make_pair(nums[p - k + 1], -(p - k + 1))));
            }
            else if ((*it).first > nums[p - k + 1]) {
                S.erase(S.find(make_pair(nums[p - k + 1], -(p - k + 1))));
                it++;
            }
            else {
                S.erase(S.find(make_pair(nums[p - k + 1], -(p - k + 1))));
            }
            if (p + 1 < n) {
                S.insert(make_pair(nums[p + 1], -(p + 1)));
                if ((*it).first >= nums[p + 1]) {
                    it--;
                }
            }
            p++;
        }while (p < n);
        return med;
    }
};
