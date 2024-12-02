class Solution {
    class Car {
    public:
        int pos, speed;
        Car(int p, int s) : pos(p), speed(s) {}
    };
    static bool Comp(Car& a, Car& b) { 
        return a.pos > b.pos;  
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.emplace_back(position[i], speed[i]);
        }

        sort(cars.begin(), cars.end(), Comp);

        stack<float> st;
        for (auto& c : cars) {
            float time = (float)(target - c.pos) / c.speed;
            if (!st.empty() && time <= st.top()) {
            } else {
                st.push(time);
            }
        }

        return st.size();
    }
};
