template<typename T>
class shared_ptr
{
private:
    T* obj;

    struct Utility
    {
        int ptr_count = 0;
    };

    Utility* util;

public:
    shared_ptr(T* ptr_obj)
        : obj(ptr_obj), util(new Utility)
    {
        util->ptr_count++;
    }   
    
    shared_ptr(const shared_ptr<T>& other)
        : obj(other.obj), util(other.util) 
    {
        util->ptr_count++;
    }

    shared_ptr()
        : obj(nullptr), util(new Utility) {}

    int count() const
    {
        return util->ptr_count;
    }

    void reset()     
    {
        if (util->ptr_count == 1 && obj != nullptr)
        {
            delete obj;
            util->ptr_count--;
        }
        else
        {
            util->ptr_count--;
            obj = nullptr;
        }
    }
    
    void operator= (const shared_ptr<T>& ptr)
    {
        if (util->ptr_count == 1 && obj != nullptr)
        {
            delete obj;

            obj = ptr.obj;
            util = ptr.util;
            util->ptr_count++;
        }
        else
        {
            if (util->ptr_count != 0)
                util->ptr_count--;

            util = ptr.util;
            obj = ptr.obj;
            util->ptr_count++;
        }
    }

    void operator= (T* m_ptr)
    {
        if (util->ptr_count == 1 && obj != nullptr)
        {
            delete obj;
        }
        else 
        {
            if(util->ptr_count != 0)
                util->ptr_count--;

            obj = m_ptr;
            util = new Utility;
            util->ptr_count++;
        }
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
        if (util->ptr_count == 1 && obj != nullptr)
        {
            delete obj;
            delete util;
        }
        else
        {
            util->ptr_count--;
        }
    }
};