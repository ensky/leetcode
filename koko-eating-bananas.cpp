class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        piles_ = &piles;
        H_ = H;
        return bsearch(1, *max_element(piles.begin(), piles.end()));
    }
    
    int bsearch(int min, int max) {
        if (min == max) {
            return min;
        }
        
        int mid = (min + max) / 2;
        int HCandidate = computeH(mid);
        
        if (HCandidate > H_) { //overflows
            return bsearch(mid + 1, max);
        } else {
            return bsearch(min, mid);
        }
    }
    
    int computeH(int K) {
        int h = 0;
        for (auto pile : (*piles_)) {
            h += (pile + K - 1) / K; // === math.ceil(pile / K)
        }
        return h;
    }
    
private:
    vector<int>* piles_;
    int H_;
};
