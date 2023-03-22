#include <iostream>
#include <sstream>

using namespace std;

class Time {
public:
    int hours;
    int minutes;
    int seconds;

    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int seconds) {
        hours = seconds / 3600;
        seconds %= 3600;
        minutes = seconds / 60;
        seconds %= 60;
        this->seconds = seconds;
    }

    Time(string timeStr) {
        stringstream ss(timeStr);
        char c;
        ss >> hours >> c >> minutes >> c >> seconds;
    }

    Time operator+(const Time& other) const {
        Time result;
        result.seconds = seconds + other.seconds;
        result.minutes = minutes + other.minutes;
        result.hours = hours + other.hours;

        if (result.seconds >= 60) {
            result.seconds -= 60;
            result.minutes++;
        }

        if (result.minutes >= 60) {
            result.minutes -= 60;
            result.hours++;
        }

        return result;
    }

    Time operator-(const Time& other) const {
        Time result;
        int totalSeconds = getTimeInSeconds() - other.getTimeInSeconds();
        result = Time(totalSeconds);
        return result;
    }

    Time operator*(const int scalar) const {
        Time result;
        int totalSeconds = getTimeInSeconds() * scalar;
        result = Time(totalSeconds);
        return result;
    }

    operator int() const {
        return getTimeInSeconds();
    }

    int getTimeInSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    string toString() const {
        stringstream ss;
        if (hours < 10) {
            ss << "0";
        }
        ss << hours << "h:";
        if (minutes < 10) {
            ss << "0";
        }
        ss << minutes << "m:";
        if (seconds < 10) {
            ss << "0";
        }
        ss << seconds << "s";
        return ss.str();
    }

    friend ostream& operator<<(ostream& os, const Time& time) {
        os << time.toString();
        return os;
    }

    friend istream& operator>>(istream& is, Time& time) {
        string timeStr;
        is >> timeStr;
        time = Time(timeStr);
        return is;
    }
};

int main() {
    Time t1(200);
    cout << t1 << endl; // displays 0h:3m:20s

    Time t2;
    cout << "Enter time in format hours:h minutes:m seconds:s: ";
    cin >> t2; // user enters 10h:12m:1s

    Time t3 = t2 - t1; // 10h:8m:41s
    int t3s = t3; // 36521
    cout << t3 << endl;
    cout << t3s << endl;

    return 0;
}
