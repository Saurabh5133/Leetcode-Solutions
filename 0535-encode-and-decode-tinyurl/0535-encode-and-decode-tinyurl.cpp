class Solution {
public:

    int count;
    unordered_map<string, string> mpp;
    // static unordered_map<int, string> decoded;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        string id = to_string(count++);
        string shortUrl = "http://tinyurl.com/" + id;
        mpp[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        return mpp[shortUrl];

    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));