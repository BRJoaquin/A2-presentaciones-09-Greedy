#include <iostream>
#include <cstring>

using namespace std;

int minSwapsToBalance(char* s, int n) {
    int balance = 0;
    int swaps = 0;
    int misplaced_right = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '[') {
            if (misplaced_right > 0) {
                swaps++;
                misplaced_right--;
            } else {
                balance++;
            }
        } else {
            if (balance > 0) {
                balance--;
            } else {
                misplaced_right++;
            }
        }
    }

    return swaps;
}

void balanceString(char* s, int n) {
    int balance = 0;
    int misplaced_right = 0;
    int left_ptr = 0;
    int right_ptr = n - 1;

    while (left_ptr < right_ptr) {
        if (s[left_ptr] == '[') {
            left_ptr++;
            continue;
        }
        if (s[right_ptr] == ']') {
            right_ptr--;
            continue;
        }
        swap(s[left_ptr], s[right_ptr]);
        left_ptr++;
        right_ptr--;
    }
}

int main() {
    char s[100];
    cout << "Ingrese la secuencia de paréntesis: ";
    cin >> s;
    int n = strlen(s);
    int result = minSwapsToBalance(s, n);
    balanceString(s, n);
    cout << "Minimum swaps required: " << result << endl;
    cout << "Balanced string: " << s << endl;
    return 0;
}
