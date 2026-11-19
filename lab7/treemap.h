#include<iostream>
#include<string>

template<typename K, typename V>
struct treemap_t{

    struct pair_t {
        K key;
        V value;
    };


    struct node_t:pair_t{
        node_t* parent;
        node_t* left;
        node_t* right;

        node_t(node_t* parent):parent{parent}, left{nullptr}, right{nullptr}{}
    };

    node_t* root;

    treemap_t():root{nullptr}{}

    node_t* lookup(node_t** pcur, node_t* parent, const K* key, bool create){

        if(*pcur == nullptr){
            if(create == false) return nullptr; //we did not find
            
            *pcur = new node_t { parent };
            (*pcur)->key = *key;
            return *pcur;
        }
        node_t* cur = *pcur;

        if(*key == cur->key) return cur;

        if(*key < cur->key) return lookup(&cur->left, cur, key, create);
        else return lookup(&cur->right, cur, key, create);

    }


    void set_at(const K& key, const V& value){
        node_t* cur = lookup(&root,  nullptr, &key, true);
        cur->value = value  ;
    }

    V& at(const K& key){
        node_t* cur = lookup(&root,  nullptr, &key, false);
        if(cur == nullptr){
            std::cout<<"A node with a key "<<key<<" does not exist"<<std::endl;
            exit(1);
        }
        return cur->value;
    }

    void display(node_t* cur, std::string prefix){
        if(cur == nullptr) return;

        display(cur->left, prefix + "  ");
        std::cout<<prefix<<"("<<cur->key<<", "<<cur->value<<")"<<std::endl;
        display(cur->right, prefix + "  ");
    }

    void display(){
        display(root, "");
    }

    struct iterator_t{
        node_t* cur;
        iterator_t(node_t* root){
            while(root != nullptr && root->left != nullptr) root = root->left;
            cur = root;
        };

        void next(){
            if(cur->right != nullptr){
                cur = cur->right;
                while(cur->left != nullptr) cur = cur->left;
            }else{
                while(cur->parent != nullptr && cur->parent->right == cur){
                    cur = cur->parent;
                }
                cur = cur->parent;
            }
        }

        iterator_t& operator ++(){
            next();
            return *this;
        }

        bool operator != (const iterator_t& it) const{
            return this->cur != it.cur;
        }


        pair_t& operator *(){
            return *cur;
        }
    };


    iterator_t begin(){
        iterator_t it = iterator_t {root};
        return it;
    }

    iterator_t end(){
        iterator_t it = iterator_t {nullptr};
        return it;
    }


    V& operator [] (const K& key){
        return lookup(&root, nullptr, &key, true)->value;
    }
    
};

struct account_t{
    double balance;
    std::string note;
    
    account_t():balance{0}, note{""}{};
    account_t(double balance):balance{balance}, note{""}{};
};





