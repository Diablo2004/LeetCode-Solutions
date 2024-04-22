class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        int moves = 0;

        if (dead.count(start)) return -1;
        if (start == target) return 0;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++) {
                string current = q.front();
                q.pop();

                if (current == target) return moves;

                for (int j = 0; j < 4; j++) {
                    for (int k = -1; k <= 1; k += 2) {
                        string next = current;
                        next[j] = (next[j] - '0' + k + 10) % 10 + '0';

                        if (!dead.count(next) && !visited.count(next)) {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }

            moves++;
        }

        return -1; 
    }
};
