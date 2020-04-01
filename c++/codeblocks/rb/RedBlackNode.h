#ifndef REDBLACKNODE_H
#define REDBLACKNODE_H
enum colors {RED,BLACK};

template < typename N>
class RedBlackNode
{
    public:
        template<typename tr> friend class RedBlackTree;
        template<typename tr> friend class InOr;
        template<typename tr> friend class PreOr;
        template<typename tr> friend class PostOr;

        RedBlackNode()
        {
            color = RED;
            sons[0] = NULL;
            sons[1] = NULL;
        }

        RedBlackNode(N x) : data(x)
        {
            color = RED;
            sons[0] = NULL;
            sons[1] = NULL;
        }

        RedBlackNode(RedBlackNode & x) : data(x.data),color(x.color)
        {
            sons[0]= x.sons[0];
            sons[1]= x.sons[1];
        }


        void setColor()
        {
            if(color == RED)
            {
                color = BLACK;
                return;
            }
            color = RED;
            return;
        }


        int get_bh()
        {
            return bh;
        }

        virtual ~RedBlackNode() {}

    private:

        N data;
        RedBlackNode * sons[2];
        colors color;
        int bh;
};

#endif // REDBLACKNODE_H
