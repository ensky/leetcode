
/**
 * problem: https://leetcode.com/problems/vowel-spellchecker/
 * result: 
 *   Runtime: 496 ms, faster than 5.04% of C++ online submissions for Vowel Spellchecker.
 *   Memory Usage: 34.5 MB, less than 61.76% of C++ online submissions for Vowel Spellchecker.
 * used_time: 20min
 */

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        this->prepareMatches(wordlist);
        return this->matchQueries(queries);
    }
    
    void prepareMatches(const vector<string>& wordlist) {
        this->wordlist = &wordlist;
        
        int idx = 0;
        for (const auto& word : wordlist) {
            this->updateMatch(this->exactMatch, word, idx);
            this->updateMatch(this->caseMatch, this->toLower(word), idx);
            this->updateMatch(this->vowelMatch, this->toVowel(word), idx);
            idx++;
        }
    }
    
    vector<string> matchQueries(const vector<string>& queries) {
        vector<string> results;
        for (const auto &query : queries) {
            string result = this->matchResult(this->exactMatch, query);
            if (result.empty()) {
                result = this->matchResult(this->caseMatch, this->toLower(query));
            }
            if (result.empty()) {
                result = this->matchResult(this->vowelMatch, this->toVowel(query));
            }
            results.emplace_back(std::move(result));
        }
        return results;
    }
    
    void updateMatch(map<string, int>& matchMap, const string& word, int idx) {
        if (matchMap.count(word) > 0) {
            return;
        }
        matchMap[word] = idx;        
    }
    
    string matchResult(const map<string, int>& matchMap, const string& query) {
        auto it = matchMap.find(query);
        if (it == matchMap.end()) {
            return "";
        }
        return this->wordlist->at(it->second);
    }
    
    string toLower(const std::string& str) {
        string result;
        std::transform(str.begin(), str.end(), std::back_inserter(result), 
                       [](char c ){ return std::tolower(c); });
        return result;
    }
    
    string toVowel(const std::string& str) {
        string newstr = toLower(str);
        string result;
        for (auto c : newstr) {
            if (this->isVowel(c)) {
                result.push_back('|');
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
    
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
private:
    const vector<string>* wordlist;
    map<string, int> exactMatch;
    map<string, int> caseMatch;
    map<string, int> vowelMatch;
};
