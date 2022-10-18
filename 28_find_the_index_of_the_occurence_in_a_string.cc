class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size())
            return -1;
        long long mod = 1000 * 1000 * 1000 + 7;
        long long prime = 31;
        long long prime_power = 1;
        for(int i = 1; i < needle.size(); i++)
            prime_power = (prime_power * prime) % mod;
        long long hash_haystack = 0, hash_needle = 0;
        for(int i = 0; i < needle.size(); i++){
            hash_haystack = (hash_haystack * prime + (haystack[i] - 'a')) % mod;
            hash_needle = (hash_needle * prime + (needle[i] - 'a')) % mod;
        }
        if(hash_haystack == hash_needle)
            return 0;
        for(int i = needle.size(); i < haystack.size(); i++){
            hash_haystack = ((hash_haystack + mod - (prime_power * (haystack[i - needle.size()] - 'a')) % mod) * prime + haystack[i] - 'a') % mod;
            if(hash_haystack == hash_needle)
                return(i - needle.size() + 1);
        }
        return -1;
    }
};
