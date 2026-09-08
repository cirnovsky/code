template<class T, class U>
inline bool cmin(T& a, const U& b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
