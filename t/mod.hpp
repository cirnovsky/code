template <int MOD>
class ModInt {
public:
	int value;

	// Constructors
	ModInt(long long v = 0) {
		value = int((v % MOD + MOD) % MOD);
	}

	// Implicit conversion to int
	operator int() const { return value; }

	// Unary minus
	ModInt operator-() const { return ModInt(-value); }

	// Arithmetic operators
	ModInt& operator+=(const ModInt& other) {
		value += other.value;
		if (value >= MOD) value -= MOD;
		return *this;
	}

	ModInt& operator-=(const ModInt& other) {
		value -= other.value;
		if (value < 0) value += MOD;
		return *this;
	}

	ModInt& operator*=(const ModInt& other) {
		value = int((1LL * value * other.value) % MOD);
		return *this;
	}

	// Modular exponentiation
	static ModInt pow(ModInt base, long long exp) {
		ModInt res = 1;
		while (exp > 0) {
			if (exp & 1) res *= base;
			base *= base;
			exp >>= 1;
		}
		return res;
	}

	// Modular inverse (only works if MOD is prime)
	static ModInt inv(ModInt a) {
		return pow(a, MOD - 2);
	}

	ModInt& operator/=(const ModInt& other) {
		return *this *= inv(other);
	}

	// Binary operators
	friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
	friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
	friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
	friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }

	// I/O
	friend ostream& operator<<(ostream& os, const ModInt& m) {
		return os << m.value;
	}
	friend istream& operator>>(istream& is, ModInt& m) {
		long long v;
		is >> v;
		m = ModInt(v);
		return is;
	}
};
