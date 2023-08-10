template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &v) {
	os << "(" << v.first << ", " << v.second << ")";
	return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
	int hsz = (int)v.size();
	int wsz = (int)v[0].size();
	os << "{ ";
	for(int i = 0; i < hsz; i++) {
		os << (i == 0 ? "" : "                    ");
		for (int j = 0; j < wsz; j++) { os << v[i][j] << ", "; }
		os << (i + 1 == hsz ? "}" : "\n");
	}
	return os;
}

template <typename T>
ostream &operator<<(ostream &os, set<T> &v) {
	os << "{ ";
	for (auto &l : v) {
		os << l << ", ";
	}
	os << "}";
	return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &v) {
	os << "{ ";
	for (auto itr = v.begin(); itr != v.end(); itr++) {
		os << *itr;
		itr++;
		if (itr != v.end()) os << ", ";
		itr--;
	}
	os << "}";
	return os;
}

template <typename T>
ostream &operator<<(ostream &os, queue<T> v) {
	os << "{ ";
	while (!v.empty()) {
		os << v.front() << ", ";
		v.pop();
	}
	os << "}";
	return os;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T> pq) {
	os << "{ ";
	while (!pq.empty()) {
		T cur = pq.top();
		pq.pop();
		os << cur << ", ";
	}
	os << "}";
	return os;
}

void debug_out() { cerr << endl; }
template <class Head, class... Tail>
void debug_out(Head H, Tail... T) {
	cerr << ", " << H;
	debug_out(T...);
}
#define debug(...) cerr << "Line " << __LINE__ << " : " << #__VA_ARGS__ << " ..", debug_out(__VA_ARGS__)