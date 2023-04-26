#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// QUESTION 1
vector<int> findCommon(const vector<int>& list1, const vector<int>& list2) {
    vector<int> result;
    for (const int& val1 : list1) {
        for (const int& val2 : list2) {
            if (val1 == val2) {
                result.push_back(val1);
                break;
            }
        }
    }
    return result;
}

// QUESTION 2
vector<string> findPalindromes(const vector<string>& strs) {
    vector<string> palindromes;
    for (const auto& s : strs) {
        if (s == string(s.rbegin(), s.rend())) {
            palindromes.push_back(s);
        }
    }
    return palindromes;
}

// QUESTION 3
vector<int> getPrimes(const vector<int>& nums) {
    vector<bool> sieve(100, true);
    for (int i = 2; i * i <= sieve.size(); i++) {
        if (sieve[i]) {
            for (int j = i * i; j < sieve.size(); j += i) {
                sieve[j] = false;
            }
        }
    }
    vector<int> primes;
    for (const int& num : nums) {
        if (num >= 2 && sieve[num]) {
            primes.push_back(num);
        }
    }
    return primes;
}

// QUESTION 4
vector<string> anagrams(const string& word, const vector<string>& word_list) {
    vector<string> result;
    string sorted_word = word;
    transform(sorted_word.begin(), sorted_word.end(), sorted_word.begin(), ::tolower);
    sort(sorted_word.begin(), sorted_word.end());
    for_each(word_list.begin(), word_list.end(), [&](string str){
        string sorted_str = str;
        transform(sorted_str.begin(), sorted_str.end(), sorted_str.begin(), ::tolower);
        sort(sorted_str.begin(), sorted_str.end());
        if (sorted_str == sorted_word) {
            result.push_back(str);
        }
    });
    return result;
}
int main() {
    cout << "QUESTION 1: "<<endl;
    vector<int> list1 = {1, 2, 3, 4, 5};
    vector<int> list2 = {3, 4, 5, 6, 7};
    vector<int> result = findCommon(list1, list2);
    cout << "Common elements: ";
    for (int i = 0; i < result.size(); i++) {
        if (result[i] != 0) {
            cout << result[i] << ", ";
        }
    }
    cout << endl << endl;

    cout << "QUESTION 2: "<<endl;
    vector<string> strs = {"level", "python", "computer", "madam", "noon"};
    vector<string> palindromes = findPalindromes(strs);
    cout << "Palindromes: ";
    for (const string& s : palindromes) {
        cout << s << ", ";
    }
    cout << endl << endl;

    cout << "QUESTION 3: "<<endl;
    vector<int> nums {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    vector<int> primes = getPrimes(nums);
    cout << "Prime numbers in the original list:" << endl;
    for (const int& prime : primes) {
        cout << prime << ", ";
    }
    cout << endl << endl;

    cout << "QUESTION 4: "<<endl;
    string word = "listen";
    vector<string> word_list {"enlists", "google", "inlets", "banana", "computer"};
    vector<string> anagrams_list = anagrams(word, word_list);
    cout << "Anagrams: ";
    for (const string& anagram : anagrams_list) {
        cout << anagram << endl;
    }
    return 0;
}
