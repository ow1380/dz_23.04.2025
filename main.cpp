#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

void multisetManipulation(multiset<double>& st1, multiset<int>& st2, multiset<int>& diff) {
    // если размеры не равны, то все
    if (st1.size() != st2.size()) {
        cout << "st1.size() != st2.size()";
        return;
    }

    // промежуточные векторы для обхода st1, st2
    vector<double> v1(st1.begin(), st1.end());
    vector<int> v2(st2.rbegin(), st2.rend());
    // вектор для записи итогового значения s2
    vector<int> new_st2;

    // обходим v1
    for (int i = 0; i < v1.size(); i++) {
        double drob = (v1[i]-floor(v1[i])) * 10.0;  // берем дробную часть *10
        // если больше 2, то записываем в разницу
        if (fabs(v2[i] - drob) > 2.0) {
            diff.insert(v2[i]);
        } else {
            // если меньше 2, то записываем в итоговое значение s2
            new_st2.push_back(v2[i]);
        }
    }
    // очищаем st2 и записываем в него итоговое значение
    st2.clear();
    for (int i : new_st2) st2.insert(i);
}

int main()
{
    multiset<double> st1 = {1.68, 2.71, 3.14};
    multiset<int>    st2 = {7, 5, 3};
    multiset<int>    diff;

    multisetManipulation(st1, st2, diff);

    cout << "st2: ";
    for (int i : st2) cout << i << ' ';

    cout << "\ndiff: ";
    for (int i : diff) cout << i << ' ';
}
