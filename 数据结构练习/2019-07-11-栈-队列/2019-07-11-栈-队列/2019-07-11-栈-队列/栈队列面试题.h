class Solution {
public:
	bool isValid(string str) {
		std::stack<char>    s;
		int size = str.size();    // ȡ�ַ����ĳ���
		for (int i = 0; i < size; i++) {
			char ch = str[i]; // ȡ i ���ַ�
			switch (ch) {
			case '(':case '[':case '{':
				s.push(ch);
				break;
			case ')': case ']': case '}': {
						  if (s.empty()) {
							  return false;
						  }
						  char left = s.top(); s.pop();
						  if (!((left == '(' && ch == ')')
							  || (left == '[' && ch == ']')
							  || (left == '{' && ch == '}'))) {
							  return false;
						  }
						  break;
			}
			}
		}

		if (!s.empty()) {
			return false;
		}

		return true;
	}
};