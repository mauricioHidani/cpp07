
template<typename T>
void swap(T& s1, T& s2) {
	T aux = s1;
	s1 = s2;
	s2 = aux;
}

template<typename T>
T min(const T& s1, const T& s2) {
	return s1 < s2 ? s1 : s2;
}

template<typename T>
T max(const T& s1, const T& s2) {
	return s1 > s2 ? s1 : s2;
}
