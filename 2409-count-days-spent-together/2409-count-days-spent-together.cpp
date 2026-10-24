
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        unordered_map<int, int> monthDays = {
            {1, 31}, {2, 28}, {3, 31}, {4, 30},
            {5, 31}, {6, 30}, {7, 31}, {8, 31},
            {9, 30}, {10, 31}, {11, 30}, {12, 31}
        };

        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for (int i = 1; i < month; i++) {
                day += monthDays[i];
            }

            return day;
        };

        int aliceArrive = convert(arriveAlice);
        int aliceLeave = convert(leaveAlice);
        int bobArrive = convert(arriveBob);
        int bobLeave = convert(leaveBob);

        int start = max(aliceArrive, bobArrive);
        int end = min(aliceLeave, bobLeave);

        return max(0, end - start + 1);
    }
};

