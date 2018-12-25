#ifndef BST_HPP
#define BST_HPP

template<typename T> class BSTNode
{
    public:
        T key;
        BSTNode<T>* parent;
        BSTNode<T>* left;
        BSTNode<T>* right;
};

template<typename T> class BST
{
    public:
        BST();
        
        virtual ~BST();
        void Insert(T key);
        bool Remove(T key);
        BSTNode<T>* Find(T key);
        void Print();
        void Destroy();
        int Size();
        private:
            BSTNode<T>* root;
            int size;
            BSTNode<T>* CreateNode(T key);
            void InOder(BSTNode<T>* node);
            void BstNodeSwap(BSTNode<T>** node);
};

#endif /* BST_HPP */

