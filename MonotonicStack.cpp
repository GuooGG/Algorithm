#include "MonotonicStack.h"

std::vector<int> MonotonicStack::theNextBiggerElement(std::vector<int> input_v)
{
	int n = input_v.size();
	std::vector<int> res(n, INT32_MIN);
	//pait<index,value>
	std::stack<std::pair<int, int>> stk;
	for (int i = 0; i < n; i++) {
		int ele = input_v[i];
		//���ϴ�ջ��ȡ��ֵ�ȵ�ǰֵС��Ԫ��
		while (!stk.empty() && stk.top().second < ele) {
			res[stk.top().first] = ele;
			stk.pop();
		}
		//��������ջ
		stk.push(std::make_pair(i, input_v[i]));
	}
	return res;
}
