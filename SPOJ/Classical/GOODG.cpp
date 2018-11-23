#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using LD=long double;

constexpr int INF = 2000000000;
constexpr LL LLINF = 9000000000000000000;

template <class T>
struct ConvexHuLLSet {
	struct Line {
		T a, b; mutable LD x; bool type;
		bool operator<(const Line& rhs) const {
			return (type || rhs.type) ? x<rhs.x : a<rhs.a;
		}
		LD intersect(const Line& rhs) const {
			return LD(b - rhs.b) / LD(rhs.a - a);
		}
	};
	static constexpr LD MAX = std::numeric_limits<T>::max() / 10;
	static constexpr LD MIN = std::numeric_limits<T>::min() / 10;
	set<Line> lines;
	void adjust(typename set<ConvexHuLLSet<T>::Line>::iterator it){
		if(it != lines.begin()){
			auto pit = prev(it);
			pit->x = it!=lines.end() ? pit->intersect(*it) : MAX;
		}
		return;
	}
	T query(T x){
		auto it = lines.lower_bound(Line{T(0), T(0), LD(x), true});
		return it != lines.end() ? it->a * x + it->b : MIN;
	}
	void add_line(T a, T b) {
		Line ln = Line{a, b, 0.0, false};
		auto it = lines.lower_bound(ln);
		if (it != lines.end() && it->a == a) {
			if (it->b >= b) return;
			adjust(it = lines.erase(it));
		}
		ln.x = it != lines.end() ? it->intersect(ln) : MAX;
		while (it != lines.end() && ln.x >= it->x) {
			adjust(it = lines.erase(it));
			ln.x = it != lines.end() ? it->intersect(ln) : MAX;
		}
		while (it != lines.begin()) {
			--it;
			LD nx = it->intersect(ln);
			if (nx >= it->x) return;
			if (it != lines.begin() && prev(it)->x >= nx)
				adjust(it = lines.erase(it));
			else break;
		}
		it = lines.insert(ln).first;
		adjust(it); adjust(next(it));
	}
};

int main()
{
	int N;
	scanf("%d",&N);
	ConvexHuLLSet<LL> chs;
	chs.add_line(0LL, 0LL);
	for(int i=0;i<N;i++){
		LL a,d;
		scanf("%lld %lld",&a,&d);
		LL sz=chs.query(i)+a;
		chs.add_line(-d,sz+i*d);
	}
	printf("%lld\n",chs.query(N));

	return 0;
}
