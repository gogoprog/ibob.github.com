#include "common.inl"

#include <vector>
#include <list>

struct ivec
{
    int x, y;
    int manhattan_length() const {
        return x + y;
    }
};

void vector(picobench::state& s)
{
    std::vector<ivec> v;
    srand(s.iterations());
    v.reserve(s.iterations());

    for (int i=0; i<s.iterations(); ++i) {
        v.push_back({rand(), rand()});
    }

    int sum = 0;

    {
        picobench::scope scope(s);
        for(const auto& elem : v) {
            sum += elem.manhattan_length();
        }
    }

    sanity_check(s.iterations(), sum);
}

void list(picobench::state& s)
{
    std::list<ivec> l;
    srand(s.iterations());

    for (int i=0; i<s.iterations(); ++i) {
        l.push_back({rand(), rand()});
    }

    int sum = 0;

    {
        picobench::scope scope(s);
        for(const auto& elem : l) {
            sum += elem.manhattan_length();
        }
    }

    sanity_check(s.iterations(), sum);
}



// dumb global-state thread-unsafe allocator
// do not reuse!
template <typename T>
class pool_alloc
{
public:
    static std::vector<std::vector<T>> pool;
    //static constexpr size_t PAGE_SIZE = 2048;
    static constexpr size_t PAGE_SIZE = 2048;

    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const* const_pointer;
    typedef value_type& reference;
    typedef value_type const& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef std::true_type propagate_on_container_swap;

    pool_alloc()
    {
        pool.back().reserve(PAGE_SIZE);
    }

    pool_alloc(const pool_alloc& other)
    {
    }

    template <typename Other>
    pool_alloc(const pool_alloc<Other>& other)
    {
    }
    
    pointer allocate(size_type size, const void* = nullptr)
    {
        if (!pool.back().empty() && pool.back().size() + size > PAGE_SIZE) {
            pool.emplace_back();
            pool.back().reserve(max(PAGE_SIZE, size));
        }

        auto os = pool.back().size();
        pool.back().resize(pool.back().size() + size);        
        return pool.back().data() + os;
    }

    void deallocate(pointer mem, size_type)
    {
        // we no care
    }

    size_type max_size() const
    {
        return 2000000000; // whatever
    }

    pool_alloc& operator=(const pool_alloc& other)
    {
        return *this;
    }

    template <class Other>
    pool_alloc& operator=(const pool_alloc<Other>& other)
    {
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    // boilerplate follows
    template <typename Other>
    struct rebind { typedef pool_alloc<Other> other; };

    pointer address(reference ref) const
    {
        return &ref;
    }

    const_pointer address(const_reference ref) const
    {
        return &ref;
    }

    void construct(pointer ptr, const value_type& val)
    {
        ::new(ptr)value_type(val);
    }

    void destroy(pointer ptr)
    {
        ptr->~value_type();
    }
};

template <typename T, typename Pool>
bool operator ==(const pool_alloc<T>& a, const pool_alloc<T>& b)
{
    return true;
}

template <typename T, typename Pool>
bool operator !=(const pool_alloc<T>& a, const pool_alloc<T>& b)
{
    return !false;
}

template <typename T>
std::vector<std::vector<T>> pool_alloc<T>::pool(1);

void list_alloc(picobench::state& s)
{
    std::list<ivec, pool_alloc<ivec>> l;
    srand(s.iterations());

    for (int i = 0; i<s.iterations(); ++i) {
        l.push_back({ rand(), rand() });
    }

    int sum = 0;

    {
        picobench::scope scope(s);
        for (const auto& elem : l) {
            sum += elem.manhattan_length();
        }
    }

    sanity_check(s.iterations(), sum);
}

PICOBENCH(vector);
PICOBENCH(list);
PICOBENCH(list_alloc);
