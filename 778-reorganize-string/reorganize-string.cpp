class Node {
public:
    char data;
    int count;
    Node(char ch, int d) {
        data = ch;
        count = d;
    }
};

class compare {
public:
    bool operator()(Node a, Node b) { return a.count < b.count; }
};
class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0}; // Frequency array for letters 'a' to 'z'
        string result = "";

        // Count the frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Max heap to store characters based on frequency
        priority_queue<Node, vector<Node>, compare> maxHeap;

        // Populate the max heap with characters and their frequencies
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push(Node('a' + i, freq[i]));
            }
        }

        // Reorganize the string
        while (maxHeap.size() > 1) {
            Node first = maxHeap.top();
            maxHeap.pop();
            Node second = maxHeap.top();
            maxHeap.pop();

            // Append the two most frequent characters
            result += first.data;
            result += second.data;

            // Decrease their frequencies and push back if still valid
            first.count--;
            second.count--;
            if (first.count > 0) {
                maxHeap.push(first);
            }
            if (second.count > 0) {
                maxHeap.push(second);
            }
        }

        // Handle the last remaining character, if any
        if (!maxHeap.empty()) {
            Node last = maxHeap.top();
            maxHeap.pop();
            if (last.count == 1) {
                result += last.data;
            } else {
                return ""; // Not possible to reorganize
            }
        }

        return result;
    }
};