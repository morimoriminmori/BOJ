
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
void __main();
const long long INF = 1e18;
int main(){
  fastio;
  __main();
  return 0;
}
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define mp make_pair
#define setbits(x) __builtin_popcountll(x)
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep1(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i > b; i--)
#define per1(i, a, b) for (int i = a; i >= b; i--)
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define lowerbound(x, y) lower_bound(all(x), y) - x.begin()
#define upperbound(x, y) upper_bound(all(x), y) - x.begin()
#define setbits(x) __builtin_popcountll(x)
#define poly vector<ll>
#define poly2 vector<pii>
#define MAX 1000005
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884L
#define EPS 1e-9
#define func(x) [](auto& x) -> decltype(auto)
#define getbit(x, i) (((x) >> (i)) & 1)
#define setbit(x, i) ((x) | (1LL << (i)))
#define clearbit(x, i) ((x) & ~(1LL << (i)))
#define togglebit(x, i) ((x) ^ (1LL << (i)))
#define isbit(x, i) (((x) >> (i)) & 1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) / __gcd(a, b) * (b))
#define allmin(x) *min_element(all(x))
#define allmax(x) *max_element(all(x))
#define allsum(x) accumulate(all(x), 0LL)
#define allprod(x) accumulate(all(x), 1LL, multiplies<ll>())
#define allsort(x) sort(all(x))
#define allrev(x) reverse(all(x))
#define allunique(x) x.erase(unique(all(x)), x.end())
#define allcount(x, y) count(all(x), y)
#define allfind(x, y) find(all(x), y)
#define allfind_if(x, y) find_if(all(x), y)
#define allfind_if_not(x, y) find_if_not(all(x), y)
#define allbinary_search(x, y) binary_search(all(x), y)
#define alllower_bound(x, y) lower_bound(all(x), y)
#define allupper_bound(x, y) upper_bound(all(x), y)
#define allequal(x, y) equal(all(x), all(y))
#define alllexicographical_compare(x, y) lexicographical_compare(all(x), all(y))
#define str string

typedef struct hashpair {
  char* key;
  int value;
} hashpair;

hashpair* makepair(char* key, int value) {
  hashpair* newpair = (hashpair*)malloc(sizeof(hashpair));
  newpair->key = strdup(key);
  newpair->value = value;
  return newpair;
}

typedef enum state
{
	EMPTY,
	USED,
	DELETED
} state;

typedef struct node
{
	hashpair* data;
	unsigned int hash_value;
	state State;
} node;

typedef struct hashtype
{
	node* bucket;
	int size;
	int capacity;
} hashtype;

void initialize(hashtype* hash)
{
	hash->bucket = NULL;
	hash->capacity = 0;
	hash->size = 0;
}

static unsigned int hasing(unsigned char *str)
{
	unsigned int hash = 5381;

	while (*str != '\0')
	{
		hash = hash * 33 + *str;
		++str;
	}
	return hash;
}

#define MAX_LOAD_FACTOR 0.5

void re_allocate(hashtype* hash, int new_capacity)
{
	if (new_capacity < 2) new_capacity = 2;
	node* new_bucket = (node*)malloc(sizeof(node) * new_capacity);
	for (int i = 0; i < new_capacity; ++i) {
		new_bucket[i].data = NULL;
		new_bucket[i].hash_value = 0;
		new_bucket[i].State = EMPTY;
	}
	if (hash->bucket) {
		for (int i = 0; i < hash->capacity; ++i) {
			if (hash->bucket[i].State == USED) {
				unsigned int idx = hash->bucket[i].hash_value;
				while (new_bucket[idx % new_capacity].State == USED) {
					++idx;
				}
				new_bucket[idx % new_capacity] = hash->bucket[i];
			}
		}
		free(hash->bucket);
	}
	hash->bucket = new_bucket;
	hash->capacity = new_capacity;
}

void insert(hashtype* hash, hashpair* data)
{
	if (hash->capacity == 0
		|| (double)hash->size / hash->capacity > MAX_LOAD_FACTOR)
		re_allocate(hash, hash->capacity == 0 ? 2 : hash->capacity * 2);
	
	unsigned int hash_value = hasing((unsigned char*)data->key);
	unsigned int idx = hash_value;

	while (hash->bucket[idx % hash->capacity].State == USED)
	{
		if (strcmp(hash->bucket[idx % hash->capacity].data->key, data->key) == 0)
			return;
		++idx;
	}

	hash->bucket[idx % hash->capacity] = (node){data, hash_value, USED};
	++hash->size;
}

