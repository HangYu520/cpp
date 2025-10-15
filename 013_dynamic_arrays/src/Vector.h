template <typename _Type>
class Vector
{
public:
    Vector() // * 构造函数，初始分配 3 个大小内存
        : m_size(0), m_capacity(3) 
    {
        m_data = static_cast<_Type*>(::operator new(sizeof(_Type) * m_capacity)); // operator new 分配内存
    }
    
    ~Vector() // * 析构函数，释放内存
    {
        for(size_t i = 0; i < m_size; i++)
        {
            m_data[i].~_Type(); // 析构对象
        }
        ::operator delete(m_data); // operator delete 释放内存
    }
    
    size_t size() const // * 返回当前大小
    {
        return m_size;
    }

    void push_back(const _Type& value) // * 添加元素
    {
        if (m_size == m_capacity)
        {
            reallocate(m_capacity + m_capacity / 2);
        }
        new (m_data + m_size) _Type(value); // placement new 构造对象
        ++m_size;
    }

    template<typename... Args>
    _Type& emplace_back(Args&&... args) // ... 表示可变个数的参数包
    {
        if (m_size == m_capacity)
        {
            reallocate(m_capacity + m_capacity / 2);
        }
        new (m_data + m_size) _Type(std::forward<Args>(args)...); // 传入参数原地构造
        ++m_size;
        return m_data[m_size - 1];
    }

    void pop_back() // * 删除最后一个元素
    {
        if (m_size > 0)
        {
            m_data[--m_size].~_Type(); // 析构对象
        }
    }

    _Type& operator[](size_t index) // * 非 const 访问元素
    {
        return m_data[index];
    }

    const _Type& operator[](size_t index) const // * const 访问元素
    {
        return m_data[index];
    }

    void reallocate(size_t newCapacity) // * 重新分配内存
    {
        m_size = newCapacity > m_size ? m_size : newCapacity; // 防止溢出
        _Type* new_data = static_cast<_Type*>(::operator new(sizeof(_Type) * m_capacity));
        for (size_t i = 0; i < m_size; ++i)
        {
            new (new_data + i) _Type(std::move(m_data[i])); // m_data 会被删除，可以放心移动
        }
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i].~_Type(); // 析构对象
        } 
        ::operator delete(m_data);
        m_data = new_data;
        m_capacity = newCapacity;
    }

    void clear() // * 清空
    {
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i].~_Type(); // 析构对象
        }
        m_size = 0;
    }

private:
    _Type* m_data;
    size_t m_size;
    size_t m_capacity;
};