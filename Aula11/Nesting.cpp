int solution(vector<int> &s) 
{
    if (s.empty()) 
	return 1;

    if (s.length() % 2)
	return 0;

    int left_brackets = 0;
    for(auto c: s) {
        if(c == '(') {
            left_brackets ++;
        }
        else if(left_brackets > 0) {
            left_brackets --;
        }
        else {
            return 0;
        }
    }
    if(left_brackets)
	return 0;
    else
	return 1;
}
