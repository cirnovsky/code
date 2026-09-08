template<class T, class U>
inline bool cmax(T& a, const U& b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