static int find_idx(hashtype* hash, char* key)
{
	unsigned int hash_value = hasing((unsigned char*)key);
	unsigned int idx = hash_value;

	for (int i = 0; i < hash->capacity; ++i, ++idx)
	{
		if (hash->bucket[idx % hash->capacity].State == EMPTY)
			break;
		if (hash->bucket[idx % hash->capacity].State == DELETED)
			continue;
		if (strcmp(hash->bucket[idx % hash->capacity].data->key, key) == 0)
			return idx % hash->capacity;
	}
	return -1;
}

void erase(hashtype* hash, char* key)
{
	int idx = find_idx(hash, key);
	if (idx == -1)
		return;
	
	free(hash->bucket[idx].data->key);
	free(hash->bucket[idx].data);
	hash->bucket[idx].State = DELETED;
	--hash->size;
}

hashpair* find(hashtype* hash, char* key)
{
	int idx = find_idx(hash, key);
	if (idx == -1)
		return NULL;
	
	return hash->bucket[idx].data;
}

static int get_next_prime(int num)
{
	while (true)
	{
		bool is_prime = true;

		for (long long i = 2; i * i <= num; ++i)
		{
			if (num % i == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			return (num);
		++num;
	}
}

void clear(hashtype* hash)
{
	for (int i = 0; i < hash->capacity; ++i)
	{
		if (hash->bucket[i].State == USED)
		{
			free(hash->bucket[i].data->key);
			free(hash->bucket[i].data);
		}
	}
	free(hash->bucket);
	initialize(hash);
}
#include <cstdio>
#include <cctype>
#include <cstring>
const int INPUT_BUFFER_SIZE = 1 << 20;
const int OUTPUT_BUFFER_SIZE = 1 << 20;

char input_buffer[INPUT_BUFFER_SIZE];
int input_pos = 0, input_len = 0;

char output_buffer[OUTPUT_BUFFER_SIZE];
int output_pos = 0;

inline char next_char() {
    if (input_pos == input_len) {
        input_len = fread(input_buffer, 1, INPUT_BUFFER_SIZE, stdin);
        input_pos = 0;
        if (input_len == 0) return EOF;
    }
    return input_buffer[input_pos++];
}

inline int fast_read_int() {
    int x = 0, neg = 0;
    char c = next_char();
    while (!isdigit(c) && c != '-' && c != EOF) c = next_char();
    if (c == '-') {
        neg = 1;
        c = next_char();
    }
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = next_char();
    }
    return neg ? -x : x;
}

inline void flush_output() {
    fwrite(output_buffer, 1, output_pos, stdout);
    output_pos = 0;
}

inline void fast_write_char(char c) {
    if (output_pos == OUTPUT_BUFFER_SIZE) flush_output();
    output_buffer[output_pos++] = c;
}

inline void fast_write_int(int x) {
    if (x < 0) {
        fast_write_char('-');
        x = -x;
    }
    char tmp[10];
    int len = 0;
    if (x == 0) tmp[len++] = '0';
    while (x > 0) {
        tmp[len++] = (x % 10) + '0';
        x /= 10;
    }
    while (len--) fast_write_char(tmp[len]);
    fast_write_char('\n');
}

inline void fast_read_string(char* s) {
    char c = next_char();
    while (isspace(c)) c = next_char();
    while (!isspace(c) && c != EOF) {
        *s++ = c;
        c = next_char();
    }
    *s = '\0';
}

inline void fast_write_string(const char* s) {
    while (*s) {
        fast_write_char(*s++);
    }
}

void __main() {
  int x, y;
  x = fast_read_int();
  y = fast_read_int();

  hashtype data;
  initialize(&data);

  vector<string> names(x + 1); 

  rep1(i, 1, x) {
    char key[100];
    fast_read_string(key);
    names[i] = key;
    hashpair* pair = makepair(key, i);
    insert(&data, pair);
  }

  rep1(i, 1, y) {
    char key[100];
    fast_read_string(key);

    if (isdigit(key[0])) {
      int num = atoi(key);
      fast_write_string(names[num].c_str());
      fast_write_char('\n');
    } else {
      hashpair* pair = find(&data, key);
      fast_write_int(pair->value);
    }
  }

  clear(&data);
  flush_output();
}
