#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;

    deque<pair<int, int>> onRoad_element_pii; // first: truck�� �󸶳� ������, second: weight
    int onRoad_sum = 0;
    int truck_weights_index = 0; // �Է��� vector�ε� pop_front�� ����ϰ� �; ���

    for (;; answer++)
    {
        // Ʈ�� left_shift
        for (auto& ele : onRoad_element_pii)
        {
            ele.first = ele.first + 1;
        }
        // ���θ� ����ģ Ʈ���� pop
        if (!onRoad_element_pii.empty() && onRoad_element_pii[0].first >= bridge_length)
        {
            onRoad_sum -= onRoad_element_pii[0].second;
            onRoad_element_pii.pop_front();
        }
        // �б� ���� ����
        if (truck_weights_index >= truck_weights.size() && onRoad_element_pii.empty())
            break;

        if (truck_weights_index >= truck_weights.size())
            continue;
        // �б� ���� ��

        // ���ο� Ʈ���� �ִ°� �����ϸ�
        if (onRoad_sum + truck_weights[truck_weights_index] <= weight)
        {
            onRoad_sum += truck_weights[truck_weights_index];
            onRoad_element_pii.push_back({ 0, truck_weights[truck_weights_index] });
            truck_weights_index++;
        }

    }

    return answer;
}