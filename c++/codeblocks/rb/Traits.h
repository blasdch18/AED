#ifndef MORE_H
#define MORE_H

template <class T>
class More
{
    public:
        More() {}
        virtual ~More() {}

        int operator()(const T &x , const T &y)
        {
            if(x<y)     return -1;
            if(x>y)     return 1;
            return 0;
        }
    protected:
    private:
};

#endif // MORE_H


template <typename T>
struct TreeTrait_cmp
{
    typedef T N;
    typedef More<N> cmp_type;
};
