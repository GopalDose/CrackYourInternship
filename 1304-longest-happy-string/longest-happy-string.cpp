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
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Node, vector<Node>, compare> maxHeap;
        string result = "";
        if (a > 0)
            maxHeap.push(Node('a', a));
        if (b > 0)
            maxHeap.push(Node('b', b));
        if (c > 0)
            maxHeap.push(Node('c', c));

        while (maxHeap.size() > 1) {
            Node first = maxHeap.top();
            maxHeap.pop();
            Node second = maxHeap.top();
            maxHeap.pop();

            if (first.count >= 2) {
                result += first.data;
                result += first.data;
                first.count -= 2;
            } else {
                result += first.data;
                first.count -= 1;
            }

            if (second.count >= 2 && second.count >= first.count) {
                result += second.data;
                result += second.data;
                second.count -= 2;
            } else {
                result += second.data;
                second.count -= 1;
            }

            if (first.count > 0) {
                maxHeap.push(first);
            }
            if (second.count > 0) {
                maxHeap.push(second);
            }
        }
        if (maxHeap.size() == 1) {
            Node first = maxHeap.top();
            maxHeap.pop();

            if (first.count >= 2) {
                result += first.data;
                result += first.data;
                first.count -= 2;
            } else {
                result += first.data;
                first.count -= 1;
            }
        }
        return result;
    }
};