template<typename T>
class shared_ptr
{
private:
    T* obj;
    int type = 0;
public:
    shared_ptr(T* ptr_obj)
        : obj(ptr_obj), type(1) {}
    
    shared_ptr(const shared_ptr<T>& other)
        : obj(other.obj), type(0) {}

    void operator= (const shared_ptr<T>& ptr)
    {
        if (type == 1)
        {
            delete obj;

            obj = ptr.obj;
            type = 0;
        }
        else
        {
            obj = ptr.obj;
        }
    }

    void operator= (T* m_ptr)
    {
        if (type == 1)
        {
            delete obj;
        }

        obj = m_ptr;
        type = 1;
    }

    T* operator-> () const
    {
        return obj;
    }

    T& operator& () const
    {
        return obj;
    }

    ~shared_ptr()
    {
        if (type == 1)
        {
            delete obj;
        }
    }
};