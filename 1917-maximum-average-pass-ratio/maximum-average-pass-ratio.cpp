class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [](const tuple<double, int, int>& a, const tuple<double, int, int>& b) {
            return get<0>(a) < get<0>(b); // Max heap based on improvement ratio
        };

        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, decltype(cmp)> pq(cmp);

        // Populate the priority queue with initial values
        for (auto cls : classes) {
            int pass = cls[0];
            int total = cls[1];
            double improvement = ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
            pq.push({improvement, pass, total});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [improvement, pass, total] = pq.top();
            pq.pop();
            pass++;
            total++;
            double newImprovement = ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
            pq.push({newImprovement, pass, total});
        }

        // Calculate the final average ratio
        double ans = 0;
        while (!pq.empty()) {
            auto [improvement, pass, total] = pq.top();
            pq.pop();
            ans += (double)pass / total;
        }

        return ans / classes.size();
    }
};
